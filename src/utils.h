#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>

#define MAX_USERNAME 16
#define MAX_PASSWORD 20

typedef struct pass {
    char* url;
    char* saved_pass;
    struct pass* next;
} password, *pass_list;

typedef struct usr {
    char* user_name;
    char* hashed_password;
    bool is_active;
    password* passwords;
} user;

// User Operations
pass_list log_in(char* user_name, char* password);
void sign_up(char* user_name, char* password);
void deactivate(char* user_name, char* password);
void reactivate(char* user_name, char* password);
void delete(char* user_name, char* password);