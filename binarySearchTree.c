#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{

    int id;

    struct vertice * right;
    struct vertice * left;

}VERTICE;

VERTICE *root = NULL;
int tam = 0;

VERTICE* search(int id, VERTICE* aux){
    if(aux != NULL){   
        if(aux->id == id){
            return root;

        }else if(aux->id > id){
            if(aux->left != NULL){
                return search(id, aux->left);

            }else{
                return aux;
            }

        }else if(aux->id < id){
            if(aux->right != NULL){
                return search(id, aux->right);
            
            }else{
                return aux;
            }

        }
    }else{
        return NULL;
    }
}


void insert(int id){

    //busca
    VERTICE *aux = search(id, root); 
    
    //condicao de existencia com base na busca
    if(aux != NULL && aux->id == id){ //se aux->id vinhesse como primeira condição daria estouro de memoria
        printf("Não foi possivel fazer a insercao\n");

    }else{
        VERTICE* novo = malloc(sizeof(VERTICE));
        novo->id = id;
        novo->right = NULL;
        novo->left = NULL;

        if(aux == NULL){
            root = novo;

        }else{
            if(aux->id > id){
                aux->left = novo;

            }else{
                aux->right = novo;
            }
        }
    }
    
}

VERTICE *removal(int id, VERTICE *aux){
    
    //checar se o elemento existe
    if(aux != NULL){

        //checar se o aux é o elemento escolhido
        if(aux->id == id){  
            //remover folha
            if(aux->left == NULL && aux->right == NULL){
                free(aux);
                return NULL;

            //remover com 1 filho
            }else if(aux->left == NULL || aux->right == NULL){
                VERTICE *storage;

                //armazena dependendo do ponteiro
                if(aux->left != NULL){
                    storage = aux->left;
                }else{
                    storage = aux->right;
                }
                free(aux);
                return storage;

            //remover com 2 filhos
            }else{
                VERTICE *storage = aux->left;
                while(storage->right != NULL){
                    storage = storage->right;
                }
                aux->id = storage->id;
                storage->id = id; 
                aux->left = removal(id, aux->left);
                return root;
            }
            
        }else{
            //caminhar na arvore de forma recursiva e depois retornar a raiz
            if(aux->id > id){
                aux->left = removal(id, aux->left);

            }else{
                aux->right = removal(id, aux->right);

            }
            return aux;
        }
    }else{
        printf("Valor nao encontrado!\n");
        return NULL;
    }
}

void pre_ordem(VERTICE *aux){
    printf("%d ", aux->id);

    if(aux->left != NULL){
        pre_ordem(aux->left);
    }

    if(aux->right != NULL){
        pre_ordem(aux->right);
    }
}

void in_ordem(VERTICE *aux){
    if(aux->left != NULL){
        in_ordem(aux->left);
    }

    printf("%d ", aux->id);

    if(aux->right != NULL){
        in_ordem(aux->right);
    }
}

void pos_ordem(VERTICE *aux){
    if(aux->left != NULL){
        pos_ordem(aux->left);
    }

    if(aux->right != NULL){
        pos_ordem(aux->right);
    }

    printf("%d ", aux->id);
    
}


int main(){
    insert(6);
    insert(2);
    insert(8);
    insert(1);
    insert(3);
    insert(9);
    insert(5);
    
    in_ordem(root);
    printf("\n");

    removal(1, root);

    in_ordem(root);
    printf("\n");
    
    removal(3, root);

    in_ordem(root);
    printf("\n");

    removal(6, root);

    in_ordem(root);
    printf("\n");

    

    return 0;
}