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

  // get the first free position in the parking lot
  int position = getFirstVacantPosition(parkingSpaces, MAX_VEHICLES);

  strcpy(descriptionOfEachVehicle[position], description);
  strcpy(licensePlateOfEachVehicle[position], licensePlate);
  strcpy(brandOfEachVehicle[position], brand);
  strcpy(modelOfEachVehicle[position], model);
  strcpy(workerRegistrationNumberOfVehicleOfEachVehicle[position], workerCode);

  showVehicleByPosition(position);

  showBlockingMessage();
}

void readVehicleByPosition(){
  // get the position from the user
  int position = getPositionFromUserInput();
  // show the vehicle
  showVehicleByPosition(position - 1);

  // block the terminal, so the user can read
  showBlockingMessage();

}

// // função para alterar uma veículo existente 
// void updateVehicle(int position, char vehicleRegistrationNumber[], char description[], char licensePlate[], char brand[], char model[], char workerRegistrationNumber[]);

// // função para excluir uma veículo
// void deleteVehicle(int position);

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



