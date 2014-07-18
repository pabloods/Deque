#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct No{
	struct No *ant;
	int info;
	struct No *prox;
};

struct tDEQUE{
	struct No *prim;
	struct No *ult;
};

typedef struct tDEQUE tdeque;

int g_tam;

void IniciarDq (tdeque *Deque){

	Deque->prim= NULL;
	Deque->ult=NULL;
	g_tam=0;
}

void Inserir_Ini(tdeque *Deque, int info){

	struct No *novo= (struct No *)malloc(sizeof (struct No));

	novo->info= info;
	novo->ant= NULL;

	if(Deque->prim == NULL){
		Deque->ult= novo;
		novo->prox= NULL;
	}
	else{
		novo->prox= Deque->prim;
		(Deque->prim)->ant= novo;
	}

	Deque->prim= novo;
	g_tam ++;
}

void Inserir_fim(tdeque *Deque, int info){

	struct No *novo= (struct No *)malloc(sizeof (struct No));

	novo->info= info;

	novo->prox= NULL;

	if(Deque-> prim ==  NULL){
		novo->ant= NULL;
		Deque ->prim= novo;
	}
	else{
		(Deque->ult)->prox= novo;
		novo->ant= Deque->ult;
	}
	Deque->ult= novo;
	g_tam ++;
}

struct No *Remover_Ini(tdeque *Deque){

	struct No *ant, *aux;

	aux= Deque-> prim;

	if(Deque->prim == Deque->ult){

		Deque->prim= NULL;
		Deque->ult= NULL;
	}
	else{
		Deque->prim= aux->prox;
		(Deque->prim)->ant= NULL;
	}
	g_tam --;
	return aux;

}

struct No *Remover_Fim(tdeque *Deque){

	struct No *ant, *aux;

	aux= Deque->ult;

	if(Deque->prim == Deque->ult){

		Deque->prim= NULL;
		Deque->ult= NULL;
	}
	else{
		Deque->ult= aux->ant;
		(Deque->ult)->prox= NULL;
	}
	g_tam --;
	return aux;
}

int teste_Vazia(tdeque *Deque){

	if((Deque->prim == NULL)&&(Deque->ult == NULL)){

		return 1;
	}
	else{
		return 0;
	}
}

void imprime(tdeque *Deque){// Função de impressão da Fila

	struct No *aux = NULL;

	if(teste_Vazia(Deque)){
		printf("A fila esta vazia. \n");
	}
	else{

		aux = Deque->prim;
		printf("\nFila:\n");

		while( aux != NULL){
			printf("   %i\n", aux->info);
			aux = aux->prox;
		}
	}
}


void trocar_lado (tdeque *Deque){
	struct No *aux = NULL;
	aux = Deque->prim;
	int i=0, d=g_tam;
	long int vet[500000];

	if(teste_Vazia(Deque)){
	printf("A fila esta vazia. \n");
	}


	else{
	system ("cls");
	printf ("Deque com o lado alterado: \n");

	while( aux != NULL)
	{
		vet[d]=aux->info;
		aux = aux->prox;
		d--;
	}


	for (i=1;i<=g_tam;i++)
	{
		printf("%i \n", vet[i]);
	}
}
printf ("\n\n\n\n\n\n\n");
}

void ordenar (tdeque *Deque){
	struct No *aux = NULL;
	aux = Deque->prim;
	int i=0,j=0, d=g_tam,temp;
	long int vet[500000];

	if(teste_Vazia(Deque)){
	printf("A fila esta vazia. \n");
	}


	else{
	system ("cls");
	printf ("Deque ordenado: \n");

	while( aux != NULL)
	{
	    vet[i]=aux->info;

		for ( i=d-1; i > 0; i-- ){
        for ( j=0; j < i; j++ ){

        if(vet[j] > vet[j+1]){
        temp=vet[j];
        vet[j]=vet[j+1];
        vet[j+1]=temp;
        }
        }
		}
		aux = aux->prox;
		}

	for (i=0;i<g_tam;i++)
	{
		printf("%i \n", vet[i]);
	}
}
printf ("\n\n\n\n\n\n\n");
}






void limpa(tdeque *Deque){//Libera o espaço alocado da Pilha

	struct No *aux = NULL, *aux2= NULL;

	if(teste_Vazia(Deque)){
		printf("A fila esta vazia. \n");
	}
	else{
		aux = (Deque->prim)->ant;

			while( aux != NULL){
				aux2= aux->prox;
				free(aux);
				aux = aux2;
			}
	}
}



void menu(tdeque *Deque){//Função que trem o menu do programa

	int op, cod;
	struct No *aux= NULL;
	clock_t inicio, fim;

	while(1){

		system("cls");
			printf("\t  ==== MENU ====\n\n");
			printf("\t1. Inserir elemento no Inicio;\n");
			printf("\t2. Inserir elemento no Fim;\n");
			printf("\t3. Apagar elemento do Inicio;\n");
			printf("\t4. Apagar elemento do Fim;\n");
			printf("\t5. Imprimir Deque;\n");
			printf("\t6. Tamanho da Fila;\n");
			printf("\t7. Apagar Deque.\n");
			printf("\t8. Trocar lado.\n");
			printf("\t9. Ordenar Deque.\n");
			printf("\t10. Sair\n");
			scanf("%d", &op);

			switch(op){
				case 1:
					inicio=clock();
					printf("Novo elemento: ");
					scanf("%d", &cod);
					Inserir_Ini(Deque, cod);
					fim=clock();
					printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
					system("Pause");
					break;

				case 2:
					inicio=clock();
					printf("Novo elemento: ");
					scanf("%d", &cod);
					Inserir_fim(Deque, cod);
					fim=clock();
					printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
					system("Pause");
					break;

				case 3:
					inicio=clock();
					aux= Remover_Ini(Deque);
					if(aux != NULL)
					printf("Elemento retirado: %d\n\n", aux->info);
					fim=clock();
					printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
					system("Pause");
					break;

				case 4:
					inicio=clock();
					aux= Remover_Fim(Deque);
					if(aux != NULL)
					printf("Elemento retirado: %d\n\n", aux->info);
					fim=clock();
					printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
					system("Pause");
					break;

				case 5:
					inicio=clock();
					imprime(Deque);
					fim=clock();
					printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
					system("Pause");
					break;

				case 6:
					inicio=clock();
					printf("A fila possui %d elementos. \n", g_tam);
					fim=clock();
					printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
					system("Pause");
					break;

				case 7:
					inicio=clock();
					limpa(Deque);
					IniciarDq(Deque);
					fim=clock();
					printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
					system("Pause");
					break;

				case 8:
					inicio=clock();
					trocar_lado(Deque);
					fim=clock();
					printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
					system("Pause");
					break;

				case 9:
					inicio=clock();
                    ordenar(Deque);
					fim=clock();
					printf("Tempo de execucao: %lf\n",((double)(fim - inicio)/CLOCKS_PER_SEC));
					system("Pause");
					break;

				case 10:
					exit(0);

				default:
					printf("Comando invalido, por favor escolha uma opcao.\n\n");
					system("Pause");
			}
	}
}
