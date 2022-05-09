#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

// #include "servidor/servidor.h"
#include "servidor/servidor.c"
#include "util/util.c"
#include "veiculo/veiculo.c"
#include "veiculo/veiculo.h"

int main(){
    // set the language to portuguese
    setlocale(LC_ALL, "Portuguese");

    // integer of choice make by user from menu of options
    int choice = 0;

    // make sure the database starts empty
    initializeBoolArray(parkingSpaces, MAX_VEHICLES);
    initializeBoolArray(spaceWorkers, MAX_WORKERS);

    // initialize columns of each table
    initializeWorkerColumns();

    // shows the menu of options, at least one time
    do{
        // menu of options
        printf("\n\nMENU\n");
        printf("%s1- Adicionar servidor                                           %s\n", cyan, normal);
        printf("%s2- Alterar servidor                                             %s\n", cyan, normal);
        printf("%s3- Deletar servidor                                             %s\n", cyan, normal);
        printf("%s4- Ler servidor                                                 %s\n", cyan, normal);
        printf("%s5- Ler todos servidores                                         %s\n", cyan, normal);
        printf("%s6- Ler todos servidores por ordem alfabética                    %s\n", cyan, normal);
        printf("%s7- Ler todos professores por ordem alfabética                   %s\n", cyan, normal);
        printf("%s8- Ler todos técnicos admnistrativos por ordem alfabética       %s\n", cyan, normal);
        printf("%s10- Adicionar veículo                                           %s\n", green, normal);
        printf("%s11- Alterar veículo                                             %s\n", green, normal);
        printf("%s12- Deletar veículo                                             %s\n", green, normal);
        printf("%s13- Ler veículo                                                 %s\n", green, normal);
        printf("%s14- Ler todos veículos                                          %s\n", green, normal);
        printf("%s15- Ler os veículos de um servidor em ordem alfabética          %s\n", green, normal);
        printf("%s16- Ler os veículos em ordem alfabética                         %s\n", green, normal);
        printf("%s100- sair                                                       %s\n", red, normal);
        printf("%sEntre com o número da sua opção:                                %s\n", cyan, normal);

        char userInput[255];
        // get the user input
        fgets(userInput, 255, stdin);
        // convert the input to an integer
        choice = atoi(userInput);
        
        switch(choice){
            case 1:
                // add a worker
                insertNewServer();
                break;
            case 2:
                // alter a worker
                alterServer(-1);
                break;
            case 3:
                // delete a worker
                deleteServer(-1);
                break;
            case 4:
                // read a worker
                read();
                break;
            case 5:
                // read all workers
                readAll();
                break;
            case 6:
                // read all workers by alphabetical order
                readAllOrderByName();
                break;
            case 7:
                // read all professors by alphabetical order
                teacherOrderByName();
                break;
            case 8:
                // read all technicians by alphabetical order
                technicianOrderByName();
                break;
            case 10:
                // add a vehicle
                insertVehicle();
                break;
            case 11:
                // alter a vehicle
                updateVehicle();
                break;
            case 12:
                // delete a vehicle
                deleteVehicle();
                break;
            case 13:
                // read a vehicle
                readVehicleByPosition();
                break;
            case 14:
                // read all vehicles
                readAllVehicles();
                break;
            case 15:      
                // read all vehicles of a worker by alphabetical order      
                readVehiclesOfWorkerInAlphabeticalOrder();
                break;
            case 16:
                // read all vehicles in alphabetical order
                readVehiclesInAlphabeticalOrder();
                break;
            case 100:
                // exit
                printf("\n%sAté a próxima ☻♥%s\n", yellow, normal);
                exit(0);
            default:
                // invalid input
                printf("Entrada inválida\n");
                break;
        }
        // clear the standard input to avoid problems
        fflush(stdin);
        // block the program until the user presses enter
        // so the user can see the output
        showBlockingMessage();
    } while (choice != 100);
}
