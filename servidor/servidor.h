#include "../util/util.h"

// Obrigatórios
// código obrigatório do servidor e não podem existir dois códigos repetidos
int workerRegistrationNumber[MAX_WORKERS];
// SIAPE obrigatório do servidor e não podem existir dois siapes repetidos
int siape[MAX_WORKERS];
// CPF obrigatório do servidor e não podem existir dois cpfs repetidos
int cpf[MAX_WORKERS];
// nome obrigatório do servidor
char name[MAX_WORKERS];
// data nascimento obrigatório do servidor 
char birthday[MAX_WORKERS];

// Opcionais
// - RG 
int rg[MAX_WORKERS];
// - endereço 

char endereco[MAX_WORKERS];
// - salário 
float salario[MAX_WORKERS];
// - mostrar/imprimir todos os professores em ordem alfabética pelo nome -
int teacherOrderByName();
// - mostrar/imprimir todos os técnicos administrativos em ordem alfabética pelo nome -


// Auxialiares
// - gerar codigo automatico para cada novo servidor -
int generateCode();
// - checar se existe codidgo, cpf, siape -
int checkExists(int value, char columnName);
// - ordenar por nome -
int orderList(void *list);
// - checar se tem espaço -
int checkHasSpace();
// - checar campos obrigatórios e se estão preenchidas correMAX_WORKERSente-
int checkItsComplete(int data);
