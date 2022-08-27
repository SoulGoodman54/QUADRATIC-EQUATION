#define EPS 0.0001
#define NOT_ROOT -100

/** @brief Scores list of constants at number of roots

    @param INF Infinite
    @param ZERO Zero roots
    @param ONE One root
    @param TWO Two roots

*/
enum NUMBER_OF_ROOTS{

    INF  = -1,
    ZERO,
    ONE,
    TWO,

};


/** @brief Stores possible types of equation

    @param INF_R All cofficients equal 0
    @param ZERO_EQ_C a and b eaqual 0
    @param L_EQ Linear equation
    @param X_EQ_ZERO b and c equal 0
    @param X2_EQ_NEG x^2 equals negative number
    @param X2_EQ_POS x^2 equals positive number
    @param C_EQ_ZERO c equals 0
    @param D_EQ_ZERO Discriminant equals 0
    @param D_EQ_NEG Discriminant less 0
    @param D_EQ_POS Discriminant more 0

*/
enum Cases{

    INF_R,
    ZERO_EQ_C,
    L_EQ,
    X_EQ_ZERO,
    X2_EQ_NEG,
    X2_EQ_POS,
    C_EQ_ZERO,
    D_EQ_ZERO,
    D_EQ_NEG,
    D_EQ_POS,

};




// SQ_QL
bool is_zero(double a);

int Probably_Case    (double  a, double  b, double  c);

void Solve_Square_Eq (double  a, double  b, double  c, double *x1, double *x2);
void Solve_Linear_Eq (           double  b, double  c, double *x);

void Solve           (double  a, double  b, double  c, double *x1, double *x2);
void Start           (double *a, double *b, double *c);

void Input (double *a);




// UNIT_TEST
int Number_Of_Roots (double a, double b, double c);
void Test(double a, double b, double c, int Num_root, int Pr_case, double correct_x1, double correct_x2);
void Unit_Test();
void Command_Line_Check (int argc, char *argv[]);

