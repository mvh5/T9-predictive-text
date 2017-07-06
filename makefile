t9 : trie.o t9.o
	gcc -Wall -std=c11 -o t9 trie.o t9.o

trie.o : trie.h trie.c
	gcc -Wall -std=c11 -g -c trie.c trie.h

t9.o : t9.c trie.h
	gcc -Wall -std=c11 -g -c t9.c trie.h
