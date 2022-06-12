// Exemplo de vetor de registros, com ponteiros e alocação de structs

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

const int NRO_CONTATOS = 5;

struct contato
{
    char nome[255];
    char sobre_nome[255];
    char fone[20];
    char email[50];
};

struct registro
{
    struct contato *contato;
    int livre;
};

void ler(char *msg, char *str)
{
    printf(msg);
    gets(str);
    fflush(stdin);
}

void inicia_contatos(struct registro registros[NRO_CONTATOS])
{
    for (int i = 0; i < NRO_CONTATOS; ++i)
    {
        registros[i].livre = 1;
    }
}

void libera_contatos(struct registro registros[NRO_CONTATOS])
{
    for (int i = 0; i < NRO_CONTATOS; ++i)
    {
        if (!registros[i].livre)
            free(registros[i].contato);
    }
}

void inserir_contato(struct registro registros[NRO_CONTATOS], struct contato cont)
{
    int index = -1;
    for (int i = 0; i < NRO_CONTATOS; ++i)
    {
        if (registros[i].livre)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Não há memória disponível!!!\n");
        return;
    }

    registros[index].contato = malloc(sizeof(struct contato));
    strcpy(registros[index].contato->nome, cont.nome);
    strcpy(registros[index].contato->sobre_nome, cont.sobre_nome);
    strcpy(registros[index].contato->fone, cont.fone);
    strcpy(registros[index].contato->email, cont.email);

    registros[index].livre = 0;
}

void inserir_contato_ui(struct registro registros[NRO_CONTATOS])
{
    struct contato cont;

    char nome[255];
    ler("nome: ", cont.nome);

    char sobre_nome[255];
    ler("sobrenome: ", cont.sobre_nome);

    char fone[255];
    ler("fone: ", cont.fone);

    char email[255];
    ler("email: ", cont.email);

    inserir_contato(registros, cont);
}

int remover_contato(struct registro registros[NRO_CONTATOS], char *nome)
{
    int index = -1;
    for (int i = 0; i < NRO_CONTATOS; ++i)
    {
        if (!strcmp(registros[i].contato->nome, nome))
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        return -1;
    }
    free(registros[index].contato);
    registros[index].contato = NULL;
    return 0;
}

void remover_contato_ui(struct registro registros[NRO_CONTATOS])
{
    char nome[255];
    ler("nome a remover: ", nome);

    int result = remover_contato(registros, nome);

    if (result == -1)
    {
        printf("Não há contato a ser removido com esse nome!!!\n");
    }
    else
    {
        printf("Contato removido com sucesso!!!\n");
    }
}

void listar_contatos(struct registro registros[NRO_CONTATOS])
{
    printf("############# LISTAGEM #################\n");
    for (int i = 0; i < NRO_CONTATOS; ++i)
    {
        if (!registros[i].livre)
        {
            struct contato *c = registros[i].contato;
            printf("[nome: %s, sobrenome: %s, fone: %s, email: %s]\n",
                   c->nome, c->sobre_nome, c->fone, c->email);
        }
    }
    printf("##########################################\n");
}

int main(int argc, char *argv[])
{
    struct registro registros[NRO_CONTATOS];
    inicia_contatos(registros);

    printf("tam. registro: %lu\n", sizeof(struct registro));
    printf("tam. contato: %lu\n", sizeof(struct contato));

    inserir_contato_ui(registros);
    listar_contatos(registros);

    inserir_contato_ui(registros);
    listar_contatos(registros);

    inserir_contato_ui(registros);
    listar_contatos(registros);

    inserir_contato_ui(registros);
    listar_contatos(registros);

    inserir_contato_ui(registros);
    listar_contatos(registros);

    remover_contato_ui(registros);
    listar_contatos(registros);

    inserir_contato_ui(registros);
    listar_contatos(registros);

    libera_contatos(registros);
    return 0;
}