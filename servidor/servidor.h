#include "../util/util.h"


// Esse header é para o módulo de servidores

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
char wage[MAX_WORKERS][255];
// - tipo (docente ou técnico administrativo)
TypeWorker type[MAX_WORKERS];




// Functions for Workers
// - inserir novo servidor --
bool insertNewServer();
// - alterar um servidor existente — 
bool alterServer(int position);
// - excluir um servidor — 
void deleteServer(int position);
// - mostrar/imprimir dados de um servidor com base no código –
void read(); 
// - mostrar/imprimir todos os servidores -
void readAll();
// - mostrar/imprimir todos os servidores em ordem alfabética pelo nome - 
void readAllOrderByName();
// - mostrar/imprimir todos os professores em ordem alfabética pelo nome -
void teacherOrderByName();
// - mostrar/imprimir todos os técnicos administrativos em ordem alfabética pelo nome -
void technicianOrderByName();







// Auxiliares
// - checar se existe codigo, cpf, siape e retornar id da position-
int checkExists(char value[], int columnNumber);
// - print at position -
void printAtPosition(int position);
// Facade to initialize columns with null value
void initializeWorkerColumns();