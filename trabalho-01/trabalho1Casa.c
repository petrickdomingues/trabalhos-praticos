#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <string.h>

char *multiply(char *num1, char *num2)
{
    int tamanho1 = strlen(num1);
    int tamanho2 = strlen(num2);
    int tamanhoResultado = tamanho1 + tamanho2;

    int *resultado = calloc(tamanhoResultado, sizeof(int));

    if (resultado == NULL)
    {
        return NULL;
    }

    for (int i = tamanho1 - 1; i >= 0; i--)
    {
        for (int j = tamanho2 - 1; j >= 0; j--)
        {
            int digito1 = num1[i] - '0';
            int digito2 = num2[j] - '0';

            int posicao = i + j + 1;

            resultado[posicao] += digito1 * digito2;
        }
    }

    for (int i = tamanhoResultado - 1; i > 0; i--)
    {
        resultado[i - 1] += resultado[i] / 10;
        resultado[i] %= 10;
    }

    int inicio = 0;

    while (inicio < tamanhoResultado - 1 && resultado[inicio] == 0)
    {
        inicio++;
    }

    char *resposta = malloc((tamanhoResultado - inicio + 1) * sizeof(char));

    if (resposta == NULL)
    {
        free(resultado);
        return NULL;
    }

    int posicao = 0;

    for (int i = inicio; i < tamanhoResultado; i++)
    {
        resposta[posicao] = resultado[i] + '0';
        posicao++;
    }

    resposta[posicao] = '\0';

    free(resultado);

    return resposta;
}


static int RodarTeste( int num, const char *n1, const char *n2,
					   const char *esperado ) {
	char *	c1;
	char *	c2;
	char *	res;
	int		ok;

	/* copias defensivas: a funcao recebe char* nao-const */
	c1 = malloc( strlen( n1 ) + 1 );
	c2 = malloc( strlen( n2 ) + 1 );
	strcpy( c1, n1 );
	strcpy( c2, n2 );

	res = multiply( c1, c2 );
	ok = ( strcmp( res, esperado ) == 0 );

	printf( "Teste %2d: \"%s\" * \"%s\"\n", num, n1, n2 );
	printf( "  esperado = \"%s\"\n  obtido   = \"%s\"  ->  %s\n\n",
			esperado, res, ok ? "OK" : "FALHOU" );

	free( res );
	free( c1 );
	free( c2 );
	return ok;
}

/*
====================
main
====================
*/
int main( void ) {
	int		passou;

	passou = 0;

	/* Teste 1: exemplo 1 do enunciado */
	passou += RodarTeste(  1, "2", "3", "6" );

	/* Teste 2: exemplo 2 do enunciado */
	passou += RodarTeste(  2, "123", "456", "56088" );

	/* Teste 3: zero a esquerda - resposta e "0", nao "000" */
	passou += RodarTeste(  3, "0", "52", "0" );

	/* Teste 4: zero vezes zero */
	passou += RodarTeste(  4, "0", "0", "0" );

	/* Teste 5: um digito com carry */
	passou += RodarTeste(  5, "9", "9", "81" );

	/* Teste 6: carry propagando por todas as posicoes */
	passou += RodarTeste(  6, "99", "99", "9801" );

	/* Teste 7: produto de 18 digitos - ainda caberia em long long, */
	/* entao NAO detecta atalho sozinho                              */
	passou += RodarTeste(  7, "123456789", "987654321",
						   "121932631112635269" );

	/* Teste 8: multiplicacao por 1 com operando longo */
	passou += RodarTeste(  8, "1", "999999999999", "999999999999" );

	/* Teste 9: zeros internos e finais */
	passou += RodarTeste(  9, "100", "100", "10000" );

	/* Teste 10: 20 x 20 digitos - as ENTRADAS ja estouram long long; */
	/* qualquer conversao para tipo nativo falha aqui                  */
	passou += RodarTeste( 10, "98765432109876543210", "12345678901234567890",
						   "1219326311370217952237463801111263526900" );

	/* Adicione aqui seus proprios casos de teste, no mesmo formato:
	   passou += RodarTeste( 11, "num1", "num2", "resultado esperado" );
	   Lembre de ajustar o total impresso e a condicao do return. */

	printf( "Resultado final: %d/10 testes passaram\n", passou );
	printf( "Lembrete: estes 10 testes NAO sao exaustivos. Submeta ao\n" );
	printf( "LeetCode e passe em todos os testes da plataforma.\n" );
	return passou == 10 ? 0 : 1;
}