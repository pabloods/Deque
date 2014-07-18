#include <stdio.h>
#include <stdlib.h>
#include <FuncaoDeque.h>



int main(){

	tdeque *Deque= (tdeque*)malloc(sizeof (tdeque));

	if(Deque == NULL){
		printf("Sem memoria disponivel para alocar a Fila Dupla.\n");
		exit(1);
	}
	else{
		IniciarDq(Deque);
		menu(Deque);
		free(Deque);
	}

	return 0;

}


