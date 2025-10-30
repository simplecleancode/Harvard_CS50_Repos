#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define CIPHER_KEY_LEN 26

int validateCipherKey(string key);
void encipher(string text, string argStr);


int main(int argc, string argv[])
{

printf("%i\n", argc);
string cipherKey = argv[1];

for(int i = 0, n = strlen(cipherKey); i < n; i++)
    {
    cipherKey[i] = tolower(cipherKey[i]);
    }

    //validate the arguments
    if(argc != 2)
    {
        printf("error: please enter one cipher\n");
        return 1;
    }

    //validate the cipher
    if (validateCipherKey(cipherKey) != 0)
    {
    printf("Error: Please enter a valid cipher\n");
    return 1;
    }

    //get plaintext
    string plainText = get_string("Enter plain text: ");

    //encipher plaintext
    encipher(plainText, argv[1]);

}

///////////// validate key
int validateCipherKey(string key)
{

    if(strlen(key) != CIPHER_KEY_LEN)
    {
    printf("Error: Invalid number of characters.\n");
    return 1;
    }

    const int CIPHER_KEY_EXPECTED_SUM = 2847;
    int cipherKeySum = 0;

    for(int i = 0; i < strlen(key); i++)
    {
        //check for non-alphabetic characters
        if(isalpha(key[i]) == 0)
        {
        printf("Error: Enter letters only.\n");
        return 1;
        }
    cipherKeySum += key[i];
    }

    //check for repeated char
    if(cipherKeySum != CIPHER_KEY_EXPECTED_SUM)
    {
    printf("Error: Enter each letter only once\n");
    return 1;
    }
    //valid key
    return 0;

}



////////encipher
void encipher(string text, string argStr)
{

int const lowerOffset = 97;
int const upperOffset = 65;

printf("ciphertext: ");

    //for each alphabetic character
    //determine what letter it maps to
    for(int i = 0, n = strlen(text); i <= n - 1; i++)
    {
        //convert

        if(islower(text[i]))
        {
            int lowerCaseIndex = text[i] - lowerOffset;
            printf("%c", tolower(argStr[lowerCaseIndex]));
        }

        if(isupper(text[i]))
        {
            int upperCaseIndex = text[i] - upperOffset;
            printf("%c", toupper(argStr[upperCaseIndex]));
        }


        if(isalpha(text[i]) == 0)
        printf("%c", text[i]);
    }

printf("\n");

//end encipher
}







