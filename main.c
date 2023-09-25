#include <stdio.h>
#include <stdlib.h>
#include "poligono.h"

int main()
{
    FILE *arquivo;
    int qntVertices;
    arquivo = fopen("vertices.txt", "r");     //� aberto o arquivo p ler os dados
    if (arquivo == NULL)
    	{
        	printf("Erro no arquivo.\n");
        	return 1;
    	}
    fscanf(arquivo, "%d", &qntVertices);        // ler o n* de v�rtices
    	Point *vertices = (Point *)malloc(qntVertices * sizeof(Point));

    	for (int i = 0; i < qntVertices; i++)
    	{
     	   fscanf(arquivo, "%lf %lf", &(vertices[i].x), &(vertices[i].y));
    	}

    fclose(arquivo);
    
    

   
    double area = AreaPoligono(vertices, qntVertices);   // CALCULA E IMPRIME A AREA

    printf("A area do poligono e %.2lf\n", area);

    // Finalizamos liberando a mem�ria
    free(vertices);

    return 0;
}
