/*
 *   Copyright (c) 2015 RingCentral Inc. All rights reserved.
 *
 *   @Author Easton Hou <easton.hou@ringcentral.com>
 *
 */

/*
 This library enables normal class to be serialized or deserialized with json object.
 
 Example 1: serialization for customized structs or classes
 
 struct B
 {
 int id;
 string name;
 string description;
 JSON_SERIALIZE(JM(id), JM(name), JM(description))
 };
 
 struct A
 {
 int id;
 vector<B> children;
 JSON_SERIALIZE(JM(id), JM(children))
 };
 
 void main()
 {
 A a = createObjectA();
 auto json = a.jserialize();
 
 A a2;
 a2.jdeserialize(json);
 }
 
 Example 2:  usage of json_serialize or json_deserialize
 void main()
 {
 using namespace json11;
 
 vector<Child> children = initializeChildren();
 
 Json::object jobj;
 json_serialize(jobj,
 "name", "Tom",
 "age", 15
 "children", children);
 
 string name;
 int age;
 json_deserialize(jobj,
 "name", name,
 "age", age,
 "children", children);
 }
 */
#pragma once

#include "json_parsing_failed.hpp"
#include "json_serialization_exceptions.hpp"
#include <json11/json11.hpp>
#include <optional/optional.hpp>

#include "../common/string_algo.hpp"

using namespace std::experimental;
//This macro declares which members are serializable
#define JSON_SERIALIZE(...)\
json11::Json jserialize()const\
{\
json11::Json::object jlist;\
json_serialize(jlist, __VA_ARGS__);\
return jlist;\
}\
void jdeserialize(const json11::Json& j)\
{\
json_deserialize(j.object_items(), __VA_ARGS__);\
}
#define JSON_NO_SERIALIZE()\
json11::Json jserialize()const {return json11::Json();}\
void jdeserialize(const json11::Json& ) {}
//using the member name as the json key.
#define JM(v)   #v, v

#define RC_KEY_VALUE(v)   #v, v

struct EmptyJsonType {
    JSON_NO_SERIALIZE()
};

namespace json11 {
    
    //deserialize native values.
    struct JsonValueAdapter {
        void operator()(const Json& j, int64_t& value) {
            value = j.int_value();
        }
        void operator()(const Json& j, int& value) {
            value = (int)j.int_value();
        }
        void operator()(const Json& j, double& value) {
            value = j.number_value();
        }
        void operator()(const Json& j, float& value) {
            value = (float)j.number_value();
        }
        void operator()(const Json& j, std::string& value) {
            value = j.string_value();
        }
        void operator()(const Json& j, bool& value) {
            value = j.bool_value();
        }
        //for container
        template<typename Type>
        void operator()(const Json& j, Type& value) {
            value.clear();
            for (const Json& item : j.array_items()) {
                typename Type::value_type v;
                JsonValueAdapter()(item, v);
                value.push_back(v);
            }
        }
    };
    
    //the functor for serializing native types, such as int, bool, string, enum, vector<native_type>, etc.
    template<typename Key, typename Type, bool IsEnum = std::is_enum<Type>::value>
    struct JsonSerializerPod {
        void forward(Json::object& jlist, const Key& name, const Type& value) {
            jlist[name] = (int64_t)value;
        }
        void backward(const Json::object& jlist, const Key& name, Type& value) {
            auto it = jlist.find(name);
            if (jlist.end() == it)
                throw JsonMissingKey(jlist, name);
            value = (Type)it->second.int_value();
        }
    };
    
    template<typename Key, typename Type>
    struct JsonSerializerPod<Key, Type, false> {
        void forward(Json::object& jlist, const Key& name, const Type& value) {
            jlist[name] = value;
        }
        void backward(const Json::object& jlist, const Key& name, Type& value) {
            auto it = jlist.find(name);
            if (jlist.end() == it)
                throw JsonMissingKey(jlist, name);
            JsonValueAdapter()(it->second, value);
        }
    };
    //serializer for customized types
    template<typename Key, typename Type>
    struct JsonSerializer {
        void forward(Json::object& jlist, const Key& name, const Type& value) {
            jlist[name] = value.jserialize();
        }
        void backward(const Json::object& jlist, const Key& name, Type& value) {
            auto it = jlist.find(name);
            if (jlist.end() == it)
                throw JsonMissingKey(jlist, name);
            value.jdeserialize(it->second);
        }
    };
    
    template<typename Key, typename Type>
    struct JsonSerializer < Key, optional<Type> > {
        void forward(Json::object& jlist, const Key& name, const optional<Type>& value) {
            if (value)
                json_serialize(jlist, name, *value);
        }
        void backward(const Json::object& jlist, const Key& name, optional<Type>& value) {
            auto it = jlist.find(name);
            if (jlist.end() != it) {
                Type v;
                json_deserialize(jlist, name, v);
                value = v;
            }
        }
    };
    //serializer for vector of customized types
    template<typename Key, typename Type>
    struct JsonSerializerVector {
        void forward(Json::object& jlist, const Key& name, const Type& value) {
            Json::array arr;
            for (const auto& item : value)
                arr.push_back(item.jserialize());
            jlist[name] = arr;
        }
        void backward(const Json::object& jlist, const Key& name, Type& value) {
            value.clear();
            auto it = jlist.find(name);
            if (jlist.end() == it)
                return; //not throwing JsonMissingKey for vectors
            //            throw JsonMissingKey(jlist, name);
            for (auto& jitem : it->second.array_items()) {
                typename Type::value_type v;
                v.jdeserialize(jitem);
                value.push_back(v);
            }
        }
    };
    //determines that if a type is a supported container. currently only vector is supported.
    template<typename T>
    struct is_supported_container {
        static const bool value = false;
    };
    template<typename T>
    struct is_supported_container < std::vector<T> > {
        static const bool value = true;
    };
    //determines if it is a vector of supported types, such as vector<int>, vector<string>
    template<typename Type>
    struct is_vector_of_native {
        static const bool value = false;
    };
    template<typename Type>
    struct is_native_type;
    template<typename Type>
    struct is_vector_of_native < std::vector<Type> > {
        static const bool value = is_native_type<Type>::value;
    };
    //determines that if a type is supported type
    template<typename Type>
    struct is_native_type {
        static const bool value =
        std::is_integral<Type>::value ||
        std::is_enum<Type>::value ||
        std::is_floating_point<Type>::value ||
        //   std::is_same<Type, std::string>::value ||
        std::is_convertible<Type, std::string>::value ||
        is_vector_of_native<Type>::value;
    };
    
    //selectors of types,
    //native type is dipatched to JsonSerializerPod
    //vector of non-native is dispatched to JsonSerializerVector
    //single non-native type is dispatched to JsonSerializer
    template<typename Key, typename Type, typename... Tail>
    inline void json_serialize(Json::object& jlist, const Key& name, const Type& value, const Tail& ... tail) {
        using namespace std;
        typename conditional < is_native_type<Type>::value,
        JsonSerializerPod<Key, Type>,
        typename conditional<is_supported_container<Type>::value,
        JsonSerializerVector<Key, Type>,
        JsonSerializer<Key, Type>
        >::type
        >::type().forward(jlist, name, value);
        json_serialize(jlist, tail...);
    }
    
    //terminus
    inline void json_serialize(Json::object& ) {
    }
    
    //the same basis as json_serialize
    template<typename Key, typename Type, typename... Tail>
    inline void json_deserialize(const Json::object& jlist, const Key& name, Type& value, Tail& ... tail) {
        using namespace std;
        typename conditional < is_native_type<Type>::value,
        JsonSerializerPod<Key, Type>,
        typename conditional<is_supported_container<Type>::value,
        JsonSerializerVector<Key, Type>,
        JsonSerializer<Key, Type>
        >::type
        >::type().backward(jlist, name, value);
        json_deserialize(jlist, tail...);
    }
    
    //terminus
    inline void json_deserialize(const Json::object& ) {
    }
}

template<>
struct stringable<json11::Json>
{
    std::string operator()(const json11::Json& value)
    {
        return value.dump();
    }
    json11::Json convert_back(const std::string& value)
    {
        std::string error;
        json11::Json json = json11::Json::parse(value, error);
        if (false == error.empty())
            throw std::runtime_error(error);
        else
            return json;
    }
};

template<typename ... KeyValues>
inline json11::Json toJson(const KeyValues& ... keyvalues) {
    json11::Json::object jlist;
    json_serialize(jlist, keyvalues...);
    return jlist;
}

inline json11::Json stringToJson(const std::string& data) {
    std::string error;
    auto jsonData = json11::Json::parse(data, error);
    if (!error.empty()) {
        throw JsonParsingFailed(data, error);
    }
    return jsonData;
}

template<typename Type>
inline json11::Json toJson(const Type& value) {
    return value.jserialize();
}

template<typename... Params>
inline std::string toJsonString(const Params&... params) {
    return string_algo::to_string(toJson(params...));
}

template<>
inline std::string toJsonString<json11::Json>(const json11::Json& json) {
    return string_algo::to_string(json);
}


