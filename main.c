#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#include "servidor/servidor.c"
#include "util/util.c"
#include "veiculo/veiculo.c"
#include "mock/mock.h"


int main() {
    setlocale(LC_ALL, "Portuguese");

    int choice = 0;

    // make sure the database starts empty
    initializeArray(spaceVehicles, MAX_VEHICLES);
    initializeArray(spaceWorkers, MAX_WORKERS);
    printArray(spaceVehicles, MAX_VEHICLES);
    printArray(spaceWorkers, MAX_WORKERS);
    
    do{
        // menu
        printf("\n\nMENU\n");
        printf("%s1- Adicionar servidor     (inserir dados)          %s\n", cyan, normal);
        printf("%s2- Alterar servidor       (inserir código e dados) %s\n", cyan, normal);
        printf("%s3- Deletar servidor       (inserir código)         %s\n", cyan, normal);
        printf("%s4- Ler servidor           (inserir código)         %s\n", cyan, normal);
        printf("%s5- Ler todos servidores                            %s\n", cyan, normal);
        printf("%s6- Ler todos servidores por ordem alfabética       %s\n", cyan, normal);
        printf("%s7- Ler todos professores por ordem alfabética      %s\n", cyan, normal);
        printf("%s8- Ler todos servidores por ordem alfabética       %s\n", cyan, normal);
        printf("%s100- sair                                          %s\n", cyan, normal);
        printf("%sEntre com o número da sua opção:                   %s\n", cyan, normal);
        scanf("%d", &choice);
        
        switch(choice){
            default:
                printf("Entrada inválida");
                break;
        }
        system("PAUSE");
    } while (choice != 100);

    exit(0);
}
