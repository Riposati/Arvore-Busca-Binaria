#include <bits/stdc++.h>

using namespace std;

struct arvore{

    struct arvore *esq;
    struct arvore *dir;
    int chave;
    int height;

}typedef Arvore;

Arvore *aux = NULL;

int height(Arvore *N){
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalance(Arvore *N){
    if (N == NULL)
        return 0;
    return height(N->esq) - height(N->dir);
}

Arvore *rightRotate(Arvore *y){
    cout<<"Rotacao simples direita na entrada da chave = "<<y->chave<<endl;

    Arvore *x = y->esq;
    Arvore *T2 = x->dir;

    // Perform rotation
    x->dir = y;
    y->esq = T2;

    // Update heights
    y->height = max(height(y->esq), height(y->dir))+1;
    x->height = max(height(x->esq), height(x->dir))+1;

    return x;
}

Arvore *leftRotate(Arvore *x){
    cout<<"Rotacao simples a esquerda na entrada da chave = "<<x->chave<<endl;

    Arvore *y = x->dir;
    Arvore *T2 = y->esq;

    // Perform rotation
    y->esq = x;
    x->dir = T2;

    //  Update heights
    x->height = max(height(x->esq), height(x->dir))+1;
    y->height = max(height(y->esq), height(y->dir))+1;

    return y;
}

Arvore *balanceamentoPosInsercao(Arvore *raiz,int chave){

    raiz->height = 1 + max(height(raiz->esq),height(raiz->dir));

    int balanco = getBalance(raiz);

    /// ( rotação simples a direita )

    if(balanco > 1 && chave < raiz->esq->chave){

        return rightRotate(raiz);
    }

    /// ( rotação simples a esquerda )

    if(balanco < -1 && chave > raiz->dir->chave){

        return leftRotate(raiz);
    }

    /// esq dir ( dupla rotação a direita )

    if(balanco > 1 && chave > raiz->esq->chave){

        cout<<"************Rotacao dupla a direita na entrada da chave = "<<chave<<endl;

        raiz->esq = leftRotate(raiz->esq);

        return rightRotate(raiz);
    }

    /// dir esq ( dupla rotação a esquerda )

    if(balanco < -1 && chave < raiz->dir->chave){

        cout<<"************Rotacao dupla a esquerda na entrada da chave = "<<chave<<endl;

        raiz->dir = rightRotate(raiz->dir);

        return leftRotate(raiz);
    }

    return raiz;
}

Arvore *putMine(Arvore *raiz,int chave){

    /// insere normalmente como numa arvore sem balanceamento

    if(aux==NULL){
        aux = new Arvore();
        aux->chave = chave;
        aux->dir = NULL;
        aux->esq = NULL;
        aux->height = 0;
    }

    if(raiz==NULL){

        raiz = aux;
        aux = NULL;

    }else{

        if(raiz->chave > chave){

            raiz->esq = putMine(raiz->esq,chave);

        }else{

            if(raiz->chave < chave){

                raiz->dir = putMine(raiz->dir,chave);
            }
        }
    }

    /// parte do balanceamento

    raiz = balanceamentoPosInsercao(raiz,chave);

    return raiz;
}

void findMine(Arvore *raiz,int chave){

    Arvore *aux = raiz;

    while(aux!=NULL && aux->chave!=chave){

        if(aux->chave > chave){

            aux = aux->esq;

        }else if(aux->chave < chave){

            aux = aux->dir;
        }
    }

    if(aux==NULL)
        cout<<"Chave nao encontrada\n";
    else
        cout<<"Chave "<<chave<<" encontrada\n";
}

Arvore *rebalanceioPosRemocao(Arvore *raiz){

    if(raiz==NULL){
        return raiz;
    }

    raiz->height = 1 + max(height(raiz->esq),height(raiz->dir));

    int balanco = getBalance(raiz);

    /// ( rotação simples a direita )

    if(balanco > 1 && getBalance(raiz->esq) >= 0){

        return rightRotate(raiz);
    }

    /// ( rotação simples a esquerda )

    if(balanco < -1 && getBalance(raiz->dir) <= 0){

        return leftRotate(raiz);
    }

    /// esq dir ( dupla rotação a direita )

    if(balanco > 1 && getBalance(raiz->esq) < 0){

        cout<<"************Rotacao dupla a direita na entrada da chave = "<<raiz->chave<<endl;
        raiz->esq = leftRotate(raiz->esq);
        return rightRotate(raiz);
    }

    /// dir esq ( dupla rotação a esquerda )

    if(balanco < -1 && getBalance(raiz->dir) > 0){

        cout<<"************Rotacao dupla a esquerda na entrada da chave = "<<raiz->chave<<endl;
        raiz->dir = rightRotate(raiz->dir);
        return leftRotate(raiz);
    }

    return raiz;
}

Arvore *deleteMine(Arvore *raiz,int chave){

    if(raiz==NULL) /// condição de parada e volta da função
        return NULL;

    /// primeiro busco a chave na arvore de forma recursiva

    if(raiz->chave  > chave)
        raiz->esq = deleteMine(raiz->esq,chave);

    else if(raiz->chave < chave)
        raiz->dir = deleteMine(raiz->dir,chave);

    else if(raiz->esq==NULL && raiz->dir==NULL){ /// no folha

        free(raiz);
        raiz = NULL;

    }else if(raiz->esq==NULL){ /// filho único a direita

        Arvore *t = raiz;
        raiz = raiz->dir;
        free(t);

    }else if(raiz->dir==NULL){ /// filho único a esquerda

        Arvore *t = raiz;
        raiz = raiz->esq;
        free(t);

    }else if(raiz->esq !=NULL && raiz->dir!=NULL){ /// No com dois filhos

        Arvore *t = raiz->dir;

        while(t->esq!=NULL){ /// pego o sucessor imediato

            t = t->esq;
        }

        raiz->chave = t->chave;
        t->chave = chave;
        raiz->dir = deleteMine(raiz->dir,chave);
    }

    /// parte do balanceamento ou re-balanceamento

    raiz = rebalanceioPosRemocao(raiz);

    return raiz;
}

void prefixa(Arvore *raiz){

    if(raiz!=NULL){
        cout<<raiz->chave<<" ";
        prefixa(raiz->esq);
        prefixa(raiz->dir);
    }
}

void infixa(Arvore *raiz){

    if(raiz!=NULL){
        infixa(raiz->esq);
        cout<<raiz->chave<<" ";
        infixa(raiz->dir);
    }
}

void posfixa(Arvore *raiz){

    if(raiz!=NULL){
        posfixa(raiz->esq);
        posfixa(raiz->dir);
        cout<<raiz->chave<<" ";
    }
}

Arvore *clearMine(Arvore *raiz){

    if(raiz->esq!=NULL){

        raiz->esq = clearMine(raiz->esq);
    }

    if(raiz->dir!=NULL){

        raiz->dir = clearMine(raiz->dir);
    }

    if(raiz->dir==NULL && raiz->esq==NULL){ /// achei folha, elimino!
            free(raiz);
            raiz = NULL;
    }
    return raiz;
}
