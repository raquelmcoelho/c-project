#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef MAX_VEHICLES 
#define MAX_VEHICLES 10
#endif

// vagas para veículos
bool parkingSpaces[MAX_VEHICLES];   


// Esse header é para o módulo de veículos
char codeOfEachVehicle[MAX_VEHICLES][255];
char descriptionOfEachVehicle[MAX_VEHICLES][255];
char licensePlateOfEachVehicle[MAX_VEHICLES][255];
char brandOfEachVehicle[MAX_VEHICLES][255];
char modelOfEachVehicle[MAX_VEHICLES][255];

// Opcionais
char workerRegistrationNumberOfVehicleOfEachVehicle[MAX_VEHICLES][255];

// função para inserir uma nova veículo
// void insertVehicle(char vehicleRegistrationNumber[], char description[], char licensePlate[], char brand[], char model[], char workerRegistrationNumber[]);
void insertVehicle();

// função para alterar uma veículo existente 
void updateVehicle();

// função para excluir uma veículo
void deleteVehicle();

void readVehiclesOfWorkerInAlphabeticalOrder();


// Funções auxiliares

// função verificadora de existência do veículo
bool existsVehicle(char vehicleRegistrationNumber[]);

// função verificadora de unicidade da descrição do veículo
bool verifyDescriptionUniqueness(char description[]);

// função para checar campos obrigatórios
bool verifyRequiredFields(char vehicleRegistrationNumber[], char description[], char licensePlate[], char brand[], char model[]);

// funções de traMAX_VEHICLESento de dados vindos do usuário
void sanitizeVehicleRegistrationNumber(char vehicleRegistrationNumber[]);
void sanitizeDescription(char description[]);
void sanitizeLicensePlate(char licensePlate[]);
void sanitizeBrand(char brand[]);
void sanitizeModel(char model[]);
void sanitizeWorkerRegistrationNumber(char workerRegistrationNumber[]);

// função geradora de códigos de identificação de veículos
void generateVehicleRegistrationNumber(char vehicleRegistrationNumber[]);



