#include <stdio.h>
#include <stdlib.h>

//LISTA

struct lista{
    int info;
    struct lista* elo;
};

typedef struct lista Lista;

Lista* cria(){
    return NULL;
}

void vazia(Lista* lista){   
    if(lista == NULL){
        printf("\nA lista esta vazia!\n");
    }else{
        printf("\nA lista nao esta vazia!\n");
    }
}

Lista* insere(Lista* lista , int info){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->info = info;
    l->elo = lista;
    return l;
}

Lista* retira(Lista* lista , int info){
    Lista* l_anterior = NULL; 
    Lista* l = lista;
    
    if(l == NULL){
        // Comentario do que faz
        return lista;
    }

    while(l != NULL && l->info != info){
        l_anterior = l;
        l = l->elo;
    }
    
    if(l == NULL){
        // Comentario do que faz
        return lista;
    }

    if(l_anterior == NULL){
        // Comentario do que faz
        lista = l->elo;
    }else{
        // Comentario do que faz
        l_anterior->elo = l->elo;
    }

    free(l);
    return lista;
}

void imprime(Lista* lista){
    Lista* l = lista;
    printf("\n", l->info);
    while(l != NULL){
        printf("informacao: %d\n",l->info);
        l = l->elo;
    }
    printf("\n");
}

Lista* busca(Lista* lista , int info){
    Lista* l = lista;
    int posicao = 1;
    while(l != NULL){
        if (l->info == info){
            printf("\n Informacao encontrada na posicao %d da lista.", posicao);
        }
        l = l->elo;
        posicao++;
    }
    printf("\n");   
    return NULL;
}

void libera(Lista* lista){
    Lista* l = lista;
    Lista* l_anterior;
    while(l != NULL) {
        l_anterior = l->elo;
        free(l);
        l = l_anterior;
    }
}