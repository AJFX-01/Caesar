#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

bool only_digits(string s);
char rotate(char c, int p);

int main(int argc, string argv[])
{
    // the code takes in just a command line
    string s = argv[1];
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // make sure the characters in agrv[1] are just digit
    else if (only_digits(s) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // chnage the argv[1] from it (string) to (int) values
    int key = atoi(argv[1]);

    // get input from the user has plaintext
    string plaintext = get_string("Plaintext: ");
    printf("ciphertext: ");

    // change individual cahracters in the plaintext
    for (int g = 0, h = strlen(plaintext); g < h; g++)
    {
        // wrap around the character if it a letter
        char ciphertext = rotate(plaintext[g], key);
        printf("%c", ciphertext);
    }
    printf("\n");

    return 0;
}
bool only_digits(string s)
{
    // to check for numerical values
    for (int n = 0, m = strlen(s); n < m; n++)
    {
        if (isdigit(s[n]))
        {

        }
        else
        {
            return false;
        }
    }
    return true;
}
char rotate(char c, int p)
{
    int switchfro = 0;
    int switchto = 0;

    // check for alphabetical characters
    if (isalpha(c) == false)
    {
        switchto = c;
    }

    // check the character an upper case
    if (isupper(c))
    {
        // index the charcater from ASCII to index value(0 - 25)
        switchfro = c - 65;

        // cipher key using
        switchto = (switchfro + p) % 26;

        // indexing back to ASCII by adding 65
        switchto += 65;
    }

    // check the character for lower case
    else if (islower(c))
    {
        // index the charcater from ASCII to index value(0 - 25)
        switchfro = c - 97;

        // cipher key using
        switchto = (switchfro + p) % 26;

        // indexing back to ASCII by adding 97
        switchto += 97;
    }
    return switchto;
}