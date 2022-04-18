#include <stdio.h>
#include <stdlib.h>



/*
Casas de westeros - 1862 
Nome: Daniele Simas Guimaraes
Matricula: 2015310060
*/


// estrutura de grafos
typedef struct graph {
   int vertice; 
   int **adj; 
} *Graph;


// inicialização da matriz 
int **iniciar_matriz(int linhas, int colunas, int valor) { 
  	int **matriz_adj = malloc(linhas * sizeof (int *));
	int i, j;

	for (i = 0; i < linhas; ++i) 
 		matriz_adj[i] = malloc(colunas * sizeof (int));

	for (i = 0; i < linhas; ++i) {
    	for (j = 0; j < colunas; ++j)
        	matriz_adj[i][j] = valor;
   }

   return matriz_adj;
}

// criação do grafos
Graph criar_grafo(int vertice) { 
	Graph grafo = malloc(sizeof *grafo);

	grafo->vertice = vertice; 
	grafo->adj = iniciar_matriz(vertice, vertice, 0);

	return grafo;
}

// inserção dos grafos
void inserir_aresta(Graph grafo, int origem, int destino) { 
	if (grafo->adj[origem][destino] == 0)
      grafo->adj[origem][destino] = 1; 
}

// verificação do conteudo inserido
int in_lista(int num, int lista[], int tam) {
	int i, a = 0;

	for (i = 0; i < tam; i++) {
		if (num == lista[i])
			break;
		else
			a++;
	}

	if (a == tam)
		return 0;
	else
		return 1;
}

// Main
int main() {
	int pessoas, i, j, k;
	scanf("%d", &pessoas);

	Graph grafo = criar_grafo(pessoas);
	
	

	for (i = 0; i < pessoas; i++) {
		char moram[pessoas+1];
		scanf("%s", &moram);
			// Inserção nas aresta
		for (j = 0; moram[j] != 0; j++) {
			if (moram[j] == 'S')
				inserir_aresta(grafo, i, j);
		}
	}
	
	// Variaveis auxiliares para as verificações
	int moram_juntos[pessoas], posicao_s[pessoas], casas[pessoas], count_ps = 0, count_c = 0;
	
	
	// For para as verificacoes das casas, pessoas e se elas sao irmaos 
	for (i = 0; i < pessoas; i++) {
		int count_mj = 0;

		for (j = 0; j < pessoas; j++) {
			if ((grafo->adj[i][j] == 1) && (in_lista(j, posicao_s, count_ps) == 0)) {
				moram_juntos[count_mj] = j;
				posicao_s[count_ps] = j;
				count_mj++;
				count_ps++;
			}
		}

		int temp = 0;

		for (j = 0; j < count_mj; j++) {
			int aux = moram_juntos[j];

			for (k = 0; k < pessoas; k++) {
				if (grafo->adj[aux][k] == grafo->adj[i][k])
					temp++;
			}
		}

		if (count_mj != 0) {
			if (temp == (pessoas*count_mj)) {
				casas[count_c] = count_mj;
				count_c++;
			} else
				count_c = -1;
		}

		if (count_c == -1) {
			printf("%d\n", count_c);
			break;
		}
	}
	
	//Print final do resultado

	if (count_c != -1) {
		printf("%d\n", count_c);

		for (i = 0; i < count_c; i++)
			printf("%d ", casas[i]);
		printf("\n");
	}

	return 0;
}
