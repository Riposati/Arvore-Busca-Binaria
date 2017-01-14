#ifndef CABECALHOS_H_INCLUDED
#define CABECALHOS_H_INCLUDED

struct arvore typedef Arvore;

int height(Arvore *N);

int getBalance(Arvore *N);

Arvore *rightRotate(Arvore *y);

Arvore *leftRotate(Arvore *x);

Arvore *balanceamentoPosInsercao(Arvore *raiz,int chave);

Arvore *putMine(Arvore *raiz,int chave);

void findMine(Arvore *raiz,int chave);

Arvore *rebalanceioPosRemocao(Arvore *raiz);

Arvore *deleteMine(Arvore *raiz,int chave);

void prefixa(Arvore *raiz);

void infixa(Arvore *raiz);

void posfixa(Arvore *raiz);

Arvore *clearMine(Arvore *raiz);

#endif // CABECALHOS_H_INCLUDED
