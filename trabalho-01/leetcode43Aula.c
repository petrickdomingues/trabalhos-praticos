#include <stdio.h>
#include <stdlib.h>
#include <string.h>




char *multiply( char *num1, char *num2 ) {

	/*char *res = malloc( 2 );
	strcpy( res, "?" );
	return res;*/
	
	// teste nao-negativo
	/* if(num1== NULL && num2==NULL){
		printf("numero negativo nao passa");
		
	}*/  // XXX  nao usar!!

	int tam=2;
	char* res = malloc(sizeof(num1) && sizeof(num2) == tam); // ou * tam??
	// res =num1 * num2; anotaçao.
	
if(num1== NULL && num2==NULL){
	int s1= strlen(num1);
	int s2= strlen(num2);

}
	
	
	
}

/*
====================
RodarTeste

	Compara o retorno de multiply com o resultado esperado hard-coded.
====================
*/
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
