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
        printf("Your password needs to be at least %d characters long!\n", MIN_PASSWORD);
        return false;
    } else if (strlen(password) > MAX_PASSWORD) {
        printf("Your Password needs to have a length of maximum %d characters!\n", MAX_PASSWORD);
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
        if (password[i] == ' ') {
            printf("Your password cannot contain spaces!\n");
            return false;
        }
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
    
    return false;
}

unsigned char* create_unique_key(int length) {
    char left = 48, right = 122;
    char interval_len = right - left;
    unsigned char* key = malloc(length);

    for (int i = 0; i < length; i++) {
        unsigned char rand_char = rand() % interval_len + left;
        key[i] = rand_char;
    }
    key[length] = '\0';
    return key;
}

bool validate_username(unsigned char* username) {
    if (strlen(username) < MIN_USERNAME) {
        printf("Your username should be bigger than %d characters!\n", MIN_USERNAME);
        return false;
    } else if (strlen(username) > MAX_USERNAME) {
        printf("Your username should be shorter than %d characters!\n", MAX_USERNAME);
        return false;
    }
    for (int i = 0; i < strlen(username); i++) {
        if ((username[i] < '0' || username[i] > '9') && (username[i] < 'a' || username[i] > 'z') && (username[i] < 'A' || username[i] > 'Z')) {
            printf("Your username should only contain digits, lowercase and uppercase letters!\n");
            return false;
        }
    }
    return true;
}