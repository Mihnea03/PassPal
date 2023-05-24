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

    printf("\nPassword succesfully added!\n");
    sleep(1);

    fclose(in);
}

void delete_url(unsigned char* file_name, user* user, unsigned char* url) {
    user->passwords = delete_pass(user->passwords, url);

    FILE* in = fopen(file_name, "wt");

    fprintf(in, "%s\n", user->key);

    pass_list aux = user->passwords;

    if (aux == NULL) {
        sleep(1);
        fclose(in);
        return;
    }

    while(aux) {
        fprintf(in, "%s %s\n", aux->url, aux->saved_pass);
        aux = aux->next;
    }
    sleep(1);

    fclose(in);
}

void print_pass_by_url(user* user, unsigned char* url) {
    pass_list aux = user->passwords;
    
    while(aux) {
        if (strcmp(aux->url, url) == 0) {
            printf("\nURL: %s\n", url);
            printf("Password: %s\n", aux->saved_pass);
            
            sleep(7);
            return;
        }
        aux = aux->next;
    }

    printf("Given URL doesn't exist!\n");
    sleep(1);
}

void print_all_passwords(user* user) {
    if (user->passwords == NULL) {
        printf("No passwords are saved on this account!\n");
        sleep(1);
        return;
    }

    pass_list aux = user->passwords;

    while(aux) {
        if (strcmp(aux->url, " ")) {
            printf("URL: %s\n", aux->url);
            printf("Password: %s\n\n", aux->saved_pass);
        }
        aux = aux->next;
    }

    sleep(10);
}

void export_passwords(unsigned char* file_name, user* user) {

    if (user->passwords == NULL) {
        printf("No passwords are saved on this account!\n");
        sleep(1);
        return;
    }

    FILE* export = fopen(file_name, "wt");
    pass_list aux = user->passwords;

    while(aux) {
        if (strcmp(aux->url, " ")) {
            fprintf(export, "URL: %s\n", aux->url);
            fprintf(export, "Password: %s\n\n", aux->saved_pass);
        }
        aux = aux->next;
        printf("\nFile exported succesfully!");
    }
    fclose(export);
    sleep(1);
}