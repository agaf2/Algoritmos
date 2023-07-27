
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//lollapalloza

    typedef struct {
        char nome[100];
        char comida[100];
        char bebida[100];
        char artista[100];
        int agregados;
} ficha;


int main() {
int n; //numero de convidados
//printf("digite o numero de convidados:\n");
scanf("%d", &n);
    
    ficha convidado[n];
    
    for(int i =0; i<n; i++){
     //   printf("digite o nome do convidado %d: ", i+1);
        scanf(" %s", convidado[i].nome);
       // printf (" digite a quantidade de agregados do convidado %d:", i+1);
        scanf("%d", &convidado[i].agregados);
        //printf("digite a comida do convidado %d: ", i+1);
        scanf(" %s", convidado[i].comida);
        //printf("digite a bebida do convidado %d: ", i+1);
        scanf(" %s", convidado[i].bebida);
       // printf("digite o artista do convidado %d: ", i+1);
        scanf(" %[^\n]", convidado[i].artista);
    }
    
    //desempatar duas categorias c mesmo votos. ordem alfabeta
    ficha favoritas;
    
    int comida [5] = {0, 0, 0, 0, 0};
    int bebida[5] = {0, 0, 0, 0, 0};
    int artista [5] = {0, 0, 0, 0, 0};
    
    int menorAgregados = 1000000; // valor inicial alto para garantir que qualquer nÃºmero seja menor

    for (int i = 0; i < n; i++) {
        if (convidado[i].agregados < menorAgregados) {
            menorAgregados = convidado[i].agregados;
        }
    }

    printf(" %d\n", menorAgregados);

    
    
    for (int i = 0; i < n; i++) {
    //comidq
        if (strcmp(convidado[i].comida, "coxinha") == 0) {
            comida[1]++;
    }   else if (strcmp(convidado[i].comida, "brigadeiro") == 0) {
            comida[0]++;
    }   else if (strcmp(convidado[i].comida, "risoto") == 0) {
            comida[4]++;
    }   else if (strcmp(convidado[i].comida, "picanha") == 0) {
            comida[2]++;
    }   else if (strcmp(convidado[i].comida, "pizza") == 0) {
            comida[3]++;
    }

    // bebida
    if (strcmp(convidado[i].bebida, "agua") == 0) 
        bebida[0]++;
     else if (strcmp(convidado[i].bebida, "suco") == 0) 
         bebida[4]++;
     else if (strcmp(convidado[i].bebida, "monster") == 0) 
         bebida[2]++;
     else if (strcmp(convidado[i].bebida, "cafe") == 0) 
         bebida[1]++;
     else if (strcmp(convidado[i].bebida, "pitu") == 0) 
         bebida[3]++;
    

    // artista
    if (strcmp(convidado[i].artista, "Gustavo Mioto") == 0) {
        artista[1]++;
    } else if (strcmp(convidado[i].artista, "Billie Eilish") == 0) {
        artista[0]++;
    } else if (strcmp(convidado[i].artista, "Pericles") == 0) {
        artista[3]++;
    } else if (strcmp(convidado[i].artista, "Shevchenko e Elloco") == 0) {
        artista[4]++;;
    } else if (strcmp(convidado[i].artista, "Joao Gomes") == 0) {
        artista[2]++;
        }
    }

  
    int parou = 0;

    for (int i =0; i < 5 && !parou; i++){
        int cont = 0;
        parou =0;
        for (int j = 0; j <= 5; j ++){
            if (comida[i] > comida[j]){
                cont++;
            }
        } if (cont == 4){
            parou = 1;
            if (i == 0){
                printf("brigadeiro\n");
            }
            if (i == 1){
                printf("coxinha\n");
            }
            if (i == 2){
                printf("picanha\n");
            }
            if (i == 3){
                printf("pizza\n");
            }
            if (i == 4){
                printf("risoto\n");
            }
    }
    }  
    
  parou = 0;
  
    for (int i =0; i < 5 && !parou; i++){
        int cont = 0;
        parou =0;
        for (int j = 0; j <= 5; j ++){
            if (bebida[i] > bebida[j]){
                cont++;
            }
        } if (cont == 4){
            parou = 1;
            if (i == 0){
                printf("agua\n");
            }
            if (i == 1){
                printf("cafe\n");
            }
            if (i == 2){
                printf("monster\n");
            }
            if (i == 3){
                printf("pitu\n");
            }
            if (i == 4){
                printf("suco\n");
            }
    }
    }   
    
  parou = 0;
  
    for (int i =0; i < 5 && !parou; i++){
        int cont = 0;
        parou =0;
        for (int j = 0; j <= 5; j ++){
            if (artista[i] > artista[j]){
                cont++;
            }
        } if (cont == 4){
            parou = 1;
            if (i == 0){
                printf("Billie Eilish\n");
            }
            if (i == 1){
                printf("Gustavo Mioto\n");
            }
            if (i == 2){
                printf("Joao Gomes\n");
            }
            if (i == 3){
                printf("Pericles\n");
            }
            if (i == 4){
                printf("Shevchenko e Elloco\n");
            }
    }
    }   
    
    printf("convidados vip:\n");
    
    
    
  
    
    





return 0;
}