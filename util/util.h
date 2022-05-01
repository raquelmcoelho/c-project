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

// Enum for Workers Type
typedef enum {
    teacher,
    administrative_technician
} TypeWorker;

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
