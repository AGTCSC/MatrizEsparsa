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
	printf("Coordenadas fora da matriz!")
}
