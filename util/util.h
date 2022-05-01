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

// Flag array for ocupation
// 0 - it's vacant
// 1 - it's occupied
bool spaceVehicles[MAX_VEHICLES];
bool spaceWorkers[MAX_WORKERS];


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

// Returns the index of the first space it finds, if it doesn't find it returns -1
int findSpace(bool array[], int n){
    for(register int i = 0; i < n; i++){
        if(array[i] == 0){
            printf("\n Has a space at index: %d\n", i);
            return i;
        }
    }
    return -1;
}