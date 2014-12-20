// PROJECTO_BM_RC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h" // necessário para usar a função system("cls")
#include "string.h" // necessário para usar a função strcpy( , )
#include "locale.h"
#include "stdio.h" // necessário ao manipular ficheiros 

// Usar matrizes como variavel global
// O programa deve indicar quando uma Sala já está cheia, sendo que se devem considerar sempre 6 lugares livres para convidados.

int lugares[11][11];

int linhas[11] = {'A','B','C','D','E','F','G','H','I','J','K'};

int colunas[11];

int lugaresvagos; // Vamos usar isto nos ciclos para ir contando os lugares por inscrição e comparar com o máximo possível para cada sala, 110 na primeira, 55 na segunda (fora as outras condições).

typedef struct registo
{ 
	char nome[35];
	int idade[3];
	char nif;
	char email;
	char twitter;
	char telemovel[10];
	int tema[1];
};

registo getregisto();

registo getregisto()
{
	registo pessoa;
	printf("Insira o seu Nome:\n");
	scanf_s("%c", &pessoa. nome);
	printf("\nInsira a sua Idade:\n");
	scanf_s("%d", &pessoa. idade);
	printf("\nInsira o seu NIF:\n");
	scanf_s("%c", &pessoa. nif);
	printf("\nInsira o seu Email:\n");
	scanf_s("%c", &pessoa. email);
	printf("\nInsira o seu Twitter:\n");
	scanf_s("%c", &pessoa. twitter);
	printf("\nInsira o seu Telemóvel:\n");
	scanf_s("%c", &pessoa. telemovel);
	printf("\nEscolha o tema que vai tratar [Big Data - 0] ou [Data Mining - 1]:\n\n");
	scanf_s("%d", &pessoa. tema);
}

void visualizarbigdata()
{
	int lugares[11][11] = {
	{'_', '_', '_', '_', '_', '*', '_', '_', '_', '_', '_'},
	{'_', '_', '_', '_', '_', '*', '_', '_', '_', '_', '_'},
	{'_', '_', '_', '_', '_', '*', '_', '_', '_', '_', '_'},
	{'_', '_', '_', '_', '_', '*', '_', '_', '_', '_', '_'},
	{'_', '_', '_', '_', '_', '*', '_', '_', '_', '_', '_'},
	{'_', '_', '_', '_', '_', '*', '_', '_', '_', '_', '_'},
	{'_', '_', '_', '_', '_', '*', '_', '_', '_', '_', '_'},
	{'_', '_', '_', '_', '_', '*', '_', '_', '_', '_', '_'},
	{'_', '_', '_', '_', '_', '*', '_', '_', '_', '_', '_'},
	{'_', '_', '_', '_', '_', '*', '_', '_', '_', '_', '_'},
	{'_', '_', '_', '_', '_', '*', '_', '_', '_', '_', '_'},
	};
	int colunas[11] = {'1','2','3','4','5','*','6','7','8','9','10'};
}

void visualizardatamining()
{
	int lugares[11][7] = {
	{'*', '_', '_', '_', '_', '_', '*'},
	{'*', '_', '_', '_', '_', '_', '*'},
	{'*', '_', '_', '_', '_', '_', '*'},
	{'*', '_', '_', '_', '_', '_', '*'},
	{'*', '_', '_', '_', '_', '_', '*'},
	{'*', '_', '_', '_', '_', '_', '*'},
	{'*', '_', '_', '_', '_', '_', '*'},
	{'*', '_', '_', '_', '_', '_', '*'},
	{'*', '_', '_', '_', '_', '_', '*'},
	{'*', '_', '_', '_', '_', '_', '*'},
	{'*', '_', '_', '_', '_', '_', '*'},
	};
	int colunas[7] = {'*','1','2','3','4','5','*'};
}

void main()
{
	setlocale(LC_ALL, "Portuguese");
	int estado, estadoc, sala, selecao;
	do
	{
		printf("******************************************");
		printf("**	1 - Inscrição						**");
		printf("**	2 - Visualizar Sala 1 (Big Data)	**");
		printf("**	3 - Visualizar Sala 2 (Data Mining)	**");
		printf("**	4 - Sair							**");
		printf("******************************************");
		printf("Insira o número da opção que pretende:\n");
		scanf_s("%d", &selecao);
		if(selecao == 1)
		{
			printf("Identifique-se como Convidado [0] ou Conferencista [1]:\n");
			scanf_s("%d", &estado);
			if(estado == 0) 
			{
				printf("\nIdentifique-se como Segurança/Bombeiro [0] ou Convidado [1]:\n"); 
				scanf_s("%d", &estadoc);
			}
			else if(estado == 1) 
			{
				registo getregisto();
			}
		}
		else if(selecao == 2)
		{
			visualizarbigdata();
			for (int i = 0; i < sizeof lugares/sizeof lugares[0]; ++i)
			{
				for (int j = 0; j < sizeof lugares[0]/sizeof lugares[0][0]; ++j)
				{
					printf("%03d ", colunas);
					printf("%03d ", lugares[i][j]);
					printf("\n");
				}
			}
		}
		else if(selecao == 3)
		{
			visualizardatamining();
		}
		printf("Pretende voltar ao menú inicial?\n");
	}
	while(selecao != 4);
	printf("Obrigado por utilizar o programa!");
}
