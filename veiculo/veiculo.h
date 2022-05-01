#include "../utils/utils.h"

// Esse header é para o módulo de veículos

// Lista de flags de ocupação de vagas
// 0 - vaga livre
// 1 - vaga ocupada
boolean positions[TAM];

// Obrigatórios

char vehicleRegistrationNumber[TAM][255];
char description[TAM][255];
char licensePlate[TAM][255];
char brand[TAM][255];
char model[TAM][255];

// Opcionais
char workerRegistrationNumber[TAM][255];

// função para inserir uma nova veículo
void insertVehicle(char vehicleRegistrationNumber[], char description[], char licensePlate[], char brand[], char model[], char workerRegistrationNumber[]);

// função para alterar uma veículo existente 
void updateVehicle(int position, char vehicleRegistrationNumber[], char description[], char licensePlate[], char brand[], char model[], char workerRegistrationNumber[]);

// função para excluir uma veículo
void deleteVehicle(int position);

// função para mostrar/imprimir dados de uma veículo com base no código 
void showVehicle(char vehicleRegistrationNumber[]);

// função para mostrar/imprimir todas as veículos de um servidor
void showVehiclesOfWorker(char workerRegistrationNumber[]);


// Funções auxiliares

// função verificadora de existência do veículo
bool existsVehicle(char vehicleRegistrationNumber[]);

// função verificadora de unicidade da descrição do veículo
bool verifyDescriptionUniqueness(char description[]);

// função para checar campos obrigatórios
bool verifyRequiredFields(char vehicleRegistrationNumber[], char description[], char licensePlate[], char brand[], char model[]);

// funções de tratamento de dados vindos do usuário
void sanitizeVehicleRegistrationNumber(char vehicleRegistrationNumber[]);
void sanitizeDescription(char description[]);
void sanitizeLicensePlate(char licensePlate[]);
void sanitizeBrand(char brand[]);
void sanitizeModel(char model[]);
void sanitizeWorkerRegistrationNumber(char workerRegistrationNumber[]);

// função geradora de códigos de identificação de veículos
void generateVehicleRegistrationNumber(char vehicleRegistrationNumber[]);

