// CS50 Pset5

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "dictionary.h"

//Define a struct of node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Define the node for the hashtable
node *hash_table[26];

// Define the hashfunction to point to the array according to the first letter
int hash_function(const char *word)
{
    return word[0] - 'a';
}

//Define a counter for the amount of nodes you add
int number_of_nodes = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // Define temporary storage
    char temp_word[LENGTH + 1] = {'\0'};

    // Copy to temp
    strcpy(temp_word, word);

    // Lowercase all
    for (int i = 0; word[i] != '\0'; i++)

        temp_word[i] = tolower(word[i]);

    // Define the array of the number
    int temp_array = hash_function(temp_word);

    // Point
    node *temp_node = hash_table[temp_array];

    // Compare the temp_word to words in the hashtable
    while(temp_node != NULL)
    {
        // Check if the word is equivalent to the string in the hash, if so return true
        if(strcmp(temp_word, temp_node->word) == 0)

            return true;

            //Move onto the next node
            temp_node = temp_node->next;
    }



    return false;
}




// Loads dictionary into memory.  Returns true if successful else false.

bool load(const char *dictionary)
{
    //Open Dictionary
    FILE *fp = fopen(dictionary, "r");

    if (dictionary == NULL)
    {
        return false;
    }

    // Define a random String
    char *string = malloc(sizeof(char)*(LENGTH+1));

    //Iterate over every word in the dictionary
    while (fscanf(fp, "%s", string) != EOF)
    {
        // Allocate new space for a node
        node* new_node = malloc(sizeof(node));

        // Copy the string into the array
        strcpy(new_node->word, string);

        int hash_number = hash_function(string);

        // point to new nodes
        new_node->next = hash_table[hash_number];
        hash_table[hash_number] = new_node;

        number_of_nodes++;
    }

    // preventing memory leaks
    free(string);

    //Close Dictionary
    fclose(fp);

    //Finish
    return true;
}


unsigned int size(void)
{
    // Check if the file was loaded
    if (number_of_nodes != 0)

        //Simply return the counter of the number of nodes implemented
    {
        return number_of_nodes;
    }

    // If not loaded, it has zero words
    return 0;
}


bool unload(void)
{
    // Loop through the hash table array
    for (int i=0;i<27;i++)
    {
        // Defining node
        node* temp_node_1 = hash_table[i];

        // Iterate through each nodes
        while(temp_node_1 != NULL)
        {

            node* temp_node_2 = temp_node_1->next;
            free(temp_node_1);
            temp_node_1 = temp_node_2;
        }
    }

    return true;
}