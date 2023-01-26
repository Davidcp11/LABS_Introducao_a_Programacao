/*  David Costa Pereira                               */
/*  Turma 3                                           */
/*  Exercicio 7: Bases Numericas                      */
/*                                                    */
/*  Programa compilado com CodeBlocks 20.03           */

#include <stdio.h>
#include <string.h>

int main()
{
    // Declarando algumas variaveis
    int base_i, base_f, numb10,
        algarismo,
        potencia,
        i,
        caso;
    // Atribuicao a variavel "caso"
    caso = 1;
    char numb[35], leitura[71], numbfinal[35];
    FILE *entrada, *saida;
    // Abrindo os arquivos de entrada e saida
    entrada = fopen("entrada7.txt", "r");
    saida = fopen("Lab7_David_Costa_Pereira.txt", "w");
    // Escrenvendo as 4 primeiras linhas do arquivo de saida
    fprintf(saida, "Conversor de bases numericas\n");
    fprintf(saida, "Bom dia\n");
    fprintf(saida, "Xabiral\n");
    fprintf(saida, "-----------------\n");
    // Lendo as 4 primeiras linhas
    fgets(leitura, 71, entrada);
    fgets(leitura, 71, entrada);
    fgets(leitura, 71, entrada);
    fgets(leitura, 71, entrada);
    // Enquanto nao chegar no final do arquivo de entrada
    while (fscanf(entrada, "%d ", &base_i) != -1)
    {
        // Lendo a base de destino
        fscanf(entrada, "%d ", &base_f);
        // Lendo o numero na base inicial
        fscanf(entrada, "%s ", numb);
        //Se o numero for diferente de zero
        if(numb[0]!='0')
        {
            // Passando o numero para base 10
            numb10 = 0;
            potencia = 1;
            // Atribuindo a i a posicao da ultima posicao da string numb
            i = strlen(numb) - 1;
            // Enquanto nao terminar de percorrer a estring
            while (i >= 0)
            {
                // Se eh um algarismo
                if ('0' <= numb[i] && numb[i] <= '9')
                {
                    algarismo = numb[i] - '0';
                }
                // Caso contrario, utilizar a posicao de 'A' valendo 10
                else
                    algarismo = numb[i] - 'A' + 10;
                // Acrescenta o produto do algarismo pela potencia da base elevada a "posicao" - 1
                numb10 += algarismo * potencia;
                // Aumenta a potencia da base
                potencia *= base_i;
                // Passamos para a posicao mais a esquerda
                i--;
            }
            // Enquanto o numero na base 10 nao for zero
            while (numb10)
            {
                i++;
                // Quandamos o resto da divasao do numero pela base de destino
                numb[i] = numb10 % base_f + '0';
                // Pegamos o quociente da divisao
                numb10 = (numb10 - numb10 % base_f) / base_f;
            }
            // Exibir o caso x:
            fprintf(saida, "%2d: ", caso);
            caso++;
            // Percorrer a matriz de restos da divisao da etapa anterior, perceba que estamos percorrendo da direita para esquerda
            while (i >= 0)
            {
                // Se o resto for maior que 9, tem uma letra correspondente
                if(numb[i]> '9')
                {
                    numb[i] = numb[i] + 'A' - 10 - '0';
                }
                // Exibir o digito
                fprintf(saida, "%c", numb[i]);
                // Pular pra posicao mais a esquerda
                i--;
            }
        }
        //Se o numero for zero
        else
        {
            fprintf(saida, "%2d: ", caso);
            caso++;
            //Printar o zero
            fprintf(saida, "%c", numb[0]);
        }
        fprintf(saida, "\n");
    }
    // Fechando arquivos de entrada e saida
    fclose(entrada);
    fclose(saida);
    return 0;
}
