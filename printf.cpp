#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Functions.h"


/** @brief Reads equation coefficient from console

    @param a is red cofficient

*/
void Input (double* a){

     while (1){

        if (scanf("%lf", a) != 1) {

            abort();

        }

        else break;
    }
}


/** @brief print text on console

    @param a Coefficient at x^2
    @param b Coefficient at x
    @param c Free coefficient

*/
void Start (double *a, double *b, double *c){

    printf ("Solution of quadratic equation\n\n");
    printf ("IMPORTANT!!! Enter only numerical values\n\n\n\n");

    printf ("Enter coefficient at x^2: ");
    Input (a);

    printf ("Enter coefficient at x: ");
    Input (b);

    printf ("Enter free coefficient: ");
    Input (c);

}


