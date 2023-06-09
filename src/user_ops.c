#include "utils.h"

// Log in user
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

    fclose(meta);

    if (ok == false) {
        printf("User with the name %s cannot be found!\n", user_name);
        sleep(1);
        return NULL;
    }

    char* user_file = malloc(128);
    strcpy(user_file, ".users/");
    strcat(user_file, name);

    FILE* usr_file = fopen(user_file, "rt");

    char* key = malloc(MAX_PASSWORD);
    fscanf(usr_file, "%s", key);

    if (strlen(password) != strlen(key)) {
        printf("The password is not correct!\n");
        sleep(1);
        return NULL;
    }

    char* encrypt_curr = encrypt(password, key);

    if (strcmp(encrypt_curr, encrypted_pass)) {
        printf("The password is not correct!\n");
        sleep(1);
        return NULL;
    }

    fclose(usr_file);

    user* user = init_user(user_name, key);
    user->passwords = user->passwords->next;

    printf("You have logged in as %s\n", user_name);
    sleep(1);

    return user;
}

// Create account for user
user* sign_up(unsigned char* user_name, unsigned char* password) {
    FILE* meta = fopen(USER_META, "rt");

    unsigned char* name = malloc(MAX_USERNAME);
    unsigned char* pass = malloc(MAX_PASSWORD);

    while(!feof(meta)) {
        fscanf(meta, "%s", name);
        fscanf(meta, "%s", pass);

        if (strcmp(name, user_name) == 0) {
            printf("Username already exists!\n");
            sleep(1);
            return NULL;
        }
    }
    fclose(meta);

    meta = fopen(USER_META, "at");

    unsigned char* key = create_unique_key(strlen(password));
    unsigned char* encrypted_pass = encrypt(password, key);

    fprintf(meta, "%s %s\n", user_name, encrypted_pass);
    fclose(meta);

    unsigned char* user_file_name = malloc(128);
    strcpy(user_file_name, ".users/");
    strcat(user_file_name, user_name);

    FILE* user_file = fopen(user_file_name, "wt");
    fprintf(user_file, "%s\n", key);
    fclose(user_file);

    user* user = init_user(user_name, key);
    user->passwords = NULL;
    printf("You have logged in as %s\n", user_name);
    sleep(1);
    return user;
}

// Delete account of the user
void delete(unsigned char* user_name, unsigned char* password) {
    FILE* meta = fopen(USER_META, "rt");
    
    pass_list users = NULL;

    char* name = malloc(MAX_USERNAME);
    char* encrypted_pass = malloc(MAX_PASSWORD);

    bool ok = false;

    while (!feof(meta)) {
        fscanf(meta, "%s", name);
        fscanf(meta, "%s", encrypted_pass);

        if (strcmp(name, user_name) == 0) {
            ok = true;
        } else {
            add_pass(users, name, encrypted_pass);
        }
    }

    fclose(meta);

    if (ok == false) {
        printf("User with the name %s cannot be found!\n", user_name);
        sleep(1);
        return;
    }

    char* user_file = malloc(128);
    strcpy(user_file, ".users/");
    strcat(user_file, name);

    FILE* usr_file = fopen(user_file, "rt");

    char* key = malloc(MAX_PASSWORD);
    fscanf(usr_file, "%s", key);

    if (strlen(password) != strlen(key)) {
        printf("The password is not correct!\n");
        sleep(1);
        return;
    }

    char* encrypt_curr = encrypt(password, key);

    if (strcmp(encrypt_curr, encrypted_pass)) {
        printf("The password is not correct!\n");
        sleep(1);
        return;
    }

    fclose(usr_file);

    FILE* meta_new = fopen(USER_META, "wt");

    while (users) {
        fprintf(meta_new, "%s %s\n", users->saved_pass, users->url);
        users = users->next;    
    }

    remove(user_file);
    fclose(meta_new);
    printf("\nUser succesfully deleted!\n");
    sleep(1);
}