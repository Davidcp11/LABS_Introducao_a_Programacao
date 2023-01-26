/*  David Costa Pereira                               */
/*  Turma 3                                           */
/*  Exercicio 7: Matrizes                             */
/*                                                    */
/*  Programa compilado com CodeBlocks 20.03           */

#include <stdio.h>
#include <math.h>
//Declarando variaveis globais
float mat[10][10];
int m, n;
FILE *entrada, *saida;
//Funcao para encontrar o menor elemento
void menorEl()
{
    //Abrindo o arquivo de saida
    saida = fopen("Lab8_David_Costa_Pereira.txt", "w");
    //Declarando e atribuindo algumas variaveis
    float aux, menor = mat[0][0];
    int linha=0, coluna=0;
    //Percorrendo a matriz
    for(int i = 0; i < m; i++)
        for(int k = 0; k < n; k++)
        {
            aux=mat[i][k];
            //Verificando se o elemento eh menor
            if(aux<menor)
            {
                menor = aux;
                linha = i;
                coluna = k;
            }
        }
    //Exibindo o menor elemento e sua posicao
    fprintf(saida, "Item a) O menor elemento esta na linha %d, coluna %d e vale %g\n\n", linha, coluna, menor);
    //Fechando arquivo de saida
    fclose(saida);
}
/*--------------------------------------------*/
void viz_negativos()
{
    //Abrindo o arquivo de saida
    saida = fopen("Lab8_David_Costa_Pereira.txt", "a");
    int viz_neg=0, linha=0, coluna=0, aux;
    for(int i=0; i < m; i++)
        for(int k=0; k < n; k++)
        {
            aux=0;
            //Percorrendo os vizinhos
            for(int a=i-1; a<=i+1; a++)
                for(int b=k-1; b<=k+1; b++)
                    //Verificando se o vizinho eh uma posicao valida e se eh negativo
                    if(mat[a][b]<0 && (a<m && b<n) && (a>=0 && b>=0) && (a!=i || b!=k))
                            aux++;
            //Verificando se eh o max ate entao
            if(aux>viz_neg)
            {
                viz_neg=aux;
                linha=i;
                coluna=k;
            }
        }
    //Exibindo a posicao e o total de vizinhos negativos do elemento em questao
    if(viz_neg)
        fprintf(saida,"Item b) O elemento com mais vizinhos negativos esta na linha %d, coluna %d e tem %d vizinhos negativos\n\n", linha, coluna, viz_neg);
    else fprintf(saida, "Item b) A matriz nao tem elementos negativos\n\n");
    //Fechando arquivo de saida
    fclose(saida);
}
/*--------------------------------------------*/
//Funcao para determinar a menor diferenca entre dois termos da matriz
void par_com_menor_dif()
{
    //Abrindo o arquivo de saida
    saida = fopen("Lab8_David_Costa_Pereira.txt", "a");
    //Declarando e atribuindo algumas variaveis
    int linha1, coluna1, linha2=1, coluna2=1;
    float menordif, aux;
    menordif = fabs(mat[0][0]-mat[1][1]);
    //Percorrendo a matriz no arquivo de entrada e alocando os termos
    for(int a=0; a<m; a++)
        for(int b=0; b<n; b++)
        {
            //Fixando um elemento
            aux=mat[a][b];
            //Variando a segundo elemento e calculando o modulo da diferenca entre eles
            for(int i=0; i<m; i++)
                for(int k=0; k<n; k++)
                {
                    //VErificando se o segundo elemento e diferente do primeiro
                    if(a!=i || b!=k)
                    {
                        if(fabs(aux-mat[i][k])<=menordif)
                        {
                            menordif = fabs(aux - mat[i][k]);
                            linha1=a;
                            coluna1=b;
                            linha2=i;
                            coluna2=k;
                        }
                    }
                }
        }
    //Exibindo o valor da menor diferenca e a localizacao dos dois elementos
    fprintf(saida, "Item c) A menor diferenca vale %g\n", menordif);
    fprintf(saida, "        Com um dos elementos na linha %d, coluna %d e o outro na linha %d, coluna %d\n\n", linha1, coluna1, linha2, coluna2);
    //Fechando o arquivo de saida
    fclose(saida);
}
/*--------------------------------------------*/
//Funcao para calcular a "norma um"
void norma1()
{
    //Abrindo arquivo de saida
    saida = fopen("Lab8_David_Costa_Pereira.txt", "a");
    //Declarando e atribuindo algumas variaveis
    int coluna=0;
    float soma, somax=0;
    //Percorrendo cada coluna
    for(int k=0; k<n; k++)
    {
        soma=0;
        for(int i=0; i<m; i++)
        {
            //Somando os elementos da coluna
            soma+=fabs(mat[i][k]);
        }
        //Se a soma for maior que a soma max, atribua o valor da soma 'a soma max e guarde a coluna
        if(soma>somax)
        {
            somax=soma;
            coluna=k;
        }
    }
    //Exibindo a "norma um" e a coluna em que se encontra
    fprintf(saida, "Item d) A \"norma um\" vale %g, e corresponde a coluna %d\n", somax, coluna);
    //Fechando arquivo de saida
    fclose(saida);
}
/*--------------------------------------------*/
int main()
{
    //Abrindo arquivo de entrada
    entrada = fopen("entrada8.txt", "r");
    //Lendo as dimensoes da matriz
    fscanf(entrada, "%d ", &m);
    fscanf(entrada, "%d ", &n);
    //Percorrendo a matriz
    for(int i = 0; i < m; i++)
        for(int k = 0; k < n; k++)
        {
            fscanf(entrada, "%f ", &mat[i][k]);
        }
    //Item a
    menorEl();
    //Item b
    viz_negativos();
    //Item c
    par_com_menor_dif();
    //Item d
    norma1();
    //Fechando arquivo de leitura
    fclose(entrada);
    return 0;
}
