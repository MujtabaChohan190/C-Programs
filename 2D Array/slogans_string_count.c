#include <stdio.h>
#include <string.h>
int main()
{
    int i, j, num_slogans;

    char slogans[3][20] = {"buy now", "save big", "limited offer"};
    num_slogans = 3;
    int char_count[3][256] = {0}; // 2D array to store the count of each character of 3 strings

    // Traverse through each string and count characters
    for (i = 0; i < num_slogans; i++)
    {
        for (j = 0; slogans[i][j] != '\0'; j++)
        { // Get the current character of the string
            char ch = slogans[i][j];
            int ascii_value = (int)ch; // Getting the ascii value of the character
            char_count[i][ascii_value]++;
        }
    }
    // Print character counts for each character
    for (i = 0; i < num_slogans; i++)
    {
        printf("\nFor \"%s\": {", slogans[i]);
        int first = 1; // Using this to ouput nicely
        for (j = 0; j < 256; j++)
        {
            if (char_count[i][j] > 0 && j != ' ')
            { // Done to ensure that only the characters in string appear and that it does not print the occurence of space in character
                if (!first)
                {
                    printf(", ");
                }
                printf("'%c': %d", j, char_count[i][j]);
                first = 0; // if first = 1 , this means the current character is the first one being printed so theres no need of comma
                          //  if first = 0 , this means that at least one character has been printed , so comma is place
            }
        }
        printf("}\n");
    }
    return 0;
}
