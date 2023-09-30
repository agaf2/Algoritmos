#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int telefone[10];
    char mensagem[255];
} Frase;

char *descriptografa(char *mensagem){
    for(int i = 0; i < strlen(mensagem); i++){
        mensagem[i] = mensagem[i] - 100;
    }
    return mensagem;
}

char *criptografa(char *mensagem){
    for(int i = 0; i < strlen(mensagem); i++){
        mensagem[i] = mensagem[i] + 100;
    }
    return mensagem;
}

Frase *carregaMensagens(char *tel_de, char *tel_para, int *qtdMens){
    char nomeArq[30];
    
    sprintf(nomeArq, "%s_%s.bin", tel_de, tel_para);
    
    FILE *arq = fopen(nomeArq, "rb");
    
    if(arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    
    *qtdMens = 0;
    Frase aux, *conversa=NULL, *auxp = NULL;

    while(feof){
        fread(&aux, sizeof(Frase), 1, arq);
        
        auxp = conversa;
        conversa = (Frase *) realloc(conversa, sizeof(Frase) * (*qtdMens + 1));
        if(conversa == NULL){
            printf("Erro ao alocar memoria\n");
            free(auxp);
            exit(1);
        }

        conversa[*qtdMens] = aux;
        (*qtdMens)++;
    }
    
    fclose(arq);
    
    return conversa;
}

void mostraMensagens(Frase * mensagens, int qtdMens){
    for(int i = 0; i < qtdMens; i++){
        descriptografa(mensagens[i].mensagem);
        printf("De:%s\n%s\n", mensagens[i].telefone,mensagens[i].mensagem);
    }
}

void graveMensagem(char *tel_de, char *tel_para, char *mensagem){
    char nomeArq1[30], nomeArq2[30];
    sprintf(nomeArq1, "%s_%s.bin", tel_de, tel_para);
    sprintf(nomeArq1, "%s_%s.bin", tel_para, tel_de);
    
    FILE *arq1 = fopen(nomeArq1, "ab");
    FILE *arq2 = fopen(nomeArq2, "ab");
    if(arq1 == NULL || arq2 == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    
    Frase aux;
    strcpy(aux.telefone, tel_de);
    strcpy(aux.mensagem, mensagem);
    
    criptografa(aux.mensagem);
    
    fwrite(&aux, sizeof(Frase), 1, arq1);
    fwrite(&aux, sizeof(Frase), 1, arq2);
    fclose(arq1);
    fclose(arq2);
}

int main(){
    int qtdMens = 0, input = -1;
    char tel_de[10], tel_para[10], novamensagem[255];
    Frase * mensagens = NULL;

    printf("Digite o primeiro numero: ");
    scanf(" %s", tel_de);
    printf("Digite o segundo numero: ");
    scanf(" %s", tel_para);
    
    while(input != 4){
        printf("1 - Carregar mensagens\n2 - Mostrar mensagens\n3 - Gravar mensagem\n4 - Sair\n");
        scanf("%d", &input);
        switch(input){
            case 1:
                mensagens = carregaMensagens(tel_de, tel_para, &qtdMens);
                break;
            case 2:
                mostraMensagens(mensagens, qtdMens);
                break;
            case 3:
                printf("Digite uma nova mensagem: ");
                scanf(" %s", novamensagem);
                graveMensagem(tel_de, tel_para, novamensagem);
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }

        
    free(mensagens);

    return 0;
}