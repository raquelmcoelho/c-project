#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 20

// initializes an array of size n with the value false
void initializeArray(bool array[], int n);

// beautifully prints an array of size n
void printArray(bool array[], int n);

// orders an array of size n alphabetically
void orderArrayAlphabetically(char array[][255], int n);

// generates a random uuid
char* generateUUID();

// sanitizes a string
char* sanitizeString(char* string);