
#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Encoding.hpp"


namespace core {
    
    class Base64urlEncoding : public Encoding
    {
    public:
        
        static void print_decode_table()
        {
            unsigned char DECODE_TABLE[256];
            for (int i=0; i<256; ++i) { DECODE_TABLE[i] = 0xff; }
            for (int i=0; i<64; ++i)  { DECODE_TABLE[(int)ENCODE_TABLE[i]] = i; }
            DECODE_TABLE[(unsigned char)'='] = 0;
            
            std::cout << "static const unsigned char DECODE_TABLE[] = {";
            for (int i=0; i<256; ++i)
            {
                if (!(i % 16)) { std::cout << std::endl << "  "; }
                std::cout << std::setw(3) << (unsigned)DECODE_TABLE[i] << ", ";
            }
            std::cout << std::endl << "};" <<std:: endl;
        }
        
        static Base64urlEncoding& getInstance()
        {
            static Base64urlEncoding instance;
            return instance;
        }
        
    private:
        
        Base64urlEncoding ()  {}
        Base64urlEncoding (Base64urlEncoding const &);
        void operator=(Base64urlEncoding const &);
        
        
        // This 64-character lookup table provides the output alphabet for the encoding.
        // It is the same table used in MIME and in Poco::Base64Encoder.
        static const char * ENCODE_TABLE;
        static const std::string ENCODED_PADDING_CHARS;
        static const std::string DECODED_PADDING_CHARS;
        // Inverse lookup table generated by print_decode_table() below.
        static const unsigned char DECODE_TABLE[];
        // Calculate inverse of ENCODE_TABLE and print it as C code to paste into this source file.
        
        const char* getEncodingTable()
        {
            return ENCODE_TABLE;
        }
        
        const unsigned char* getDecodingTable()
        {
            return DECODE_TABLE;
        }
        
        const std::string & getEncodedPaddingChars()
        {
            return ENCODED_PADDING_CHARS;
        }
        
        const std::string & getDecodedPaddingChars()
        {
            return DECODED_PADDING_CHARS;
        }
        
        bool isPaddingCharEncoded()
        {
            return true;
        }
    };
    
    
}
