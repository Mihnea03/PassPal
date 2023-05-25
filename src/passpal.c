#include "utils.h"

#define clear() printf("\033[H\033[J")

// Main menu of the app
static void print_main_menu() {
    printf("1. Log In\n");
    printf("2. Sign Up\n");
    printf("3. Delete account\n\n");

    printf("Type 'q' to quit the program...\n\n");
}

// User menu of the app
static void print_user_menu(user* user) {
    printf("Welcome %s\n\n", user->user_name);

    printf("1. Add password\n");
    printf("2. Delete password\n");
    printf("3. See password by URL\n");
    printf("4. See passwords\n");
    printf("5. Export passwords\n");
    printf("6. Clear all passwords\n\n");

    printf("Type 'e' to log out...\n\n");
}   

// Validating user input to verify if they comply with the given standards 
static bool validate_login_info(unsigned char* user_name, unsigned char* password) {
    bool valid_usr;
    int tries = 1;
    printf("Enter username: ");
    do {
        scanf("%s", user_name);
        valid_usr = validate_username(user_name);
        if (valid_usr == false && tries == TRIES) {
            printf("\nToo many attempts, canceling operation...\n");
            sleep(1);
            clear();
            return false;
        }
        if (valid_usr == false && tries != TRIES) {
            printf("Re-enter username: ");
            tries++;
        }
    } while(valid_usr == false);

    if (valid_usr == false)
        return false;

    bool valid_pass;
    tries = 1;
    printf("Enter password: ");
    do {
        scanf("%s", password);
        valid_pass = validate_pass(password);
        if (valid_pass == false && tries == TRIES) {
            printf("\nToo many attempts, canceling operation...\n");
            sleep(1);
            clear();
            return false;
        }
        if (valid_pass == false && tries != TRIES) {
            printf("Re-enter password: ");
            tries++;
        }
    } while(valid_pass == false);

    return true;
}

// User menu functionality
static void manage_user(user* user) {
    char input = 0;

    while (input != 'e') {
        print_user_menu(user);
        scanf(" %c", &input);

        switch(input) {
            case '1': {
                unsigned char* url = malloc(MAX);
                printf("Enter URL: ");
                scanf("%s", url);

                unsigned char* pass = malloc(MAX);
                printf("Enter password: ");
                scanf("%s", pass);

                char* file_name = malloc(MAX);
                strcpy(file_name, ".users/");
                strcat(file_name, user->user_name);

                write_new_user_file(file_name, user, url, pass);
                free(url);
                free(pass);
                break;
            }
            case '2': {
                unsigned char* url = malloc(MAX);
                printf("Enter URL: ");
                scanf("%s", url);

                char* file_name = malloc(MAX);
                strcpy(file_name, ".users/");
                strcat(file_name, user->user_name);

                delete_url(file_name, user, url);
                free(url);
                free(file_name);
                break;
            }
            case '3': {
                unsigned char* url = malloc(MAX);
                printf("Enter URL: ");
                scanf("%s", url);

                print_pass_by_url(user, url);
                free(url);
                break;
            }
            case '4': {
                print_all_passwords(user);
                break;
            }
            case '5': {
                unsigned char* file_name = malloc(MAX);
                printf("File name: ");
                scanf("%s", file_name);

                export_passwords(file_name, user);
                free(file_name);
                break;
            }
            case '6': {
                char* file_name = malloc(MAX);
                strcpy(file_name, ".users/");
                strcat(file_name, user->user_name);

                clear_all_urls(file_name, user);
                free(file_name);
                break;
            }
        }
        clear();
    }
    printf("You have logged out succesfully!\n");
    user = NULL;
    sleep(1);
    clear();
}

int main() {
    // Main menu functionality
    
    unsigned char input = 0;
    clear();

    while (input != 'q') {
        print_main_menu();
        scanf(" %c", &input);

        unsigned char* user_name = malloc(MAX_USERNAME);
        unsigned char* password = malloc(MAX_PASSWORD);

        switch (input) {
            case '1': {
                if (validate_login_info(user_name, password) == false)
                    break;

                printf("\n");
                user* user = log_in(user_name, password);
                clear();
                if (user)
                    manage_user(user);
                break;
            }
            case '2': {
                if (validate_login_info(user_name, password) == false)
                    break;

                printf("\n");
                user* user = sign_up(user_name, password);
                clear();

                if (user)
                    manage_user(user);
                break;
            }
            case '3': {
                if (validate_login_info(user_name, password) == false)
                    break;

                printf("\n");
                delete(user_name, password);
                clear();
            }
        }
        clear();
    }
    return 0;
}