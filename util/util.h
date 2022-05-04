#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// String methods lib
#include <string.h>

// Boolean type
typedef int boolean;
#define false 0
#define true 1

// Size of our hardcoded database
#ifndef MAX_WORKERS
#define MAX_WORKERS 20
#endif

#ifndef MAX_VEHICLES
#define MAX_VEHICLES 20
#endif

// Colors to use in terminal
#define red "\x1B[31m"
#define green "\x1B[32m"
#define yellow "\x1B[33m"
#define blue "\x1B[34m"
#define purple "\x1B[35m"
#define cyan "\x1B[36m"
#define white "\x1B[37m"
#define normal "\x1B[0m"

// Enum for Workers Type
typedef enum {
    null_type,
    administrative_technician,
    teacher    
} TypeWorker;

// Flag array for ocupation
// 0 - it's vacant
// 1 - it's occupied
// bool spaceVehicles[MAX_VEHICLES];
bool spaceWorkers[MAX_WORKERS];


// initializes an array of size n with the value false
void initializeBoolArray(bool array[], int n);
void initializeIntArray(int *array, int n);
void initializeStringArray(char array[][255], int n);


// beautifully prints an array of size n
void printBoolArray(bool array[], int n);
void printStringArray(char array[][255], int n);
void printIntArray(int array[], int n);

// orders an array of size n alphabetically
void orderArrayAlphabetically(char array[][255], int n);
void orderPositionsAlphabetically(int indexes[], char array[][255], int n);

// generates a random uuid
char* generateUUID();

// removes trailling and leading spaces from a string
char* removeTrailingAndLeadingSpaces(char* string);

// Returns the index of the first space it finds, if it doesn't find it returns -1
int findSpace(bool array[], int n);

// Find something in a array and return the position
int findStringInArray(char array[][255], int n, char string[]);

// Shows a message at screen and wait the user to press some key to continue
void showCustomBlockingMessage(char *msg);
void showBlockingMessage();

// get a mandatory (or not) string, integer or float field from the user
char* getMandatoryStringFieldFromUserInput(char* field, char msg[]);
int getMandatoryIntegerFieldFromUserInput(char* field, char msg[]);
char* getStringFieldFromUserInput(char* field, char msg[]);
int getIntegerFieldFromUserInput(char* field, char msg[]);



// get the first vacant position in an array
int getFirstVacantPosition(bool array[], int n);

// sanitizes a string
char* sanitizeString(char* string);

// Find something in a array and return the position
int findStringInArray(char array[][255], int n, char string[]);

// get the first vacant position in an array
int getFirstVacantIndex(bool array[], int n);

char* getDivider();
