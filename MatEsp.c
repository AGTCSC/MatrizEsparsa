#define nl 5										//numero da linha
#define nc 6										//numero da coluna
typedef struct matrizEsp
{
	int lin, col, valor;
	struct matrizEsp*pc, *pl;
} MatEsp;

void insere (MatEsp* vetlin[], MatEsp* vetcol[], int valor, int lin, int col)
{
	MatEsp* aux, *nova;
	
	if(lin >= 0 && lin < nl && col >= 0 && col < nc) 				//verificação se o elemento está dentro dos limites da matriz
	{
		verificaOcupado(vetlin, lin, col, &aux); 				//verifica se existe um elemento naquela posição
		if(aux != NULL)
			aux -> valor = valor;
		else
			nova = (MatEsp*) malloc(sizeof(MatEsp));
			nova->lin = lin;
			nova->col = col;
			nova->valor = valor;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
											//Ligação Horizontal
			if(vetlin[lin] == NULL)
			{
				nova->pl = NULL;
				vetlin[lin] = nova;
			}
			else
				if(col < vetlin[lin]->col)
				{
					nova->pl    = vetlin[lin];
					vetlin[lin] = nova;
				}
				else
				{
					aux = vetlin[lin];
					while(aux != NULL && col > aux->col)
					{
						ant = aux;
						aux = aux->pl;
					}
					nova->pl = aux;
					ant->pl  = nova;
				}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
											//Ligação Vetorial
			if(vetcol[col] == NULL)
			{
				nova->pc = NULL;
				vetcol[col] = nova;
			}
			else
				if(col < vetcol[col]->lin)
				{
					nova->pc    = vetcol[col];
					vetcol[col] = nova;
				}
				else
				{
					aux = vetcol[col];
					while(aux != NULL && lin > aux->lin)
					{
						ant = aux;
						aux = aux->pc;
					}
					nova->pc = aux;
					ant->pc  = nova;
				}
	}
	printf("Coordenadas fora da matriz!");
}

void exibe (MatEsp* vetlin[])
{
	int i, j;
	MatEsp* aux;
	for(i = 0; i < nl; i++)
	{
		for(j = 0; j < nc; j++)
		{
			verificaOcupada(vetlin, i, j, &aux);
			if(aux != NULL)
				printf("%d ", aux->valor);
			else
				printf("0 ");
		}
		printf("\n");
	}
}

void soma(MatEsp* vetlinA[], MatEsp* vetlinB[], MatEsp* vetlinC[], MatEsp* vetcolC[])
{
	int i, j, soma=0;
	MatEsp* aux;
	for(int i=0; i < nl; i++)
	{
		for(j = 0; j < nc; j++)
		{
			verificaOcupado(vetlinA, i, j, &aux1);
			verificaOcupado(vetlinB, i, j, &aux2);
			if(aux1->val != 0)
				soma += aux->val;
			if(aux2->val != 0)
				soma += aux->val;
			if(soma != 0)
				insere(vetlinC, vetcolC, soma, i, j);
		}
	}
}

void mult(MatEsp* vetlinA, int linhaA, int colunaA, MatEsp* vetlinB, , int mB, int nB, MatEsp* vetlin, MatEsp* vetcol)
{
	int val, soma;
	MatEsp* aux1, *aux2;
	if(colunaA == linhaB)
	{
		for(int i=0; i < linhaA, i++)
		{
			for(int j=0; j < colunaB; j++)
			{
				soma = 0; val = 0;
				for(int k=0; k < colunaA; k++)
				{
					verificaOcupado(vetlinA, i, k, &aux1);
					verificaOcupado(vetlinB, k, j, &aux2);
					if(aux1 != NULL && aux2 != NULL)
						soma*= aux->val;
					val+= soma;
					
				}
				insere(vetlinC, vetcolC, i, j, val);
			}
		}
	}
	else
		printf("Matrizes incompativeis\n");
}
