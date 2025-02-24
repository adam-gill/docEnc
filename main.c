#include <stdio.h>
#include <string.h>

// get and store input for a given variable, also has a prompt parameter to give the user a prompt
void getInput(char *variable, const char *prompt) {
    while (1) {
        printf("%s", prompt);
        if (!fgets(variable, 101, stdin)) {
            continue;
        }

        variable[strcspn(variable, "\n")] = '\0';

        int len = strlen(variable);
        int isEmpty = 1;
        for (int j = 0; j < len; j++) {
            if (variable[j] != ' ' && variable[j] != '\t') {
                isEmpty = 0;
                break;
            }
        }

        if (isEmpty) {
            printf("Input cannot be empty. Please try again.\n");
        } else if (len >= 100) {
            printf("Input cannot exceed 100 characters. Please try again.\n");
        } else {
            break;
        }
    }
}

// swap every other character with one another, then reverse that string
// ex: lebron --> belnor --> ronleb
void byteSwap(char *data)
{
    int len = strlen(data);

    for (int i = 0; i < len - 2; i += 3)
    {
        char temp = data[i];
        data[i] = data[i + 2];
        data[i + 2] = temp;
    }

    // reverse string
    for (int i = 0; i < len / 2; i++)
    {
        char temp = data[i];
        data[i] = data[len - 1 - i];
        data[len - 1 - i] = temp;
    }
}

// reverses the byteSwap to get the original string 
// ex: ronleb --> lebron
void reverseByteSwap(char *data)
{
    int len = strlen(data);

    for (int i = 0; i < len / 2; i++)
    {
        char temp = data[i];
        data[i] = data[len - 1 - i];
        data[len - 1 - i] = temp;
    }

    for (int i = 0; i < len - 2; i += 3)
    {
        char temp = data[i];
        data[i] = data[i + 2];
        data[i + 2] = temp;
    }
}

// applies key to the plaintext/ciphertext to encrypt or decrypt
// if key is longer than plaintext: key is only applied to the characters that it matches up with in the plain
// text (leftover key). If the key is shorter than the plaintext: the key loops around the plaintext until all
// characters of the plaintext are xored with a character from the key
void applyKey(char *data, char *key) {
    int dataLen = strlen(data);
    int keyLen = strlen(key);
    
    for (int i = 0; i < dataLen; i++) {
        // Convert plaintext and key char into an index in 0..93
        int pIndex = data[i] - 33;         // plaintext index (0–93)
        int kIndex = key[i % keyLen] - 33;   // key index (0–93)
        
        // Involutory transformation: 
        // ciphertext index = (key index - plaintext index) mod 94
        int cIndex = (kIndex - pIndex + 94) % 94;
        
        // Convert back into printable ASCII (33–126)
        data[i] = cIndex + 33;
    }
}

// does a byte swap, xores with the key, then byte swaps again
void encrypt(char *plaintext, char *key, char *ciphertext)
{
    strcpy(ciphertext, plaintext);
    byteSwap(ciphertext);
    applyKey(ciphertext, key);
    byteSwap(ciphertext);
}


// does the inverse of the encryption to decrypt
void decrypt(char *plaintext, char *key, char *ciphertext)
{
    strcpy(plaintext, ciphertext);
    reverseByteSwap(plaintext);
    applyKey(plaintext, key);
    reverseByteSwap(plaintext);
}

int main()
{
    

    char plaintext[101];
    char key[101];
    char ciphertext[101];
    char control[2];

    printf("+-------------------------------------------------------+\n");
    printf("| Welcome to Adam's Simple Encryption program.    ^_^   |\n| Please enter ASCII values of 100 characters or less.  |");
    printf("\n+-------------------------------------------------------+\n\n");

    getInput(key, "Enter a key: ");

    do
    {
        printf("Enter 'e' to encrypt, 'd' to decrypt, and 'q' to quit: ");
        scanf(" %1s", control);
        getchar();

        if (strcmp(control, "e") == 0)
        {
            getInput(plaintext, "Enter plaintext to encrypt: ");
            encrypt(plaintext, key, ciphertext);
            printf("Ciphertext: %s\n", ciphertext);
        }
        else if (strcmp(control, "d") == 0)
        {
            getInput(ciphertext, "Enter ciphertext to decrypt: ");
            decrypt(plaintext, key, ciphertext);
            printf("Plaintext: %s\n", plaintext);
        }

    } while (strcmp(control, "q") != 0);
    // driver program to take in input and encrypt/decrypt values


    return 0;
}