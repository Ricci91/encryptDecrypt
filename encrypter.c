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
void encrypt(char text[],struct EncryptionSettings *settings);
int stringlength(char text[]);

/**
 * @struct EncryptionSettings
 * @brief  Holds settings for encryption.
 * 
 * This struct is used to store the settings required for the encryption
 * process.
*/
struct EncryptionSettings
{
    int shift; /**< The number of positions to shift in the cipher*/
};

/**
 * @brief Main entry of the program
 * 
 * Demonstrates the encryption of a string when using Caesar cipher.
 * 
*/
int main() {
    
    struct EncryptionSettings mySettings;
        mySettings.shift = 3;

    char text[1024];
    printf("Enter the text you want to be encrypted: ");
    gets(text);

    int shift; 
    printf("Enter the encryption number: ");
    scanf("%d", &mySettings.shift);
    getchar();

    printf("Original text: %s.\n", text);
    encrypt(text, &mySettings); // Pass pointer to mySettings
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

void encrypt(char text[], struct EncryptionSettings *settings) {
    char *ptr = text; //Pointer to the first character of the text

    while (*ptr != '\0')
    {
        if (isalpha(*ptr)) 
        {
            char base = islower(*ptr) ? 'a' : 'A';
            *ptr = (*ptr - base + settings->shift) % 26 +base;
        }
        ptr++;
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
    return length; }