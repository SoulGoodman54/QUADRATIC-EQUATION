#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Functions.h"

/** @mainpage Quadratic equation solver */

/** @brief Execution of the program

    @param argc Number of command line arguments
    @param argv List of command line arguments

    @return Program exit status
*/
int main(int argc, char *argv[]){

    Command_Line_Check (argc, argv);

    double x1 = NAN;
    double x2 = NAN;

    double a = NAN, b = NAN, c = NAN;

    Start (&a, &b, &c);
    Solve ( a,  b,  c, &x1, &x2);

    printf("\n");

    return 0;

}


