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
    bool is_valid = false;
    bool lower = false, higher = false, number = false, symbol = false;
    const char SYMBOLS[] = "~`!@#$%^&*()_-+=|\\}]{[\"':;?/>.<,";

    if (strlen(password) < MIN_PASSWORD) {
        printf("Password needs to be at least 8 characters long!\n");
        return false;
    }

    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z')
            lower = true;
        if (password[i] >= 'A' && password[i] <= 'Z')
            higher = true;
        if (password[i] >= '0' && password[i] <= '9')
            number = true;
        if (strchr(SYMBOLS, password[i]))
            symbol = true;
    }

    if (lower == true && higher == true && number == true && symbol == true)
        return true;

    if (lower == false)
        printf("Your password needs to contain at least one lowercase letter!\n");
    if (higher == false)
        printf("Your password needs to contain at least one uppercase letter!\n");
    if (number == false)
        printf("Your password needs to contain at least one digit!\n");
    if (symbol == false)
        printf("Your password needs to contain at least one symbol!\n");
}