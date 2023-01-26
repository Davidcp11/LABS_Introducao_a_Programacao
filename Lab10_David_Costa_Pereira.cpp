/*  David Costa Pereira                               */
/*  Turma 3                                           */
/*  Exercicio 10: Vestibular                          */
/*                                                    */
/*  Programa compilado com CodeBlocks 20.03           */

#include <stdio.h>
#include <string.h>

#define boolean int
#define TRUE 1
#define FALSE 0

struct candidato
{
    char nome[30];
    int n_inscricao;
    char curso;
    char respostas[51];
    float nota;
    char situacao[15];
    int fez_a_prova;
};

struct candidato dados[70];

int main()
{
    int numb_c,
        numb_r,
        n_insc;
    char gab[51];
    char leitura[100];
    FILE * inscritos,
         * resps,
         * gabarito,
         * saida;
    /// Abrindo arquivos de entrada.
    inscritos = fopen("Lab10_inscritos.txt", "r");
    resps = fopen("Lab10_respostas_preenchidas.txt", "r");
    gabarito = fopen("Lab10_gabarito.txt", "r");
    /// Abrindo arquivo de saida.
    saida = fopen("Lab10_David_Costa_Pereira.txt", "w");
    /// Lendo as linhas iniciais.
    fgets(leitura, 100, inscritos);
    fgets(leitura, 100, inscritos);
    fgets(leitura, 100, inscritos);
    fgets(leitura, 100, inscritos);
    fgets(leitura, 32, inscritos);
    /// Numero de candidatos.
    fscanf(inscritos, " %d ", &numb_c);
    fgets(leitura, 100, inscritos);
    fgets(leitura, 100, inscritos);
    fgets(leitura, 100, inscritos);
    /// Dados de cada candidato.
    for(int i=0; i<numb_c; i++)
    {
        fscanf(inscritos, " %d ", &dados[i].n_inscricao);
        fgets(dados[i].nome, 28, inscritos);
        fscanf(inscritos, " %c ", &dados[i].curso);
    }
    /// Lendo as respostas.
    /// Lendo as linhas iniciais.
    fgets(leitura, 100, resps);
    fgets(leitura, 100, resps);
    fgets(leitura, 100, resps);
    fgets(leitura, 100, resps);
    fgets(leitura, 31, resps);
    /// Numero de respostas recebidas.
    fscanf(resps, " %d ", &numb_r);
    fgets(leitura, 100, resps);
    fgets(leitura, 100, resps);
    boolean achou;
    for(int i=0; i<numb_r; i++)
    {
        achou = FALSE;
        fscanf(resps, " %d ", &n_insc);
        for(int k=0; k<numb_c && !achou; k++)
        {
            if(dados[k].n_inscricao == n_insc)
            {
                fscanf(resps, " %s ", &dados[k].respostas);
                dados[k].fez_a_prova = 1;
                achou = TRUE;
            }
        }
    }
    /// Lendo gabarito, vags por curso e nota minima de cada curso.
    /// Lendo as linhas iniciais.
    fgets(leitura, 100, gabarito);
    fgets(leitura, 100, gabarito);
    fgets(leitura, 100, gabarito);
    fgets(leitura, 100, gabarito);
    fgets(leitura, 100, gabarito);
    fscanf(gabarito, " %s ", gab);
    fgets(leitura, 100, gabarito);
    fgets(leitura, 100, gabarito);
    fgets(leitura, 100, gabarito);
    /// Variaveis para as notas minimas e para o numero de vagas.
    int   vagas_C,
          vagas_A,
          vagas_T;
    float notam_C,
          notam_A,
          notam_T;
    /// Lendo o numero de vagas e a nota minima de cada curso.
    fscanf(gabarito, " %s ", leitura);
    fscanf(gabarito, " %d ", &vagas_C);
    fscanf(gabarito, " %f ", &notam_C);
    fscanf(gabarito, " %s ", leitura);
    fscanf(gabarito, " %d ", &vagas_A);
    fscanf(gabarito, " %f ", &notam_A);
    fscanf(gabarito, " %s ", leitura);
    fscanf(gabarito, " %d ", &vagas_T);
    fscanf(gabarito, " %f ", &notam_T);
    /// Fechando os arquivos.
    fclose(inscritos);
    fclose(resps);
    fclose(gabarito);
    /// Atribuindo a nota de cada um dos candidatos.
    float nota_indiv;
    for(int i=0; i<numb_c; i++)
    {
        nota_indiv=0;
        for(int k=0; k<50; k++)
            if(dados[i].respostas[k] == gab[k])
                nota_indiv++;
        dados[i].nota = (nota_indiv)/5.0;
    }
    /// Ordenando os candidatos por nota.
    struct candidato aux;
    for(int i=0; i<numb_c; i++)
        for(int k=0; k<numb_c-i-1; k++)
        {
            if(dados[k].nota<dados[k+1].nota)
            {
                aux=dados[k];
                dados[k]=dados[k+1];
                dados[k+1]=aux;
            }
        }
    /// Atribuindo a situacao final de cada candidato.
    int n1=vagas_C,
        n2=vagas_A,
        n3=vagas_T;
    for(int i=0; i<numb_c; i++)
    {
        if(dados[i].curso == 'C')
        {
            if(dados[i].nota>=notam_C)
            {
                if(n1)
                {
                    strcpy(dados[i].situacao, "classificado");
                    n1--;
                }
                else strcpy(dados[i].situacao, "fila de espera");
            }
            else
            {
                if(dados[i].fez_a_prova)
                    strcpy(dados[i].situacao, "reprovado");
                else strcpy(dados[i].situacao, "ausente");
            }
        }
        if(dados[i].curso == 'A')
        {
            if(dados[i].nota>=notam_A)
            {
                if(n2)
                {
                    strcpy(dados[i].situacao, "classificado");
                    n2--;
                }
                else strcpy(dados[i].situacao, "fila de espera");
            }
            else
            {
                if(dados[i].fez_a_prova)
                    strcpy(dados[i].situacao, "reprovado");
                else strcpy(dados[i].situacao, "ausente");
            }
        }
        if(dados[i].curso == 'T')
        {
            if(dados[i].nota>=notam_T)
            {
                if(n3)
                {
                    strcpy(dados[i].situacao, "classificado");
                    n3--;
                }
                else strcpy(dados[i].situacao, "fila de espera");
            }
            else
            {
                if(dados[i].fez_a_prova)
                    strcpy(dados[i].situacao, "reprovado");
                else strcpy(dados[i].situacao, "ausente");
            }
        }
    }

    /// Ordenando por ordem alfabetica.
    for(int i=0; i<numb_c; i++)
        for(int k=0; k<numb_c-i-1; k++)
        {
            if(strcmp(dados[k].nome, dados[k+1].nome)>0)
            {
                aux=dados[k];
                dados[k]=dados[k+1];
                dados[k+1]=aux;
            }
        }
    /// Relatorio "a".
    fprintf(saida, "Com o teste do enunciado, as respostas sao as seguintes.\n\n");
    fprintf(saida, "----------------------------------\n");
    fprintf(saida, "a) Classificados no vestibular\n");
    fprintf(saida, "----------------------------------\n\n");
    fprintf(saida, "Sub-lista Computacao:\n");
    for(int i=0; i<numb_c; i++)
    {
        if(dados[i].curso=='C')
            if(strcmp(dados[i].situacao, "classificado")==0)
                fprintf(saida, "\n    %s", dados[i].nome);
    }
    if(n1==vagas_C)
        fprintf(saida, "\n");
    else fprintf(saida, "\n\n");
    fprintf(saida, "        Numero de classificados: %d\n", vagas_C-n1);
    fprintf(saida, "        Vagas remanescentes:     %d\n", n1);
    fprintf(saida, "\n");
    fprintf(saida, "Sub-lista Astronomia:\n");
    for(int i=0; i<numb_c; i++)
    {
        if(dados[i].curso=='A')
            if(strcmp(dados[i].situacao, "classificado")==0)
                fprintf(saida, "    %s\n", dados[i].nome);
    }
    if(n2==vagas_A)
        fprintf(saida, "\n");
    else fprintf(saida, "\n\n");
    fprintf(saida, "        Numero de classificados: %d\n", vagas_A-n2);
    fprintf(saida, "        Vagas remanescentes:     %d\n", n2);
    fprintf(saida, "\n");
    fprintf(saida, "Sub-lista Turismo:\n");
    for(int i=0; i<numb_c; i++)
    {
        if(dados[i].curso=='T')
            if(strcmp(dados[i].situacao, "classificado")==0)
                fprintf(saida, "\n    %s", dados[i].nome);
    }
    if(n3==vagas_T)
        fprintf(saida, "\n");
    else fprintf(saida, "\n\n");
    fprintf(saida, "        Numero de classificados: %d\n", vagas_T-n3);
    fprintf(saida, "        Vagas remanescentes:     %d\n", n3);
    fprintf(saida, "\n");
    /// Relatorio "b".
    fprintf(saida, "----------------------------------\n");
    fprintf(saida, "b) Pontuacao geral\n");
    fprintf(saida, "----------------------------------\n\n");
    /// Organizando por ordem de nota.
    for(int i=0; i<numb_c; i++)
        for(int k=0; k<numb_c-i-1; k++)
        {
            if(dados[k].nota<dados[k+1].nota)
            {
                aux=dados[k];
                dados[k]=dados[k+1];
                dados[k+1]=aux;
            }
        }
    fprintf(saida, "Posicao       Nome                   Nota\n\n");
    int caso=0;
    for(int i=0; i<numb_c; i++)
        if(dados[i].fez_a_prova)
        {
            caso++;
            fprintf(saida, "   %2d    ", caso);
            fprintf(saida, "%s", dados[i].nome);
            fprintf(saida, "%2.1f\n", dados[i].nota);
        }
    fprintf(saida, "\n");
    /// Relatorio "c".
    fprintf(saida, "----------------------------------\n");
    fprintf(saida, "c) Relatorio completo\n");
    fprintf(saida, "----------------------------------\n\n");
    /// Organizando por ordem alfabetica.
    for(int i=0; i<numb_c; i++)
        for(int k=0; k<numb_c-i-1; k++)
        {
            if(strcmp(dados[k].nome, dados[k+1].nome)>0)
            {
                aux=dados[k];
                dados[k]=dados[k+1];
                dados[k+1]=aux;
            }
        }
    fprintf(saida, "Num.          Nome                   Curso    Nota   Situacao\n\n");
    for(int i=0; i<numb_c; i++)
    {
        fprintf(saida, "%4d  ", dados[i].n_inscricao);
        fprintf(saida, "%s", dados[i].nome);
        switch(dados[i].curso)
        {
        case 'C':
            fprintf(saida, "Computacao   ");
            break;
        case 'A':
            fprintf(saida, "Astronomia   ");
            break;
        case 'T':
            fprintf(saida, "Turismo      ");
            break;
        }
        if(dados[i].fez_a_prova)
        {
            fprintf(saida, "%2.1f  ", dados[i].nota);
            fprintf(saida, "%s\n", dados[i].situacao);
        }
        else
        {
            fprintf(saida, "0.0  ");
            fprintf(saida, "ausente\n");
        }
    }
    ///Fechando arquivos de saida.
    fclose(saida);
    return 0;
}
