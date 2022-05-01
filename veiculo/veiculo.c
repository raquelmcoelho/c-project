#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// get a mandatory field from the user
char* getMandatoryFieldFromUserInput(char* description){
  char* sanitizedString;
  do {
    fgets(description, 255, stdin);
    sanitizedString = removeTrailingAndLeadingSpaces(description);
  } while (sanitizedString[0] == '\n');
  return sanitizedString;
}

// get the vehicle description from the user
char* getVehicleDescriptionFromUserInput(){
  char description[255];
  printf("Digite a descrição do veículo: ");
  return getMandatoryFieldFromUserInput(description);
}

// get the vehicle brand from the user
char* getVehicleBrandFromUserInput(){
  char brand[255];
  printf("Digite a marca do veículo: ");
  return getMandatoryFieldFromUserInput(brand);
}

// get the vehicle license plate from the user
char* getVehicleLicensePlateFromUserInput(){
  char licensePlate[255];
  printf("Digite a placa do veículo: ");
  return getMandatoryFieldFromUserInput(licensePlate);
}

char* getVehicleModelFromUserInput(){
  char model[255];
  printf("Digite o modelo do veículo: ");
  return getMandatoryFieldFromUserInput(model);
}




// #define TAM 10

// // Esse header é para o módulo de veículos

// // Lista de flags de ocupação de vagas
// // 0 - vaga livre
// // 1 - vaga ocupada

// bool positions[TAM];

// // Obrigatórios

// char vehicleRegistrationNumber[TAM][255];
// char description[TAM][255];
// char licensePlate[TAM][255];
// char brand[TAM][255];
// char model[TAM][255];

// // Opcionais
// char workerRegistrationNumber[TAM][255];

// // função para inserir uma nova veículo
void insertVehicle(){
  char* description = malloc(255 * sizeof(char));
  char* licensePlate = malloc(255 * sizeof(char));
  char* brand = malloc(255 * sizeof(char));
  char* model = malloc(255 * sizeof(char));

  description = getVehicleDescriptionFromUserInput();
  licensePlate = getVehicleLicensePlateFromUserInput();
  brand = getVehicleBrandFromUserInput();
  model = getVehicleModelFromUserInput();

  printf("Os dados coletados foram: \n");
  printf("Descrição: %s\n", description);
  printf("Placa: %s\n", licensePlate);
  printf("Marca: %s\n", brand);
  printf("Modelo: %s\n", model);

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



