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

    // integer of choice make by user from menu of options
    int choice = 0;

    // make sure the database starts empty
    initializeBoolArray(parkingSpaces, MAX_VEHICLES);
    initializeBoolArray(spaceWorkers, MAX_WORKERS);
    printBoolArray(parkingSpaces, MAX_VEHICLES);
    printBoolArray(spaceWorkers, MAX_WORKERS);

    // initialize columns of each table
    initializeWorkerColumns();
    // printf("%s\n", generateUUID());
    // printf("%s\n", sanitizeString(unsanitized_string));

    do
    {
        // menu of options
        printf("\n\nMENU\n");
        printf("%s1- Adicionar servidor     (inserir dados)                       %s\n", cyan, normal);
        printf("%s2- Alterar servidor       (inserir código e dados)              %s\n", cyan, normal);
        printf("%s3- Deletar servidor       (inserir código)                      %s\n", cyan, normal);
        printf("%s4- Ler servidor           (inserir código)                      %s\n", cyan, normal);
        printf("%s5- Ler todos servidores                                         %s\n", cyan, normal);
        printf("%s6- Ler todos servidores por ordem alfabética                    %s\n", cyan, normal);
        printf("%s7- Ler todos professores por ordem alfabética                   %s\n", cyan, normal);
        printf("%s8- Ler todos técnicos admnistrativos por ordem alfabética       %s\n", cyan, normal);
        printf("%s10- Adicionar veículo                                            %s\n", green, normal);
        printf("%s11- Alterar veículo                                             %s\n", green, normal);
        printf("%s12- Deletar veículo                                             %s\n", green, normal);
        printf("%s13- Ler veículo                                                 %s\n", green, normal);
        printf("%s14- Ler todos veículos                                          %s\n", green, normal);
        printf("%s15- Ler todos veículos por ordem alfabética                     %s\n", green, normal);
        printf("%s100- sair                                                       %s\n", red, normal);
        printf("%sEntre com o número da sua opção:                                %s\n", cyan, normal);
        char userInput[255];
        fgets(userInput, 255, stdin);
        choice = atoi(userInput);
        
        switch(choice){
            case 1:
                insertNewServer();
                break;
            case 2:
                alterServer(1);
                break;
            case 3:
                deleteServer(1);
                break;
            case 4:
                read("123");
                break;
            case 5:
                readAll();
                break;
            case 6:
                readAllOrderByName();
                break;
            case 7:
                teacherOrderByName();
                break;
            case 8:
                technicianOrderByName();
                break;
            case 10:
                insertVehicle();
                break;
            case 11:
                updateVehicle();
                break;
            case 12:
                deleteVehicle();
                break;
            case 13:
                readVehicleByPosition();
                break;
            case 14:
                readAllVehicles();
                break;
            default:
                printf("Entrada inválida\n");
                break;
        }
        
        // fflush(stdin);
        // showBlockingMessage();
    } while (choice != 100);

    exit(0);
}
