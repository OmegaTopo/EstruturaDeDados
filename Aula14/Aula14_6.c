#include <stdio.h>
#include <stdlib.h>

//LISTA CIRCULAR

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
    if(lista == NULL){
        l->elo = l;
    }else{
        l->elo = lista->elo;
        lista->elo = l;
    }
    lista = l;
    return l;
}

void imprime(Lista* lista){
    Lista* l_anterior = lista;
    Lista* l = lista;
    do{
        printf("Informacao: %d\n", l->info);
        l = l->elo;
    }while(l != l_anterior);
    printf("\n");
}

Lista* retira(Lista* lista , int info){
    Lista* l_anterior = NULL; 
    Lista* l = lista;
    
    if(l == NULL){
       
        return lista;
    }

    while(l != NULL && l->info != info){
        l_anterior = l;
        l = l->elo;
    }
    
    if(l == NULL){
        
        return lista;
    }

    if(l_anterior == NULL){
        
        lista = l->elo;
    }else{
        
        l_anterior->elo = l->elo;
    }

    free(l);
    return lista;
}

int main()
{
    int menu, funcao,info;
    Lista *lesma;

    while(menu)
    {
        printf("Digite a funcao que deseja realizar:");
        scanf("%d", &funcao);
        cria(lesma);
        switch(funcao)
        {
            case 1:
            printf("Retirar: \n");
            retira(lesma, info);
            break;

            case 2:
            printf("Buscar: \n");
            break;

            case 3: 
            printf("Liberar: \n");
            break;

            case 4:
            printf("Imprimir: \n");
            imprime (lesma);
            break;
        }
    }
return 0;
}