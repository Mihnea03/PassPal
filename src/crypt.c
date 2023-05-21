#include "utils.h"

static char* encrypt_password(unsigned char* password) {
    int length = strlen(password);
    unsigned char* encrypted_pass = calloc(2 * length, 1);

    char first_part_mask = 15; // 0000 1111
    for (int i = 0; i < length; i++) {
        char first = password[i] & first_part_mask;
        char second = password[i] >> 4;

        first *= 
    }

    return encrypted_pass;
}

char* encrypt(char* password) {
    return encrypt_password(password);
}