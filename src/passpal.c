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

int main() {
    char input = 0;
    clear();

    while (input != 'q') {
        print_main_menu();
        scanf("%c", &input);
        printf("%c", input);

        switch (input) {
            case '1': {
                char* user_name = malloc(MAX_USERNAME);
                char* password = malloc(MAX_PASSWORD);
                log_in(user_name, password);
                break;
            }
            case '2': {
                sign_up();
                break;
            }
            case '3': {
                deactivate();
                break;
            }
            case '4': {
                reactivate();
                break;
            }
            case '5': {
                delete();
                break;
            }
        }
        // clear();
    }
    return 0;
}