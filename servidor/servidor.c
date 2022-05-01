#include "servidor.h"

// Functions for Workers
// - inserir novo servidor --
bool insertNewServer(char newWorkerRegistrationNumber[], char newSiape[], char newCpf[], char newName[], char newBirthday[], char newRg[], char newAddress[], float newWage){
    int spaceIndex = findSpace(spaceWorkers, MAX_WORKERS);
    if(spaceIndex == -1){
        printf("Doesn't has space");
        return false;
    } else {
        // Check if it has data
        // Check if already exists registration number, cpf, siape and rg
        if((checkExists(newWorkerRegistrationNumber, 1) == -1) && (checkExists(newSiape, 2) == -1) && (checkExists(newCpf, 3) == -1) && (checkExists(newRg, 4) == -1)){
            strcpy(workerRegistrationNumber[spaceIndex], newWorkerRegistrationNumber);
            strcpy(workerRegistrationNumber[spaceIndex], newWorkerRegistrationNumber);
            strcpy(siape[spaceIndex], newSiape);
            strcpy(cpf[spaceIndex], newCpf);
            strcpy(name[spaceIndex], newName);
            strcpy(birthday[spaceIndex], newBirthday);
            strcpy(rg[spaceIndex], newRg);
            strcpy(address[spaceIndex], newAddress);
            wage[spaceIndex] = newWage;

            spaceWorkers[spaceIndex] = 1;
            return true;
        }
    }
}

// // - alterar um servidor existente — 
// bool alterServer(int position, char newWorkerRegistrationNumber[], char newSiape[], char newCpf[], char newName[], char newBirthday[], char newRg[], char newAddress[], float newWage);

// - excluir um servidor — 
void deleteServer(int position){
    strcpy(workerRegistrationNumber[position], "vazio");
    strcpy(siape[position], "vazio");
    strcpy(cpf[position], "vazio");
    strcpy(name[position], "vazio");
    strcpy(birthday[position], "vazio");
    strcpy(rg[position], "vazio");
    strcpy(address[position], "vazio");
    wage[position] = 0.0;
}

// - mostrar/imprimir dados de um servidor com base no código –
void read(char registrationNumber[]){
    printf("\nServidor de código: %s\n", registrationNumber);
    int idWorker = checkExists(registrationNumber, 1);

    if(idWorker == -1){
        printf("\nNão conseguimos achar esse código\n");
    } else {
        printAtPosition(idWorker);
    }
}
// - mostrar/imprimir todos os servidores -
void readAll(){
    printf("\n---------------------------------------------------------------\n");
    for(register int i = 0; i < MAX_WORKERS; i++){
        printAtPosition(i);
    }
    printf("\n---------------------------------------------------------------\n");
}

// // - mostrar/imprimir todos os servidores em ordem alfabética pelo nome - 
void readAllOrderByName(){
    char lista[3][255] = {
        "maciel",
        "raquel",
        "coelho"
    };
    int indexes[3];
    orderPositionsAlphabetically(indexes, lista, 3);
    printStringArray(lista, 3);
    printIntArray(indexes, 3);
}
// // - mostrar/imprimir todos os professores em ordem alfabética pelo nome -
void teacherOrderByName(){
    
}
// // - mostrar/imprimir todos os técnicos administrativos em ordem alfabética pelo nome -
void techOrderByName(){
    
}


// Auxiliares
// - checar se existe codidgo, cpf, siape e retornar id da position-
int checkExists(char value[], int columnNumber){
    switch(columnNumber){
        //workerRegistrationNumber
        case 1:
            findStringInArray(workerRegistrationNumber, MAX_WORKERS, value);
            break;
        //siape
        case 2:
            findStringInArray(siape, MAX_WORKERS, value);
            break;
        //cpf
        case 3:
            findStringInArray(cpf, MAX_WORKERS, value);
            break;
        //rg
        case 4:
            findStringInArray(rg, MAX_WORKERS, value);
            break;

    }
}

// - checar campos obrigatórios e se estão preenchidas corretamente-
// bool checkItsComplete(int data);


// - print at position -
void printAtPosition(int position){
        printf("\nPosição %d\n", position);

        printf("Código do servidor: %s\n", workerRegistrationNumber[position]);
        printf("SIAPE:              %s\n", siape[position]);
        printf("CPF:                %s\n", cpf[position]);
        printf("Nome:               %s\n", name[position]);
        printf("Data de Nascimento: %s\n", birthday[position]);
        printf("RG:                 %s\n", rg[position]);
        printf("Endereço:           %s\n", address[position]);
        printf("Salário:            %.2f\n", wage[position]);
}


// Facade to initialize columns with null value
void initializeWorkerColumns(){
    for(register int i = 0; i < MAX_WORKERS; i++){
        deleteServer(i);
    }
}