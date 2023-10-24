#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Jazigo{
    int key;
    int ocupado;
}Jazigo;

typedef struct Andar{
    Jazigo *vagas;
    int tamanho;
}Andar;

Andar * predio = NULL;
int m, l = 0;


int binary_insert(int key, int andar){
    int left = 0, right = l-1;
    while(left < right){
        int middle = (left + right)/2;
        if(predio[andar].vagas[middle].key <= key)
            left = middle + 1;
        else
            right = middle;  
    }
    if(left < predio[andar].tamanho && predio[andar].vagas[left].key < key)
        left++;
    return left;
}

int binary_search(int key, int andar){
    int left = 0;
    int right = l-1;
    int middle = (left + right)/2;
    while(left <= right){
        if( predio[andar].vagas[middle].key == key){
             return middle;
        }
        else if( predio[andar].vagas[middle].key > key){
            right = middle - 1;
            middle = (left + right)/2;      
        }
        else{
            left = middle + 1;
            middle = (left + right)/2;
        }
    }
    
    return -1;
}


int hash(int key, int cont){
    return (key % m + cont) % m;
}
    
int ADD(int key, int frehashing){
    int cont = 0;
    int index = hash(key, cont);
    while(predio[index].tamanho == l && cont != m){
        cont++;
        index = hash(key, cont);
    }

    if(cont == m)
        return 0;
    
    
        int pos = binary_insert(key, index);
        
        if(predio[index].tamanho != 0){
            for(int i = predio[index].tamanho; i > pos; i--){
                predio[index].vagas[i] = predio[index].vagas[i-1];
            }
        }

        predio[index].vagas[pos].key = key;
        predio[index].vagas[pos].ocupado = 1;
        predio[index].tamanho++;
        
        if(!frehashing)
            printf("%d.%d\n", index, pos);
        return 1;
        
}

void rehasing(){
    int auxm = m;
    m = m*2+1;
    Andar * aux = predio;
    predio = (Andar*) malloc(m * sizeof(Andar));

    for(int i = 0; i < m; i++){
        predio[i].vagas = (Jazigo*) malloc(l * sizeof(Jazigo));
        predio[i].tamanho = 0;
        for(int j = 0; j < l; j++){
            predio[i].vagas[j].ocupado = 0;
            predio[i].vagas[j].key = INT_MAX;
        }
    }
    
    for(int i = 0; i < auxm; i++){
        for(int j = 0; j < l; j++){
            if(aux[i].vagas[j].ocupado == 1)
            ADD(aux[i].vagas[j].key, 1);
        }
    }
    
    for(int i = 0; i < auxm; i++){
        free(aux[i].vagas);
    }
    free(aux);
}

void REM(int key){
    int cont = 0;
    while(cont!=m){
        int index = hash(key, cont);
        int pos = binary_search(key, index);
        if(pos != -1 && predio[index].vagas[pos].ocupado != -1){
            predio[index].vagas[pos].ocupado = -1;
            printf("%d.%d\n", index, pos);
            return;
        }
        else if( pos != -1 && predio[index].vagas[pos].ocupado == -1){
            printf("?.?\n");
            return;
        }
        cont++;
    }
    printf("?.?\n");
}

void QRY(int key){
    int cont = 0;
    while(cont!=m){
        int index = hash(key, cont);
        int pos = binary_search(key, index);
        if(pos != -1 && predio[index].vagas[pos].ocupado != -1){
            printf("%d.%d\n", index, pos);
            return;
        }
        else if( pos != -1 && predio[index].vagas[pos].ocupado == -1){
            printf("?.?\n");
            return;
        }
        cont++;
    }
    printf("?.?\n");
}

int main(){
    int key;
    char input[4];
    scanf("%d %d", &m, &l);  

    predio = (Andar*) malloc(m * sizeof(Andar));
    
    for(int i = 0; i < m; i++){
        predio[i].vagas = (Jazigo*) malloc(l * sizeof(Jazigo));
        predio[i].tamanho = 0;
        for(int j = 0; j < l; j++){
            predio[i].vagas[j].ocupado = 0;
            predio[i].vagas[j].key = INT_MAX;
        }
    }

    while(strcmp(input, "END") != 0){
        scanf("%s", input);  
        
        if(strcmp(input, "ADD") == 0){
            scanf("%d", &key);
            if(!ADD(key, 0)){
                rehasing();
                ADD(key, 0);
            }
        }
        else if(strcmp(input, "REM") == 0){
            scanf("%d", &key);
            REM(key);
        }
        else if(strcmp(input, "QRY") == 0){
            scanf("%d", &key);
            QRY(key);
        }
        else if(strcmp(input, "END") == 0){
            break;
        }
   
    }
        for(int i = 0; i < m; i++){
            free(predio[i].vagas);
        }
        free(predio);
    
    return 0;
}
