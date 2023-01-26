/*  David Costa Pereira                               */
/*  Turma 3                                           */
/*  Exercício 3: Conversor de Medidas                 */
/*                                                    */
/*  Programa compilado com CodeBlocks 20.03           */

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    // declaracao de variaveis
    float medida;
    int quant,
        i,
        contm,
        contk,
        contc,
        medsaida,
        medmilha,
        medjarda,
        medpe,
        maiork,
        menorc;
    char u;
    FILE *entrada3, *saida3;
    // escrever mensagem inicial na tela
    printf("----------------------------------------\n");
    printf("     PROGRAMA CONVERSOR DE UNIDADES     \n");
    printf("----------------------------------------\n");
    // atribuicao inicial para algumas variaveis
    i=1;
    contm=0;
    contk=0;
    contc=0;
    maiork;
    menorc;
    // abrir arquivos de entrada e saida
    entrada3 = fopen ("entrada3.txt", "r");
    saida3 = fopen ("Lab3_David_Costa_Pereira.txt", "w");
    // escrever mensagem inicial no arquivo
    fprintf(saida3,"----------------------------------------\n");
    fprintf(saida3,"    PROGRAMA CONVERSOR DE UNIDADES      \n");
    fprintf(saida3,"----------------------------------------\n");
    // ler a quantidade n de casos
    fscanf(entrada3, "%d", &quant);
    // para cada um dos n casos, fazer:
    while(i<=quant)
    {
        // ler um float e um char com a unidade
        fscanf(entrada3, "%f %c", &medida, &u);
        // se unidade m (metros)
        if(u=='m' || u=='M')
        {
            // converter distancia
            medsaida = ((medida)/(0.0254));
            medmilha = ((medsaida)/(63360));
            fprintf(saida3,"%.2f metros =\n %9d milhas +\n", medida, medmilha);
            medsaida=(medsaida%63360);
            medjarda=(medsaida/36);
            fprintf(saida3,"%10d jardas +\n", medjarda);
            medsaida=medsaida%36;
            medpe=(medsaida/12);
            fprintf(saida3,"%10d pes    +\n", medpe);
            medsaida=medsaida%12;
            fprintf(saida3,"%10d polegadas\n", medsaida);
            contm+=1;
            i+=1;
        }
        // se unidade k (kilogramas)
        else if(u=='k' || u=='K')
            // converter massa
        {
            medsaida=medida/(0.453592);
            fprintf(saida3,"%.2f kilogramas =\n %10d libras\n", medida, medsaida);
            contk+=1;
            i+=1;
            // verifica se eh a maior ate o momento
            if(maiork<=medsaida)
            {
                maiork=medsaida;
            }
        }
        // se unidade c (celsius)
        else if(u=='c' || u=='C')
        {
            // converter temperatura
            medsaida=(((9*medida)/5 + 32));
            fprintf(saida3,"%.2f graus Celsius =\n %10d graus Fahrenheit\n", medida, medsaida);
            contc+=1;
            i+=1;
            // verifica se eh a menor ate o momento
            if(menorc>=medsaida)
            {
                menorc=medsaida;
            }
        }
    }

    // Ao terminar o arquivo de entrada,
    // escrever as informações "acumuladas" (a), (b) e (c)"
    fprintf(saida3,"----------------------------------------\n");
    fprintf(saida3,"(a) Quantidade de casos de cada tipo:\n");
    fprintf(saida3," Massa       : %d vezes.\n", contk);
    fprintf(saida3," Temperatura : %d vezes.\n", contc);
    fprintf(saida3," Distancia   : %d vezes.\n", contm);
    fprintf(saida3,"(b) Maior massa:\n");
    if(contk==0)
        fprintf(saida3,"Nao ocorre.\n");
    else fprintf(saida3," %d libras\n", maiork);

    fprintf(saida3,"(c) Menor temperatura:\n");
    if(contc==0)
        fprintf(saida3,"Nao ocorre.\n");
    else fprintf(saida3," %d graus Fahrenheit\n", menorc);
    fprintf(saida3,"----------------------------------------\n");
    // fechar arquivos de entrada e saida
    fclose(entrada3);
    fclose(saida3);
    // mensagem final na tela + pausa
    system("pause");
    // finalizar
    return 0;
}
