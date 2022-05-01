#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORKERS 20

typedef enum { docente, tecnico} tipoEnum;

// space flag array
bool space[MAX_WORKERS];

// obrigatórios
// código obrigatório do servidor e não podem existir dois códigos repetidos
int codigo[MAX_WORKERS];
// SIAPE obrigatório do servidor e não podem existir dois siapes repetidos
int siape[MAX_WORKERS];
// CPF obrigatório do servidor e não podem existir dois cpfs repetidos
int cpf[MAX_WORKERS];
// nome obrigatório do servidor
char nome[MAX_WORKERS];
// data nascimento obrigatório do servidor 
char dataNascimento[MAX_WORKERS];


// facultativos
// - RG 
int rg[MAX_WORKERS];
// - endereço 
char endereco[MAX_WORKERS];
// - salário 
float salario[MAX_WORKERS];
// - tipo (docente ou técnico administrativo) 
// enum tipoEnum[] tipo[MAX_WORKERS];


int main();
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
int techOrderByName();


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
