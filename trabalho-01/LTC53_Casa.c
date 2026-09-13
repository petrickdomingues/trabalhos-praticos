int maxSubArray(int* nums, int numsSize)
{
    int somaAtual = nums[0];
    int melhorSoma = nums[0];

    for (int i = 1; i < numsSize; i++)
    {
        if (somaAtual + nums[i] < nums[i])
        {
            somaAtual = nums[i];
        }
        else
        {
            somaAtual = somaAtual + nums[i];
        }

        if (somaAtual > melhorSoma)
        {
            melhorSoma = somaAtual;
        }
    }

    return melhorSoma;
}




static void ImprimirArray( const int *a, int n ) {
	int		i;

	printf( "[" );
	for ( i = 0; i < n; i++ ) {
		printf( "%d%s", a[i], i + 1 < n ? "," : "" );
	}
	printf( "]" );
}

/*
====================
RodarTeste

	Compara o retorno de maxSubArray com o resultado esperado
	hard-coded.
====================
*/
static int RodarTeste( int num, int *nums, int n, int esperado ) {
	int		obtido;
	int		ok;

	obtido = maxSubArray( nums, n );
	ok = ( obtido == esperado );

	printf( "Teste %2d: nums = ", num );
	ImprimirArray( nums, n );
	printf( "\n  esperado = %d | obtido = %d  ->  %s\n\n",
			esperado, obtido, ok ? "OK" : "FALHOU" );
	return ok;
}

/*
====================
main
====================
*/
int main( void ) {
	int		passou;

	/* Teste 1: exemplo 1 do enunciado - melhor subarray [4,-1,2,1] */
	int		t1[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

	/* Teste 2: exemplo 2 do enunciado - um único elemento */
	int		t2[] = { 1 };

	/* Teste 3: exemplo 3 do enunciado - o array inteiro */
	int		t3[] = { 5, 4, -1, 7, 8 };

	/* Teste 4: um único elemento negativo */
	int		t4[] = { -1 };

	/* Teste 5: TODOS negativos - resposta é o maior elemento, não 0 */
	int		t5[] = { -2, -3, -1, -5 };

	/* Teste 6: todos positivos - o array inteiro */
	int		t6[] = { 1, 2, 3, 4, 5 };

	/* Teste 7: melhor subarray é só o último elemento */
	int		t7[] = { -1, -2, -3, 4 };

	/* Teste 8: negativo no meio compensa ser atravessado */
	int		t8[] = { 2, -1, 2, 3, -9 };

	/* Teste 9: dois elementos, ambos negativos */
	int		t9[] = { -2, -1 };

	/* Teste 10: valores no limite das restrições ( +-10^4 ) */
	int		t10[] = { 10000, -10000, 10000 };

	passou = 0;
	passou += RodarTeste(  1, t1,  9, 6 );
	passou += RodarTeste(  2, t2,  1, 1 );
	passou += RodarTeste(  3, t3,  5, 23 );
	passou += RodarTeste(  4, t4,  1, -1 );
	passou += RodarTeste(  5, t5,  4, -1 );
	passou += RodarTeste(  6, t6,  5, 15 );
	passou += RodarTeste(  7, t7,  4, 4 );
	passou += RodarTeste(  8, t8,  5, 6 );
	passou += RodarTeste(  9, t9,  2, -1 );
	passou += RodarTeste( 10, t10, 3, 10000 );

	/* Adicione aqui seus próprios casos de teste, no mesmo formato:
	   passou += RodarTeste( 11, arrayNums, tamanho, resultadoEsperado );
	   Lembre de ajustar o total impresso e a condição do return. */

	printf( "Resultado final: %d/10 testes passaram\n", passou );
	printf( "Lembrete: estes 10 testes NAO sao exaustivos. Submeta ao\n" );
	printf( "LeetCode e passe em todos os testes da plataforma.\n" );
	return passou == 10 ? 0 : 1;
}