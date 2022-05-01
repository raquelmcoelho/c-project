#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#include "servidor/servidor.c"
#include "util/util.c"
#include "veiculo/veiculo.c"


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
        printf("\x1B[31m1- Adicionar servidor     (inserir dados)\x1B[0m\n");
        printf("\x1B[32m2- Alterar servidor       (inserir codigo e dados)\x1B[0m\n");
        printf("\x1B[33m3- Deletar servidor       (inserir codigo)\x1B[0m\n");
        printf("\x1B[34m4- Ler servidor           (inserir codigo)\x1B[0m\n");
        printf("\x1B[35m5- Ler todos servidores\x1B[0m\n");
        printf("\x1B[36m6- Ler todos servidores por ordem alfabetica\x1B[0m\n");
        printf("\x1B[37m7- Ler todos professores por ordem alfabetica\x1B[0m\n");
        printf("8- Ler todos servidores por ordem alfabetica\n");
        printf("100- sair\n\n");
        printf("Entre com o número da sua opção:\n");
        scanf("%d", &choice);

        printf("agora choice esta assim %d\n", choice);
        
        switch(choice){
            default:
                printf("Entrada inválida");
                break;
        }
        system("PAUSE");
    } while (choice != 100);

    exit(0);
}
