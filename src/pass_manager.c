#include "utils.h"

void write_new_user_file(unsigned char* file_name, user* user, unsigned char* url, unsigned char* pass) {
    FILE* in = fopen(file_name, "wt");

    fprintf(in, "%s\n", user->key);
    user->passwords = add_pass(user->passwords, pass, url);

    pass_list aux = user->passwords;

    while(aux) {
        fprintf(in, "%s %s\n", aux->url, aux->saved_pass);
        aux = aux->next;
    }

    fclose(in);
}