#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define USER_META ".users/.user_meta"

#define MAX_USERNAME 16
#define MIN_USERNAME 4
#define MAX_PASSWORD 20
#define MIN_PASSWORD 6
#define MAX 128
#define TRIES 5

typedef struct pass {
    unsigned char* url;
    unsigned char* saved_pass;
    struct pass* next;
} password, *pass_list;

typedef struct usr {
    unsigned char* user_name;
    unsigned char* key;
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
bool validate_username(unsigned char* username);

// Initializations and frees
pass_list init_pass_list();
pass_list add_pass(pass_list list, char* password, char* url);
void delete_pass(pass_list list, char* url);
user* init_user(unsigned char* username, unsigned char* key);

// Password Manager
void write_new_user_file(unsigned char* file_name, user* user, unsigned char* url, unsigned char* pass);
