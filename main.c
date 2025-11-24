#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TAM_LINHA 256
#define TAM_NOME_CIDADE 50

typedef struct Fronteira{
    char destino[4];
    float distancia;
    bool balsa;
    struct Fronteira *prox;
} Fronteira;

typedef struct{
    char Nome[TAM_NOME_CIDADE];
    char UF[2];
    Fronteira *fronteiras;
} Cidade;

void abrirArquivo(char arq[]);
void adicionarFronteira(Cidade *cidade, const char *uf, float distancia);
void imprimirCidade(Cidade *cidade);

int main(void){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    abrirArquivo("capitais.txt");
}


void imprimirCidade(Cidade *cidade){
    printf("\nCidade: %s (%s)\n", cidade->Nome, cidade->UF);

    Fronteira *f = cidade->fronteiras;
    while (f != NULL) {
        printf(" -> %s : %7.2f km\t| Usa balsa:%d\n", f->destino, f->distancia, f->balsa);
        f = f->prox;
    }
}

void adicionarFronteira(Cidade *cidade, const char *uf, float distancia){
    Fronteira *nova = (Fronteira*) malloc(sizeof(Fronteira));

    if (nova == NULL) {
        printf("Erro de alocacao\n");
        return;
    }


    if (uf[0] == '*') {
        strncpy(nova->destino, uf + 1, sizeof(nova->destino) - 1);
        nova->balsa = true;
    } else {
        strncpy(nova->destino, uf, sizeof(nova->destino) - 1);
        nova->balsa = false;
    }

    nova->destino[sizeof(nova->destino) - 1] = '\0';

    nova->distancia = distancia;
    nova->prox = cidade->fronteiras;

    cidade->fronteiras = nova;
}

void armazenarDados(FILE *file){
    char linha[MAX_TAM_LINHA];
    char *token;

    int num_linha=1;

    while(fgets(linha, MAX_TAM_LINHA, file) != NULL) {
        linha[strcspn(linha, "\n")] = 0;
        token = strtok(linha, ",");
        int tokennum =0;
        Cidade cidade;
        cidade.fronteiras = NULL;
        while(token != NULL){
            if(tokennum == 0){
                strcpy(cidade.Nome, token);
            }else if (tokennum ==1){
                strcpy(cidade.UF, token);
            }else{
                char destino[3];
                float distancia;
                sscanf(token, "%3[^:]:%f", destino, &distancia);

                adicionarFronteira(&cidade, destino, distancia);
            }
            token = strtok(NULL, ",");
            tokennum++;
        }
        imprimirCidade(&cidade);
        num_linha++;

    }
}

void abrirArquivo(char arq[]) {
    FILE *file;
    file = fopen(arq, "r");

    if (file == NULL) {
        printf("Arquivo nao pode ser aberto\n");
        system("pause");
        return;
    }

    int linhas = 0;
    char c;

    // Conta apenas as linhas
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            linhas++;
        }
    }

    // Caso o arquivo não termine com \n
    if (c != '\n' && linhas > 0) {
        linhas++;
    }


    printf("Lendo arquivo '%s'...\n", arq);
    printf("Total de capitais: %d\n\n", linhas);

    rewind(file);

    armazenarDados(file);

    fclose(file);
}


