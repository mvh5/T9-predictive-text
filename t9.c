#include<stdio.h>
#include "trie.h"

//Mauricio Vinagre Hernandez
//CSE 374 HW 4
//T9 application which asks the user for input, and the
//program returns the corresponding word

int main(int argc, char **argv) {
  FILE *file = fopen(argv[1],"r");
  if (file == NULL) {
    fprintf(stderr,"Error opening file\n");
    return 1;
  }
  Node *root = create(file);
  
  char myNumbers[50];
  printf("Enter Key Sequence or # for next word: ");
  scanf("%s",myNumbers);
  while (strcmp(myNumbers,"exit") != 0) {
   lookUp(myNumbers,root);
   printf("Enter Key sequence of # for next word: ");
   scanf("%s",myNumbers);
  }
  destroy(root);
  return 0;
}


