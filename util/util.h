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
#define MAX_WORKERS 20
#define MAX_VEHICLES 20
#define PARKING_LOT_SIZE 20


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
    teacher,
    administrative_technician
} TypeWorker;

// Flag array for ocupation
// 0 - it's vacant
// 1 - it's occupied
bool spaceVehicles[MAX_VEHICLES];
bool spaceWorkers[MAX_WORKERS];


// initializes an array of size n with the value false
void initializeArray(bool array[], int n);

// beautifully prints an array of size n
void printBoolArray(bool array[], int n);
void printStringArray(char array[][255], int n);

// orders an array of size n alphabetically
void orderArrayAlphabetically(char array[][255], int n);

// generates a random uuid
char* generateUUID();

// sanitizes a string
char* sanitizeString(char* string);

// Returns the index of the first space it finds, if it doesn't find it returns -1
int findSpace(bool array[], int n);