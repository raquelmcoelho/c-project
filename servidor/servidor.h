#include "../utils/utils.h"

// Obrigatórios
// código obrigatório do servidor e não podem existir dois códigos repetidos
int workerRegistrationNumber[TAM];
// SIAPE obrigatório do servidor e não podem existir dois siapes repetidos
int siape[TAM];
// CPF obrigatório do servidor e não podem existir dois cpfs repetidos
int cpf[TAM];
// nome obrigatório do servidor
char name[TAM];
// data nascimento obrigatório do servidor 
char birthday[TAM];

// Opcionais
// - RG 
int rg[TAM];
// - endereço 
char address[TAM];
// - salário 
float wage[TAM];
// - tipo (docente ou técnico administrativo) 
TypeWorker typeWorker[TAM];

// - inserir novo servidor --
int insertNewServer(int data);
// - alterar um servidor existente — 
int alterServer(int position, int data);
// - excluir um servidor — 
int deleteServer(int position);
// - mostrar/imprimir dados de um servidor com base no código –
int read(int codigo); 
// - mostrar/imprimir todos os servidores -
int readAll();
// - mostrar/imprimir todos os servidores em ordem alfabética pelo nome - 
int readAllOrderByName();
// - mostrar/imprimir todos os professores em ordem alfabética pelo nome -
int teacherOrderByName();
// - mostrar/imprimir todos os técnicos administrativos em ordem alfabética pelo nome -
int technicianOrderByName();


// Auxialiares
// - gerar codigo automatico para cada novo servidor -
int generateCode();
// - checar se existe codidgo, cpf, siape -
int checkExists(int value, char columnName);
// - ordenar por nome -
int orderList(void *list);
// - checar se tem espaço -
int checkHasSpace();
// - checar campos obrigatórios e se estão preenchidas corretamente-
int checkItsComplete(int data);
