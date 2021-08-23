//------Arvore AVL-----//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
	#define true 1;
	#define false 0;


typedef int boool;
typedef int TipoChave;

typedef struct aux{
	TipoChave chave;
	struct aux *esq;
	struct aux *dir;
	int h;
}NO;
typedef NO* PONT;

PONT Inicializa(){
	return(NULL);
};

PONT criar_Novo_No(TipoChave ch){
	PONT novoNo = (PONT)malloc(sizeof(NO));
	novoNo->esq = NULL;
	novoNo->dir= NULL;
	novoNo->chave = ch;
	novoNo->h = 0;
	return(novoNo);
};

PONT adicionar(PONT raiz,PONT no){
	/*ignoro chaves iguais*/
	if(raiz == NULL)
		return (no);
	if(no->chave<raiz->chave)
		raiz->esq = adicionar(raiz->esq,no);
	else
		raiz->dir=adicionar(raiz->dir,no);
	return(raiz);
};

PONT Busca(TipoChave ch, PONT raiz){
	if(raiz==NULL)			//ve se a raiz for vazia retorna
		return(NULL);
	if(raiz->chave==ch)	  //ve se a chave do elemento posto ao elemento inserido//
		return(raiz);
	if(raiz->chave>ch)	//se for menor ela vai e faz a busca denovo por recursividade//
		return(Busca(ch,raiz->esq));
	return(Busca(ch,raiz->dir)); //caso os elementos que eu procurava esta a direita//
};

PONT BuscaNo(PONT raiz,TipoChave ch,PONT *pai){
	PONT atual = raiz;
	*pai = NULL;
	while(atual)
	{
		if(atual->chave == ch)
			return(atual);
		if(ch<atual->chave)
			atual = atual->esq;
		else
			atual=atual->dir;
	}
	return(NULL);
}

PONT Excluir(TipoChave ch, PONT raiz){
	PONT pai,no,p,q; //estruturas auxiliares pra remoção//
	no = BuscaNo(raiz,ch,&pai); //pre det
	if(no==NULL)
		return (raiz);
	if(!no->esq || !no->dir){
		if(!no->esq)
			q = no->dir;
		else
			q = no->esq;
	}else{
		p = no;
		q = no->esq;
		while(q->dir)
		{
			p = q;
			q = q->dir;
		}
		if(p != no){
			p->dir = q->esq;
			q->esq = no->esq;
		}
		q->dir = no->esq;
	}
	if(!pai){
		free(no);
		return(q);	
	}
	if(ch < pai->chave)
		pai->esq = q;
	else
		pai->dir = q;
	free(no);
	return(raiz);
}

int n_Nos(PONT raiz){
	if(!raiz)
		return 0;
	return(n_Nos(raiz->esq)+1+ n_Nos(raiz->dir));
};

void Pre_Ordem(PONT raiz){
	if(raiz!=NULL){
		printf("%i",raiz->chave);
		printf("(");
		Pre_Ordem(raiz->esq);
		Pre_Ordem(raiz->dir);
		printf(")");
	}
};

void In_Ordem(PONT raiz){
	if(raiz!=NULL){
		In_Ordem(raiz->esq);
		printf("%i",raiz->chave);
		printf("\n%i",raiz->h);
		printf("()");
		In_Ordem(raiz->dir);
		printf(")");
		printf("%i",raiz->chave);
		printf(")");
	}
};

 void So_Direita(PONT raiz){
	 if(raiz!=NULL){
		 printf("%i",raiz->chave);
		 printf("<->");
		 So_Direita(raiz->dir);
		 printf("->");
	 }
 };

 void Elevando_Cubo(PONT raiz){
	 if(raiz!=NULL){
		raiz->chave=pow(raiz->chave,3);
		Elevando_Cubo(raiz->esq);
		Elevando_Cubo(raiz->dir);
	 }
 };

 void So_SubArv_Direita(PONT raiz){
	if(raiz!=NULL){
		So_SubArv_Direita(raiz->dir);
		So_SubArv_Direita(raiz->esq);
		
			if(raiz->dir||raiz->dir==NULL){
				if((raiz) = raiz->dir){
					printf("%i",raiz->chave); 	
					printf("->");
				}
				
			}else{
				
			}
					
	}
};

int Altura(PONT raiz){ //ok//
 	 if(!raiz)
 	 	return (-1);
 	 return (raiz->h);
};

int maximo(int a ,int b)
{
	if(a>b){
		return b;
	}
}

PONT Rotacao_Direita(PONT r){
	PONT aux;
	aux = r->esq;
	r->esq = aux->dir;
	aux->dir = r;
	r->h = (maximo((Altura(r->dir)),(Altura(r->esq))) +1);
	aux->h = maximo((Altura(aux->esq)),(r->h)) +1;
 	return(aux);
};

PONT Rotacao_Esquerda(PONT r){
	PONT aux;
	aux = r->dir;
	r->dir = aux->esq;
	aux->esq = r;
	r->h = maximo((Altura(r->dir)),(Altura(r->esq))) +1;
	aux->h = maximo((Altura(aux->dir)),(r->h)) +1;
	return(aux);
};


 //rotaçoes duplas // 
PONT Rotacao_Dir_Esq(PONT r){
	r->esq = Rotacao_Esquerda(r->esq);
	return (Rotacao_Direita(r));
};

PONT Rotacao_Esq_Dir(PONT r){
	r->dir = Rotacao_Direita(r->dir);
	return(Rotacao_Esquerda(r->dir));
};

PONT inserir(PONT raiz, TipoChave ch){
	if(!raiz)
		return (criar_Novo_No(ch));
	if(ch<raiz->chave){
		raiz->esq = inserir(raiz->esq , ch);
		if((Altura(raiz->esq)-Altura(raiz->dir)) == 2);
			if(ch<raiz->esq->chave)
				raiz = Rotacao_Direita(raiz);
			else
				raiz = Rotacao_Esq_Dir(raiz);
			
	}else
		if(ch>raiz->chave){
			raiz->dir = inserir(raiz->dir,ch);
			if((Altura(raiz->dir)-Altura(raiz->esq))==2)
				if(ch>raiz->dir->chave)
					raiz = Rotacao_Esquerda(raiz);
				else
					raiz = Rotacao_Dir_Esq(raiz);
		}
	raiz->h = max(Altura(raiz->esq),Altura(raiz->dir)) +1;
	return(raiz);
};

void Estetica(){
	printf("\n-------------------ARVORE AVL-----------------\n");
	printf("\n1-Inserir Elemento:");
	printf("\n2-Imprimir Arvore:");
	printf("\n3-Excluir Elemento:");
	printf("\n4-Sair\n");
	//system("pause");
	//system("cls");
};

 //------------------------//
int main(int argc, char** argv){
	
	
	
	/*PONT r = Inicializa();
	PONT no = criar_Novo_No(32);
	r = adicionar(r,no);
	no = criar_Novo_No(23);
	r = adicionar(r,no);
	no = criar_Novo_No(38);
	r =adicionar(r,no);
	no = criar_Novo_No(25);
	r = adicionar(r,no);
	no = criar_Novo_No(36);
	r = adicionar(r,no);
	no = criar_Novo_No(39);
	r = adicionar(r,no);
	no = criar_Novo_No(24);
	r = adicionar(r,no);
	

	
	In_Ordem(r);
	
	
	printf("\n\n");
	*/
	
	while(1)
	{
		int Elemento;
		int opcao;
		PONT r = Inicializa();
		PONT no;
		Estetica();
		scanf("%d",&opcao);
		if(opcao==4)
			break;
		switch(opcao)
		{
		case 1:
			printf("\nDigite o elemento :\n");
			scanf("%d",&Elemento);
			no = criar_Novo_No(Elemento);
			r = adicionar(r,no);
			r = inserir(no,Elemento);
			break;
		case 2:
			In_Ordem(r);
			break;
		case 3:
			printf("\nDigite o Elemento que deseja excluir:\n");
			scanf("%d",&Elemento);
			//no = criar_Novo_No(Elemento);
			Excluir(Elemento,r);
			break;
		}
			
	}
	
	return 0;
};