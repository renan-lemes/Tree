#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>


#define black 0
#define red 1

typedef int Tipo_chave;
typedef int Tipo_cor;

typedef struct Arvore_red_black
{
    Tipo_chave chave;
    struct Arvore_n *esq;
    struct Arvore_n *dir;
    struct Arvore_n *pai;
    Tipo_cor cor;
}NO;
typedef NO* PONT;

PONT Inicializa(){
    return(NULL);
}

PONT Criar_Novo_No_Black(Tipo_chave ch){
    PONT novoNo = (PONT)malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    novoNo->cor = black;
    return(novoNo);
}

PONT Criar_Novo_No_Red(Tipo_chave ch){
    PONT novoNo = (PONT)malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    novoNo->cor = red;
    return(novoNo);
}

PONT Inserir(PONT raiz, Tipo_chave ch){
    if(!raiz)
        return(Criar_Novo_No_Black(ch));
    if (ch<raiz->chave)
    {
        raiz->esq = Inserir(raiz->esq,ch);
        if (raiz->dir->cor || raiz->esq->cor == black)
        {
            
        }
        
    }
    

}

PONT Rotacao_D(PONT r){
    PONT aux;
    aux = r->esq;
    r->dir = aux->esq;
    aux->esq = r;
    r->cor = Mudar_Cor(r->dir->cor,r->esq);
    aux->cor = Mudar_Cor(aux->esq->cor,r->cor);
    return(aux);
}
PONT Rotacao_E(PONT r){
    PONT aux;
    aux = r->dir;
    r->dir = aux->esq;
    aux->esq = r;
    r->cor = Mudar_Cor(aux->dir->cor, r->esq);
    return(aux);
}
int Mudar_Cor(cor, PONT r){
    if (cor==black)
    {
        r->cor = red;
    }else{
        r->cor = black;
    }
    
}


int main(){

}