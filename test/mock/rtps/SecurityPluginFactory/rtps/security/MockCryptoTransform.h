// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file MockCryptoTransform.h	
 */
#ifndef _RTPS_SECURITY_MOCKCRYPTOTRANSFORM_H_
#define _RTPS_SECURITY_MOCKCRYPTOTRANSFORM_H_

#include <fastrtps/rtps/security/cryptography/CryptoTransform.h>
#include <fastrtps/rtps/security/cryptography/CryptoTypes.h>
#include <gmock/gmock.h>

namespace eprosima {
namespace fastrtps {
namespace rtps {
namespace security {

class MockCryptoTransform : public CryptoTransform
{
    public:

        virtual ~MockCryptoTransform(){}

        MOCK_METHOD5(encode_serialized_payload, bool (
                std::vector<uint8_t>&,
                std::vector<uint8_t>&,
                const std::vector<uint8_t>&,
                DatawriterCryptoHandle&,
                SecurityException&));
        MOCK_METHOD5(encode_datawriter_submessage, bool (
                std::vector<uint8_t>&,
                const std::vector<uint8_t>&,
                DatawriterCryptoHandle&,
                std::vector<DatareaderCryptoHandle*>&,
                SecurityException&));

        MOCK_METHOD5(encode_datareader_submessage, bool (
                std::vector<uint8_t>&,
                const std::vector<uint8_t>&,
                DatareaderCryptoHandle&,
                std::vector<DatawriterCryptoHandle*>&,
                SecurityException &exception));

        MOCK_METHOD5(encode_rtps_message, bool (
                std::vector<uint8_t>&,
                const std::vector<uint8_t>&,
                ParticipantCryptoHandle&,
                const std::vector<ParticipantCryptoHandle*>&,
                SecurityException&));

        MOCK_METHOD5(decode_rtps_message, bool (
                std::vector<uint8_t>&,
                const std::vector<uint8_t>&,
                const ParticipantCryptoHandle&,
                const ParticipantCryptoHandle&,
                SecurityException&));

        MOCK_METHOD7(preprocess_secure_submsg, bool (
                DatawriterCryptoHandle**,
                DatareaderCryptoHandle**,
                SecureSubmessageCategory_t&,
                const std::vector<uint8_t>,
                ParticipantCryptoHandle&,
                ParticipantCryptoHandle&,
                SecurityException&));

        MOCK_METHOD5(decode_datawriter_submessage, bool (
                std::vector<uint8_t>&,
                const std::vector<uint8_t>&,
                DatareaderCryptoHandle&,
                DatawriterCryptoHandle&,
                SecurityException&));

        MOCK_METHOD5(decode_datareader_submessage, bool (
                std::vector<uint8_t>&,
                const std::vector<uint8_t>&,
                DatawriterCryptoHandle&,
                DatareaderCryptoHandle&,
                SecurityException&));

        MOCK_METHOD6(decode_serialized_payload, bool (
                std::vector<uint8_t>&,
                const std::vector<uint8_t>&,
                const std::vector<uint8_t>&,
                DatareaderCryptoHandle &,
                DatawriterCryptoHandle&,
                SecurityException&));

};

} //namespace security
} //namespace rtps
} //namespace fastrtps
} //namespace eprosima

#endif //_RTPS_SECURITY_MOCKCRYPTOTRANSFORM_H_
