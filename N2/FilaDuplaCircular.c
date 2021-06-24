#include <stdio.h>
#include <stdlib.h>

struct no
{
   int info;
   struct no* elo_anterior;
   struct no* elo_proximo;
};

typedef struct no No;

struct fila
{
   No* inicio;
   No* fim;
};

typedef struct fila Fila;

Fila* cria()
{
   Fila* fila = (Fila*) malloc(sizeof(Fila));
   if(fila == NULL)
    {
      printf("Memoria insuficiente!\n");
      exit(1);
    }
   fila->inicio = NULL;
   fila->fim = NULL;
   printf("\nFila criada com sucesso!\n");
   return fila;
}

void vazia(Fila* fila)
{
    if(fila->inicio == NULL && fila->fim == NULL)
    {  // se o inicio e o fim estiverem vazios, a fila está vazia
        printf("\nA fila esta vazia.\n");
    }
    else{
        printf("\nA fila nao esta vazia.\n");
    }
}

No* insere_inicio(int info, No* inicio, No* fim)
{
   No* no = (No*) malloc(sizeof(No));
   no->info = info;
   no->elo_proximo = inicio;
   no->elo_anterior = NULL;
   if(fim == NULL && inicio == NULL)
    {
        no->elo_proximo = no;
        no->elo_anterior = no;
    }
   else
    {
        inicio->elo_anterior = no;
        no->elo_anterior = fim;
        fim->elo_proximo = no;
    }
   return no;
}

void enqueue_inicio(Fila* fila , int info)
{
   fila->inicio = insere_inicio(info, fila->inicio, fila->fim);
   if(fila->fim == NULL)
    {
      fila->fim = fila->inicio;
    }
}

No* retira_inicio(No* inicio, No* fim)
{
   No* no = inicio->elo_proximo;
   no->elo_anterior = inicio->elo_anterior;
   fim->elo_proximo = no;
   if (inicio->elo_anterior == inicio)
   {
      free(inicio);
      return NULL;
   }
   return no;
}

int dequeue_inicio(Fila* fila)
{
   int valorRemovido = fila->inicio->info;
   fila->inicio = retira_inicio(fila->inicio, fila->fim);
   if(fila->inicio == NULL)
   {
      fila->fim = NULL;
   }
   return valorRemovido;
}

No* insere_fim(No* fim , int info, No* inicio)
{
   No* no = (No*) malloc(sizeof(No));
   no->info = info;
   no->elo_proximo = NULL;
   no->elo_anterior = fim;
   if(fim == NULL && inicio == NULL)
    {
        no->elo_proximo = no;
        no->elo_anterior = no;
    }
   else
    {
        fim->elo_proximo = no;
        no->elo_proximo = inicio;
        inicio->elo_anterior = no;
    }
   return no;
}

void enqueue_fim(Fila* fila, int info)
{
   fila->fim = insere_fim(fila->fim , info, fila->inicio);
   if(fila->inicio == NULL)
   {
      fila->inicio = fila->fim;
   }
}

No* retira_fim(No* fim, No* inicio)
{
   No* no = fim->elo_anterior;
   no->elo_proximo = fim->elo_proximo;
   inicio->elo_anterior = no;
   if (fim->elo_anterior == fim)
    {
      free(fim);
      return NULL;
    }
   return no;
}

int dequeue_fim(Fila* fila)
{
   int valorRemovido = fila->fim->info;
   fila->fim = retira_fim(fila->fim, fila->inicio);
   if (fila->fim == NULL)
    {
      fila->inicio = NULL;
    }
   return valorRemovido;
}

void imprime(Fila* fila)
{
    No* no;
    printf("\nFila: %p\nNo inicio: %p\nNo fim: %p\n", fila, fila->inicio, fila->fim);
    no = fila->inicio;
    if(fila->inicio == NULL && fila->fim == NULL)
    {
        printf("\nA fila esta vazia.\n");
    }
    else
    {
      do
      {
         printf("\nNo: %p => Info: %d | Elo anterior: %p | Elo proximo: %p\n", no, no->info, no->elo_anterior, no->elo_proximo);
         no = no->elo_proximo;
      }
    while(no != fila->inicio);
      printf("\n");
    }
}

void libera(Fila* fila)
{
   No* no;
   No* no_anterior;
   for(no = fila->inicio; no != NULL; no = no_anterior)
   {
      no_anterior = no->elo_proximo;
      free(no);
   }
   free(fila);
}
int main()
{

    Fila* f1;

    int menu, num;

    do{
        printf("\nPrograma de Criar um Fila Dupla Circular \n");
        printf("1 - Cria fila\n");
        printf("2 - Verifica se existe fila\n");
        printf("3 - Insere um numero no inicio da fila\n");
        printf("4 - Insere um numero no final da fila\n");
        printf("5 - Remove o numero do inicio da fila\n");
        printf("6 - Remove o numero do final da fila\n");
        printf("7 - Mostrar a fila\n");
        printf("8 - Elimina a fila\n");
        printf("9 - Sair\n");
        scanf("%d", &menu);

        switch(menu)
        {
            //Cria a fila
            case 1:
                f1 = cria();
                break;

            //Verifica se a fila esta vazia
            case 2:
                vazia(f1);
                break;

            //Insere numero no inicio fila
            case 3:
                printf("\nDigite o numero a ser inserido no inicio fila: \n");
                scanf("%d", &num);
                enqueue_inicio(f1, num);
                break;

            //Insere numero no final fila
            case 4:
                printf("\nDigite o numero a ser inserido no final fila: \n");
                scanf("%d", &num);
                enqueue_fim(f1, num);
                break;

            //Retira numero do inicio da fila
            case 5:
                num = dequeue_inicio(f1);
                printf("\nNumero retirado: %d\n", num);
                break;

            //Retira numero do final da fila
            case 6:
                num = dequeue_fim(f1);
                printf("\nNumero retirado: %d\n", num);
                break;

            //Imprime a fila
            case 7:
                imprime(f1);
                break;

            //Libera a fila
            case 8:
                libera(f1);
                break;
        }
    } while(menu != 9);

    return 0;
}
