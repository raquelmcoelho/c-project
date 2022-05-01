#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// initializes an array of size n with the value false
void initializeArray(bool* array, int n){
    for(register int i = 0; i < n; i++){
        array[i] = false;
    }
}

// beautifully prints an array of size n
void printArray(bool array[], int n){
    printf("[");
    for(register int i = 0; i < n; i++){
        printf("%d", array[i]);
        if(i != n - 1){
            printf(", ");
        }
    }
    printf("]\n");
}


// orders an array of size n alphabetically
// void orderArrayAlphabetically(char array[][255], int n);

// generates a random uuid
// char* generateUUID();

// sanitizes a string
// char* sanitizeString(char* string);