#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "user_input/user_input.c"
#include "read/read.c"
#include "veiculo.h" 



// função para inserir um novo veículo
void insertVehicle(){
  // declare necessary variables
  char* description = malloc(255 * sizeof(char));
  char* licensePlate = malloc(255 * sizeof(char));
  char* brand = malloc(255 * sizeof(char));
  char* model = malloc(255 * sizeof(char));
  char* code = malloc(255 * sizeof(char));
  char* workerCode = malloc(255 * sizeof(char));

  // get the vehicle data
  code = generateUUID();
  workerCode = getWorkerCodeFromUserInput();
  description = getVehicleDescriptionFromUserInput();
  licensePlate = getVehicleLicensePlateFromUserInput();
  brand = getVehicleBrandFromUserInput();
  model = getVehicleModelFromUserInput();

  // get the first free firstFreeIndex in the parking lot
  int firstFreeIndex = getFirstVacantIndex(parkingSpaces, MAX_VEHICLES);

  strcpy(codeOfEachVehicle[firstFreeIndex], code);
  strcpy(descriptionOfEachVehicle[firstFreeIndex], description);
  strcpy(licensePlateOfEachVehicle[firstFreeIndex], licensePlate);
  strcpy(brandOfEachVehicle[firstFreeIndex], brand);
  strcpy(modelOfEachVehicle[firstFreeIndex], model);
  strcpy(workerRegistrationNumberOfVehicleOfEachVehicle[firstFreeIndex], workerCode);

  // mark the position as occupied
  parkingSpaces[firstFreeIndex] = true;

  // show the vehicle
  showVehicleByPosition(firstFreeIndex + 1);


  showBlockingMessage();
}

void readVehicleByPosition(){
  // get the position from the user
  int position = getPositionFromUserInput();
  // show the vehicle
  showVehicleByPosition(position);

  // block the terminal, so the user can read
  showBlockingMessage();

}

void readAllVehicles(){
  // show all vehicles
  showAllVehicles();

  // block the terminal, so the user can read
  showBlockingMessage();
}

// // função para alterar uma veículo existente 
void updateVehicle(){
  int position;

  // get the position from the user
  position = getPositionFromUserInput();

  char answer;
  printf("Deseja alterar a descrição do veículo? (s/n)\n");
  answer = getWillFromUserInput();
  if(answer == 's'){
    // get the new description from the user
    char* description = getVehicleDescriptionFromUserInput();
    // update the description
    strcpy(descriptionOfEachVehicle[position - 1], description);
  }

  printf("Deseja alterar a marca do veículo? (s/n)\n");
  answer = getWillFromUserInput();
  if(answer == 's'){
    // get the new brand from the user
    char* brand = getVehicleBrandFromUserInput();
    // update the brand
    strcpy(brandOfEachVehicle[position - 1], brand);
  }

  printf("Deseja alterar o modelo do veículo? (s/n)\n");
  answer = getWillFromUserInput();
  if(answer == 's'){
    // get the new model from the user
    char* model = getVehicleModelFromUserInput();
    // update the model
    strcpy(modelOfEachVehicle[position - 1], model);
  }

  printf("Deseja alterar a placa do veículo? (s/n)\n");
  answer = getWillFromUserInput();
  if(answer == 's'){
    // get the new license plate from the user
    char* licensePlate = getVehicleLicensePlateFromUserInput();
    // update the license plate
    strcpy(licensePlateOfEachVehicle[position - 1], licensePlate);
  }

  printf("Deseja alterar o código do trabalhador responsável pelo veículo? (s/n)\n");
  answer = getWillFromUserInput();
  if(answer == 's'){
    // get the new worker code from the user
    char* workerCode = getWorkerCodeFromUserInput();
    // update the worker code
    strcpy(workerRegistrationNumberOfVehicleOfEachVehicle[position - 1], workerCode);
  }

  // show the vehicle
  showVehicleByPosition(position);

  // block the terminal, so the user can read
  showBlockingMessage();
}



//  função para excluir uma veículo
void deleteVehicle(){
  // get the position from the user
  int position = getPositionFromUserInput();
  // mark the position as empty
  parkingSpaces[position - 1] = false;
  // show the vehicle
  showVehicleByPosition(position);

  // block the terminal, so the user can read
  showBlockingMessage();
}

// // função para mostrar/imprimir dados de uma veículo com base no código 
// void showVehicle(char vehicleRegistrationNumber[]);

// // função para mostrar/imprimir todas as veículos de um servidor
// void showVehiclesOfWorker(char workerRegistrationNumber[]);


// // Funções auxiliares

// // função verificadora de existência do veículo
// bool existsVehicle(char vehicleRegistrationNumber[]);

// // função verificadora de unicidade da descrição do veículo
// bool verifyDescriptionUniqueness(char description[]);

// // função para checar campos obrigatórios
// bool verifyRequiredFields(char vehicleRegistrationNumber[], char description[], char licensePlate[], char brand[], char model[]);

// // funções de tratamento de dados vindos do usuário
// void sanitizeVehicleRegistrationNumber(char vehicleRegistrationNumber[]);
// void sanitizeDescription(char description[]);
// void sanitizeLicensePlate(char licensePlate[]);
// void sanitizeBrand(char brand[]);
// void sanitizeModel(char model[]);
// void sanitizeWorkerRegistrationNumber(char workerRegistrationNumber[]);

// // função geradora de códigos de identificação de veículos
// void generateVehicleRegistrationNumber(char vehicleRegistrationNumber[]);

///////////////////////////////////////////////



