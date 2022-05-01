#include "../util/util.h"

// Obrigatórios
// código obrigatório do servidor e não podem existir dois códigos repetidos
char workerRegistrationNumber[MAX_WORKERS][255];
// SIAPE obrigatório do servidor e não podem existir dois siapes repetidos
char siape[MAX_WORKERS][255];
// CPF obrigatório do servidor e não podem existir dois cpfs repetidos
char cpf[MAX_WORKERS][255];
// nome obrigatório do servidor
char name[MAX_WORKERS][255];
// data nascimento obrigatório do servidor 
char birthday[MAX_WORKERS][255];

// Opcionais
// - RG 
char rg[MAX_WORKERS][255];
// - endereço 
char address[MAX_WORKERS][255];
// - salário 
float wage[MAX_WORKERS];


// Functions for Workers
// - inserir novo servidor --
bool insertNewServer(char newWorkerRegistrationNumber[], char newSiape[], char newCpf[], char newName[], char newBirthday[], char newRg[], char newAddress[], float newWage);
// - alterar um servidor existente — 
bool alterServer(int position, char newWorkerRegistrationNumber[], char newSiape[], char newCpf[], char newName[], char newBirthday[], char newRg[], char newAddress[], float newWage);
// - excluir um servidor — 
bool deleteServer(int position);
// - mostrar/imprimir dados de um servidor com base no código –
void read(int registrationNumber); 
// - mostrar/imprimir todos os servidores -
void readAll();
// - mostrar/imprimir todos os servidores em ordem alfabética pelo nome - 
void readAllOrderByName();
// - mostrar/imprimir todos os professores em ordem alfabética pelo nome -
void teacherOrderByName();
// - mostrar/imprimir todos os técnicos administrativos em ordem alfabética pelo nome -
void techOrderByName();


// Auxialiares
// - checar se existe codidgo, cpf, siape -
bool checkExists(int value, char columnName);

// - checar campos obrigatórios e se estão preenchidas corretamente-
bool checkItsComplete(int data);