#include "utils.h"

pass_list init_pass_list() {
    pass_list list = malloc(sizeof(password));
    list->saved_pass = malloc(MAX_PASSWORD);
    list->url = malloc(MAX_PASSWORD);
    list->next = NULL;
}

void add_pass(pass_list list, char* password, char* url) {
    pass_list node = init_pass_list();
    strcpy(node->saved_pass, password);
    strcpy(node->url, url);
    pass_list aux = list;
    node->next = aux;
    list = node;
}

user* init_user(unsigned char* username, unsigned char* key) {
    user* user = malloc(sizeof(user));
    user->key = malloc(MAX_PASSWORD);
    strcpy(user->key, key);
    user->is_active = true;
    user->passwords = init_pass_list();
    user->user_name = malloc(MAX_PASSWORD);
    strcpy(user->user_name, username);

    unsigned char* file_name = malloc(128);
    strcpy(file_name, ".users/");
    strcat(file_name, username);

    FILE* user_file = fopen(file_name, "rt");

    unsigned char* aux = malloc(MAX_PASSWORD);
    fscanf(user_file, "%s", aux);
    free(aux);
    
    unsigned char* url = calloc(128, 1);
    unsigned char* pass = calloc(128, 1);

    while (!feof(user_file)) {
        fscanf(user_file, "%s", url);
        fscanf(user_file, "%s", pass);

        add_pass(user->passwords, pass, url);
    }

    fclose(user_file);
    return user;
}