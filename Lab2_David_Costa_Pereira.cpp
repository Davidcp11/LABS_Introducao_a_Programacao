
/* David Costa Pereira                     */
/* Turma 3                                 */
/* Exercicio 2: Juros Simples e Compostos  */
/*                                         */
/* Programa compilado com CodeBlocks 20.03 */

#include <stdio.h>

  int main()
{
    printf("--------------------------------------\n");
    printf("    PROGRAMA PARA CALCULO DE JUROS    \n");
    printf("         SIMPLES E COMPOSTOS          \n");
    printf("--------------------------------------\n");
    float emprestimo;
    float juros;
    int i;
    float divida;
    i=1;
    printf("\n");
    printf("Qual o valor do emprestimo?\n");
    scanf("%f", &emprestimo);
    printf("Qual o valor dos juros (em %%?)\n");
    scanf("%f", &juros);
    printf("\n");
    divida=emprestimo;
    printf("--------------\n");
    printf("JUROS SIMPLES \n" );
    printf("--------------\n");
    printf("Mes     Divida\n");

    while(i<=12)
    {
        divida= divida + emprestimo*(juros/100);
        printf("%3d     %.2f\n", i, divida);
        i=i+1;
    }
    printf("\n");

    i=1;
    divida=emprestimo;
    printf("--------------\n");
    printf("JUROS COMPOSTOS\n");
    printf("--------------\n");
    printf("Mes     Divida\n");

    while(i<=12)
    {
        divida=divida*(1+(juros/100));
        printf("%3d     %.2f\n", i, divida);
        i=i+1;
    }
    printf("--------------------------------------\n");
    printf("Fim do programa!\n");
    printf("Pressione ENTER para terminar...");

    getchar();
    getchar();
    return 0;
}
