#include <stdio.h>
#include <stdlib.h>

//MATRIZ TAD MATRIZ

struct matriz{
    int linhas;
    int colunas;
    int** info;
};

typedef struct matriz Matriz;

Matriz* cria(int linhas , int colunas){
    int i;
    Matriz* matriz = (Matriz*) malloc(sizeof(Matriz));
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->info = (int**) malloc(linhas * sizeof(int*));
    for (i = 0; i < linhas; i++){
        matriz->v[i] = (int*) malloc(colunas * sizeof(int));
    }
    return matriz;
}

void insere(Matriz* matriz , int i , int j , int info) {
    if (i < 0 || i >= matriz->linhas || j < 0 || j >= matriz->colunas) {
        printf("Parametros inexistentes!\n");
    }
    matriz->info[i][j] = info;
}

int acessa(Matriz* matriz , int i , int j) {
    if (i < 0 || i >= matriz->linhas || j < 0 || j > matriz->colunas) {
        printf("Parametros inexistentes!\n");
    }
    return matriz->info[i][j];
}

int linhas(Matriz* matriz) {
    return matriz->linhas;
}

int colunas(Matriz* matriz) {
    return matriz->colunas;
}

void libera(Matriz* matriz){
    int i;
    for (i = 0; i < linhas; i++){
        free(matriz->info[i]);
    }
    free(matriz->info);
    free(matriz);
}
int main()
{   
    Matriz** m;
    int menu, criaMatriz;
    int  linhas, colunas;

    while(criaMatriz != 's' || criaMatriz != 'S')
    {
        printf("Deseja criar uma matriz? (S) ou (N)");
        scanf("%d", &criaMatriz);
            
        if(criaMatriz == 's' || criaMatriz == 'S')
        {   
            printf("Linhas: ");
            scanf("%d", &linhas);

            printf("Colunas: ");
            scanf("%d", &colunas);

            cria(Linhas, colunas);
            
            if(linhas(linhas) == 0 && colunas(colunas))
            {
                pritnf("Matriz criada com sucesso!");
            }else(
                printf("Falha na criação da matriz!");
            }
            
        }else
        {
            print("Crie a matriz para prosseguir!\n");
        }
    }

    switch (menu)
    {

    }
    
    
    return 0;
}

