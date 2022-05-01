#include "servidor/servidor.h"
// #include "veiculo/veiculo.h"
#include <locale.h>

// space flag array
int space[TAM];

int findSpace();

int main() {
    setlocale(LC_ALL, "Portuguese");
    int choice = 0;
    char values[TAM][255];

    // preenchendo spaces como vazia
    for(register int i = 0; i < TAM; i++){
        printf("\nantes: %d", space[i]);
        space[i] = 0;
        strcpy(values[i], "vazio");
        printf("\ndepois: %d", space[i]);
    }
    
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
        
        int spaceIndex = findSpace(); 
        
        switch(choice){
            case 1:
                if(spaceIndex != -1){
                    printf("\n\n%s, entre com uma nova string: \n", values[spaceIndex]);
                    scanf("%255s", values[spaceIndex]);
                    printf("\n\n agora está assim: %s\n", values[spaceIndex]);
                    space[spaceIndex] = 1;
                } else {
                    printf("\nnão há espaço livre\n");
                }
                break;
            // case 2:
            //     break;
            // case 3:
            //     break;
            // case 4:
            //     break;
            case 5:
                for(register int j = 0; j < TAM; j++){
                    printf("%s\n", values[j]);
                }
                break;
            // case 6:
            //     break;
            // case 7:
            //     break;
            // case 8:
            //     break;
            default:
                printf("default\n");
                break;
        }
        system("PAUSE");
    } while (choice != 100);

    exit(0);
}

int findSpace(){
    for(register int i = 0; i < TAM; i++){
        if(space[i] == 0){
            printf("\ntem espaço no index: %d\n", i);
            return i;
        }
    }

    return -1;
}