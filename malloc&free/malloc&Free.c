#include <stdio.h>
#include <stdlib.h>  // para malloc y free

float media(int* edades, int tam){
    int i;
    float acum = 0;
    for (i = 0; i < tam; i++){
        acum += edades[i];
    }
    return acum / tam;
}

int main(){
    int tam;
    printf("Cuantos elementos vas a meter: ");
    scanf("%d", &tam);

    //asignacion dinamica de memoria para edades
    int* edades = (int*)malloc(tam * sizeof(int));
    
    // verificar si malloc fallo
    if (edades == NULL){
        printf("Error en la asignación de memoria.\n");
        return 1;
    }

    for (int i = 0; i < tam; i++){
        printf("Introduce la edad %d: ", i + 1);
        scanf("%d", &edades[i]);
    }

    printf("La edad media es %.2f\n", media(edades, tam));

    // Liberar memoria reservada
    free(edades);

    return 0;
}
