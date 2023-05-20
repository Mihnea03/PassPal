#include "utils.h"

static char* encrypt_password(unsigned char* password) {
    int length = strlen(password);
    unsigned char* encrypted_pass = calloc(64, 1);
    for (int i = 0; i < length; i++)
        encrypted_pass[i] = password[i];
    encrypted_pass[length] = 1 << 7;

    unsigned int bitmask = 1 << 31;
    for (int i = 0; i < 32; i++) {
        int curr_bit = length & bitmask;
        if (curr_bit) {
            encrypted_pass[60 + i / 8] |= bitmask;
        }
        bitmask >>= 1;
    }

    // Buffers
    int A = 0x01234567;
    int B = 0x89abcdef;
    int C = 0xfedcba98;
    int D = 0x76543210;

    

    return encrypted_pass;
}

char* encrypt(char* password) {
    return encrypt_password(password);
}