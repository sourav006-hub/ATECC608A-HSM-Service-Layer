#ifndef HSM_SERVICE_H
#define HSM_SERVICE_H

#include <cstdint>
#include <cstddef>

class HSMService
{
public:
    bool init();

    bool generateKey(uint16_t slot, uint8_t* publicKey);

    bool ecdsaSign(uint16_t slot,
                   const uint8_t* digest,
                   uint8_t* signature);

    bool ecdsaVerify(const uint8_t* digest,
                     const uint8_t* signature,
                     const uint8_t* publicKey);

    bool ecdh(uint16_t slot,
              const uint8_t* publicKey,
              uint8_t* sharedSecret);

    bool sha256(const uint8_t* data,
                size_t dataLength,
                uint8_t* digest);

    bool random(uint8_t* randomData);
};

#endif