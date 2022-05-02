#include "servidor.h"

// Functions for Workers
// - inserir novo servidor --
bool insertNewServer(char newWorkerRegistrationNumber[], char newSiape[], char newCpf[], char newName[], char newBirthday[], char newRg[], char newAddress[], float newWage, TypeWorker newType){
    int spaceIndex = findSpace(spaceWorkers, MAX_WORKERS);
    if(spaceIndex == -1){
        printf("\nNão há espaço disponível!\n");
        return false;
    } else {
        // Check if it has data
        if(alterServer(spaceIndex, newWorkerRegistrationNumber, newSiape, newCpf, newName, newBirthday, newRg, newAddress, newWage, newType)){
            spaceWorkers[spaceIndex] = 1;
            return true;
        } else {
            printf("\nFALHA: Código, SIAPE ou CPF repetido\n");
            return false;
        }
    }
}

// - alterar um servidor existente — 
bool alterServer(int position, char newWorkerRegistrationNumber[], char newSiape[], char newCpf[], char newName[], char newBirthday[], char newRg[], char newAddress[], float newWage, TypeWorker newType){
    // Check if already exists registration number, cpf, siape and rg
    if((checkExists(newWorkerRegistrationNumber, 1) == -1) && (checkExists(newSiape, 2) == -1) && (checkExists(newCpf, 3) == -1)){ //} && (checkExists(newRg, 4) == -1)){
        strcpy(workerRegistrationNumber[position], newWorkerRegistrationNumber);
        strcpy(siape[position], newSiape);
        strcpy(cpf[position], newCpf);
        strcpy(name[position], newName);
        strcpy(birthday[position], newBirthday);
        strcpy(rg[position], newRg);
        strcpy(address[position], newAddress);
        wage[position] = newWage;
        type[position] = newType;
        return true;
    } else {
        return false;
    }
}

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
    type[position] = 0;

    spaceWorkers[position] = 0;
}

// - mostrar/imprimir dados de um servidor com base no código –
void read(char registrationNumber[]){
    printf("\nServidor de código: %s\n", registrationNumber);
    int idWorker = checkExists(registrationNumber, 1);

    if(idWorker == -1){
        printf("\nNão há esse código em nossos dados\n");
    } else {
        printAtPosition(idWorker);
    }
}
// - mostrar/imprimir todos os servidores -
void readAll(){
    for(register int i = 0; i < MAX_WORKERS; i++){
        printAtPosition(i);
    }
}

// // - mostrar/imprimir todos os servidores em ordem alfabética pelo nome - 
void readAllOrderByName(){
    int indexes[MAX_WORKERS];
    orderPositionsAlphabetically(indexes, name, MAX_WORKERS);

    for(register int i = 0; i < MAX_WORKERS; i ++){
        printAtPosition(indexes[i]);
    }
}
// - mostrar/imprimir todos os professores em ordem alfabética pelo nome -
void teacherOrderByName(){
    int indexes[MAX_WORKERS];
    orderPositionsAlphabetically(indexes, name, MAX_WORKERS);

    for(register int i = 0; i < MAX_WORKERS; i ++){
        if(type[indexes[i]] == 2){
            printAtPosition(indexes[i]);
        }
    }
}
// - mostrar/imprimir todos os técnicos administrativos em ordem alfabética pelo nome -
void technicianOrderByName(){
    int indexes[MAX_WORKERS];
    orderPositionsAlphabetically(indexes, name, MAX_WORKERS);

    for(register int i = 0; i < MAX_WORKERS; i ++){
        if(type[indexes[i]] == 1){
            printAtPosition(indexes[i]);
        }
    }
}





// Auxiliares
// - checar se existe codidgo, cpf, siape e retornar id da position-
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

// - checar campos obrigatórios e se estão preenchidas corretamente-
// bool checkItsComplete(int data){

// }


// - print at position -
void printAtPosition(int position){
    if(spaceWorkers[position] == 1){
        printf(line);

        printf("\nPosição %d\n", position);

        printf("Código do servidor: %s\n", workerRegistrationNumber[position]);
        printf("SIAPE:              %s\n", siape[position]);
        printf("CPF:                %s\n", cpf[position]);
        printf("Nome:               %s\n", name[position]);
        printf("Data de Nascimento: %s\n", birthday[position]);
        printf("RG:                 %s\n", rg[position]);
        printf("Endereço:           %s\n", address[position]);
        printf("Salário:            %.2f\n", wage[position]);

        switch(type[position]){
            case 0:
                printf("Tipo:            Vazio");
                break;
            case 1:
                printf("Tipo:            Técnico Admnistrativo");
                break;
            case 2:
                printf("Tipo:            Docente");
                break;
        }

        printf(line);
    }
}


// Facade to initialize columns with null value
void initializeWorkerColumns(){
    for(register int i = 0; i < MAX_WORKERS; i++){
        deleteServer(i);
    }
}