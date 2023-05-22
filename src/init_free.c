#include "utils.h"

pass_list init_pass_list() {
    pass_list list = malloc(sizeof(password));
    list->saved_pass = NULL;
    list->url = NULL;
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