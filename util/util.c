#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PRESS_ANY_KEY_TO_CONTINUE "Pressione qualquer tecla para continuar   .    .    ."


// initializes an array of size n with the value false
void initializeBoolArray(bool* array, int n){
    for(register int i = 0; i < n; i++){
        array[i] = false;
    }
}

void initializeIntArray(int* array, int n){
    for(register int i = 0; i < n; i++){
        array[i] = 0;
    }
}

void initializeStringArray(char array[][255], int n){
    for(register int i = 0; i < n; i++){
        strcpy(array[i], "");
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

void printIntArray(int *array, int n){
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

// order the positions of an array of strings and return an array of the properly indexes
void orderPositionsAlphabetically(int indexes[], char array[][255], int n){
    char copy[n][255];

    // fill array with original positions index and make a copy with values
    for(register int k = 0; k < n; k ++){
        indexes[k] = k;
        strcpy(copy[k], array[k]);
    }

    // find the properly order
    for(register int i = 0; i < n; i++){
        for(register int j = 0; j < n; j++){
            if(strcmp(copy[i], copy[j]) < 0){
                char temp[255];
                int tempInt;

                // order copy
                strcpy(temp, copy[i]);
                strcpy(copy[i], copy[j]);
                strcpy(copy[j], temp);

                // order position array
                tempInt = indexes[i];
                indexes[i]= indexes[j];
                indexes[j] = tempInt;
            }
        }
    }
}


// generates a random uuid
char* generateUUID(){
    char* uuid = malloc(sizeof(char) * 255);
    sprintf(uuid, "%04x%04x-%04x-%04x-%04x",
        rand() & 0xffff, rand() & 0xffff,
        rand() & 0xffff,
        rand() & 0x0fff | 0x4000,
        rand() & 0x3fff | 0x8000
    );
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
    newString[strlen(string) - j -1] = '\0';
    return newString;
}

// Find something in a array and return the position
int findStringInArray(char array[][255], int n, char string[]){
    for(register int i = 0; i < n; i++){
        if(strcmp(array[i], string) == 0 ){
            return i;
        }
    }
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
char* getMandatoryStringFieldFromUserInput(char* field, char msg[]){
    char* sanitizedString;
    do {
        sanitizedString = getStringFieldFromUserInput(field, msg);
    } while (strcmp(sanitizedString,"") == 0);
    return sanitizedString;
}

char getMandatoryWillFieldFromUserInput(){
    char will;
    do {
        will = getchar();
    } while (will != 's' && will != 'n');
    return will;
}

// get a mandatory integer field from the user
int getMandatoryIntegerFieldFromUserInput(char* field, char msg[]){
    int integer;
    do {
        integer = getIntegerFieldFromUserInput(field, msg);
    } while (integer == 0);
    return integer; 
}

// get a string field from the user
char* getStringFieldFromUserInput(char* field, char msg[]){
    printf("\n%s\n", msg);
    fgets(field, 255, stdin);
    return removeTrailingAndLeadingSpaces(field);
}

int getIntegerFieldFromUserInput(char* field, char msg[]){
    printf("\n%s\n", msg);
    fgets(field, 255, stdin);
    return atoi(field); 
}


// Returns the index of the first vacant it finds, if it doesn't find it returns -1
int getFirstVacantIndex(bool array[], int n){
    for(register int i = 0; i < n; i++){
        if(array[i] == false){
            return i;
        }
    }
    return -1;
}

char* getDivider(){
    char* _line = malloc(sizeof(char) * 255);
    for(register int i = 0; i < 150; i++){
        _line[i] = '-';
    }
    _line[255] = '\0';
    return _line;
}
