#include <stdio.h>
#include <stdlib.h>

//FILA

struct no{
   int info;
   struct no* elo_anterior;
   struct no* elo_proximo;
};

typedef struct no No;

struct fila{
   No* inicio;
   No* fim;
};

typedef struct fila Fila;

Fila* cria(){
   Fila* fila = (Fila*) malloc(sizeof(Fila));
   fila->inicio = NULL;
   fila->fim = NULL;
   return fila;
}

No* insere_inicio(No* inicio , int info){
   No* no = (No*) malloc(sizeof(No));
   no->info = info;
   no->elo_proximo = inicio;
   no->elo_anterior = NULL;
   if(inicio != NULL){
      inicio->elo_anterior = no;
   }
   return no;
}

void enqueue_inicio(Fila* fila , int info){
   fila->inicio = insere_inicio(fila->inicio , info);
   if(fila->fim == NULL){
      fila->fim = fila->inicio;
   }
}

No* retira_inicio(No* inicio){
   No* no = inicio->elo_proximo;
   if (no != NULL){
      no->elo_anterior = NULL;
   }
   free(inicio);
   return no;
}

int dequeue_inicio(Fila* fila){
   fila->inicio = retira_inicio(fila->inicio);
   if (fila->inicio == NULL){
      fila->fim = NULL;
   }
}

No* insere_fim(No* fim , int info){
   No* no = (No*) malloc(sizeof(No));
   no->info = info;
   no->elo_proximo = NULL;
   no->elo_anterior = fim;
   if (fim != NULL){
      fim->elo_proximo = no;
   }
   return no;
}

void enqueue_fim(Fila* fila , int info){
   fila->fim = insere_fim(fila->fim , info);
   if(fila->inicio == NULL){
      fila->inicio = fila->fim;
   }
}

No* retira_fim(No* fim){
   No* no = fim->elo_anterior;
   if (no != NULL){
      no->elo_proximo = NULL;
   }
   free(fim);
   return no;
}

int dequeue_fim(Fila* fila){
   fila->fim = retira_fim(fila->fim);
   if (fila->fim == NULL){
      fila->inicio = NULL;
   }
}

void imprime(Fila* fila){
   No* no;
   for(no = fila->inicio; no != NULL; no = no->elo_proximo){
      printf("%d\n",no->info);
   }
   printf("\n");
}

void libera(Fila* fila){
   No* no;
   No* no_anterior;
   for(no = fila->inicio; no != NULL; no = no_anterior){
      no_anterior = no->elo_proximo;
      free(no);
   }
   free(fila); 
}