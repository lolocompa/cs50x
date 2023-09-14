// Implements a dictionary's functionality

#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    const char lower_word[] = tolower(*word);

    char l = lower_word[0];
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

        n->next = table[index];
        table[index] = n;
    }

    fclose(dic);
    return 1;
}











// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
