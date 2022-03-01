#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argh[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argh[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    
    for (int i = 0, n = strlen(argh[1]); i < n; i++)
    {
        if (!isalpha(argh[1][i]))
        {
            printf("Key must contain alphabetic characters only.\n");
            return 1;
        }
        
        for (int j = i + 1; j < n; j++)
        {
            if (argh[1][i] == argh[1][j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            //ci is the index of character in plaintext
            int ci = plaintext[i];
            char c;
            
            if (isupper(plaintext[i]))
            {
                ci -= 'A';
                c = toupper(argh[1][ci]);
            }
            else
            {
                ci -= 'a';
                c = tolower(argh[1][ci]);
            }
            
            printf("%c", c);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    
    return 0;
}