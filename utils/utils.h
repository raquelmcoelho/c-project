#include <stdio.h>
#include <stdlib.h>
// String methods lib
#include <string.h>

// Boolean type
typedef int boolean;
#define false 0
#define true 1

// Size of our hardcoded database
#define TAM 20

// Enum for Workers Type
typedef enum {
    teacher,
    administrative_technician
} TypeWorker;