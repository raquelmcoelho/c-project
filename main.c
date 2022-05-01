#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#include "servidor/servidor.c"
#include "util/util.c"
#include "veiculo/veiculo.c"
#include "mock/mock.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int choice = 0;

    // make sure the database starts empty
    initializeArray(spaceVehicles, MAX_VEHICLES);
    initializeArray(spaceWorkers, MAX_WORKERS);
    printBoolArray(spaceVehicles, MAX_VEHICLES);
    printBoolArray(spaceWorkers, MAX_WORKERS);
    printf("%s\n", generateUUID());
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
        printf("%s12- Ler veículo                                    %s\n", green, normal);
        printf("%s13- Ler todos veículos                             %s\n", green, normal);
        printf("%s14- Ler todos veículos por ordem alfabética        %s\n", green, normal);
        printf("%s100- sair                                          %s\n", red, normal);
        printf("%sEntre com o número da sua opção:                   %s\n", cyan, normal);
        scanf("%d", &choice);
        {
        
        switch(choice){
            case 1:
                insertNewServer("12345", "321", "091", "raquel", "15/1", "2018", "rua 123", 103.4);
                printStringArray(workerRegistrationNumber, MAX_WORKERS);
                printStringArray(workerRegistrationNumber, MAX_WORKERS);
                printStringArray(workerRegistrationNumber, MAX_WORKERS);
                printStringArray(siape, MAX_WORKERS);
                printStringArray(cpf, MAX_WORKERS);
                printStringArray(name, MAX_WORKERS);
                printStringArray(birthday, MAX_WORKERS);
                printStringArray(rg, MAX_WORKERS);
                printStringArray(address, MAX_WORKERS);
                printFloatArray(wage, MAX_WORKERS);
                
                break;
            default:
                printf("Entrada inválida\n");
                break;
        }
        system("PAUSE");
    } while (choice != 100);

    exit(0);
}
