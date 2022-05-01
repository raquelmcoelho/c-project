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
void printBoolArray(bool array[], int n){
    printf("[");
    for(register int i = 0; i < n; i++){
        printf("%d", array[i]);
        if(i != n - 1){
            printf(", ");
        }
    }
    printf("]\n");
}

void printStringArray(char array[][255], int n){
    printf("[");
    for(register int i = 0; i < n; i++){
        printf("%s", array[i]);
        if(i != n - 1){
            printf(", ");
        }
    }
    printf("]\n");
}


// orders an array of size n alphabetically
void orderArrayAlphabetically(char array[][255], int n){
    for(register int i = 0; i < n; i++){
        for(register int j = 0; j < n; j++){
            if(strcmp(array[i], array[j]) < 0){
                char temp[255];
                strcpy(temp, array[i]);
                strcpy(array[i], array[j]);
                strcpy(array[j], temp);
            }
        }
    }
}

// generates a random uuid
char* generateUUID(){
    char* uuid = malloc(sizeof(char) * 255);
    sprintf(uuid, "%04x%04x-%04x-%04x-%04x-%04x%04x%04x",
        rand() & 0xffff, rand() & 0xffff,
        rand() & 0xffff,
        rand() & 0x0fff | 0x4000,
        rand() & 0x3fff | 0x8000,
        rand() & 0xffff, rand() & 0xffff, rand() & 0xffff);
    return uuid;
}

// sanitizes a string, removing all spaces and @ # $ % ^ & * ( ) - _ + = [ ] { } | \ : ; " ' < > ? /
char* sanitizeString(char* string){
    char* sanitized = malloc(sizeof(char) * 255);
    int i = 0;
    for(register int j = 0; j < strlen(string); j++){
        if(string[j] != ' ' && string[j] != '@' && string[j] != '#' && string[j] != '$' && string[j] != '%' && string[j] != '^' && string[j] != '&' && string[j] != '*' && string[j] != '(' && string[j] != ')' && string[j] != '-' && string[j] != '_' && string[j] != '+' && string[j] != '=' && string[j] != '[' && string[j] != ']' && string[j] != '{' && string[j] != '}' && string[j] != '|' && string[j] != '\\' && string[j] != ':' && string[j] != ';' && string[j] != '"' && string[j] != '\'' && string[j] != '<' && string[j] != '>' && string[j] != '?' && string[j] != '/'){
            sanitized[i] = string[j];
            i++;
        }
    }
    sanitized[i] = '\0';
    return sanitized;
}

int findSpace(bool array[], int n){
    for(register int i = 0; i < n; i++){
        if(array[i] == 0){
            printf("\n Has a space at index: %d\n", i);
            return i;
        }
    }
    return -1;
}