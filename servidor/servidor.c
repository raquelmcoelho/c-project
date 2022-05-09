#include "servidor.h"

bool insertNewServer(){
    // get the fisrt vacant space for workers
    int spaceIndex = getFirstVacantIndex(spaceWorkers, MAX_WORKERS);
    
    // if there is no space, return false
    if(spaceIndex == -1){
        printf("\nNão há espaço disponível!\n");
        return false;
    } else {
        // use the alter server function to insert the new worker
        if(alterServer(spaceIndex)){            
            return true;
        } else {
            return false;
        }
    }
}

// Alter a server/worker getting the new data from user
bool alterServer(int position){
    // get Mandatory User Data
    char newWorkerRegistrationNumber[255] ;
    char newSiape[255];
    char newCpf[255];
    char newName[255];
    char newBirthday[255];

    // get Optional User Data
    char newRg[255];
    char newAddress[255];
    char newWage[255];
    TypeWorker newType;
    
    // Generate a code
    strcpy(newWorkerRegistrationNumber, generateUUID());
    
    // Uses myVar to get the input of all fields
    char myVar[255];
    strcpy(myVar, "");
    strcpy(newSiape, getMandatoryStringFieldFromUserInput(myVar, "Insira número SIAPE:"));
    strcpy(newCpf, getMandatoryStringFieldFromUserInput(myVar, "Insira seu número de CPF:"));
    strcpy(newName, getMandatoryStringFieldFromUserInput(myVar, "Insira seu Nome:"));
    strcpy(newBirthday, getMandatoryStringFieldFromUserInput(myVar, "Insira sua data de nascimento"));
    strcpy(newRg, getStringFieldFromUserInput(myVar, "(opcional) Insira seu número de RG"));
    strcpy(newAddress, getStringFieldFromUserInput(myVar, "(opcional) Insira seu endereço"));
    strcpy(newWage, getStringFieldFromUserInput(myVar, "(opcional) Insira seu salário"));

    // Get type enum
    int typeChoosen = 0;
    typeChoosen = getIntegerFieldFromUserInput(myVar, "(opcional) Insira seu tipo: \n 0 - Nada\n 1- Docente\n 2- Técnico Admnistrativo\nResposta:");
    switch(typeChoosen){
        case 0:
            newType = 0;
            break;
        case 1:
            newType = 1;
            break;
        case 2:
            newType = 2;
            break;
        default:
            newType = 0;
            break;
    }

    // Check if already exists registration number, cpf and siape
    if((checkExists(newWorkerRegistrationNumber, 1) == -1) && (checkExists(newSiape, 2) == -1) && (checkExists(newCpf, 3) == -1)){ //} && (checkExists(newRg, 4) == -1)){
        // Get a position if it's not defined yet
        if(position == -1){
            char positionChar[255];
            do {
                position = getMandatoryIntegerFieldFromUserInput(positionChar, "Insira a posição desejada para armazenar os dados [1 a 20]:") - 1;
            } while (!(position < MAX_WORKERS && position >= 0));
        } 

        
        // Inserts each value
        strcpy(workerRegistrationNumber[position], newWorkerRegistrationNumber);
        strcpy(siape[position], newSiape);
        strcpy(cpf[position], newCpf);
        strcpy(name[position], newName);
        strcpy(birthday[position], newBirthday);
        strcpy(rg[position], newRg);
        strcpy(address[position], newAddress);
        strcpy(wage[position], newWage);
        type[position] = newType;
        
        // Set position space to true
        spaceWorkers[position] = 1;
        return true;
    } else {
        printf("\nFALHA: Código Gerado, SIAPE ou CPF repetido\n");
        return false;
    }
}


void deleteServer(int position){
    if(position == -1){
        char positionChar[255];
        do {
            position = getMandatoryIntegerFieldFromUserInput(positionChar, "Insira a posição desejada para deletar os dados [1 a 20]:") - 1;
        } while (!(position < MAX_WORKERS && position >= 0));
    } 
    
    // Clear all data in that position
    strcpy(workerRegistrationNumber[position], "");
    strcpy(siape[position], "");
    strcpy(cpf[position], "");
    strcpy(name[position], "");
    strcpy(birthday[position], "");
    strcpy(rg[position], "");
    strcpy(address[position], "");
    strcpy(wage[position], "");
    type[position] = 0;

    // Set position space to false
    spaceWorkers[position] = 0;
}


void read(){
    char registrationNumber[255];
    strcpy(registrationNumber, getMandatoryStringFieldFromUserInput(registrationNumber, "Insira o código do servidor a ser lido"));
    int idWorker = checkExists(registrationNumber, 1);

    if(idWorker == -1){
        printf("\nNão há esse código em nossos dados\n");
    } else {
        printAtPosition(idWorker);
    }
}


void readAll(){
    for(register int i = 0; i < MAX_WORKERS; i++){
        printAtPosition(i);
    }
}


void readAllOrderByName(){
    int indexes[MAX_WORKERS];
    orderPositionsAlphabetically(indexes, name, MAX_WORKERS);

    for(register int i = 0; i < MAX_WORKERS; i ++){
        printAtPosition(indexes[i]);
    }
}


void teacherOrderByName(){
    int indexes[MAX_WORKERS];
    orderPositionsAlphabetically(indexes, name, MAX_WORKERS);

    for(register int i = 0; i < MAX_WORKERS; i ++){
        if(type[indexes[i]] == 2){
            printAtPosition(indexes[i]);
        }
    }
}


void technicianOrderByName(){
    int indexes[MAX_WORKERS];
    orderPositionsAlphabetically(indexes, name, MAX_WORKERS);

    for(register int i = 0; i < MAX_WORKERS; i ++){
        if(type[indexes[i]] == 1){
            printAtPosition(indexes[i]);
        }
    }
}




// Check if the value exists in the column specified and returns the index of where it finds it
int checkExists(char value[], int columnNumber){
    switch(columnNumber){
        //workerRegistrationNumber
        case 1:
            return findStringInArray(workerRegistrationNumber, MAX_WORKERS, value);
            break;
        //siape
        case 2:
            return findStringInArray(siape, MAX_WORKERS, value);
            break;
        //cpf
        case 3:
            return findStringInArray(cpf, MAX_WORKERS, value);
            break;
        //rg
        case 4:
            return findStringInArray(rg, MAX_WORKERS, value);
            break;
    }
}


// Shows each column in that position
void printAtPosition(int position){
    if(spaceWorkers[position] == 1){
        printf("\n%s\n", getDivider());

        printf("\nPosição %d\n", position + 1);

        printf("%-20s %s\n",   "Código do servidor:", workerRegistrationNumber[position]);
        printf("%-20s %s\n",   "SIAPE:", siape[position]);
        printf("%-20s %s\n",   "CPF:", cpf[position]);
        printf("%-20s %s\n",   "Nome:", name[position]);
        printf("%-20s %s\n",   "Data de Nascimento:", birthday[position]);
        printf("%-20s %s\n",   "RG:", rg[position]);
        printf("%-20s %s\n",   "Endereço:", address[position]);
        printf("%-20s %s\n",   "Salário:", wage[position]);

        switch(type[position]){
            case 0:
                printf("%-20s Vazio", "Tipo:");
                break;
            case 1:
                printf("%-20s Técnico Admnistrativo", "Tipo:");
                break;
            case 2:
                printf("%-20s Docente", "Tipo:");
                break;
        }

        printf("\n%s\n", getDivider());
    } else {
        printf("\nNão há nada na posição %d\n", position + 1);
    }
}


// Initialize columns deleting each position
void initializeWorkerColumns(){
    for(register int i = 0; i < MAX_WORKERS; i++){
        deleteServer(i);
    }
}

