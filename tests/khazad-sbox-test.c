
#include "khazad-sbox.h"
#include "khazad-print-block.h"

#include <string.h>


static const uint8_t sbox_ref[256u] =
{
    0xBA, 0x54, 0x2F, 0x74, 0x53, 0xD3, 0xD2, 0x4D, 0x50, 0xAC, 0x8D, 0xBF, 0x70, 0x52, 0x9A, 0x4C,
    0xEA, 0xD5, 0x97, 0xD1, 0x33, 0x51, 0x5B, 0xA6, 0xDE, 0x48, 0xA8, 0x99, 0xDB, 0x32, 0xB7, 0xFC,
    0xE3, 0x9E, 0x91, 0x9B, 0xE2, 0xBB, 0x41, 0x6E, 0xA5, 0xCB, 0x6B, 0x95, 0xA1, 0xF3, 0xB1, 0x02,
    0xCC, 0xC4, 0x1D, 0x14, 0xC3, 0x63, 0xDA, 0x5D, 0x5F, 0xDC, 0x7D, 0xCD, 0x7F, 0x5A, 0x6C, 0x5C,
    0xF7, 0x26, 0xFF, 0xED, 0xE8, 0x9D, 0x6F, 0x8E, 0x19, 0xA0, 0xF0, 0x89, 0x0F, 0x07, 0xAF, 0xFB,
    0x08, 0x15, 0x0D, 0x04, 0x01, 0x64, 0xDF, 0x76, 0x79, 0xDD, 0x3D, 0x16, 0x3F, 0x37, 0x6D, 0x38,
    0xB9, 0x73, 0xE9, 0x35, 0x55, 0x71, 0x7B, 0x8C, 0x72, 0x88, 0xF6, 0x2A, 0x3E, 0x5E, 0x27, 0x46,
    0x0C, 0x65, 0x68, 0x61, 0x03, 0xC1, 0x57, 0xD6, 0xD9, 0x58, 0xD8, 0x66, 0xD7, 0x3A, 0xC8, 0x3C,
    0xFA, 0x96, 0xA7, 0x98, 0xEC, 0xB8, 0xC7, 0xAE, 0x69, 0x4B, 0xAB, 0xA9, 0x67, 0x0A, 0x47, 0xF2,
    0xB5, 0x22, 0xE5, 0xEE, 0xBE, 0x2B, 0x81, 0x12, 0x83, 0x1B, 0x0E, 0x23, 0xF5, 0x45, 0x21, 0xCE,
    0x49, 0x2C, 0xF9, 0xE6, 0xB6, 0x28, 0x17, 0x82, 0x1A, 0x8B, 0xFE, 0x8A, 0x09, 0xC9, 0x87, 0x4E,
    0xE1, 0x2E, 0xE4, 0xE0, 0xEB, 0x90, 0xA4, 0x1E, 0x85, 0x60, 0x00, 0x25, 0xF4, 0xF1, 0x94, 0x0B,
    0xE7, 0x75, 0xEF, 0x34, 0x31, 0xD4, 0xD0, 0x86, 0x7E, 0xAD, 0xFD, 0x29, 0x30, 0x3B, 0x9F, 0xF8,
    0xC6, 0x13, 0x06, 0x05, 0xC5, 0x11, 0x77, 0x7C, 0x7A, 0x78, 0x36, 0x1C, 0x39, 0x59, 0x18, 0x56,
    0xB3, 0xB0, 0x24, 0x20, 0xB2, 0x92, 0xA3, 0xC0, 0x44, 0x62, 0x10, 0xB4, 0x84, 0x43, 0x93, 0xC2,
    0x4A, 0xBD, 0x8F, 0x2D, 0xBC, 0x9C, 0x6A, 0x40, 0xCF, 0xA2, 0x80, 0x4F, 0x1F, 0xCA, 0xAA, 0x42
};


int main(int argc, char **argv)
{
    size_t  i;
    uint8_t sbox_out[256u];

    (void)argc;
    (void)argv;

    for (i = 0; i < 256u; i++)
    {
        sbox_out[i] = i;
    }
    for (i = 0; i < 256u; i += KHAZAD_BLOCK_SIZE)
    {
        khazad_sbox_apply_block(&sbox_out[i]);
    }

    printf("s-box array:\n");
    for (i = 0; i < 256u; i += 16u)
    {
        print_block_hex(&sbox_out[i], 16u);
    }

    return memcmp(sbox_out, sbox_ref, 256u) ? 1 : 0;
}

