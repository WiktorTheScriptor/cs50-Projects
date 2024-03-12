#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Program for comparing the scrabble scores of 2 words

// Letter scores:
int scores[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int get_score(string word);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    int score1 = get_score(word1);
    int score2 = get_score(word2);
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Calculates the score of a word
int get_score(string word)
{
    // Find length of word:
    int len = strlen(word);
    // Converts string to lower
    for (int i = 0; i < len; i++)
    {
        word[i] = tolower(word[i]);
    }
    // Finds the score by converting ASCII to int and using scores array
    int sc = 0;
    for (int i = 0; i < len; i++)
    {
        if (((int) word[i]) >= 97 && ((int) word[i]) <= 122)
        {
            sc += scores[(int) word[i] - 97]; // 'a' is 97 on ASCII table, starts 'a' at index 0
        }
    }
    return sc;
}
