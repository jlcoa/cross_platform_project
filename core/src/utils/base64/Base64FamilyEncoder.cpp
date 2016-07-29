#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include "Base64FamilyEncoder.hpp"

namespace core {
    
    const unsigned int Base64FamilyEncoder::MAX_PADDING_SEQUENCE_SIZE = 2;
    
    const std::string Base64FamilyEncoder::NEW_LINE_STRING = "\r\n";
    
    std::string Base64FamilyEncoder::encode(unsigned char const * input, unsigned length, bool includeNewLines)
    {
        return addMissingPaddingChars(encodeWithoutPadding(input, length, includeNewLines));
    }
    
    
    std::string Base64FamilyEncoder::encodeWithoutPadding(unsigned char const * input, unsigned length, bool includeNewLines)
    {
        if(input == 0 || length == 0)
        {
            return "";
        }
        
        // Work with input octets in groups of threes
        const unsigned int groupSize = 3;
        const unsigned int encodedGroupSize = 4;
        unsigned char octets[groupSize];
        
        std::string encoded;
        int ncodechars = 0;
        int groupIndex = 0;
        
        for (unsigned i = 0; i < length; ++i, ++groupIndex%=groupSize)
        {
            octets[groupIndex] = input[i];
            
            // Enough to encode a full group of octets
            if (groupIndex == (groupSize - 1))
            {
                encodeGroup(octets, groupSize, encoded);
                ncodechars += encodedGroupSize;
                if (includeNewLines && !(ncodechars % LINE_LENGTH))
                {
                    encoded.append(NEW_LINE_STRING.begin(), NEW_LINE_STRING.end());
                }
            }
        }
        // Handle leftovers ...
        if((groupIndex % groupSize) != 0)
        {
            encodeGroup(octets, groupIndex, encoded);
        }
        return encoded;
    }
    
    
    
    void Base64FamilyEncoder::encodeGroup(const unsigned char octets[], const unsigned int octetsSize, std::string & encoded)
    {
        if(octetsSize == 0) return;
        const std::string paddingChars = m_encoding->getEncodedPaddingChars();
        const char* encodingTable = m_encoding->getEncodingTable();
        
        // First output char is coded from the first 6 bits of 24
        unsigned code_index = octets[0] >> 2;
        encoded.append(1, encodingTable[code_index]);
        if(octetsSize == 1)
        {
            code_index = ((octets[0] & 0x03) << 4) | 0;
            encoded.append(1, encodingTable[code_index]);
            return;
        }
        // Second output char is coded from the next 6 bits of 24
        code_index = ((octets[0] & 0x03) << 4) | octets[1] >> 4;
        encoded.append(1, encodingTable[code_index]);
        if(octetsSize == 2)
        {
            code_index = ((octets[1] & 0x0f) << 2) | 0;
            encoded.append(1, encodingTable[code_index]);
            return;
        }
        // Third output char is coded from the next 6 bits of 24
        code_index = ((octets[1] & 0x0f) << 2) | octets[2] >> 6;
        encoded.append(1, encodingTable[code_index]);
        // Fourth output char is coded from the final 6 bits of 24
        code_index = octets[2] & 0x3f;
        encoded.append(1, encodingTable[code_index]);
    }
    
    int Base64FamilyEncoder::decodeWithoutPadding(const std::string & encoded, std::vector<unsigned char> & decoded)
    {
        return decode(addMissingPaddingChars(encoded), decoded);
    }
    
    
    std::string Base64FamilyEncoder::addMissingPaddingChars(const std::string & input)
    {
        int paddingCharsNeeded = computePaddingCharsNeeded(input, getNewLines(input), 0);
        if(paddingCharsNeeded == 0) return input;
        std::string localEncoded(input);
        const std::string paddingChar  = m_encoding->getEncodedPaddingChars();
        for(int i = 0 ; i < paddingCharsNeeded; i++)
            localEncoded.append(paddingChar.begin(),paddingChar.end());
        return localEncoded;
    }
    
    
    int Base64FamilyEncoder::decode(const std::string & input, std::vector<unsigned char> & decoded)
    {
        
        if(input.size() == 0)
        {
            return -1;
        }
        std::string localEncoded(input);
        int paddingCharsFound = getPaddingChars(input);
        if(paddingCharsFound < 0)
        {
            return -2;
        }
        if(!weakCheckNewLines(input))
        {
            return -2;
        }
        int newLinesFound = getNewLines(input);
        if(!checkInputSize(input, newLinesFound, paddingCharsFound))
        {
            return -2;
        }
        int remainingPaddingChars = removeUnnecessaryEncodedPaddingChars(localEncoded, newLinesFound, paddingCharsFound);
        if(remainingPaddingChars > 0)
        {
            decodeEndingPaddingChars(localEncoded, remainingPaddingChars);
        }
        else
        {
            if(remainingPaddingChars != 0)
            {
                if(remainingPaddingChars == -1)
                {
                    return -2;
                }
                else
                {
                    return -3;
                }
            }
        }
        eraseNewLines(localEncoded);
        int currentIndex = 0;
        int encodedSize = localEncoded.size();
        while(!(currentIndex >= encodedSize))
        {
            std::vector<unsigned char> charGroup;
            for (; charGroup.size() < 4 && currentIndex < encodedSize; )
            {
                charGroup.push_back(localEncoded[currentIndex++]);
            }
            if(charGroup.size() != 4)
            {
                decoded.clear();
                return -3;
            }
            std::vector<unsigned char> decodedCharGroup;
            if(decodeGroup(charGroup, decodedCharGroup) != 0)
            {
                decoded.clear();
                return -2;
            }
            decoded.insert(decoded.end(), decodedCharGroup.begin(), decodedCharGroup.end());
        }
        decoded.resize(decoded.size() - remainingPaddingChars);
        return 0;
    }
    
    void Base64FamilyEncoder::eraseNewLines(std::string & input)
    {
        std::string::size_type newLineSize = NEW_LINE_STRING.size();
        std::string::size_type index = input.find(NEW_LINE_STRING);
        while(index != std::string::npos)
        {
            input.erase(index, newLineSize);
            index = input.find(NEW_LINE_STRING);
        }
    }
    
    int Base64FamilyEncoder::getPaddingChars(const std::string & input)
    {
        const std::string paddingChar = m_encoding->getEncodedPaddingChars();
        size_t paddingCharSize = paddingChar.size();
        size_t inputSize = input.size();
        size_t index = input.find(paddingChar, 0);
        if(index == std::string::npos ) return 0;
        else
        {
            int paddingCharsFound = 1;
            index+=paddingCharSize;
            while(index < inputSize)
            {
                if(input.find(paddingChar, index) == index)
                {
                    index+=paddingCharSize;
                    paddingCharsFound++;
                }
                else
                {
                    if(NEW_LINE_STRING.find(input[index]) == index)
                    {
                        index+=NEW_LINE_STRING.size();
                    }
                    else
                    {
                        return -1;
                    }
                }
            }
            return paddingCharsFound;
        }
    }
    
    bool Base64FamilyEncoder::weakCheckNewLines(const std::string & input)
    {
        size_t inputSize = input.size();
        size_t newLineSize = NEW_LINE_STRING.size();
        size_t lineLength = input.find(NEW_LINE_STRING, 0);
        size_t fullLineLength = lineLength + newLineSize;
        for(size_t expectedNewLineIndex = lineLength ; expectedNewLineIndex < inputSize ; expectedNewLineIndex+=fullLineLength)
        {
            if(input.substr(expectedNewLineIndex, newLineSize).compare(NEW_LINE_STRING) != 0)
            {
                if(!isInsideEncodedPaddingChar(input, expectedNewLineIndex)) return false;
            }
        }
        return true;
    }
    
    
    int Base64FamilyEncoder::getNewLines(const std::string & input)
    {
        size_t inputSize = input.size();
        size_t newLineSize = NEW_LINE_STRING.size();
        size_t lineLength = input.find(NEW_LINE_STRING, 0);
        int newLines = 0;
        size_t newLineIndex = lineLength;
        size_t nextCharIndex = newLineIndex;
        while(newLineIndex != std::string::npos)
        {
            newLines++;
            nextCharIndex = newLineIndex + newLineSize;
            newLineIndex = input.find(NEW_LINE_STRING, nextCharIndex);
        }
        return newLines;
    }
    
    bool Base64FamilyEncoder::isInsideEncodedPaddingChar(const std::string & input, const unsigned int index)
    {
        std::string::size_type paddingCharsSize = m_encoding->getEncodedPaddingChars().size();
        std::string paddingChars = m_encoding->getEncodedPaddingChars();
        for(unsigned int i = 0 ; i < paddingCharsSize && (index - 1) > 0 ; i++)
        {
            if(input.substr(index - i, paddingCharsSize).compare(paddingChars) == 0)
                return true;
        }
        return false;
    }
    
    bool Base64FamilyEncoder::checkInputSize(const std::string & input, const int newLinesAvailable, const int paddingCharsAvailable)
    {
        int lastGroupNonPaddingCharNum = computeLastGroupSize(input, newLinesAvailable, paddingCharsAvailable, m_encoding->getEncodedPaddingChars().size());
        if(lastGroupNonPaddingCharNum != 0 && lastGroupNonPaddingCharNum < (4 - MAX_PADDING_SEQUENCE_SIZE))
        {
            return false;
        }
        return true;
    }
    
    int Base64FamilyEncoder::computeLastGroupSize(const std::string & input,  const int newLinesAvailable, const int paddingCharsAvailable, std::string::size_type paddingCharsSize)
    {
        return (input.size() - (paddingCharsAvailable * paddingCharsSize) - (newLinesAvailable * NEW_LINE_STRING.size())) % 4;
    }
    
    /*
     *
     * returns the number of remaining padding chars
     *         -1 if not enough padding chars are available
     *         -2 in case of internal errors
     *
     */
    int Base64FamilyEncoder::removeUnnecessaryEncodedPaddingChars(std::string & input, const int newLinesAvailable, const int paddingCharsAvailable)
    {
        int paddingCharsNeeded = computePaddingCharsNeeded(input, newLinesAvailable, paddingCharsAvailable);
        if(paddingCharsAvailable < paddingCharsNeeded)
        {
            return -1;
        }
        else
        {
            if(paddingCharsAvailable > paddingCharsNeeded)
            {
                const std::string paddingChars = m_encoding->getEncodedPaddingChars();
                const int paddingCharSize = m_encoding->getEncodedPaddingChars().size();
                int index;
                for(int i = 0 ; i < (paddingCharsAvailable - paddingCharsNeeded) ; i++)
                {
                    index = input.rfind(paddingChars);
                    if(index == std::string::npos)
                    {
                        return -2;
                    }
                    else
                    {
                        input.erase(index, paddingCharSize);
                    }
                }
            }
        }
        return paddingCharsNeeded;
    }
    
    
    int Base64FamilyEncoder::computePaddingCharsNeeded(const std::string & input, const int newLinesAvailable, const int paddingCharsAvailable)
    {
        return (4 - computeLastGroupSize(input, newLinesAvailable, paddingCharsAvailable, m_encoding->getEncodedPaddingChars().size())) % 4;
    }
    
    void Base64FamilyEncoder::decodeEndingPaddingChars(std::string & encoded, const int paddingCharsNum)
    {
        if(!m_encoding->isPaddingCharEncoded()) return;
        encoded.resize(encoded.size() - (paddingCharsNum *  m_encoding->getEncodedPaddingChars().size()));
        std::string::const_iterator decodedPadingBegin =  m_encoding->getDecodedPaddingChars().begin();
        std::string::const_iterator decodedPadingEnd = m_encoding->getDecodedPaddingChars().end();
        for(int i = 0 ; i < paddingCharsNum; i++)
            encoded.append(decodedPadingBegin,decodedPadingEnd);
    }
    
    /*
     *
     * return 0 if decoding performed correctly
     *        -1 if encodedChars is malformed
     *
     *
     */
    int Base64FamilyEncoder::decodeGroup(const std::vector<unsigned char> & encodedChars, std::vector<unsigned char> & decodedChars)
    {
        if(encodedChars.size() != 4)
        {
            return -1;
        }
        if(!checkCharGroup(encodedChars))
        {
            return -1;
        }
        const unsigned char* decodingTable = m_encoding->getDecodingTable();
        // Reform the three octets represented by the four encoded chars
        decodedChars.push_back(((decodingTable[encodedChars[0]] << 2)) | (decodingTable[encodedChars[1]] >> 4));
        decodedChars.push_back(((decodingTable[encodedChars[1]] & 0x0f) << 4) | (decodingTable[encodedChars[2]] >> 2));
        decodedChars.push_back(((decodingTable[encodedChars[2]] & 0x03) << 6) |  decodingTable[encodedChars[3]]);
        return 0;
    }
    
    bool Base64FamilyEncoder::checkCharGroup(const std::vector<unsigned char> & charGroup)
    {
        // Ensure the input characters are from the expected code set
        const unsigned char* decodingTable = m_encoding->getDecodingTable();
        const std::vector<unsigned char>::const_iterator end = charGroup.end();
        for(std::vector<unsigned char>::const_iterator ite = charGroup.begin(); ite != end ; ite++)
        {
            if (decodingTable[*ite] == 0xff) return false;
        }
        return true;
    }
    
}
