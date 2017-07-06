//Mauricio Vinagre, hw4 CSE 374
#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100

//function prototypes
Node *init_node();
int fromCharToInt(char c);
Node *add_node(Node * tree, char c);
Node * add_word(Node * tree, char * word);
void add_word2 (Node * root, char * word);
Node * addNodeAuxiliary(Node * tree, int currentIndex, char * word);
void addNodeAuxiliary2(Node * tree, int currentIndex, char * word);


//Adds the given word to the given trie
Node * add_word(Node * tree, char * word) {
  Node *temp = add_node(tree,word[0]);
  
  int i = 1;
  while (word[i] != 0) {
    
    temp = add_node(tree,word[i]);
    i++;
  }
  temp->data = malloc(strlen(word) + 1);
  strncpy(temp->data,word,strlen(word)+1);
  //printf("%s",temp->data);
  return tree;
}


//Adds a node if it doesn't already exist
Node * add_node(Node *tree, char c) {
  int index = fromCharToInt(c);
  if ( tree->children[index] == NULL) {
    tree->children[index] = init_node();
      
  }
  return tree;
  
}



Node * addNodeAuxiliary(Node * tree, int currentIndex, char * word) {

  if (word[currentIndex] != 0) {
    int indexInChildren = fromCharToInt(word[currentIndex]);
    if (tree->children[indexInChildren] == NULL) {
      tree->children[indexInChildren] = init_node();
    }
    tree->children[indexInChildren] = addNodeAuxiliary(tree->children[indexInChildren],currentIndex+1,word);
  } else {
    //tree->data = malloc(strlen(word)+1);
    //strncpy(tree->data,word,strlen(word)+1);
    tree->data = malloc(100);
    strncpy(tree->data,word,100);
    
  }
  return tree;
}

void addNodeAuxiliary2(Node * tree, int currentIndex, char * word) {
  if (word[currentIndex] != '\n') {
    //printf("%c\n",word[currentIndex]);
    int indexInChildren = fromCharToInt(word[currentIndex]);
    if (tree->children[indexInChildren] == NULL) {
      tree->children[indexInChildren] = init_node();
    }
    addNodeAuxiliary2(tree->children[indexInChildren],currentIndex+1,word);
  } else {
    while (tree->data != NULL) {
      if (tree->children[8] == NULL) {
	tree->children[8] = init_node();
      }
      tree = tree->children[8];
    }
    tree->data = malloc(strlen(word)+1);
    strncpy(tree->data,word,strlen(word)+1);
    
    
  }
  
}

//adds the given word in the trie
void add_word2 (Node * root, char * word) {
   addNodeAuxiliary2(root,0,word);
   //printf("%lu\n",strlen(word));
}



    
//Converts the given char into an appropiate integer index
int fromCharToInt(char c) {
  // c = tolower(c);
  if (c == 'a' || c == 'b' || c == 'c') {
    return 0;
  } else if (c == 'd' || c == 'e' || c == 'f'){
    return 1;
  } else if (c == 'g' || c == 'h' || c == 'i'){
    return 2;
  } else if (c == 'j' || c == 'k' || c == 'l'){
    return 3;
  } else if (c == 'm' || c == 'n' || c == 'o'){
    return 4;
  } else if (c == 'p' || c == 'q' || c == 'r'|| c == 's'){
    return 5;
  } else if (c == 't' || c == 'u' || c == 'v'){
    return 6;
  } else if (c == 'w' || c == 'x' || c == 'y'|| c == 'z'){
    return 7;
  } else if(c == '#') {
    return 8;
  } else {
    return -1;
  }
}
  
    
//Initializes a node and returns it
Node *init_node(){
  Node *n = malloc(sizeof(*n));
  if (n == NULL) {
    fprintf(stderr, "init_node: malloc failed\n");
    exit(1);
  }
  n->data=NULL;
  for (int i = 0; i < 9; i++) {
    n->children[i]= NULL;
  }
  return n;
}

//Creates the whole tree
Node *  create(FILE *f) {
  Node *trie = init_node();
  char line [MAX_LINE_LENGTH];

  while (fgets(line,MAX_LINE_LENGTH,f)) {
    add_word2(trie,line);
  }
  return trie;
}

//Given a trie and the user input, this method search in the trie until it finds the corresponding
//word (if it exists)
char * lookUp(char * userInput,Node * root){
  Node * temp = root;
  int i = 0;
  int index = 0;
  while (userInput[i] != 0) {
    if (userInput[i] == '#') {
      index = 8;
    } else {
      index = userInput[i] - '0';
      index = index-2;
    }
    //printf("%d\n",index);
    if (temp->children[index] == NULL) {
      printf("Not Found\n");
      return NULL;
    }
    temp = temp->children[index];
    i++;
  }
  if (temp == NULL || temp->data ==NULL) {
    printf("Not found\n");
    return NULL;
  }
  printf("%s\n",temp->data);
  return temp->data;
}

//frees all the data to avoid leaks
void destroy(Node * trie) {
  for (int i = 0; i < 9; i++) {
    if (trie->children[i] != NULL ) {
      destroy(trie->children[i]);
    }
  }
  if (trie->data != NULL) {
    free(trie->data);
  }
  free(trie);
}
    
    
