#pragma once
#include <string>
#include <vector>
#include "Encoding.hpp"

namespace core {
    
    class Base64FamilyEncoder
    {
    public:
        
        Base64FamilyEncoder (Encoding* encoding) : m_encoding(encoding) {}
        
        /**
         * Encodes an arbitrary sequence of bytes of specified length according
         * to the encoding available in the m_encoding member
         *
         * @param[in] input an array of input bytes
         * @param[in] length the length of the input byte array
         * @param[in] includeNewLines optional parameter to specify if new lines should be included in the encoded
         *            output. If set to true, newlines will be included after each row of 72 characters (LINE_LENGTH member),
         *            if set to false then no newlines will be included. Default value is true.
         *
         * @return an std::string representing the Base64 Encoded ASCII string
         *            in case of empty input an empty string is returned
         *
         */
        std::string encode(unsigned char const * input, unsigned length, bool includeNewLines = true);
        
        /**
         * Encodes an arbitrary sequence of bytes of specified length according
         * to the encoding available in the m_encoding member without adding padding chars even if needed
         *
         * @param[in] input an array of input bytes
         * @param[in] length the length of the input byte array
         * @param[in] includeNewLines optional parameter to specify if new lines should be included in the encoded
         *            output. If set to true, newlines will be included after each row of 72 characters (LINE_LENGTH member),
         *            if set to false then no newlines will be included. Default value is true.
         *
         * @return an std::string representing the Base64 Encoded ASCII string
         *            in case of empty input an empty string is returned
         *
         */
        std::string encodeWithoutPadding(unsigned char const * input, unsigned length, bool includeNewLines = true);
        
        /**
         * Decodes an encoded string to a sequence of bytes according
         * to the encoding available in the m_encoding member
         *
         * @param[in] encoded the encoded ASCII string
         * @param[out] decoded the decoded sequence of bytes contained in a std::vector,
         *                     the caller owns this output vector.
         *
         * @return zero if successful, non-zero otherwise.
         *         -1 if the encoded string parameter is empty
         *         -2 if the encoded string parameter is not well formed according to m_encoding
         *         -3 if an internal error occurs
         *
         */
        int decode(const std::string & encoded, std::vector<unsigned char> & decoded);
        
        /**
         * Decodes an encoded string to a sequence of bytes according
         * to the encoding available in the m_encoding member
         *
         * @param[in] encoded the encoded ASCII string. The string can lack any required padding char
         * @param[out] decoded the decoded sequence of bytes contained in a std::vector,
         *                     the caller owns this output vector.
         *
         * @return zero if successful, non-zero otherwise.
         *         -1 if the encoded string parameter is empty
         *         -2 if the encoded string parameter is not well formed according to m_encoding
         *         -3 if an internal error occurs
         *
         */
        int decodeWithoutPadding(const std::string & encoded, std::vector<unsigned char> & decoded);
        
        
        
    private:
        /* Encoding methods*/
        void encodeGroup(const unsigned char octets[], const unsigned int octetsSize, std::string & encoded);
        
        /* Decoding methods*/
        std::string addMissingPaddingChars(const std::string & encoded);
        int computePaddingCharsNeeded(const std::string & input, const int newLinesAvailable, const int paddingCharsAvailable);
        void eraseNewLines(std::string & input);
        int getPaddingChars(const std::string & input);
        bool weakCheckNewLines(const std::string & input);
        int getNewLines(const std::string & input);
        bool isInsideEncodedPaddingChar(const std::string & input, const unsigned int index);
        bool checkInputSize(const std::string & input, const int newLinesAvailable, const  int paddingCharsAvailable);
        int computeLastGroupSize(const std::string & input, const int newLinesAvailable, const  int paddingCharsAvailable, std::string::size_type paddingCharsSize);
        int removeUnnecessaryEncodedPaddingChars(std::string & input, const int newLinesAvailable, const  int paddingCharsAvailable);
        void decodeEndingPaddingChars(std::string & encoded, const  int paddingChars);
        int decodeGroup(const std::vector<unsigned char> & encodedChars, std::vector<unsigned char> & decodedChars);
        bool checkCharGroup(const std::vector<unsigned char> & charGroup);
        
        static const unsigned int MAX_PADDING_SEQUENCE_SIZE;
        static const std::string NEW_LINE_STRING;
        //changing this value to a value that is not a multiple of encodedGroupSize requires rewriting newlines appending code
        static const unsigned int LINE_LENGTH = 72;
        
        Encoding* m_encoding;
        
    };
    
}
