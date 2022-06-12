
#include "../../veiculo.h"

// função para mostrar/imprimir dados de uma veículo com base no código 
// void showVehicle(char vehicleRegistrationNumber[]);


// show vehicle by position
void showVehicleByPosition(int position){
    if(parkingSpaces[position - 1]){
        printf("Veículo na %dª posição: \n", position);
        printf("%-20s\t%s\n", "Código:", codeOfEachVehicle[position - 1]);
        printf("%-20s\t%s\n", "Descrição:", descriptionOfEachVehicle[position - 1]);
        printf("%-20s\t%s\n", "Placa:", licensePlateOfEachVehicle[position - 1]);
        printf("%-20s\t%s\n", "Marca:", brandOfEachVehicle[position - 1]);
        printf("%-20s\t%s\n", "Modelo:", modelOfEachVehicle[position - 1]);
        printf("%-20s\t%s\n", "Código do servidor:", workerRegistrationNumberOfVehicleOfEachVehicle[position - 1]);
        printf("%s\n", getDivider());
    } else {
        printf("\nNão há nada na posição %d\n", position);
    }
}

// show vehicles of worker
void showVehiclesOfWorker(char workerRegistrationNumber[]){
    // for each space that is occupied in the parking lot
    for(int i = 0; i < MAX_VEHICLES; i++){
        // if the worker registration number of the vehicle is the same as the worker registration number
        if(parkingSpaces[i] && strcmp(workerRegistrationNumberOfVehicleOfEachVehicle[i], workerRegistrationNumber) == 0){
            showVehicleByPosition(i);
        }
    }
}


void showVehicleByCode(char code[]){
    // for each space that is occupied in the parking lot
    for(int i = 0; i < MAX_VEHICLES; i++){
        // if the code of the vehicle is the same as the code
        if(parkingSpaces[i] && strcmp(codeOfEachVehicle[i], code) == 0){
            showVehicleByPosition(i + 1);
        }
    }
}





void showAllVehicles(){
    for(int i = 0; i < MAX_VEHICLES; i++){
        showVehicleByPosition(i + 1);
    }
}

void orderCodesLikeTheDescriptionsAlphabetically(char** codeOfEachVehicleCopy){
    char** descriptionOfEachVehicleCopy = (char**) malloc(255 * sizeof(char*));

    // copy the description array
    for(int i = 0; i < MAX_VEHICLES; i++){
        descriptionOfEachVehicleCopy[i] = malloc(sizeof(char) * 255);
        strcpy(descriptionOfEachVehicleCopy[i], descriptionOfEachVehicle[i]);
    }

    // copy the code array
    for(int i = 0; i < MAX_VEHICLES; i++){
        codeOfEachVehicleCopy[i] = malloc(sizeof(char) * 255);
        strcpy(codeOfEachVehicleCopy[i], codeOfEachVehicle[i]);
    }

    // sort the description array alphabetically, ordering also the code array so
    // the code of each vehicle is in the same position as the description
    for(int i = 0; i < MAX_VEHICLES; i++){
        for(int j = 0; j < MAX_VEHICLES; j++){
            if(strcmp(descriptionOfEachVehicleCopy[i], descriptionOfEachVehicleCopy[j]) < 0){
                char* temp = descriptionOfEachVehicleCopy[i];
                descriptionOfEachVehicleCopy[i] = descriptionOfEachVehicleCopy[j];
                descriptionOfEachVehicleCopy[j] = temp;

                temp = codeOfEachVehicleCopy[i];
                codeOfEachVehicleCopy[i] = codeOfEachVehicleCopy[j];
                codeOfEachVehicleCopy[j] = temp;
            }
        }
    }
}

void orderWorkerCodesLikeTheDescriptionsAlphabetically(char** workerRegistrationNumberOfVehicleOfEachVehicleCopy){
    char** descriptionOfEachVehicleCopy = (char**) malloc(255 * sizeof(char*));

    // copy the description array
    for(int i = 0; i < MAX_VEHICLES; i++){
        descriptionOfEachVehicleCopy[i] = malloc(sizeof(char) * 255);
        strcpy(descriptionOfEachVehicleCopy[i], descriptionOfEachVehicle[i]);
    }

    // copy the code array
    for(int i = 0; i < MAX_VEHICLES; i++){
        workerRegistrationNumberOfVehicleOfEachVehicleCopy[i] = malloc(sizeof(char) * 255);
        strcpy(workerRegistrationNumberOfVehicleOfEachVehicleCopy[i], workerRegistrationNumberOfVehicleOfEachVehicle[i]);
    }

    // sort the description array alphabetically, ordering also the code array so
    // the code of each vehicle is in the same position as the description
    for(int i = 0; i < MAX_VEHICLES; i++){
        for(int j = 0; j < MAX_VEHICLES; j++){
            if(strcmp(descriptionOfEachVehicleCopy[i], descriptionOfEachVehicleCopy[j]) < 0){
                char* temp = descriptionOfEachVehicleCopy[i];
                descriptionOfEachVehicleCopy[i] = descriptionOfEachVehicleCopy[j];
                descriptionOfEachVehicleCopy[j] = temp;

                temp = workerRegistrationNumberOfVehicleOfEachVehicleCopy[i];
                workerRegistrationNumberOfVehicleOfEachVehicleCopy[i] = workerRegistrationNumberOfVehicleOfEachVehicleCopy[j];
                workerRegistrationNumberOfVehicleOfEachVehicleCopy[j] = temp;
            }
        }
    }
}

void showVehiclesOfWorkerInAlphabeticalOrder(char workerRegistrationNumber[]){
    char** codeOfEachVehicleCopy = (char**) malloc(255 * sizeof(char*));
    char** workerRegistrationNumberOfVehicleOfEachVehicleCopy = (char**) malloc(255 * sizeof(char*));

    orderCodesLikeTheDescriptionsAlphabetically(codeOfEachVehicleCopy);
    orderWorkerCodesLikeTheDescriptionsAlphabetically(workerRegistrationNumberOfVehicleOfEachVehicleCopy);
    // for each code, show the vehicle
    for(int i = 0; i < MAX_VEHICLES; i++){
        if(strcmp(workerRegistrationNumberOfVehicleOfEachVehicleCopy[i], workerRegistrationNumber) == 0){
            showVehicleByCode(codeOfEachVehicleCopy[i]);
        }
    }   
}


void showVehiclesInAlphabeticalOrder(){
    char** codeOfEachVehicleCopy = (char**) malloc(255 * sizeof(char*));
    orderCodesLikeTheDescriptionsAlphabetically(codeOfEachVehicleCopy);
    // for each code, show the vehicle
    for(int i = 0; i < MAX_VEHICLES; i++){
        showVehicleByCode(codeOfEachVehicleCopy[i]);
    }    
}
