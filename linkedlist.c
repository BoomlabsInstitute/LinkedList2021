#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
typedef struct nodo
{
    int numero;
    struct nodo * siguiente;
}
nodo;

void ImprimirMenu();




int main()
{
    // Creamos una lista vacia de nodos
    nodo *lista = NULL;
    nodo *n = NULL;
    nodo *tmp = NULL;

    while(true)
    {
        ImprimirMenu();
        int opcion = get_int("Selecciona una opción: ");
        switch(opcion)
        {
            case 1:
                printf("Seleccionaste Agregar un nodo al principio\n");
                // Creando el primer nodo de la lista
                n = malloc(sizeof(nodo));
                if(n == NULL)
                {
                    printf("Algo salió mal\n");
                    return 1;
                }
                // Estableciendo los valores del primer nodo
                n -> numero = get_int("n: ");
                n -> siguiente = NULL;

                if(lista == NULL){
                    // Agregar el primer nodo a la lista
                    lista = n;
                } else {
                    n -> siguiente = lista;
                    lista = n;
                }
                break;
            case 2:
                printf("Seleccionaste Agregar un nodo al final\n");
                tmp = lista;
                while(tmp -> siguiente != NULL)
                {
                    tmp = tmp -> siguiente;
                }
                // Creando el nuevo nodo de la lista
                n = malloc(sizeof(nodo));
                if(n == NULL)
                {
                    printf("Algo salió mal\n");
                    return 1;
                }
                // Estableciendo los valores del primer nodo
                n -> numero = get_int("n: ");
                n -> siguiente = NULL;
                // Agregando el nuevo nodo al final.
                tmp -> siguiente = n;
                break;
            case 3:
                printf("Seleccionaste Agregar un nodo en la pos. n.\n");
                int pos = get_int("En qué pos?: ");

                // Empezar a recorrer la lista
                tmp = lista;
                int i = 0;
                while (tmp -> siguiente != NULL && i != pos)
                {
                    tmp = tmp -> siguiente;
                    i++;
                }

                // Creando el nuevo nodo de la lista
                n = malloc(sizeof(nodo));
                if(n == NULL)
                {
                    printf("Algo salió mal\n");
                    return 1;
                }
                // Estableciendo los valores del primer nodo
                n -> numero = get_int("n: ");
                n -> siguiente = tmp -> siguiente;
                tmp -> siguiente = n;
                break;
            case 4:
                printf("\nSeleccionaste Imprimir la lista\n");
                tmp = lista;
                if(lista != NULL)
                {
                    while(tmp -> siguiente != NULL)
                    {
                        tmp = tmp -> siguiente;
                        printf("%i -> ", tmp -> numero);
                    }
                    printf("%i", tmp -> numero);
                }

                break;
            default:
                printf("Opción no válida.\n");
        }
    }





}

void ImprimirMenu()
{
    printf("\n1. Agregar un nodo al principio.\n");
    printf("2. Agregar un nodo al final.\n");
    printf("3. Agregar un nodo en la pos. n.\n");
    printf("4. Imprimir la lista.\n");
}
