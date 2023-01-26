/*  David Costa Pereira                               */
/*  Turma 3                                           */
/*  Exercicio 6: Strings                              */
/*                                                    */
/*  Programa compilado com CodeBlocks 20.03           */

#include <stdio.h>
#include <string.h>
int main()
{
    //Declaracoes de algumas variaveis
    int contador;
    char pasta[31], memoria[31], arquivo[16], xpalavra[16], aux[31], leitura[81];
    FILE *entrada, *saida, *entradaux;
    //Abertura dos arquivos
    entrada = fopen("Lab6\\entrada6.txt", "r");
    saida = fopen("Lab6\\Lab6_David_Costa_Pereira.txt", "w");
    //4 linhas iniciais
    fprintf(saida, "Bom dia\n");
    fprintf(saida, "Boa tarde\n");
    fprintf(saida, "Boa noite\n");
    fprintf(saida, "----------------------------------------\n");
    //Pulando as 7 primeiras linhas.
    for(int i =0; i<7; i++)
    {
        fgets (leitura, 81, entrada);
    }
    //Lendo a primeira |
    fscanf(entrada, "%s ", leitura);
    //Enquanto o tamanho da variavel de leitura nao for maior que 40, tamanho de "PASTA"+"ARQUIVO"+
    while(strcmp(leitura, "|")==0)
    {
        //Lendo o conteudo da coluna "PASTA"
        fscanf(entrada, "%s", pasta);
        //Lendo a segunda |
        fscanf(entrada, "%s ", leitura);
        //Lendo o conteudo da coluna "ARQUIVO"
        fscanf(entrada, "%s", arquivo);
        //Lendo a terceira |
        fscanf(entrada, "%s ", leitura);
        //Lendo o conteudo da coluna "PROCURAR PALAVRA"
        fscanf(entrada, "%s ", xpalavra);
        //Caso pasta seja diferente da anterior
        if(strlen(pasta)!=1)
        {
            //Preparando o endereco do arquivo
            strcpy(leitura,"\\");
            //Colocando a \ no final de "pasta"
            strcpy(pasta, strcat(pasta, leitura));
            //Quardando o endereco da pasta, caso seja um = na linha de baixo
            strcpy(memoria, pasta);
            //Passando a concatenacao de pasta+arquivo para a variavel aux
            strcpy(aux, strcat(pasta,arquivo));
            //Colocando o .txt
            strcat(aux,".txt");
            fprintf(saida, "\n%s\n", aux);
            //Abrindo o arquivo auxiliar
            entradaux=fopen(aux, "r");
            //Caso o arquivo nao seja encontrado
            if(fopen(aux, "r")==NULL)
                fprintf(saida, "\tARQUIVO NAO ENCONTRADO.\n");
        }
        //Mesmos passos da etapa anterior, so que para o caso que so a pasta nao muda e o arquivo muda
        else if(strlen(arquivo)!=1)
        {
            strcpy(aux, strcat(memoria,arquivo));
            strcat(aux,".txt");
            entradaux=fopen(aux, "r");
            fprintf(saida, "\n%s\n", aux);
            if(fopen(aux, "r")==NULL)
                fprintf(saida, "\tARQUIVO NAO ENCONTRADO.\n");
        }
        if(fopen(aux,"r")!=NULL)
        {
            contador=0;
            //Enquanto nao chegar no final do arquivo da pasta
            while(fscanf(entradaux,"%s", leitura)!=-1)
            {
                //Caso a palavra lida seja a procurada
                if(!strcmp(leitura, xpalavra))
                    contador++;
            }
            //Exibir o numero de ocorrencias da palavra x no arquivo
            fprintf(saida,"\t%s: %d ocorrencias\n", xpalavra, contador);
        }
        //Fechando a entrada auxiliar
        fclose(entradaux);
        //Lendo a quarta |
        fscanf(entrada, "%s ", leitura);
        //Pulou de linha, agora volta a ler a primeira |
        fscanf(entrada, "%s ", leitura);
    }
    //Fechando arquivos de entrada e saida e finalizando
    fclose(saida);
    fclose(entrada);
    return 0;
}
