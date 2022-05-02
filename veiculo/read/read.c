
#include "../veiculo.h"

// função para mostrar/imprimir dados de uma veículo com base no código 
// void showVehicle(char vehicleRegistrationNumber[]);


// show vehicle by position
void showVehicleByPosition(int position){
    printf("%-20s\t%s\n", "Código:", codeOfEachVehicle[position]);
    printf("%-20s\t%s\n", "Descrição:", descriptionOfEachVehicle[position]);
    printf("%-20s\t%s\n", "Placa:", licensePlateOfEachVehicle[position]);
    printf("%-20s\t%s\n", "Marca:", brandOfEachVehicle[position]);
    printf("%-20s\t%s\n", "Modelo:", modelOfEachVehicle[position]);
    printf("%-20s\t%s\n", "Código do servidor:", workerRegistrationNumberOfVehicleOfEachVehicle[position]);
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
            showVehicleByPosition(i);
        }
    }
}





void showAllVehicles(){
    for(int i = 0; i < MAX_VEHICLES; i++){
        if(parkingSpaces[i]){
            showVehicleByPosition(i);
            printf("\n");
        }
    }
}


void showVehiclesOfWorkerInAlphabeticalOrder(char workerRegistrationNumber[]){

    int vehiclesOfWorker[MAX_VEHICLES];
    char descriptionsOfVehiclesOfWorker[MAX_VEHICLES][255];

    initializeIntArray(vehiclesOfWorker, MAX_VEHICLES);

    
    // first, get the positions of the vehicles of the worker

    // for each space that is occupied in the parking lot
    for(int i = 0; i < MAX_VEHICLES; i++){
        // if the worker registration number of the vehicle is the same as the worker registration number
        if(parkingSpaces[i] && strcmp(workerRegistrationNumberOfVehicleOfEachVehicle[i], workerRegistrationNumber) == 0){
            vehiclesOfWorker[i] = i;
        }
    }

    // get the descriptions of the vehicles of the worker
    for(int i = 0; i < MAX_VEHICLES; i++){
        if(parkingSpaces[i] && strcmp(workerRegistrationNumberOfVehicleOfEachVehicle[i], workerRegistrationNumber) == 0){
            strcpy(descriptionsOfVehiclesOfWorker[i], descriptionOfEachVehicle[i]);
        }
    }

    // sort the vehicles of the worker according to description alphabetically
    for(int i = 0; i < MAX_VEHICLES; i++){
        for(int j = 0; j < MAX_VEHICLES; j++){
            if(strcmp(descriptionsOfVehiclesOfWorker[i], descriptionsOfVehiclesOfWorker[j]) < 0){
                char aux[255];
                strcpy(aux, descriptionsOfVehiclesOfWorker[i]);
                strcpy(descriptionsOfVehiclesOfWorker[i], descriptionsOfVehiclesOfWorker[j]);
                strcpy(descriptionsOfVehiclesOfWorker[j], aux);

                int aux2 = vehiclesOfWorker[i];
                vehiclesOfWorker[i] = vehiclesOfWorker[j];
                vehiclesOfWorker[j] = aux2;
            }
        }
    }

    // show the vehicles of the worker
    for(int i = 0; i < MAX_VEHICLES; i++){
        if(vehiclesOfWorker[i] != 0){
            showVehicleByPosition(vehiclesOfWorker[i]);
        }
    }

}
