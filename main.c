#include <stdio.h>

void get4CharInput(char *input) {
    while (1) {
        printf("Enter a 4-character ciphertext: ");
        scanf("%4s", input);

        int length = 0;
        while (input[length] != '\0') {
            length++;
        }

        if (length == 4 && getchar() == '\n') {
            break;
        }

        printf("Invalid input! Please enter exactly 4 characters.\n");
        while (getchar() != '\n');
    }
}

int main() {
    char plaintext[5];
    char key[101];

    get4CharInput(plaintext);

    printf("Enter a key (up to 100 characters): ");
    scanf("%100s", key);

    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);

    return 0;
}