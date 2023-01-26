/*  David Costa Pereira                               */
/*  Turma 3                                           */
/*  Exercício 4: Contador de dias                     */
/*                                                    */
/*  Programa compilado com CodeBlocks 20.03           */
#include <stdio.h>
#include <stdlib.h>

int main()
{   // Variaveis para o dia, mes e ano inicial(i) e final(f), total de dias e quantidade de linhas na entrada.
    int
        di, mi, ai,
        df, mf, af,
        soma, quant, i, j;
    FILE *entrada4, *saida;
    //Declarando algumas variaveis:
    soma=0;
    i=1;
    j=1;
    //Abrindo a entrada e saida de dados.
    entrada4=fopen("entrada4.txt", "r");
    saida=fopen("Lab4_David_Costa_Pereira.txt", "w");
    //Escrevendo as 3 primeiras linhas.
    fprintf(saida, "Lab com muitos casos.          \n"
                   "Muitos casos, dor e sofrimento.\n"
                   "E ainda nem comecou a semana 5.\n"
                   "-------------------------------\n");
    //Lendo a quantidade de linhas.
    fscanf(entrada4, "%d", &quant);
    //para cada linha, faz-se:
    while(i<=quant)
    {
      //Leitura dos dados da linha.
      fscanf(entrada4, "%d %d %d %d %d %d", &di, &mi, &ai, &df, &mf, &af);
      //Ajustando os valores para nao ter problema na soma dos meses e anos.
      soma=(soma + df);
      soma=(soma - di);
      // Verificando se o ano final eh bissexto.
      if((af%4==0 && !(af%100==0)) || (af%100==0 && af%400==0))
      {   //Caso seja, soma-se 1 para podermos trabalhar com os meses normais.
          soma+=1;
      }
      //Caso os anos ai e af sejam iguais, bissexto e os meses sejam anteriores ou iguais a fevereiro.
      // Devemos tirar
      if(ai==af && mi<3 && mf<3)
      { // Devemos tirar um dia, pois nao "passamos" pelo dia 29 de fevereiro ainda.
        soma-=1;
      }
      //Acrescentando os dias do ano final.
      // Caso o mes seja fevereiro e o dia seja 29, devemos tirar um dia pois ja foi contabilizado no ano(bissexto).
      while(mf!=1)
      {   // Se o mes for x, somamos os dias do mes x-1, pois os dias do mes atual ja foram contabilizados.
          //Caso o mes tenha 31 dias.
          if((mf==2 && df!=29) || mf==4 || mf==6 || mf==8 || mf==9 || mf==11)
          {
              soma+=31;
              mf-=1;
          }
          // Caso mes seja fevereiro.
          else if(mf==3)
          {
              soma+=28;
              mf-=1;
          }
          // Caso o mes seja fevereiro e o dia seja 29, devemos tirar um dia pois ja foi contabilizado no ano(bissexto).
          else if(mf==2 && df==29)
          {   // Se o mes for x, somamos os dias do mes x-1, pois os dias do mes atual ja foram contabilizados.
              soma+=30;
              mf-=1;
          }
          // O restante dos meses tem 30 dia.
          else
          {
              soma+=30;
              mf-=1;
          }
      }
      // Tirando os dias do ano inicial.
      // Analogo a etapa anterior.
      while(mi!=1)
      {
          if(mi==2 || mi==4 || mi==6 || mi==8 || mi==9 || mi==11)
          {
              soma-=31;
              mi-=1;
          }
          else if(mi==3)
          {
              soma-=28;
              mi-=1;
          }
          else
          {
              soma-=30;
              mi-=1;
          }
      }
      // Somando os dias usando os anos anteriores.
      while(ai<af)
      {
        // Verificando se o ano ai eh bissexto.
        if((ai%4==0 && !(ai%100==0)) || (ai%100==0 && ai%400==0))
          {   //Caso seja, soma-se mais 1 dia ao ano.
              soma+=366;
              ai+=1;
          }
        else
          {
              soma+=365;
              ai+=1;
          }
      }
      // escrever no arquivo de saida o total de dias do par de datas dado.
      fprintf(saida, "%2d: %6d dias.\n", j, soma);
      i+=1;
      j+=1;
      soma=0;
    }
    //Fechar arquivos de entrada e saida.
    fclose(entrada4);
    fclose(saida);
    // mensagem final na tela + pausa.
    system("pause");
    // finalizar.
    return 0;
}
