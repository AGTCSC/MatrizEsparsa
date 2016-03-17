#define nl 5
#define nc 6
typedef struct matrizEsp
{
	int lin, col, valor;
	struct matrizEsp*pc, *pl;
} MatEsp;
