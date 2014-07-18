/*   DEQUE   */

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

/*  Inicializa��o */
void IniciarDq (tdeque *Deque);

/* Inser��o */
void Inserir_Ini(tdeque *Deque, int info);
void Inserir_fim(tdeque *Deque, int info);

/* Remor��o */
struct No *Remover_Ini(tdeque *Deque);
struct No *Remover_Fim(tdeque *Deque);

/* Teste para conferir a deque */
int teste_Vazia(tdeque *Deque);

/* Impress�o */
void imprime(tdeque *Deque);

/*Fun��o para troca de lado do primeiro elemento da Deque*/
void trocar_lado (tdeque *Deque);

/*Fun��o para ordena��o da Deque*/
void ordenar (tdeque *Deque);

/* Apaga cada elemento da Deque */
void limpa(tdeque *Deque);

/* Op��es do programa */
void menu(tdeque *Deque);

////////////////////////////////////////////
