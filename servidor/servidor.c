#include "servidor.h"



// - inserir novo servidor --
bool insertNewServer(){
    int spaceIndex = findSpace(spaceWorkers, MAX_WORKERS);
    
    if(spaceIndex == -1){
        printf("\nNão há espaço disponível!\n");
        return false;
    } else {
        if(alterServer(spaceIndex)){            
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
    char myVar[255];
    strcpy(myVar, "");
    strcpy(newSiape, getMandatoryStringFieldFromUserInput(myVar, "Insira número SIAPE:"));
    strcpy(newCpf, getMandatoryStringFieldFromUserInput(myVar, "Insira seu número de CPF:"));
    strcpy(newName, getMandatoryStringFieldFromUserInput(myVar, "Insira seu Nome:"));
    strcpy(newBirthday, getMandatoryStringFieldFromUserInput(myVar, "Insira sua data de aniversário"));
    strcpy(newRg, getStringFieldFromUserInput(myVar, "(opcional) Insira seu número de RG"));
    strcpy(newAddress, getStringFieldFromUserInput(myVar, "(opcional) Insira seu endereço"));

    newWage = getFloatFieldFromUserInput(myVar, "(opcional) Insira seu salário");

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

    printf("\nCODIGO: %s", newWorkerRegistrationNumber) ;  
    printf("\nSIAPE: %s", newSiape) ;  
    printf("\nCPF: %s", newCpf) ;  
    printf("\nNOME: %s", newName) ;  
    printf("\nANIVERSARIO: %s", newBirthday) ;  
    printf("\nRG: %s", newRg) ;  
    printf("\nENDEREÇO: %s", newAddress) ;  
    printf("\nSALÁRIO: %.2f", newWage) ;  
    printf("\nTIPO ENUM: %d", newType) ;  


    // Check if already exists registration number, cpf and siape
    if((checkExists(newWorkerRegistrationNumber, 1) == -1) && (checkExists(newSiape, 2) == -1) && (checkExists(newCpf, 3) == -1)){ //} && (checkExists(newRg, 4) == -1)){
        if(position == -1){
            char positionChar[255];
            do {
                position = getMandatoryIntegerFieldFromUserInput(positionChar, "Insira a posição desejada para armazenar os dados [1 a 20]:") - 1;
            } while (!(position < MAX_WORKERS && position >= 0));
        } 

        strcpy(workerRegistrationNumber[position], newWorkerRegistrationNumber);
        strcpy(siape[position], newSiape);
        strcpy(cpf[position], newCpf);
        strcpy(name[position], newName);
        strcpy(birthday[position], newBirthday);
        strcpy(rg[position], newRg);
        strcpy(address[position], newAddress);
        wage[position] = newWage;
        type[position] = newType;

        spaceWorkers[position] = 1;
        return true;
    } else {
        printf("\nFALHA: Código Gerado, SIAPE ou CPF repetido\n");
        return false;
    }
}

// - excluir um servidor — 
void deleteServer(int position){
    if(position == -1){
        char positionChar[255];
        do {
            position = getMandatoryIntegerFieldFromUserInput(positionChar, "Insira a posição desejada para deletar os dados [1 a 20]:") - 1;
            printf("%d", position);
        } while (!(position < MAX_WORKERS && position >= 0));
    } 

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
void read(){
    char registrationNumber[255];
    strcpy(registrationNumber, getMandatoryStringFieldFromUserInput(registrationNumber, "Insira o código do servidor a ser lido"));
    
    printf("\nServidor de código: {%s}\n", registrationNumber);
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


// - print at position -
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
        printf("%-20s %.2f\n", "Salário:", wage[position]);

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


// Facade to initialize columns with null value
void initializeWorkerColumns(){
    for(register int i = 0; i < MAX_WORKERS; i++){
        deleteServer(i);
    }
}

void seeDatabase(){
    printf("\nworkerRegistrationNumber:\n");
    printStringArray(workerRegistrationNumber, MAX_WORKERS);
    printf("\nsiape:\n");
    printStringArray(siape, MAX_WORKERS);
    printf("\ncpf:\n");
    printStringArray(cpf, MAX_WORKERS);
    printf("\nname:\n");
    printStringArray(name, MAX_WORKERS);
    printf("\nbirthday:\n");
    printStringArray(birthday, MAX_WORKERS);
    printf("\nrg:\n");
    printStringArray(rg, MAX_WORKERS);
    printf("\naddress:\n");
    printStringArray(address, MAX_WORKERS);
    printf("\nwage:\n");
    printFloatArray(wage, MAX_WORKERS);
    printf("\ntype:\n");
    printIntArray(type, MAX_WORKERS);
    printf("\nspaceWorkers:\n");
    printBoolArray(spaceWorkers, MAX_WORKERS);
}