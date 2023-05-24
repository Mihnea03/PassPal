#include "utils.h"

pass_list init_pass_list() {
    pass_list list = malloc(sizeof(password));
    list->saved_pass = malloc(MAX);
    list->url = malloc(MAX);
    list->next = NULL;

    return list;
}

pass_list add_pass(pass_list list, char* password, char* url) {
    pass_list node = init_pass_list();
    strcpy(node->saved_pass, password);
    strcpy(node->url, url);

    if (list == NULL)
        return node;

    pass_list aux = list;
    node->next = aux;
    list = node;
    return list;
}

void delete_pass(pass_list list, char* url) {
    
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
    
    unsigned char* url = malloc(128);
    unsigned char* pass = malloc(128);

    while (!feof(user_file)) {
        fscanf(user_file, "%s", url);
        fscanf(user_file, "%s", pass);

        printf("%s %s\n", url, pass);

        user->passwords = add_pass(user->passwords, pass, url);
    }

    printf("%s", user->passwords->saved_pass);
    fclose(user_file);
    return user;
}