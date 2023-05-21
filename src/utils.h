#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>

#define MAX_USERNAME 20
#define MAX_PASSWORD 32
#define MIN_PASSWORD 8

typedef struct pass {
    unsigned char* url;
    unsigned char* saved_pass;
    struct pass* next;
} password, *pass_list;

typedef struct usr {
    unsigned char* user_name;
    unsigned char* hashed_password;
    bool is_active;
    password* passwords;
} user;

// User Operations
user* log_in(unsigned char* user_name, unsigned char* password);
user* sign_up(unsigned char* user_name, unsigned char* password);
void deactivate(unsigned char* user_name, unsigned char* password);
void reactivate(unsigned char* user_name, unsigned char* password);
void delete(unsigned char* user_name, unsigned char* password);

// Crypting
unsigned char* encrypt(unsigned char* password, unsigned char* key);
bool validate_pass(unsigned char* password);
unsigned char* create_unique_key(int length);