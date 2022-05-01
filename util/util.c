#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PRESS_ANY_KEY_TO_CONTINUE "Pressione qualquer tecla para continuar   .    .    ."


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

void printFloatArray(float array[], int n){
    printf("[");
    for(register int i = 0; i < n; i++){
        printf("%.2f", array[i]);
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

// removes trailling and leading spaces from a string
char* removeTrailingAndLeadingSpaces(char* string){
    char* newString = malloc(sizeof(char) * 255);
    int i = 0;
    while(string[i] == ' '){
        i++;
    }
    int j = 0;
    while(string[strlen(string) - 1 - j] == ' '){
        j++;
    }
    for(register int k = i; k < strlen(string) - j; k++){
        newString[k - i] = string[k];
    }
    newString[strlen(string) - j] = '\0';
    return newString;
}

int findSpace(bool array[], int n){
    for(register int i = 0; i < n; i++){
        if(array[i] == 0){
            printf("\n Has a space at index: %d\n", i);
            return i;
        }
    }
    printf("\nDoesn't has space\n");
    return -1;
}

int findStringInArray(char array[][255], int n, char string[]){
    for(register int i = 0; i < n; i++){
        if(strncmp(array[i], string, strlen(string)) == 0 ){
            printf("\nFind something in position: %d\n", i);
            return i;
        }
    }
    printf("\nDoesn't find\n");
    return -1;
}

void showCustomBlockingMessage(char *msg)
{
	printf("%s\n", msg);
    getchar();
    getchar();
}

void showBlockingMessage()
{
	printf("%s", PRESS_ANY_KEY_TO_CONTINUE);
    getchar();
    getchar();
}

// get a mandatory string field from the user
char* getMandatoryStringFieldFromUserInput(char* field){
  char* sanitizedString;
  do {
    fgets(field, 255, stdin);
    sanitizedString = removeTrailingAndLeadingSpaces(field);
  } while (sanitizedString[0] == '\n');
  return sanitizedString;
}

// get a mandatory integer field from the user
int getMandatoryIntegerFieldFromUserInput(char* field){
  int integer;
  do {
    fgets(field, 255, stdin);
    integer = atoi(field);
  } while (integer == 0);
  return integer;
}

int getFirstVacantPosition(bool array[], int n){
    for(register int i = 0; i < n; i++){
        if(array[i] == false){
            return i;
        }
    }
    return -1;
}

