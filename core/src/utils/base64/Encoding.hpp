#pragma once

#include <string>
#include <vector>


namespace core {
    
    class Encoding
    {
    public:
        virtual ~Encoding ()  {}
        
        virtual const char* getEncodingTable() = 0;
        virtual const unsigned char* getDecodingTable() = 0;
        virtual const std::string & getEncodedPaddingChars() = 0;
        virtual const std::string & getDecodedPaddingChars() = 0;
        virtual bool isPaddingCharEncoded() = 0;
        
    protected:
        Encoding ()  {}
        
    };
    
}