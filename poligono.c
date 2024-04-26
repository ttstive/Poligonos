#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define V 3

typedef struct {
    float X;
    float Y;
} Ponto;

float funcaoAreaTri(Ponto A, Ponto B, Ponto C) {
    float calculo = ((A.X * B.Y) + (B.X * C.Y) + (C.X * A.Y)) - ((A.Y * B.X) + (B.Y * C.X) + (C.Y * A.X));
    return fabs(calculo) / 2.0;
}

void funcaoCalcuPolig(char* file) {
    int i;
    int num;
    Ponto *vertices;
    float areaAbsoluta = 0.0;

    FILE *f;
    f = fopen(file, "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    fscanf(f, "%d", &num);
    vertices = (Ponto *)malloc(num * sizeof(Ponto)); 

    for (i = 0; i < num; i++) {
        fscanf(f, "%f %f", &vertices[i].X, &vertices[i].Y);
    }
    fclose(f);

    if (num == V) {
        areaAbsoluta = funcaoAreaTri(vertices[0], vertices[1], vertices[2]);
    } else {
        int i = 2;
        while (i < num) {
            areaAbsoluta += funcaoAreaTri(vertices[0], vertices[i - 1], vertices[i]);
            i++;
        }
    }

    printf("A area do poligono é: %.2f\n", areaAbsoluta);
    free(vertices);
}
int main() {
    setlocale(LC_ALL, "Portuguese");
    funcaoCalcuPolig("/home/estevaolins/Documentos/AtividadeCalculoÁrea/trianguloABC.txt");
    return 0;
}
