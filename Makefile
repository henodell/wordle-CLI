CC = gcc

hellomake:
	$(CC) -std=c23 -o wordle ./wordle.c
	./wordle.exe