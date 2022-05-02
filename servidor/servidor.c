#include "servidor.h"

// Functions for Workers
// - inserir novo servidor --
bool insertNewServer(){
    int spaceIndex = findSpace(spaceWorkers, MAX_WORKERS);
    
    if(spaceIndex == -1){
        printf("\nNão há espaço disponível!\n");
        return false;
    } else {
        // Check if it has data
        if(alterServer(spaceIndex)){
            spaceWorkers[spaceIndex] = 1;
            return true;
        } else {
            return false;
        }
    }
}

// - alterar um servidor existente — 
bool alterServer(int position){
    // get Mandatory User Data
    char newWorkerRegistrationNumber[255] ;
    char newSiape[255];
    char newCpf[255];
    char newName[255];
    char newBirthday[255];

    // get Opcional User Data
    char newRg[255];
    char newAddress[255];
    float newWage;
    TypeWorker newType;

    strcpy(newWorkerRegistrationNumber, generateUUID());

    strcpy(newSiape, getMandatoryStringFieldFromUserInput(siape, "Insira número SIAPE:"));
    strcpy(newCpf, getMandatoryStringFieldFromUserInput(cpf, "Insira seu número de CPF:"));
    strcpy(newName, getMandatoryStringFieldFromUserInput(name, "Insira seu Nome:"));
    strcpy(newBirthday, getMandatoryStringFieldFromUserInput(birthday, "Insira sua data de aniversário"));


    strcpy(newRg, getMandatoryStringFieldFromUserInput(rg, "(opcional) Insira seu número de RG"));
    strcpy(newAddress, getMandatoryStringFieldFromUserInput(address, "(opcional) Insira seu endereço"));
    newWage = getFloatFieldFromUserInput(wage, "(opcional) Insira seu salário");

    int myVar = 0;
    myVar = getIntegerFieldFromUserInput(type, "(opcional) Insira seu tipo: \n0 - Nada\n 1- Docente\n 2- Técnico Admnistrativo\nResposta:");
    switch(myVar){
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

    printf("CODIGO: %s", newWorkerRegistrationNumber) ;  
    printf("\nSIAPE: %s", newSiape) ;  
    printf("CPF: %s", newCpf) ;  
    printf("NOME: %s", newName) ;  
    printf("ANIVERSARIO: %s", newBirthday) ;  
    printf("RG: %s", newRg) ;  
    printf("ENDEREÇO: %s", newAddress) ;  
    printf("SALÁRIO: %.2f", newWage) ;  
    printf("\nTIPO ENUM: %d", newType) ;  

    // TODO: retirar \n no fgets()

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
        printf("\nFALHA: Código, SIAPE ou CPF repetido\n");
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