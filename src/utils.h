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
    char* uid;
    char* user_name;
    char* hashed_password;
    bool is_active;
    password* passwords;
} user;

// User Operations
void log_in(char* user_name, char* password);