#include "HSMService.h"
#include "cryptoauthlib.h"

bool HSMService::init()
{
    ATCA_STATUS status =
        atcab_init(&cfg_ateccx08a_i2c_default);

    return status == ATCA_SUCCESS;
}

bool HSMService::generateKey(uint16_t slot,
                             uint8_t* publicKey)
{
    ATCA_STATUS status =
        atcab_genkey(slot, publicKey);

    return status == ATCA_SUCCESS;
}

bool HSMService::ecdsaSign(uint16_t slot,
                           const uint8_t* digest,
                           uint8_t* signature)
{
    ATCA_STATUS status =
        atcab_sign(slot, digest, signature);

    return status == ATCA_SUCCESS;
}

bool HSMService::ecdsaVerify(const uint8_t* digest,
                             const uint8_t* signature,
                             const uint8_t* publicKey)
{
    ATCA_STATUS status;
    bool verified = false;

    status = atcab_verify_extern(
        digest,
        signature,
        publicKey,
        &verified
    );

    return (status == ATCA_SUCCESS && verified);
}

bool HSMService::random(uint8_t* randomData)
{
    ATCA_STATUS status =
        atcab_random(randomData);

    return status == ATCA_SUCCESS;
}

bool HSMService::ecdh(uint16_t slot,
                      const uint8_t* publicKey,
                      uint8_t* sharedSecret)
{
    // Implement after ATECC608A configuration
    return false;
}

bool HSMService::sha256(const uint8_t* data,
                        size_t dataLength,
                        uint8_t* digest)
{
    // Implement next
    return false;
}