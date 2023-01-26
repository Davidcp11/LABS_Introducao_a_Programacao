/*  David Costa Pereira                               */
/*  Turma 3                                           */
/*  Exercicio 7: Subprogramacao                       */
/*                                                    */
/*  Programa compilado com CodeBlocks 20.03           */

#include <stdio.h>
#include <string.h>

#define boolean int
#define TRUE 1
#define FALSE 0
//Atribui uma frase a uma string.
void mensagem_inicial_na_tela(char c[70])
{
    strcpy(c, "Bom dia\nBoa tarde\nBoa noite\n-------------\n");
}
/*----------------------------------------------*/
//Imprime uma mensagem e pausa.
void mensagem_final_na_tela_e_pausa()
{
    printf("Programa finalizado....");
    getchar();
}
/*----------------------------------------------*/
//A funcao juros recebe a qauntidade inicial, o juros aplicado, a quantidade de meses e o tipo de juros aplicado.
//E devolve a quantidade final.
void juros(float *quant, float juros, int qmeses, char tipo)
{
    float aux=*quant;
    //Juros simples.
    if(tipo=='s' || tipo=='S')
    {
        while(qmeses--)
        {
            *quant = *quant + aux*juros/100;
        }
    }
    //Juros compostos.
    else
    {
        while(qmeses--)
        {
            *quant = *quant*(1+juros/100);
        }
    }
}
/*----------------------------------------------*/
//Recebe dois numeros e retorna a media aritmetica entre eles.
float media(float n1, float n2)
{
    return (n1+n2)/2.0;
}
/*----------------------------------------------*/
//Recebe um numero inteiro e retorna o proximo multiplo de 26.
int pmvs(int n1)
{
    n1++;
    //Enquanto o numero nao for divisivel por 26.
    while(n1%26)
        n1++;
    return n1;
}
/*----------------------------------------------*/
//Recebe um char, se for letra minuscula transforma para maiuscula, e verifica se pertence aos termos da base hexadecimal.
//Retornando TRUE em caso afirmativo e FALSE em caso negativo.
boolean hexa(char v[])
{
    boolean a = TRUE;
    //Passando as minusculas para maiusculas e verificando se eh um caractere valido.
    for (int i = 0; i < strlen(v); i++)
    {
        if ('a' <= v[i] && v[i] <= 'z')
        {
            v[i] = v[i] - 'a' + 'A';
        }
        if (!('A' <= v[i] && v[i] <= 'F' || '0' <= v[i] && v[i] <= '9'))
        {
            a = FALSE;
        }
    }
    return a;
}
int main()
{
    //Declarando algumas variaveis.
    int meses, casos=1, inteiro;
    float  numb1, numb2, juros_apl;
    boolean valido=TRUE;
    char tipo[6], leitura[70], tipojuros, aux;
    FILE *entrada, *saida;
    //Abrindo arquivos de entrada.
    entrada = fopen("entrada9.txt", "r");
    saida = fopen("Lab9_David_Costa_Pereira.txt", "w");
    //Lendo o tipo de avaliacao e verificando se chegou no fim do arquivo.
    mensagem_inicial_na_tela(leitura);
    fprintf(saida, "%s", leitura);
    while(fscanf(entrada, "%s", &tipo)!=-1)
    {
        //Exibindo o caso correspondente.
        fprintf(saida, " %.2d:  ", casos);
        casos++;
        //Verificando o tipo de tarefa.
        if(!strcmp(tipo, "juros"))
        {
            //Lendo o R$.
            fscanf(entrada,"%s ", leitura);
            //Lendo a quantidade inicial.
            fscanf(entrada,"%f ", &numb1);
            //Lendo o juros aplicado.
            fscanf(entrada,"%f ", &juros_apl);
            //Lendo o %.
            fscanf(entrada,"%s ", leitura);
            //Lendo a quantidade de meses.
            fscanf(entrada,"%d ", &meses);
            //Lendo o tipo de juros.
            fscanf(entrada,"%c ", &tipojuros);
            juros(&numb1, juros_apl, meses, tipojuros);
            fprintf(saida, "R$ %0.2f\n", numb1);

        }
        else if(!strcmp(tipo, "media"))
        {
            //Lendo os dois numeros e exibindo a media.
            fscanf(entrada, "%f ", &numb1);
            fscanf(entrada, "%f ", &numb2);
            fprintf(saida,"%0.2f\n", media(numb1, numb2));
        }
        else if(!strcmp(tipo, "pmvs"))
        {
            //Lendo o inteiro e exibindo o prox multiplo de 26.
            fscanf(entrada, "%d ", &inteiro);
            fprintf(saida, "%d\n", pmvs(inteiro));
        }
        else if(!strcmp(tipo, "hexa"))
        {
            //Armazenando a string.
            fscanf(entrada, "%s ", leitura);
            inteiro=strlen(leitura);
            //Analisando se a string eh valida.
            valido = hexa(leitura);
            if(valido)
                fprintf(saida, "%s em hexadecimal eh valida\n", leitura);
            else fprintf(saida, "%s em hexadecimal nao eh valida\n", leitura);
        }
    }
    //Fecahndo os arquivos
    fclose(entrada);
    fclose(saida);
    //Mensagem final e pausa
    mensagem_final_na_tela_e_pausa();
    return 0;
}
