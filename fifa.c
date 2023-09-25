#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    char posicao[3];
    float chute;
    float drible;
    float defesa;
    float velocidade;
    float passe;
    float forca;
    float overall;
    char tier[10];
}Jogador;

Jogador * decide_tier(Jogador *jogador, int n){
    
        if(jogador[n].overall >= 90)
        strcpy(jogador[n].tier, "TOTY");
        else if(jogador[n].overall >=70)
        strcpy(jogador[n].tier, "LEGEND");
        else if(jogador[n].overall >= 60)
        strcpy(jogador[n].tier, "OURO");
        else if(jogador[n].overall < 60)
        strcpy(jogador[n].tier, "PRATA");

        return jogador;
    
}

Jogador* calculo_overall(Jogador *jogador, int n){
    for(int i = 0; i < n; i++){
    if(strcmp(jogador[i].posicao, "GOL") == 0)
    jogador[i].overall = (jogador[i].chute*2 + jogador[i].drible*1 + jogador[i].defesa*5 + jogador[i].velocidade*2 + jogador[i].passe*1 + jogador[i].forca*4) / 15.0;
    else if(strcmp(jogador[i].posicao, "ATA") == 0)
    jogador[i].overall = (jogador[i].chute*5 + jogador[i].drible*3 + jogador[i].defesa*1 + jogador[i].velocidade*3 +jogador[i].passe*2 +jogador[i].forca*1) / 15.0;
    else if(strcmp(jogador[i].posicao, "MEI") == 0)
    jogador[i].overall = (jogador[i].chute*3 + jogador[i].drible*3 + jogador[i].defesa*2 + jogador[i].velocidade*3 +jogador[i].passe*2 +jogador[i].forca*2) / 15.0;
    else if(strcmp(jogador[i].posicao, "ZAG") == 0)
    jogador[i].overall = (jogador[i].chute*2 + jogador[i].drible*1 + jogador[i].defesa*5 + jogador[i].velocidade*2 +jogador[i].passe*1 +jogador[i].forca*4) / 15.0;

    jogador = decide_tier(jogador, i);

    printf("%s - %s - %s\nOverall: %.2f\nChute: %f\nDrible: %f\nForça: %f\nDefesa: %f\nVelocidade: %f\nPasse: %f\n", jogador[i].nome, jogador[i].posicao, jogador[i].tier,jogador[i].overall, jogador[i].chute, jogador[i].drible, jogador[i].forca, jogador[i].defesa, jogador[i].velocidade, jogador[i].passe);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(jogador[j].overall < jogador[j+1].overall){
                Jogador aux = jogador[j];
                jogador[j] = jogador[j+1];
                jogador[j+1] = aux;
            }
        }
    }
    return jogador;
}


void showdestaque(char* destaque,Jogador *Jogador, int n ){
    int flag = 0;
    for(int i = 0; i < n && flag == 0; i++){
        
        if(strcmp(destaque, "FINALIZADOR") == 0 && strcmp("ATA", Jogador[i].posicao) == 0){
            printf("O melhor jogador para a habilidade %s eh: %s\n", destaque, Jogador[i].nome);
            flag = 1;
        }
        if(strcmp(destaque, "DRIBLADOR") == 0 && strcmp("MEI", Jogador[i].posicao) == 0){
            printf("O melhor jogador para a habilidade %s eh: %s\n", destaque, Jogador[i].nome);
            flag = 1;
        }
        if(strcmp(destaque, "DEFENSOR NATO") == 0 &&( strcmp("ZAG", Jogador[i].posicao) == 0) || (strcmp("GOL", Jogador[i].posicao) == 0)){
            printf("O melhor jogador para a habilidade %s eh: %s\n", destaque, Jogador[i].nome);
            flag = 1;
        }
    }
    if(!flag){
        printf("O melhor jogador para a habilidade %s eh: %s\n", destaque, Jogador[0].nome);
    }
    
} 

int main(){
    char destaque[20];
    int n;
    scanf("%d", &n);
    Jogador *jogadores = NULL;

    jogadores = (Jogador *) malloc(sizeof(Jogador) * n);

    for(int i = 0; i < n; i++){
        scanf(" %[^\n]",jogadores[i].nome);
        scanf(" %s",jogadores[i].posicao);
        scanf("%f %f %f %f %f %f", &jogadores[i].chute, &jogadores[i].drible, &jogadores[i].forca, &jogadores[i].defesa, &jogadores[i].velocidade, &jogadores[i].passe);
    }

    jogadores = calculo_overall(jogadores, n);
    scanf(" %[^\n]", destaque);
    showdestaque(destaque, jogadores, n);
    
    free(jogadores);
    return 0;
}