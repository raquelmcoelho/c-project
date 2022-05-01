#include "servidor.h"


/*


Módulo de Servidores -> Responsável: Raquel Maciel Coelho de Sousa
- função para inserir um novo servidor 
- função para alterar um servidor existente 
- função para excluir um servidor 
- função para mostrar/imprimir dados de um servidor com base no código 
- função para mostrar/imprimir todos os servidores 
- função para mostrar/imprimir todos os servidores em ordem alfabética pelo nome
- função para mostrar/imprimir todos os professores em ordem alfabética pelo nome  
- função para mostrar/imprimir todos os técnicos administrativos em ordem alfabética pelo nome 
- função para verificar a unicidade do código do servidor
- função para verificar a unicidade do CPF do servidor
- função para verificar a unicidade do SIAPE do servidor
- função para checar campos obrigatórios
- funções de tratamento de dados vindos do usuário
- função geradora de códigos de identificação de servidor

*/


// Functions for Workers
// Functions for Workers
// - inserir novo servidor --
bool insertNewServer(char newWorkerRegistrationNumber[], char newSiape[], char newCpf[], char newName[], char newBirthday[], char newRg[], char newAddress[], float newWage){
    int spaceIndex = findSpace(spaceWorkers, MAX_WORKERS);
    if(spaceIndex == -1){
        printf("Doesn't has space");
        return false;
    } else {
        // Check if already exists registration number, cpf, siape and rg
        // Check if it has data
        strcpy(workerRegistrationNumber[spaceIndex], newWorkerRegistrationNumber);
        strcpy(workerRegistrationNumber[spaceIndex], newWorkerRegistrationNumber);
        strcpy(siape[spaceIndex], newSiape);
        strcpy(cpf[spaceIndex], newCpf);
        strcpy(name[spaceIndex], newName);
        strcpy(birthday[spaceIndex], newBirthday);
        strcpy(rg[spaceIndex], newRg);
        strcpy(address[spaceIndex], newAddress);
        wage[spaceIndex] = newWage;
        spaceWorkers[spaceIndex] = 1;
        return true;
    }
}
// // - alterar um servidor existente — 
// bool alterServer(int position, char newWorkerRegistrationNumber[], char newSiape[], char newCpf[], char newName[], char newBirthday[], char newRg[], char newAddress[], float newWage);
// // - excluir um servidor — 
// bool deleteServer(int position);
// // - mostrar/imprimir dados de um servidor com base no código –
// void read(int registrationNumber); 
// // - mostrar/imprimir todos os servidores -
// void readAll();
// // - mostrar/imprimir todos os servidores em ordem alfabética pelo nome - 
// void readAllOrderByName();
// // - mostrar/imprimir todos os professores em ordem alfabética pelo nome -
// void teacherOrderByName();
// // - mostrar/imprimir todos os técnicos administrativos em ordem alfabética pelo nome -
// void techOrderByName();
