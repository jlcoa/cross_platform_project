/*
 *
 * Base64.hpp
 *
 *
 * CSF2G Base64 Encode and Decode Functions
 *
 */

#pragma once

#include <string>
#include <vector>

namespace core {
    
    /**
     * Encodes an arbitrary sequence of bytes of specified length according
     * to the Base64 ASCII encoding
     *
     * @param[in] input an array of input bytes
     * @param[in] length the length of the input byte array
     * @param[in] includeNewLines optional parameter to specify if new lines should be included in the encoded
     *            output. If set to true, newlines will be included after each row of 72 characters,
     *            if set to false then no newlines will be included. Default value is true.
     *
     * @return an std::string representing the Base64 Encoded ASCII string
     *
     */
    std::string base64_encode(unsigned char const * input, unsigned length, bool includeNewLines = true);
    
    /**
     * Encodes an arbitrary sequence of bytes of specified length according
     * to the Base64 ASCII encoding
     *
     * @param[in] input an array of input bytes
     * @param[in] length the length of the input byte array
     * @param[in] includeNewLines optional parameter to specify if new lines should be included in the encoded
     *            output. If set to true, newlines will be included after each row of 72 characters,
     *            if set to false then no newlines will be included. Default value is true.
     *
     * @return an std::string representing the Base64 Encoded ASCII string without padding chars
     *
     */
    std::string base64_encode_without_padding(unsigned char const * input, unsigned length, bool includeNewLines = true);
    
    /**
     * Decodes a Base64 encoded string to a sequence of bytes according
     * to the Base64 ASCII encoding
     *
     * @param[in] encoded the Base64 encoded ASCII string
     * @param[out] decoded the decoded sequence of bytes contained in a std::vector,
     *                     the caller owns this output vector.
     *
     * @return zero if successful, non-zero otherwise.
     *         -1 if the encoded string parameter is empty
     *         -2 if the encoded string parameter is not well formed according to base64 encoding
     *         -3 if an internal error occurs
     */
    int base64_decode(const std::string & encoded, std::vector<unsigned char> & decoded);
    
    /**
     * Decodes a Base64 encoded string to a sequence of bytes according
     * to the Base64 ASCII encoding
     *
     * @param[in] encoded the Base64 encoded ASCII string without padding chars
     * @param[out] decoded the decoded sequence of bytes contained in a std::vector,
     *                     the caller owns this output vector.
     *
     * @return zero if successful, non-zero otherwise.
     *         -1 if the encoded string parameter is empty
     *         -2 if the encoded string parameter is not well formed according to base64 encoding
     *         -3 if an internal error occurs
     */
    int base64_decode_without_padding(const std::string & encoded, std::vector<unsigned char> & decoded);
    
    /**
     * Encodes an arbitrary sequence of bytes of specified length according
     * to the Base64url ASCII encoding
     *
     * @param[in] input an array of input bytes
     * @param[in] length the length of the input byte array
     * @param[in] optional parameter to specify if new lines should be included in the encoded
     *            output. If set to true, newlines will be included after each row of 72 characters,
     *            if set to false then no newlines will be included. Default value is true.
     *
     * @return an std::string representing the Base64url Encoded ASCII string
     *
     */
    std::string base64url_encode(unsigned char const * input, unsigned length, bool includeNewLines = true);
    
    /**
     * Encodes an arbitrary sequence of bytes of specified length according
     * to the Base64url ASCII encoding
     *
     * @param[in] input an array of input bytes
     * @param[in] length the length of the input byte array
     * @param[in] includeNewLines optional parameter to specify if new lines should be included in the encoded
     *            output. If set to true, newlines will be included after each row of 72 characters,
     *            if set to false then no newlines will be included. Default value is true.
     *
     * @return an std::string representing the Base64url Encoded ASCII string without padding chars
     *
     */
    std::string base64url_encode_without_padding(unsigned char const * input, unsigned length, bool includeNewLines = true);
    
    /**
     * Decodes a Base64url encoded string to a sequence of bytes according
     * to the Base64url ASCII encoding
     *
     * @param[in] encoded the Base64url encoded ASCII string
     * @param[out] decoded the decoded sequence of bytes contained in a std::vector,
     *                     the caller owns this output vector.
     *
     * @return zero if successful, non-zero otherwise.
     *         -1 if the encoded string parameter is empty
     *         -2 if the encoded string parameter is not well formed according to base64url encoding
     *         -3 if an internal error occurs
     */
    int base64url_decode(const std::string & encoded, std::vector<unsigned char> & decoded);
    
    /**
     * Decodes a Base64url encoded string to a sequence of bytes according
     * to the Base64url ASCII encoding
     *
     * @param[in] encoded the Base64url encoded ASCII string without padding chars
     * @param[out] decoded the decoded sequence of bytes contained in a std::vector,
     *                     the caller owns this output vector.
     *
     * @return zero if successful, non-zero otherwise.
     *         -1 if the encoded string parameter is empty
     *         -2 if the encoded string parameter is not well formed according to base64 encoding
     *         -3 if an internal error occurs
     */
    int base64url_decode_without_padding(const std::string & encoded, std::vector<unsigned char> & decoded);
    
    
} // namespace csf


