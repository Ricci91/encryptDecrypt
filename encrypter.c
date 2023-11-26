/**
 *      ENCRYPTER/DECRYPTER
 * 
 * A program that takes in text from the user and encrypts
 * or decrypts the input data.
 * 
 * @author Richard Frøyland
 * @file   encrypter.c
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>



//Function prototypes
void encrypt(char text[],int shift);
int stringlength(char text[]);


/**
 * @brief Main entry of the program
 * 
 * Demonstrates the encryption of a string when using Caesar cipher.
 * 
*/
int main() {
    char text[1024];
    printf("Enter the text you want to be encrypted: ");
    gets(text);

    int shift; 
    printf("Enter the encryption number: ");
    scanf("%d", &shift);
    getchar();

    printf("Original text: %s.\n", text);
    encrypt(text, shift);
    printf("Encrypted text: %s.\n", text);

    return 0;
}

/**
 * @brief Encrypts input text with a simple caesar cipher
 * 
 * This function takes input text and a shift number to encrypt a string 
 * with a simple caesar cipher.
 * 
 * @param text The text to encrypt
 * @param shift The number of positions to shift each character
 * 
 * @example
 * char myText[] = "abc";
 * encrypt(myText, 2);
 * // myText is now "cde"
*/

void encrypt(char text[], int shift) {
    int length = stringlength(text);

    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i])) 
        {
            char base = 'A';
            if (islower(text[i]))
            {
                base = 'a';
            }
            text[i] = (text[i] - base + shift) %26 + base;
        } 
    }
}

/**
 * @brief Gets the length of a string.
 * 
 * @param text The text string that should be measured.
 * @return An int that represents the number of chars in the string.
*/

int stringlength(char text[]) {
    int length = 0;
    // Iterate over each character until the null-terminator is found
    while (text[length] != '\0') 
    {
        length++;
    }
    return length;
}