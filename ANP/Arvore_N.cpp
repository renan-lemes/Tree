#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <malloc.h>

typedef int Type_key;

typedef struct Arvore_N
{
    Type_key t_k;
    Arvore_N *f_1;
    Arvore_N *f_n;
}NO;
typedef NO* PONT;

PONT Initialize(){
    return(NULL);
}

PONT criaNovo_NO(Type_key k){
    PONT novono = (PONT)malloc(sizeof(NO));
    novono->f_1 = NULL;
    novono->f_n = NULL;
    novono->t_k = k;
    return(novono);
}

PONT Initialize(Type_key k){
    return(criaNovo_NO(k));
}


PONT search_key(Type_key k, PONT raiz){
    if(raiz == NULL) return(NULL);
    if(raiz->t_k == k) return (raiz);
    PONT p = raiz->f_1;
    while (p)
    {
        PONT respon = search_key(k,p);
        if (respon) return (respon);
        p = p->f_n;
    }
    return(NULL);
}

bool insertion(PONT raiz, Type_key newk, Type_key f_k){
    PONT father = search_key(f_k ,raiz );
    if (!father) return (false);
    PONT son = criaNovo_NO(newk);
    PONT F = father->f_1 ;
    if (!F) father->f_1 = son;
    else{
        while (F->f_n)
            F = F->f_n;
        F->f_n = son;
    }
    return(true);
}


void print_tree(PONT raiz){
    if(raiz == NULL) return;
    printf("%d -> ",raiz->t_k);
    PONT F = raiz->f_1;
    while (F)
    {
        print_tree(F);
        F = F->f_n;
    }
    printf("<-");
}

int main(int argc, char** argv){
    PONT tree = Initialize(6);
    
    insertion(tree, 4,6);
    insertion(tree, 2,4);
    insertion(tree,7,2);
    insertion(tree,12,7);
    insertion(tree,16,12);
    print_tree(tree);
}