#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* Função exit*/
#include <ctype.h> /* Função toupper*/
#include <locale.h>

#define ARQ "Dados.Dat" /* Arquivo com os dados*/

#define OP_INSERIR '1'
#define OP_ALTERAR '2'
#define OP_APAGAR  '3'
#define OP_LISTAR '4'
#define OP_PESQUISAR '5'

#define OP_SAIR '0'

#define OP_PESQ_IDADE '1'
#define OP_PESQ_NOME '2'



char *MainMenu[]={
	"1. Inserir Registro",
	"2. Alterar Registro",
	"3. Apagar Registro",
	"4. Listar Registros",
	"5. Pesquisas",
	"0. Sair",
	NULL	/* Acabaram as opções*/
};

char *PesqMenu[]={
	"1. Pesquisar por Intervalo  de Idade",
	"2. Pesquisar por Nome",
	"0. Voltar",
	NULL	/* Acabaram as opções*/ 	
};

FILE *fp; /*Variável Global pois é útil ao longo do programa*/

typedef struct
{
	char Nome[30+1];
	int Idade;
	float Salario;
	char Status; 	/*		'*' indica que o registro será apagado		*/
}PESSOA;


void Mensagem(char *msg);


/* Lê os dados  de um registro intrduzidos pelo usuário*/

void Ler_Pessoa(PESSOA *p)
{
	printf("Nome	: ");scanf("%s",&p->Nome);
	printf("Idade	: ");scanf("%d",&p->Idade);
	printf("Salário	: ");scanf("%f",&p->Salario);
	p->Status=' ';
	fflush(stdin);
}

/* Mostra na tela os dados existentes no registro*/

void Mostrar_Pessoa(PESSOA p)
{
	printf("%-30s  %3d  %10.2f\n",p.Nome,p.Idade,p.Salario);
}

/* Adiciona uma pessoa ao arquivo*/
void Adicionar_Pessoa (PESSOA p)
{
	fseek(fp,0L, SEEK_END);
	if(fwrite(&p,sizeof(p),1,fp)!=1)
		Mensagem("adicionar Pessoa: Falhou a escrita do registro");
}

/* Coloca uma mensagem na tela */
void Mensagem(char *msg)
{
	printf(msg);
	getchar();
}

/*
 *	Verifica se o Arquivo já existe. Se não existir, ele é criado
 * Se já existir, abre-o em Modo de Leitura e Escrita
 */

void Inic()
{
	fp=fopen(ARQ,"r+b"); /*Tentar Abrir*/
	if(fp==NULL)
	{
		fp=fopen(ARQ,"w+b");
		if(fp==NULL)
		{
			fprintf(stderr,"ERRO FATAL: Impossível Criar Arquivo de Dados\n");
			exit(1);
		}
	}
}

/*
 *Faz um Menu Simples com as opções do vetor de Strings
 *Seleciona a Opção, usando o primeiro caractere de cada string
 *Devolve o primeiro caractere da opção
 */
 
 char Menu(char *Opcoes[])
 {
 	int i;
 	char ch;
 	
 	while(1)
 	{  /*Cls*/
 		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
 		for(i=0;Opcoes[i]!=NULL; i++)
 		printf("\t\t%s\n\n",Opcoes[i]);
 		
 	printf("\n\n\tOpção: ");
 	ch=getchar(); fflush(stdin);
 	for(i=0; Opcoes[i]!=NULL; i++)
 	if(Opcoes[i][0]==ch)
 		return ch;
	 }
 }
 
 void Inserir_Pessoa()
 {
 	PESSOA x;
 	Ler_Pessoa(&x);
 	Adicionar_Pessoa(x);
 }
 
 void Alterar_Pessoa()
 {
 	PESSOA x;
 	long int n_reg;
	printf("Qual o Nº do Registro: ");
	scanf("%ld", &n_reg);fflush(stdin);
	if(fseek(fp, (n_reg-1)*sizeof(PESSOA),SEEK_SET)!=0)
		{
		Mensagem("Registro Inexistente ou Problemas no Posicionamento!!!");
		return;	
			
		}
	if(fread(&x,sizeof(PESSOA),1,fp)!=1)
	{
		Mensagem("Problemas na leitura do Registro!!!");
		return;
	}
	if(x.Status=='*')
	{
		Mensagem("Um Registro Apagado não pode ser alterado!!!\n\n");
		return;
	}
		
	printf("\n\nDados Atuais\n\n");
	Mostrar_Pessoa(x);
	printf("\n\nNovos Dados\n\n");
	Ler_Pessoa(&x);
	
	//Recuar um Registro no Arquivo
	fseek(fp,-(long) sizeof(PESSOA),SEEK_CUR);
	//Reescrever o Registro;
	fwrite(&x,sizeof(PESSOA),1,fp);
	fflush(fp); /*Despejar os Dados no Disco Rígido*/	 
 }
 
 void Apagar_Pessoa()
 {
 	PESSOA x;
 	long int n_reg;
 	char resp;
 	
 	printf("Qual o Nº do Registro:");
 	scanf("%ld", &n_reg);fflush(stdin);
 	
 	if(fseek(fp, (n_reg-1)*sizeof(PESSOA),SEEK_SET)!=0)
		{
		Mensagem("Registro Inexistente ou Problemas no Posicionamento!!!");
		return;	
			
		}
	if(fread(&x,sizeof(PESSOA),1,fp)!=1)
	{
		Mensagem("Problemas na leitura do Registro!!!");
		return;
	}
	if(x.Status=='*')
	{
		Mensagem("O registro já está apagado!!!\n\n");
		return;
	}
	
	printf("\n\nDados Atuais\n\n");
	Mostrar_Pessoa(x);
	
	printf("\n\nApagar o Registro (s/n)???: "); resp=getchar(); fflush(stdin);
	if (toupper(resp)!='S') return;
	
	x.Status='*';
		//Recuar um Registro no Arquivo
	fseek(fp,-(long) sizeof(PESSOA),SEEK_CUR);
	//Reescrever o Registro;
	fwrite(&x,sizeof(PESSOA),1,fp);
	fflush(fp); /*Despejar os Dados no Disco Rígido*/	
	
 }
 
 void Listar()
 {
 	long int N_Linhas=0;
 	PESSOA reg;
 	rewind(fp);
 	while(1)
 	{
 		if (fread(&reg,sizeof(reg),1,fp)!=1)break; /*Sair do Laço*/
 		if (reg.Status=='*')continue; /*Passa ao próximo registro*/
 		Mostrar_Pessoa(reg);
 		N_Linhas++;
 		if(N_Linhas%20==0)
 		Mensagem("PESSIONE <ENTER> para continuar	.	.	. ");
	 }
	Mensagem("PESSIONE <ENTER> para continuar	.	.	. "); /*No fim da Listagem*/ 
 }
 
 void Pesquisar_Idades (int ini, int fim)
{
	PESSOA reg;
	rewind(fp);
	
	while(fread(&reg,sizeof(PESSOA),1,fp))
	if(reg.Status!='*' && reg.Idade>=ini && reg.Idade<=fim)
		Mostrar_Pessoa(reg);
	
	Mensagem("PESSIONE <ENTER> para continuar	.	.	. "); /*No fim da Listagem*/		
 } 
 
 void Pesquisar_Nome(char *s)
 {
 	PESSOA reg;
 	rewind(fp);
 	
 	while(fread(&reg,sizeof(PESSOA),1,fp))
 	if(reg.Status!='*'&&strstr(reg.Nome,s))
 		Mostrar_Pessoa(reg);
 		
 	Mensagem("PESSIONE <ENTER> para continuar	.	.	. "); /*No fim da Listagem*/	
 }
 
 
 int main()
 {
 	setlocale(LC_ALL, "Portuguese");
 	char Opcao;
 	Inic();
 	while((Opcao=Menu(MainMenu))!=OP_SAIR)
 		switch(Opcao)
 		{
 			case OP_INSERIR: Inserir_Pessoa();break;
 			case OP_ALTERAR: Alterar_Pessoa();break;
 			case OP_APAGAR:  Apagar_Pessoa(); break;
 			case OP_LISTAR:  Listar(); break;
 			case OP_PESQUISAR:
 				while((Opcao=Menu(PesqMenu))!=OP_SAIR)
 				switch(Opcao)
 				{
 					case OP_PESQ_IDADE:
 						{
 							int n1,n2;
 							printf("Qual o intervalo de idades: ");
 							scanf("%d%d",&n1,&n2);fflush(stdin);
 							Pesquisar_Idades(n1,n2);
 							break; 
					 	}
					case OP_PESQ_NOME:
						{
							char string[BUFSIZ+1];
							printf("Qual o Nome a Procurar: ");
							fgets(string, 10 , stdin);fflush(stdin);
							Pesquisar_Nome(string);
						}
				 }
		 }
 }