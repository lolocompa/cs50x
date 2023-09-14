// Implements a dictionary's functionality
#include <strings.h>

#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include "dictionary.h"

int hashing_times = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 17576;

// Hash table
node *table[N];









// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    node *cursor = table[index];

    while (cursor != NULL)
    {
        int is_in = strcasecmp(word, cursor->word);
        if (is_in == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}










// Hashes word to a number
unsigned int hash(const char *word)
{
    int length = strlen(word);
    char lower_word[length];
    for(int i = 0; i < length; i++)
    {
        lower_word[i] = tolower(word[i]);
    }
    lower_word[length] = '\0';

    int first_term = (lower_word[0] - 97) * 26;
    int second_term = (lower_word[1] - 97) * 26;
    int third_term = lower_word[2] - 97;

    int index = first_term + second_term + third_term;
    return index;
}








// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dic = fopen(dictionary, "r");
    char word[LENGTH + 1];

    if (dic == NULL)
    {
        return false;
    }

    while (fscanf(dic, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, word);
        n->next = NULL;

        int index = hash(n->word);
        hashing_times++;

        n->next = table[index];
        table[index] = n;
    }

    fclose(dic);
    return 1;
}











// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return hashing_times;
}







// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i = 0; i < 17576; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node * tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
