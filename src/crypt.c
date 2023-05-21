#include "utils.h"

static void encrypt_password(unsigned char* password, const char* key, unsigned char* encrypted_password) {
    int length = strlen(password);

    for (int i = 0; i < length; i++) {
        unsigned char curr = password[i];
        unsigned char curr_key = key[i];


        curr = (curr ^ curr_key) + (curr << 3);
        curr = (curr ^ (curr_key + 2)) ^ (curr >> 2);
        curr = (curr ^ (curr_key + 1)) + (curr << 1);

        curr = (curr % 95) + 32;

        encrypted_password[i] = curr;
    }
    encrypted_password[length] = '\0';
}

unsigned char* encrypt(unsigned char* password, unsigned char* key) {
    unsigned char* encrypted_password = malloc(strlen(password) + 1);
    encrypt_password(password, key, encrypted_password);
    return encrypted_password;
}

bool validate_pass(unsigned char* password) {

}