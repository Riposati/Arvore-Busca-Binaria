#include <bits/stdc++.h>
#include "headers/cabecalhos.h"

using namespace std;

int main()
{
    cout<<"-----------Arvore busca binaria AVL-----------"<<endl<<endl;

    /// essas 3 linhas abaixo deixa o código em c++ mais rapido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Arvore *raiz = NULL;

    raiz = putMine(raiz,15);
    raiz = putMine(raiz,10);
    raiz = putMine(raiz,5);
    raiz = putMine(raiz,3);
    raiz = putMine(raiz,4);
    raiz = putMine(raiz,-1);
    raiz = putMine(raiz,-3);
    raiz = putMine(raiz,30);
    raiz = putMine(raiz,13);
    raiz = putMine(raiz,14);
    raiz = putMine(raiz,35);
    raiz = putMine(raiz,40);

    cout<<"forma prefixa = \n";
    prefixa(raiz);
    cout<<endl;

    cout<<"forma infixa = \n";
    infixa(raiz);
    cout<<endl;

    cout<<"forma posfixa = \n";
    posfixa(raiz);
    cout<<endl<<endl;

    findMine(raiz,15);

    cout<<"----- Remocoes -----\n";
    raiz = deleteMine(raiz,15);
    raiz = deleteMine(raiz,30);
    raiz = deleteMine(raiz,14);
    raiz = deleteMine(raiz,40);
    raiz = deleteMine(raiz,35);
    raiz = deleteMine(raiz,4);
    cout<<endl;

    prefixa(raiz);

    cout<<endl<<"Limpeza da arvore"<<endl;
    raiz = clearMine(raiz); /// clear()

    infixa(raiz);

    return 0;
}
