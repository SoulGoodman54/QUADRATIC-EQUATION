#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Functions.h"

/** @brief Counts number of roots of equation

    @param b Coefficient at x
    @param c Free coefficient
    @param x Root of equation

    @return Number of roots
*/
int Number_Of_Roots(double a, double b, double c){

    if (Probably_Case(a, b, c) == INF_R)
            return INF;

    if (Probably_Case(a, b, c) == ZERO_EQ_C ||
        Probably_Case(a, b, c) == X2_EQ_NEG ||
        Probably_Case(a, b, c) == D_EQ_NEG)
            return ZERO;

    if (Probably_Case(a, b, c) == L_EQ      ||
        Probably_Case(a, b, c) == X_EQ_ZERO ||
        Probably_Case(a, b, c) == D_EQ_ZERO)
            return ONE;

    else    return TWO;

}


/** @brief Tests some functions from main program

    @param b Coefficient at x
    @param c Free coefficient
    @param x Root of equation
    @param Num_root Correct number of root
    @param Pr_case Correct choose case
    @param correct_x1 Correct first root of equation
    @param correct_x2 Correct second root of equation

*/
void Test(double a, double b, double c, int Num_of_root, int Pr_case, double correct_x1, double correct_x2){

    int test_num_root = Number_Of_Roots(a, b, c);
    int test_pr_case  = Probably_Case  (a, b, c);

    printf ("a=%.3lf b=%.3lf c=%.3lf\n", a, b, c);
    printf ("Case: %d\n", test_pr_case);
    printf ("Number of roots: %d\n", test_num_root);

    double x1 = NOT_ROOT, x2 = NOT_ROOT;

    if (test_num_root > 0)
        Solve(a, b, c, &x1, &x2);

    else if (Number_Of_Roots(a, b, c) == -1)
        printf ("Infinite number of roots\t\t\t");

    else printf("Zero number of roots\t\t\t\t");


    if (is_zero(correct_x1 - x1) && is_zero(correct_x2 - x2) &&
        test_num_root == Num_of_root && test_pr_case == Pr_case)

            printf("SUCCESS\n\n");

    else    printf("UNSUCCESS\n\n");

}


/**
    @brief Test some Examples
*/
void Unit_Test(){

    Test (0, 0,  0,  INF,     INF_R, NOT_ROOT, NOT_ROOT);
    Test (0, 0,  2, ZERO, ZERO_EQ_C, NOT_ROOT, NOT_ROOT);
    Test (0, 2, -4,  ONE,      L_EQ,        2, NOT_ROOT);
    Test (1, 0,  0,  ONE, X_EQ_ZERO,        0, NOT_ROOT);
    Test (1, 0,  1, ZERO, X2_EQ_NEG, NOT_ROOT, NOT_ROOT);
    Test (2, 0, -8,  TWO, X2_EQ_POS,        2,       -2);
    Test (1, 5,  0,  TWO, C_EQ_ZERO,        0,       -5);
    Test (1, 6,  9,  ONE, D_EQ_ZERO,       -3, NOT_ROOT);
    Test (2, 2,  3, ZERO,  D_EQ_NEG, NOT_ROOT, NOT_ROOT);
    Test (2, 3,  1,  TWO,  D_EQ_POS,     -0.5,       -1);

}

/** @brief Checks the argument from command line and reads it
*/
void Command_Line_Check (int argc, char *argv[]){

    if (argc > 1 && *argv[1] == *"-ut"){
        Unit_Test();
        exit(0);
    }

}

