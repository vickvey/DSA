#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "singly_linked_list.c"

void clear_screen() {
#ifdef _WIN32
    const char* clear = "cls";
#else
    const char* clear = "clear";
#endif
    system(clear);
}

// ANSI escape code for blue color
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

int int_input(char* prompt, int lower, int upper) {
    char *warning = "Wrong Input!\n";
    char buffer[20];  // Adjust the size based on your requirements
    long input;
    char *end_ptr;

    if (prompt == NULL) return -1;
    while (1) {
        printf("%s\n", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            // Handle input error or EOF
            return -1;
        }
        // Convert string to long, set end_ptr to the first character that wasn't used
        input = strtol(buffer, &end_ptr, 10);
        // Check if conversion was successful and if the entire string was consumed
        if (end_ptr != buffer && (*end_ptr == '\n' || *end_ptr == '\0')) {
            if (input >= lower && input <= upper) {
                break;  // Valid input, exit the loop
            }
        }
        // Handle invalid input
        printf("\033[38;5;198m%s\033[0mPlease enter a valid integer between %d and %d.\n", warning, lower, upper);
    }
    return (int)input;
}

void menu() {
    printf("\n");
    printf("Press " ANSI_COLOR_BLUE "1" ANSI_COLOR_RESET ": to view the list.\n");
    printf("Press " ANSI_COLOR_BLUE "2" ANSI_COLOR_RESET ": to add a number in list.\n");
    printf("Press " ANSI_COLOR_BLUE "3" ANSI_COLOR_RESET ": to delete a number in list.\n");
    printf("Press " ANSI_COLOR_BLUE "4" ANSI_COLOR_RESET ": to get count of nodes.\n");
    printf("Press " ANSI_COLOR_BLUE "5" ANSI_COLOR_RESET ": to clear the screen.\n");
    printf("Press " ANSI_COLOR_BLUE "0" ANSI_COLOR_RESET ": to exit the program.\n");
    // add more options...
}

int main() {
    // code here
    Node *head = NULL;
    int data = -1;
    int pos = -1;

    for(;;) {
        menu();
        int key = int_input("Enter your prompt: ", 0, 5);
        if(key == 0) {
            break;
        }

        switch (key) {
            case 1:
                // view the list
                if(display_list(&head)) {
                    fprintf(stderr, "List is empty.\n");
                }
                break;
            case 2:
                // add a number
                data = int_input("Enter the data you want to insert: ", INT_MIN, INT_MAX);
                pos = int_input
                        ("Enter the position at which you want to insert: ", 0, INT_MAX);
                insert_at_posi(&head, data, pos);
                break;
            case 3:
                // delete a number
                if(display_list(&head)) {
                    fprintf(stderr, "List is empty.\n");
                }
                pos = int_input
                        ("Enter the position which you want to delete: ", 1, count_nodes(&head));
                delete_at_posi(&head, pos);
                printf("Here is the list after deletion: \n");
                if(display_list(&head)) {
                    fprintf(stderr, "List is empty.\n");
                }
                break;
            case 4:
                // get count of nodes
                printf("The total number of nodes in list are : %d\n", count_nodes(&head));
                break;
            case 5:
                // clear the screen
                clear_screen();
                break;
                // add more cases...

            default:
                fprintf(stdin, "Invalid input!\n.");
                break;
        }
    }
    puts("\nThanks for using this program.");
    puts("Have a nice day!!\n");

    clear_list(&head);
    return 0;
}
