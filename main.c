#include <stdio.h>
#include <stdlib.h>
#define Tam 100
#include <string.h>
#include <time.h>

typedef struct no{
	char dado[Tam];
	struct no *prox;
}No;

int inserir_apos_cabeca(No **L, char name[Tam]){
	No *novo;
	novo = (No *) malloc(sizeof(No));
	if (novo == NULL)
		return 0;
  strcpy(novo->dado, name);    
  novo->prox = NULL;

	if (*L == NULL){
		novo->prox = novo;
		*L = novo;
	}else{
		novo->prox = (*L)->prox;
		(*L)->prox = novo;
	}

  return 0;
}

int sorteio(No **L){
  int lower = 1,upper = 5,count = 1;
  if (*L == NULL) {
		printf("Lista vazia.\n");		
	}
	else
	{
	No *p;
  int num = (rand() %
      (upper - lower + 1)) + lower;	
	p = *L;
	for (int i = 0; i < num; p=p->prox , i++);	
	printf("Soldado que foi sorteado para iniciar a contagem: %s\n", p->dado);
	return 1;	
	}
    
return 1;
}

void soldado_azarado(No **L, char cabeca_de_papel[Tam], int qtd){
  int i;
  if (*L == NULL) {
		printf("Lista vazia.\n");		
	}
  else{
    No *p; No *q;
    int num = 0 + ( rand() % 100 );	//Sorteio
    p = *L;
    while (qtd > 1){
      for(i = 0, p=*L; i < num; p= p->prox, i++){
        printf("Soldado azarado(eliminado): %s\n", p->dado);//print da contagem
      }
      for(q = (*L)->prox; q->prox != p; q = q->prox);
      if(p == *L){
        p = *L; *L = NULL; *L = p->prox; q->prox=*L;
			  free(p);//Eliminação
      }
      else{
        q->prox = p->prox;
			  free(p);//Eliminação
      }
      qtd--;
    }
    if(qtd == 1)
    {
      No *p;
      printf("O número sorteado foi: %d\n", num);//Sorteio da linha 58
      for (p=*L; p->prox != *L; p=p->prox){
        printf("Soldado sortudo (ou esperto) que irá fugir no cavalo: %s\n", p->dado);
      }
      printf("Soldado sortudo (ou esperto) que irá fugir no cavalo: %s\n", p->dado);
    }
  }
}

/*int remover_por_pos(No **L, int vlr){
	if (*L == NULL)
		return 0;

	No *p, *q;
	q = *L;
	for (p = (*L)->prox; p != *L ; p=p->prox){
		if (p->dado == vlr)
			break;
		q = p;
	}
	
	if (p == q){
		// verificar se é o elemento a ser removido.
		if (p->dado == vlr){
			free(p);
			*L = NULL;
			return 1;
		}else{
			return 0;
		}	
	}
  

	if (p == *L){
		// não encontramos o valor a ser removido... mas precisa verificar se é nó apontado por L.
		if (p->dado == vlr){
			q->prox = p->prox;
			*L = p->prox;
			free(p);
			return 1;
		}else{
			return 0;
		}
	}

	// fazer a remoção do elemento apontado por p.
	q->prox = p->prox;
	free(p);
	return 1;
}
*/

void mostrar_lista(No **L){
	No *p;

	if (*L == NULL)
		printf("Lista vazia.\n");
	else{
		for (p=*L; p->prox != *L; p=p->prox){
			printf("%s\n", p->dado);
		}
		printf("%s\n", p->dado);
	}
}

int menu() {
  No *cabeca = NULL;
	int opc;
	system("clear");
	printf("[ 0 ] - Sair.\n");
	printf("[ 1 ] - Inserir soldado.\n");
	printf("[ 2 ] - Mostrar soldados.\n");
	printf("[ 3 ] - Sortear o soldado que iniciará a contagem.\n");
	printf("[ 4 ] - Apresentar o soldado selecionado (apresente também o número n sorteado e os soldados eliminados).\n\n");

	printf("Escolha uma opção: ");
	scanf("%i", &opc);
	return opc;
}

int main() {
  int opc, qtd=0;
  No x;
  No *cabeca = NULL;
  char nome, *sort;

/*  inserir_apos_cabeca(&cabeca, "Joao");
  inserir_apos_cabeca(&cabeca, "Gabriel");
  inserir_apos_cabeca(&cabeca, "Pedro");
  inserir_apos_cabeca(&cabeca, "Davi");
  inserir_apos_cabeca(&cabeca, "Lucas");
  inserir_apos_cabeca(&cabeca, "Heverton");*/

	while (opc = menu()) {
		switch (opc) {
		case 1: {
      printf("Insira o nome do soldado: ");
      char nome[Tam];
      //fgets(x.dado, 5, stdin);
      scanf("%s", nome);
      //inserir_apos_cabeca(&cabeca, x.dado);
      inserir_apos_cabeca(&cabeca, nome);
      qtd++;
		} break;

		case 2: {
			mostrar_lista(&cabeca);
		} break;

		case 3: {
			sort = sorteio(&cabeca);
		} break;

		case 4: {
			soldado_azarado(&cabeca, sort, qtd);
      qtd = 1;
		} break;


		default:
			printf("Opção inválida.\n");
		}

		getchar();
		getchar();
	}
}
