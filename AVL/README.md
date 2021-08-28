# AVL 
Árvore AVL é uma árvore binária de busca balanceada, ou seja, uma árvore balanceada (árvore completa) são as árvores que minimizam o número
de comparações efetuadas no pior caso para uma busca com chaves de probabilidades de ocorrências idênticas. Contudo, para garantir essa propriedade 
em aplicações dinâmicas, é preciso reconstruir a árvore para seu estado ideal a cada operação sobre seus nós (inclusão ou exclusão), para ser 
alcançado um custo de algoritmo com o tempo de pesquisa tendendo a log n.

## Definição 
Uma árvore binária T é denominada AVL quando, para qualquer nó de T, as alturas de suas duas subárvores, esquerda e direita, diferem em módulo de 
até uma unidade.
* Exemplo:

![img](https://1.bp.blogspot.com/-tQzL7-2C8Jg/W4VIRSjspPI/AAAAAAAAEdw/QilAm-RIFb4cqVZEhhZlCUj32XntkP_GwCK4BGAYYCw/s400/ar1.png)
