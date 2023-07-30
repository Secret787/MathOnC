#ifndef MY_MATH_H
#define MY_MATH_H
#define MY_PI 3.14159265358979323846264338327950288
#define MY_INFINITY __builtin_huge_valf()                
#define MY_NAN __builtin_nanf("0x7fc00000")              // NAN Not-a-Number
#define DOUBLE_MIN 2.22507e-308L
#define DOUBLE_MAX 1.79769e+308L
#define MY_EPS 1e-10
#define eps 0.0000001
#define EXP 2.7182818284590452353602874713527
#define lnTEN 2.3025850929940459010936137929093092679977
int my_abs(int x);
long double my_ceil(double x);
long double my_floor(double x);
long double my_fabs(double x);
long double factoriamy_d(long double n);
long double my_cos(double x);
long double my_sin(double x);
long double my_tan(double x);
long double my_exp(double x);
long double my_acos(double x);
long double my_asin(double x);
long double my_asin2(double x);
long double my_p(long double  x, int n);
long double my_atan(double x);
long double my_log(double x);
long double my_pow(double base, double e);
long double my_sqrt(double x);
long double my_fmod(double x, double y);
#endif
