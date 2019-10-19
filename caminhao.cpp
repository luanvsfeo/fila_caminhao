#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct caminhoneiro Caminhoneiro;
struct caminhoneiro{
	int cpf;
	char nome [30];
	char placa [30];
	char tipo_entrega[30];	
	struct caminhoneiro *prox;
};

typedef struct fila Fila;
 struct fila{
	Caminhoneiro *inicio;
	Caminhoneiro *fim;
};
		
void enfileirar(Fila* f);
void desemfileirar(Fila* f,Fila* f2);
void enfileirarEntrega(Caminhoneiro* c,Fila* f);
void liberar(Fila* f);
void listar(Fila* f);
int isEmpty(Fila* f);
Fila* inicializar();


int main (){

	Fila *adm_fila,*fila_entregado;
	adm_fila = inicializar();
	fila_entregado = inicializar();
	int e;
	
	printf("\nMenu\n1-Adicionar na fila\n2-Realiza entrega\n3-Listar entregas realizadas\n4- Finalizar o dia(liberar a lista)\n0-Sair");
	
	do{
		printf("\nEscolha: ");
		scanf("%d",&e);
		
		switch(e){
			case 1 :
				enfileirar(adm_fila);
			break;
			
			case 2 :
				desemfileirar(adm_fila,fila_entregado);
			break;
			
			case 3 :
				listar(fila_entregado);
			break;
			
			
			case 4 :
				liberar(adm_fila);
				adm_fila = inicializar();
				fila_entregado = inicializar();
			break;
			
			case 0 :
				
			break;
			
			default:
				printf("\nValor invalido");
			break;
		}
	}while(e!= 0);		

	return 0;
}


void enfileirar(Fila* f){

	Caminhoneiro *novo;
	novo = (Caminhoneiro*)malloc(sizeof(Caminhoneiro));
	
	printf("Informe o cpf do caminhoneiro: ");
	scanf("%d",&novo->cpf);
	printf("Informe o nome do caminhoneiro: ");
	scanf("%s",novo->nome);
	printf("Informe o placa do caminhoneiro: ");
	scanf("%s",novo->placa);
	printf("Informe o tipo de entrega do caminhoneiro: ");
	scanf("%s",novo->tipo_entrega);


	novo->prox = NULL;
	
	if(f->fim != NULL){
		f->fim->prox = novo;
	}else{
		f->inicio = novo;
	}
	
	f->fim = novo;
	
	
}

void enfileirarEntrega(Caminhoneiro* c,Fila* f){
	
	Caminhoneiro *novo;
	novo = (Caminhoneiro*)malloc(sizeof(Caminhoneiro));

	novo->cpf = c->cpf;
	strcpy(novo->nome,c->nome);
	strcpy(novo->placa,c->placa);
	strcpy(novo->tipo_entrega,c->tipo_entrega);
	novo->prox = NULL;
	
	if(f->fim != NULL){
		f->fim->prox = novo;
	}else{
		f->inicio = novo;
	}
	
	f->fim = novo;
	

}


void desemfileirar(Fila* f,Fila* f2){
	
	Caminhoneiro *t;
	if(isEmpty(f)){
		printf("fila vazia\n");
		
	}else{
		t=f->inicio;
		f->inicio = t->prox;
		enfileirarEntrega(t,f2);
			
	if(f->inicio == NULL)
		f->fim =NULL;
	
	free(t);
	}
	
}


void listar(Fila* f){
	Caminhoneiro *q;
	q = f->inicio;
	
	if(q!= NULL){
		int i=0;		
		printf("\n---------------------------");
		printf("\nNumero : %d",i+1);
		printf("\nCpf : %d",q->cpf);
		printf("\nNome : %s",q->nome);
		printf("\nPlaca : %s",q->placa);
		printf("\nTipo de entrega : %s",q->tipo_entrega);
		
		
		do{	
			
			i++;
			Caminhoneiro *t;
			t = q->prox;
			
			if(t!=NULL){
				printf("\n---------------------------");
				printf("\nNumero : %d",i+1);
				printf("\nCpf : %d",t->cpf);
				printf("\nNome : %s",t->nome);
				printf("\nPlaca : %s",t->placa);
				printf("\nTipo de entrega : %s",t->tipo_entrega);
				q=t;
			}else{
				break;
			}
							
		}while(q!=NULL);
	
	}else{
		printf("Impossivel mostrar, Lista esta vazia");
	}
		
		
				
	
		

}


Fila* inicializar(){	
	Fila *f1 = (Fila*)malloc(sizeof(Fila));
	f1->inicio = NULL;
	f1->fim = NULL;
	return f1;
}


int isEmpty(Fila* f){
	if(f->inicio == NULL)
		return 1;
		
	return 0;
}

void liberar(Fila* f){
	Caminhoneiro *q = f->inicio;
	while(q!=NULL){
		Caminhoneiro *t = q->prox;
		free(q);
		q=t;
	}
	free(f);
}
