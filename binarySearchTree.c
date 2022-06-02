#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{

    int id;

    struct vertice * dir;
    struct vertice * esq;

}VERTICE;

VERTICE *raiz = NULL;
int tam = 0;

VERTICE* search(int id, VERTICE* aux){
    if(aux != NULL){   
        if(aux->id == id){
            return raiz;

        }else if(aux->id > id){
            if(aux->esq != NULL){
                return search(id, aux->esq);

            }else{
                return aux;
            }

        }else if(aux->id < id){
            if(aux->dir != NULL){
                return search(id, aux->dir);
            
            }else{
                return aux;
            }

        }
    }else{
        return NULL;
    }
}


void adicionar(int id){

    //busca
    VERTICE *aux = search(id, raiz); 
    
    //condicao de existencia com base na busca
    if(aux != NULL && aux->id == id){ //se aux->id vinhesse como primeira condição daria estouro de memoria
        printf("Não foi possivel fazer a insercao\n");

    }else{
        VERTICE* novo = malloc(sizeof(VERTICE));
        novo->id = id;
        novo->dir = NULL;
        novo->esq = NULL;

        if(aux == NULL){
            raiz = novo;

        }else{
            if(aux->id > id){
                aux->esq = novo;

            }else{
                aux->dir = novo;
            }
        }
    }
    
}



void pre_ordem(VERTICE *aux){
    printf("%d ", aux->id);

    if(aux->esq != NULL){
        pre_ordem(aux->esq);
    }

    if(aux->dir != NULL){
        pre_ordem(aux->dir);
    }
}

void in_ordem(VERTICE *aux){
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }

    printf("%d ", aux->id);

    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}

void pos_ordem(VERTICE *aux){
    if(aux->esq != NULL){
        pos_ordem(aux->esq);
    }

    if(aux->dir != NULL){
        pos_ordem(aux->dir);
    }

    printf("%d ", aux->id);
    
}


int main(){
    adicionar(10);
    adicionar(5);
    adicionar(11);
    adicionar(3);
    adicionar(8);
    
    in_ordem(raiz);
    printf("\n");
    

    return 0;
}