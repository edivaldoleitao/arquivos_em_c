#ifndef bibilioteca_h
#define biblioteca_h 

typedef struct
{
	char nome[100];
	float preco;
	int qte; 

}Produto;


///////////////////////////    estrutura do cliente 
typedef struct
{
	char nome[100];
	char senha[10];
	float compras;
	int status ;
	}Cliente;



int menu_principal()
{
	int x;
	printf("escolha o tipo de acesso ou encerrar sessao \n1-administrador\n2-cliente\n3-sair");
	scanf("%i",&x);
	if(x==1||x==2||x==3)
	{
		return x ;
	}
	else
	{
		system("cls");
		printf("\nopcao invalida");
		getch();
		return 0;
	}
	
}


int login_adm()
{
	int comp,comp2;
	char senha1[5],nick1[5];
	
	char nick[5]="adm20";
	char senha[5] = "1234a";
	printf("digite o nome de usuario\n");
	fflush(stdin);
	gets(nick1);
	fflush(stdin);
	printf("\ndigite a senha\n");
	gets(senha1);
	fflush(stdin);
	
	comp=strcmp(nick,nick1);
	comp2=strcmp(senha,senha1);
	
	if((comp==0)&&(comp2==0))
	{
		return 1;
	}
	else
	{
		printf("\nsenha ou login incorreto!!\n");
			
	}
	
}




///////////////////////////////////////////////////////////     le o tamnho do vetor
void ler_tamanho_v(int* v)
{
	FILE *arq1;
	arq1=fopen("qte1.txt","r");
	fscanf(arq1,"%i",&*v);
	fclose(arq1);
}
/////////////////////////////////////////////////////// cadastrar cliente///////////////nao precisa usar * para alterar na posicao
void cadastro(Cliente* c)
{
	printf("digite seu login\n");
	fflush(stdin);
	gets(c->nome);
	fflush(stdin);
	printf("digite sua senha\n");
	fflush(stdin);
	gets(c->senha);
	fflush(stdin);
}
//////////////////////////////////////////////   escreve tamanho do vetor
void escrever_tam_vetor(int* tam)
{
	FILE *arq;
	arq=fopen("qte1.txt","w");
	fprintf(arq,"%i",*tam);
	fclose(arq);
}
////////////////////////////////////////////    escreve os clentes no arquivo
void escrever_clientes(Cliente c[],int v)
{
	FILE *arq;
	arq=fopen("clientes.txt","w");
	for(int x=0;x<v;x++)
	{
		fprintf(arq,"%s %s %f %i \n",c[x].nome,c[x].senha,c[x].compras,c[x].status);
	}
	fclose(arq);
}

////////////////////////////////  le clientes do arquivo

void ler_clientes(Cliente c[],int v)
{
	FILE *arq;
	arq=fopen("clientes.txt","r");
	for(int x=0;x<v;x++)
	{
		fscanf(arq,"%s %s %f %i \n",c[x].nome,c[x].senha,&c[x].compras,&c[x].status);
	}
	fclose(arq);
	
}
//////////////////////////////////////////////////////////////// le os produtos
void ler_produtos(Produto p[],int qt)
{
	FILE *arq;
	arq=fopen("produtos.txt","r");
	for(int x=0;x<qt;x++)
	{
		fscanf(arq,"%s %f %i",p[x].nome,&p[x].preco,&p[x].qte);
	}
	fclose(arq);
}
/////////////////////////////////////////////////////////////// escreve produtos no arquivo
void escrever_produtos(Produto p[],int qtd)
{
	FILE *arq;
	arq=fopen("produtos.txt","w");
	for(int x=0;x<qtd;x++)
	{
		fprintf(arq,"%s %f %i\n",p[x].nome,p[x].preco,p[x].qte);
	}
	fclose(arq);
} 















#endif
