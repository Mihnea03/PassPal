#include "utils.h"

static char* encrypt_password(unsigned char* password) {
    int length = strlen(password);
    unsigned char* encrypted_pass = calloc(64, 1);
    strcpy(encrypted_pass, password);
    encrypted_pass[length] = 1 << 7

}

char* encrypt(char* password) {
    return encrypt_password(password);
}