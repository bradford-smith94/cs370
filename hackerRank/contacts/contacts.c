/* Bradford Smith
 * CS 370 HackerRank Contacts contacts.c
 * 03/14/2016
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ALPHABET 26

struct s_node
{
    char c;
    int numChildren;
    struct s_node *children[ALPHABET];
};

typedef struct s_node node;

node *gl_trie;

node* new_node(char c)
{
    int i;
    node *ret;

    ret = (node*)malloc(sizeof(node));
    for (i = 0; i < ALPHABET; i++)
        ret->children[i] = NULL;
    ret->c = c;

    return ret;
}

void trie_add(char* s)
{
    int i;

    if (gl_trie == NULL)
    {
        gl_trie = new_node('\0');
        node *temp = gl_trie;
        for (i = 0; i < strlen(s); i++)
        {
            temp->children[s[i] - 97] = new_node(s[i]);
            temp = temp->children[s[i] - 97];
        }
    }
    else
    {
        node *temp = gl_trie;
        for (i = 0; i < strlen(s); i++)
        {
            if (temp->children[s[i] - 97] == NULL)
            {
                temp->children[s[i] - 97] = new_node(s[i]);
                temp = temp->children[s[i] - 97];
            }
        }
    }
}

int trie_find(char *p)
{
    int i;
    int num;

    num = 0;

    if (gl_trie != NULL)
    {
        node *temp = gl_trie;
        for (i = 0; i < strlen(p); i++)
        {
            if (temp->children[p[i] - 97] != NULL)
            {
                /* TODO: */
            }
        }
    }

    return num;
}

int main(int argc, char **argv)
{
    int numStatements;
    char *line;
    unsigned long len;
    int n;
    char *command;
    char *string;

    scanf("%d\n", &numStatements);

    if (numStatements <= 0)
        return 1;

    gl_trie = NULL;
    line = NULL;
    while (numStatements--)
    {
        n = getline(&line, &len, stdin);
        if (n == -1)
            break;
        command = strtok(line, " ");
        string = strtok(NULL, " ");

#ifdef DEBUG
        printf("Command: %s\n", command);
        printf("String: %s\n", string);
#endif

        if (!strcmp(command, "add"))
            trie_add(string);
        else if (!strcmp(command, "find"))
            printf("%d", trie_find(string));
    }
}
