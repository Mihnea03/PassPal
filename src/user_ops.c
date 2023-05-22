#include "utils.h"

user* log_in(unsigned char* user_name, unsigned char* password) {
    FILE* meta = fopen(USER_META, "rt");
    
    char* name = malloc(MAX_USERNAME);
    char* encrypted_pass = malloc(MAX_PASSWORD);

    bool ok = false;

    while (!feof(meta)) {
        fscanf(meta, "%s", name);
        fscanf(meta, "%s", encrypted_pass);

        if (strcmp(name, user_name) == 0) {
            ok = true;
            break;
        }
    }

    if (ok == false) {
        printf("User with the name %s cannot be found!\n", user_name);
        return NULL;
    }

    FILE* user_file = fopen(name, "rt");

    char* key = malloc(MAX_PASSWORD);
    fscanf(user_file, "%s", key);

    char* encrypt_curr = encrypt(password, key);

    if (strcmp(encrypt_curr, encrypted_pass)) {
        printf("The password is not correct!\n");
        return NULL;
    }

    
}

user* sign_up(unsigned char* user_name, unsigned char* password) {

}

void deactivate(unsigned char* user_name, unsigned char* password) {

}

void reactivate(unsigned char* user_name, unsigned char* password) {

}

void delete(unsigned char* user_name, unsigned char* password) {

}