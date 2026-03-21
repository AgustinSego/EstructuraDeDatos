#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();
   for(size_t i = 1; i <= 10; i++)
      {
         int * n = malloc(sizeof(int) * 10);
         *n = i;
         pushBack(L, n);
      }
   
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int suma = 0; 
   void *aux = first(L);
   while(aux != NULL)
      {
         suma += *(int *)aux;
         aux = next(L);
      }
   
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   void *aux = first(L);
   
   while(aux != NULL)
      {
         if(*(int *)aux == elem)
         {
            popCurrent(L);
         }
         aux = next(L);
      }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack *auxStack = create_stack();
   void *aux;
   while(top(P1) != NULL)
      {
         aux = top(P1);
         push(auxStack, aux);
         pop(P1);
      }
   while(top(auxStack) != NULL)
      {
         aux = top(auxStack);
         push(P2, aux);
         push(P1, aux);
         pop(auxStack);
      }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   List *listaAb = create_list();
   List *listaCe = create_list();
   int *aux1 = 0;
   int *aux2 = 0;
   for(int i = 0; cadena[i] != '\0'; i++)
      {
         if(cadena[i] == '(')
         {
            *aux1 = 1;
            pushBack(listaAb, aux1);
         }
         else if(cadena[i] == '{')
         {
            *aux1 = 2; 
            pushBack(listaAb, aux1);
         }
         else if(cadena[i] == '[')
         {
            *aux1 = 3;
            pushBack(listaAb, aux1);
         }
         if(cadena[i] == ')')
         {
            *aux2 = 1;
            pushFront(listaCe, aux2);
            
         }
         else if(cadena[i] == '}')
         {
            *aux2 = 2;
            pushFront(listaCe, aux2);
         }
         else if (cadena[i] == ']')
         {
            *aux2 = 3;
            pushFront(listaCe, aux2);
         }
      }

   int cont1 = get_size(listaAb);
   int cont2 = get_size(listaCe);
   
   if(cont1 != cont2) return 0;
   else
   {
     while(first(listaAb) != NULL && first(listaCe) != NULL)
        {
           aux1 = first(listaAb);
           aux2 = first(listaCe);
           if(*aux1 != *aux2) return 0;
           next(listaAb);
           next(listaCe);
        }
      return 1;
   }
}

