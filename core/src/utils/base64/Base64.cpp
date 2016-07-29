/*
 *
 * Base64.cpp
 *
 *
 * CSF2G Base64 Encode and Decode Functions
 *
 */

#include <string>
#include <vector>
#include "Base64.hpp"
#include "Base64FamilyEncoder.hpp"
#include "Base64Encoding.hpp"
#include "Base64urlEncoding.hpp"

using namespace std;

namespace core {
    
    static Base64FamilyEncoder base64Encoder(&Base64Encoding::getInstance());
    static Base64FamilyEncoder base64urlEncoder(&Base64urlEncoding::getInstance());
    
    std::string base64_encode(unsigned char const * input, unsigned length, bool includeNewLines)
    {
        return base64Encoder.encode(input, length, includeNewLines);
    }
    
    std::string base64_encode_without_padding(unsigned char const * input, unsigned length, bool includeNewLines)
    {
        return base64Encoder.encodeWithoutPadding(input, length, includeNewLines);
    }
    
    int base64_decode(const std::string & encoded, std::vector<unsigned char> & decoded)
    {
        return base64Encoder.decode(encoded, decoded);
    }
    
    int base64_decode_without_padding(const std::string & encoded, std::vector<unsigned char> & decoded)
    {
        return base64Encoder.decodeWithoutPadding(encoded, decoded);
    }
    
    std::string base64url_encode(unsigned char const * input, unsigned length, bool includeNewLines)
    {
        
        return base64urlEncoder.encode(input, length, includeNewLines);
    }
    
    std::string base64url_encode_without_padding(unsigned char const * input, unsigned length, bool includeNewLines)
    {
        
        return base64urlEncoder.encodeWithoutPadding(input, length, includeNewLines);
    }
    
    int base64url_decode(const std::string & encoded, std::vector<unsigned char> & decoded)
    {
        return base64urlEncoder.decode(encoded, decoded);
    }
    
    int base64url_decode_without_padding(const std::string & encoded, std::vector<unsigned char> & decoded)
    {
        return base64urlEncoder.decodeWithoutPadding(encoded, decoded);
    }
} // namespace

