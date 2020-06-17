#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "biblioteca.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */




int main(int argc, char *argv[]) {





float escolha,controle;
int tam_vetor,posicao,posicao_p,compra;

ler_tamanho_v(&tam_vetor);

Cliente clientes[tam_vetor];

Produto produtos[5];

ler_clientes(clientes,tam_vetor);

ler_produtos(produtos,5);

do
{
	printf("\n informe a opcao desejada\n1-cadastro cliente\n2-login cliente \n5-sair\n");
	fflush(stdin);
	scanf("%f",&escolha);
	fflush(stdin);
	if(escolha==1)
	{
	cadastro(&clientes[tam_vetor-1]);		
	controle =1;
	}
	else if(escolha==2)
	{
		char comp_s[10],comp_l[10],comp_p[100];
		printf("digite seu login\n");
		fflush(stdin);
		gets(comp_l);
		fflush(stdin);
		printf("digite a senha\n");
		gets(comp_s);
		fflush(stdin);
		int erro =0;
		for(int x=0;x<tam_vetor;x++)
		{
			if(strcmp(comp_l,clientes[x].nome)==0&&strcmp(comp_s,clientes[x].senha)==0)
			{
				printf("\ncomprar");
				for(int x=0;x<5;x++)
				{
					printf("\nnome : %s\npreco : %f \n quantidade : %i\n\n",produtos[x].nome,produtos[x].preco,produtos[x].qte);
					fflush(stdin);
					posicao=x;
				}
				printf("\ninforme o nome do produto\n");			
				gets(comp_p);
				fflush(stdin);
				for(int x=0;x<5;x++)
				{
					if(strcmp(comp_p,produtos[x].nome)==0)
					{
						posicao_p=x;		
					}
				}
				printf("\ninforme  a qtd\n");
				fflush(stdin);
				scanf("%i",&compra);
				produtos[posicao_p].qte = produtos[posicao_p].qte-compra;
				clientes[posicao].compras =clientes[posicao].compras + produtos[posicao_p].preco*compra;	
			}
			else 
			{
				erro++;
			}	
		}			
		if(erro==tam_vetor)
		{
			printf("\nsenha ou login errados!!\n");
		}
	}
	
}while(escolha!=5);
fflush(stdin);
if(controle==1)
{
	tam_vetor++;
}

escrever_clientes(clientes,tam_vetor);

escrever_produtos(produtos,5);

escrever_tam_vetor(&tam_vetor);

	return 0;
}
