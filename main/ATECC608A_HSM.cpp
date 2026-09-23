#include <cstdio>
#include <cstdint>

#include "HSMService.h"

HSMService hsm;

extern "C" void app_main()
{
    printf("\n=============================\n");
    printf("   ATECC608A HSM PROJECT\n");
    printf("=============================\n");

    // 1. Initialize CryptoAuthLib
    if (!hsm.init())
    {
        printf("ERROR: ATECC608A initialization failed.\n");
        return;
    }

    printf("OK: ATECC608A initialized.\n");

    // 2. Generate 32 random bytes
    uint8_t randomData[32];

    if (!hsm.random(randomData))
    {
        printf("ERROR: RNG failed.\n");
        return;
    }

    printf("OK: RNG working.\n");
    printf("Random data: ");

    for (int i = 0; i < 32; i++)
    {
        printf("%02X", randomData[i]);
    }

    printf("\n");
}