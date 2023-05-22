#include "utils.h"

#define clear() printf("\033[H\033[J")

void print_main_menu() {
    printf("1. Log In\n");
    printf("2. Sign Up\n");
    printf("3. Deactivate Account\n");
    printf("4. Reactivate Account\n");
    printf("5. Delete Account\n");

    printf("\n");

    printf("Type 'q' to quit the program...\n\n");
}

void await_exit(char* input) {
    printf("Type anything to continue... ");
    scanf("%c", input);
    clear();
}

int main() {
    unsigned char input = 0;
    clear();

    while (input != 'q') {
        print_main_menu();
        scanf("%c", &input);


        unsigned char* user_name = malloc(MAX_USERNAME);
        unsigned char* password = malloc(MAX_PASSWORD);

        switch (input) {
            case '1': {
                bool valid_usr;
                int tries = 0;
                printf("Enter username: ");
                do {
                    scanf("%s", user_name);
                    valid_usr = validate_username(user_name);
                    if (valid_usr == false && tries == TRIES) {
                        printf("Too many attempts, canceling operation...\n\n");
                        await_exit(&input);
                        break;
                    }
                    if (valid_usr == false && tries != TRIES) {
                        printf("Re-enter username: ");
                        tries++;
                    }
                } while(valid_usr == false);
                user* user = log_in(user_name, password);
                break;
            }
            case '2': {
                user* user = sign_up(user_name, password);
                break;
            }
            case '3': {
                deactivate(user_name, password);
                break;
            }
            case '4': {
                reactivate(user_name, password);
                break;
            }
            case '5': {
                delete(user_name, password);
                break;
            }
        }
    }
    return 0;
}