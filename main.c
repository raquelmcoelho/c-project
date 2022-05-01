#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#include "servidor/servidor.c"
#include "util/util.c"
#include "veiculo/veiculo.c"
#include "veiculo/veiculo.h"
#include "mock/mock.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int choice = 0;

    // make sure the database starts empty
    initializeArray(parkingSpaces, MAX_VEHICLES);
    initializeArray(spaceWorkers, MAX_WORKERS);
    printBoolArray(parkingSpaces, MAX_VEHICLES);
    printBoolArray(spaceWorkers, MAX_WORKERS);

    // initialize columns of each table
    initializeWorkerColumns();
    // printf("%s\n", generateUUID());
    // printf("%s\n", sanitizeString(unsanitized_string));

    do
    {
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
        printf("%s9- Adicionar veículo                               %s\n", green, normal);
        printf("%s10- Alterar veículo                                %s\n", green, normal);
        printf("%s11- Deletar veículo                                %s\n", green, normal);
        printf("%s12- Ler veículo pela posição                       %s\n", green, normal);
        printf("%s13- Ler todos veículos                             %s\n", green, normal);
        printf("%s14- Ler todos veículos por ordem alfabética        %s\n", green, normal);
        printf("%s100- sair                                          %s\n", red, normal);
        printf("%sEntre com o número da sua opção:                   %s\n", cyan, normal);
        // scanf("%d", &choice);
        char userInput[255];
        fgets(userInput, 255, stdin);
        choice = atoi(userInput);
        printf("Prosseguindo com %d\n", choice);
        
        switch(choice){
            case 1:
                insertNewServer("12345", "321", "091", "raquel", "15/1", "2018", "rua 123", 103.4);
                readAll();
                break;
            case 4:
                read("12345");
                break;
            case 5:
                readAll();
                break;
            default:
                printf("Entrada inválida\n");
                break;
            case 9:
                insertVehicle();
                break;
            case 12:
                readVehicleByPosition();
                break;
        }
        
        fflush(stdin);
        // system("PAUSE");
    } while (choice != 100);

    exit(0);
}
