#include<stdio.h>
#include<stdlib.h>

//PILHA

struct no{
    int info;
    struct no* elo;
};

typedef struct no No;

struct pilha{
    No* no;
};

typedef struct pilha Pilha;

Pilha* cria(){
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->no = NULL;
    return pilha;
}

No* insere_no(No* no , int info){
    No* no_topo = (No*) malloc(sizeof(No));
    no_topo->info = info;
    no_topo->elo = no;
    return no_topo;
}

void push(Pilha* pilha , int info){
    pilha->no = insere_no(pilha->no, info);
}

void imprime(Pilha* pilha){
    No* no;
    for(no = pilha->no; no != NULL; no = no->elo){
        printf("informacao: %d\n",no->info);
    }
    printf("\n\n");
}

No* retira_no(No* no){
    No* no_topo = no->elo;
    free(no);
    return no_topo;
}

void pop(Pilha* pilha){
    pilha->no = retira_no(pilha->no);
}

void libera(Pilha* pilha){
    No* no_topo;
    No* novo_no_topo;
    for(no_topo = pilha->no; no_topo != NULL; no_topo = novo_no_topo){
        novo_no_topo = no_topo->elo;
        free(no_topo);
    }
    free(pilha);
}