#include <stdio.h>

void getPlainText(char *outputText) {
    char input[5]; // Array to hold 4 characters + null terminator
    printf("Enter 4 ASCII characters: ");
    fgets(input, sizeof(input), stdin);

    
}

int main() {
    char binaryOutput[33]; // 32 bits for 4 characters + null terminator
    getPlainText(binaryOutput); // Call the modified function
    printf("Binary representation: %s\n", binaryOutput);
  // Lebron
    
    

  return 0;


}