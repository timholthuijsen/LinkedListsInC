CC = gcc

bst: bst.c bst.h main.c list.c list.h
	$(CC) -o bst bst.c
