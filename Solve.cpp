#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "Functions.h"

/** @brief Compares a double type number with 0

    @param a Number is compared with 0

    @return Result comparison

*/
bool is_zero (double a){

    return fabs(a) < EPS;
}

/** @brief Смотрит, какой вид имеет данное уравнение

    @param a Coefficient at x^2
    @param b Coefficient at x
    @param c Free coefficient

    @return Type of equation

*/
int Probably_Case(double a, double b, double c){


    if (is_zero(a)){

        if (is_zero(b) && is_zero(c))
                return INF_R;

        else if (is_zero(b))
                return ZERO_EQ_C;

        else    return L_EQ;

    }

    else if (is_zero(b)){

        if (is_zero(c))
                return X_EQ_ZERO;

        else if (c > 0)
                return X2_EQ_NEG;

        else
                return X2_EQ_POS;

    }


    else if (is_zero(c))
                return C_EQ_ZERO;


    else{

        double D = b*b - 4*a*c;

        if (is_zero(D))
                return D_EQ_ZERO;

        else if (D < 0)
                return D_EQ_NEG;

        else
                return D_EQ_POS;

    }
}

/** @brief Solves linear equation

    @param b Coefficient at x
    @param c Free coefficient
    @param x Root of equation

*/
void Solve_Linear_Eq (double b, double c, double *x) {

    switch(Probably_Case(0, b, c)){

        case     INF_R: printf("Inf_num_of_roots\t\t");
                        break;

        case ZERO_EQ_C: printf("No roots\t\t\t");
                        break;

        case      L_EQ: *x = -c/b;
                        printf("One root: %.3lf\t\t\t\t\t", *x);
                        break;

        default:        break;

    }
}


/** @brief Solves quadratic equation

    @param a Coefficient at x^2
    @param b Coefficient at x
    @param c Free coefficient
    @param x1 First root of equarion
    @param x2 Second root of equation
*/
void Solve_Square_Eq (double a, double b, double c, double *x1, double *x2){

    double D = b*b - 4*a*c;

    switch (Probably_Case(a, b, c)){

        case   X_EQ_ZERO: *x1 = 0;
                          printf("One root: 0\t\t\t\t\t");
                          break;

        case   X2_EQ_NEG: printf("No roots\t\t\t");
                          break;


        case   X2_EQ_POS: *x1 = sqrt(-c/a);
                          *x2 = -sqrt(-c/a);
                          printf("Two roots: %.3lf and %.3lf\t\t\t", *x1, *x2);
                          break;


        case   C_EQ_ZERO: *x1 = 0;
                          *x2 = -b/a;
                          printf("Two roots: 0 and %.3lf\t\t\t\t", *x2);
                          break;

        case   D_EQ_NEG: printf("No roots\t\t\t\t\t");
                          break;

        case   D_EQ_ZERO: *x1 = -b/(2 * a);
                         printf("One root: %.3lf\t\t\t\t", *x1);
                         break;

        case   D_EQ_POS: *x1 = (-b + sqrt(D)) / (2 * a);
                         *x2 = (-b - sqrt(D)) / (2 * a);
                         printf("Two roots: %.3lf and %.3lf\t\t\t", *x1, *x2);
                         break;

        default:         break;

    }
}

/** @brief Solves equation of different types

    @param a Coefficient at x^2
    @param b Coefficient at x
    @param c Free coefficient
    @param x1 First root of equation
    @param x2 Second root of equation

*/
void Solve (double a, double b, double c, double *x1, double *x2){

    assert (x1 != NULL && x2 != NULL);


    if (fabs(a) < EPS)
        Solve_Linear_Eq(b, c, x1);
    else
        Solve_Square_Eq(a, b, c, x1, x2);

}



