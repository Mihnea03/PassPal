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

    while (input != 'q') {
        clear();
        print_main_menu();
        scanf("%c", &input);
    }
    return 0;
}