/*  David Costa Pereira                               */
/*  Turma 3                                           */
/*  Exercício 5: Sobremesa                            */
/*                                                    */
/*  Programa compilado com CodeBlocks 20.03           */

#include <stdio.h>

int main()
{
    //Declaracoes de variaveis
    int b, g, f, s;
    //Arquivos de entrada e saida.
    FILE *entrada, *saida;
    //Abertura dos arquivos.
    entrada = fopen("entrada5.txt", "r");
    saida = fopen("Lab5_David_Costa_Pereira.txt", "w");
    //Mensagem inicial.
    fprintf(saida,"Sobremesas do rancho hipotetico.\n");
    fprintf(saida,"Bolos, gelatinas, frutas e sorvetes.\n");
    fprintf(saida,"Aproveite, hoje eh rancho festivo.\n");
    fprintf(saida,"-----\n");
    //Enquanto o fscanf nao chega no final do arquivo.
    while(fscanf(entrada, " %d %d %d %d ", &b, &g, &f, &s)!=-1)
    {
        // Se o numero de bolos for diferente de zero.
        if(b!=0)
        {
            fprintf(saida, "%d bolo", b);
            //Se for plural.
            if(b>1)
                fprintf(saida, "s");
            //Caso somente um dos posteriores nao seja zero.
            if(((g!=0 && f==0 && s==0)||(g==0 && f!=0 && s==0)||(g==0 && f==0 && s!=0)))
                fprintf(saida, " e ");
            //Caso mais de um nao seja zero.
            if(((g!=0 && f!=0 && s==0)||(g==0 && f!=0 && s!=0)||(g!=0 && f==0 && s!=0)||(g!=0 && f!=0 && s!=0)))
                fprintf(saida, ", ");
            //Caso todos sejam zero.
            if(g==0 && f==0 && s==0)
                fprintf(saida, ".");
        }
        //Analogamente, mas ja nao precisamos considerar o(os) bolo(s).
        if(g!=0)
        {

            fprintf(saida, "%d gelatina", g);
            //Caso seja plural.
            if(g>1)
                fprintf(saida, "s");
            //Caso os posteriores sejam zero.
            if((f==0 && s==0))
                fprintf(saida, ".");
            //Caso somente um nao seja zero.
            if(((f!=0 && s==0)||(f==0 && s!=0)))
                fprintf(saida, " e ");
            //Caso ambos nao sejm zero.
            if((f!=0 && s!=0))
                fprintf(saida, ", ");
        }
        //Analogo aos anteriores.
        if(f!=0)
        {

            fprintf(saida,"%d fruta", f);
            //Caso seja plural.
            if(f>1)
                fprintf(saida, "s");
            //Caso o numero de sorvetes seja zero.
            if(s==0)
                fprintf(saida,".");
            //Caso nao seja.
            else
                fprintf(saida," e ");
        }
        //Para os sorvetes, so precisamos avaliar se eh plural ou nao.
        if(s==1)
            fprintf(saida, "%d sorvete.", s);
        if(s>1)
            fprintf(saida, "%d sorvetes.", s);
        fprintf(saida, "\n");
    }
    //Fechando os arquivos de  entrada e saida.
    fclose(entrada);
    fclose(saida);
    //Finalizar.
    return 0;
}
