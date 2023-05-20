#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>

#define MAX_USERNAME 16
#define MAX_PASSWORD 32

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
user* log_in(char* user_name, char* password);
user* sign_up(char* user_name, char* password);
void deactivate(char* user_name, char* password);
void reactivate(char* user_name, char* password);
void delete(char* user_name, char* password);

// Crypting
char* encrypt(char* password);