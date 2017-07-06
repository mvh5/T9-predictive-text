// Mauricio Vinagre Hernandez
//CSE 374 Homework 4

#ifndef TRIE_H
#define TRIE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct node that contains data and 9 children
typedef struct node {
  char *data;
  struct node *children[9];
} Node;

//Creates the whole tree with the words contained in file
Node * create(FILE * f);

//searches in the given trie for the word asked by user
char * lookUp(char * userInput,Node *root);

//destroys trie, freeing all the data to avoid leaks
void destroy(Node * trie);

//void printTrie(Node * trie);

#endif
