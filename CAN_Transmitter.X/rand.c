#include "rand.h"

uint16_t seed = 0x3456;

void srand16(uint16_t seed_init) {
    seed = seed_init;
}

uint16_t rand16(uint16_t min, uint16_t max) {
    seed ^= seed << 7;
    seed ^= seed >> 9;
    seed ^= seed << 8;
    return min + (seed % (max - min));
}