/* Aidan Racaniello, Bradford Smith and Nicholas Zubrycki
 * CS 370 Assignment 7 HackerRank Contacts contacts.c
 * 03/28/2016
 * "We pledge our honor that we have abided by the Stevens Honor System."
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ALPHABET 26

/* structure defining a trie node */
struct s_node
{
    int isEnd; /* this is the end of a contact */
    int count;
    struct s_node *children[ALPHABET];
};

/* typedef for convenience */
typedef struct s_node node;

/* global trie */
node *gl_trie;

/* pre: none
 * post: creates a new trie node
 * retrun: a node* pointing to the newly allocated trie node
 */
node* new_node()
{
    int i;
    node *ret;

    ret = (node*)malloc(sizeof(node));
    for (i = 0; i < ALPHABET; i++)
        ret->children[i] = NULL;
    ret->isEnd = 0;
    ret->count = 0;

    return ret;
}

/* pre: takes in a char* 's'
 * post: adds the string 's' to the global trie
 */
void trie_add(char* s)
{
    int i;

    /* if the global trie is empty */
    if (gl_trie == NULL)
    {
        gl_trie = new_node();
        node *temp = gl_trie;
        for (i = 0; i < strlen(s); i++)
        {
#ifdef DEBUG
            printf("[DEBUG]\tAdding %c at %d\n",
                    s[i], (s[i] - 97));
            fflush(stdout);
#endif
            temp->children[s[i] - 97] = new_node();
            temp = temp->children[s[i] - 97];
            temp->count++;
        }
        temp->isEnd = 1;
    }
    else /* if adding to an existing global trie */
    {
        node *temp = gl_trie;
        for (i = 0; i < strlen(s); i++)
        {
            if (temp->children[s[i] - 97] == NULL)
            {
#ifdef DEBUG
                printf("[DEBUG]\tAdding %c at %d\n",
                        s[i], (s[i] - 97));
                fflush(stdout);
#endif
                temp->children[s[i] - 97] = new_node();
                temp = temp->children[s[i] - 97];
                temp->count++;
            }
            else
            {
                temp = temp->children[s[i] - 97];
                temp->count++;
            }
        }
        temp->isEnd = 1;
    }
}

/* pre: takes in a char* 'p'
 * post: searches the global trie for the partial string 'p'
 * return: an integer that is the number of matches found in the trie for the
 *      partial string 'p'
 */
int trie_find(char *p)
{
    int i;

#ifdef DEBUG
    printf("[DEBUG]\tFind \"%s\"\n", p);
    fflush(stdout);
#endif

    /* skip if the global trie is empty */
    if (gl_trie != NULL)
    {
        node *temp = gl_trie;
        for (i = 0; i < strlen(p); i++)
        {
            if (temp->children[p[i] - 97] != NULL)
            {
                temp = temp->children[p[i] - 97];
            }
            else
            {
                temp = NULL;
                break;
            }
        }
        /* temp is now at the end of the partial string match,
         * or is NULL if no match */
        if (temp != NULL)
        {
            return temp->count;
        }
    }

    return 0;
}

/* pre: takes in int 'argc' anc char** 'argv' command line arguments
 * post: runs the HackerRank challenge "contacs" program
 * return: 0 on success, else 1
 */
int main(int argc, char **argv)
{
    int numStatements;
    char command[5];
    char string[22];

    /* read in number of operations to perform */
    scanf("%d\n", &numStatements);

    if (numStatements <= 0)
        return 1;

    /* loop while there are still statements to read */
    gl_trie = NULL;
    while (numStatements--)
    {
        /* read inputs */
        scanf("%s", command);
        scanf(" %s", string);

#ifdef DEBUG
        printf("[DEBUG]\tCommand: %s\n", command);
        printf("[DEBUG]\tString: %s\n", string);
#endif

        /* call the appropriate handler function based on the value of command */
        if (!strcmp(command, "add"))
            trie_add(string);
        else if (!strcmp(command, "find"))
            printf("%d\n", trie_find(string));
    }

    return 0;
}
