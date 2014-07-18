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

/*  Inicialização */
void IniciarDq (tdeque *Deque);

/* Inserção */
void Inserir_Ini(tdeque *Deque, int info);
void Inserir_fim(tdeque *Deque, int info);

/* Remorção */
struct No *Remover_Ini(tdeque *Deque);
struct No *Remover_Fim(tdeque *Deque);

/* Teste para conferir a deque */
int teste_Vazia(tdeque *Deque);

/* Impressão */
void imprime(tdeque *Deque);

/*Função para troca de lado do primeiro elemento da Deque*/
void trocar_lado (tdeque *Deque);

/*Função para ordenação da Deque*/
void ordenar (tdeque *Deque);

/* Apaga cada elemento da Deque */
void limpa(tdeque *Deque);

/* Opções do programa */
void menu(tdeque *Deque);

////////////////////////////////////////////
