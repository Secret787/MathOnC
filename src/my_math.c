#include "my_math.h"

#include <float.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>


int my_abs(int x) {                   
  if (x < 0) { x = -1 * x; }
  return x;
}

long double my_ceil(double x) {       
  long double result = (long int)x;
  if (x == -MY_INFINITY) {result = -MY_INFINITY;
  } else if (x == MY_INFINITY) { result = MY_INFINITY;
  } else if (x == DBL_MAX) { result = DBL_MAX;
  } else if (x == -DBL_MAX) { result = -DBL_MAX;
  } else if (x != x) { result = MY_NAN;
  } else if (result < x ) { result = result + 1;
  } 
  return result;
}

long double my_floor(double x) {        
  long double result = (long long int)x;
  if (x == MY_INFINITY) { result = MY_INFINITY;
  } else if (x == -MY_INFINITY) { result = -MY_INFINITY;
  } else if (x == DBL_MAX) { result = DBL_MAX;
  } else if (x == -DBL_MAX) { result = -DBL_MAX;
  } else if (x != x) { result = MY_NAN;
  } else if (result > x) { result = result - 1;
  }
  return result;
}

long double my_fabs(double x) {          
  long double result = x;
  if (x < 0) { result = x * -1.0L; }
  return result;
}

long double factoriamy_d(long double n) {   
  if (n == 0.0 || n == 1.0) {
    return 1.0;
  } else {
    return n * factoriamy_d(n - 1);
  }
}

long double my_cos(double x) { 
  int sign = 1;
  if (((0 <= my_fabs(x)) && (my_fabs(x) < MY_PI/2)) || 
  ((3 * MY_PI / 2 <= my_fabs(x)) && (my_fabs(x) <= 2 * MY_PI))){
    sign = 1;
  } else {sign = -1;}
  return sign * my_sqrt(1 - my_sin(x) * my_sin (x)); 
  }

long double my_sin(double x) {
  long double result = 0;
  long double denominator = 1.;
  if (x == MY_INFINITY || x == -MY_INFINITY) { result = MY_NAN;
  } else if (my_fabs(x) > 2 * MY_PI) {
    x = my_fmod(x, (2 * MY_PI));
  }
  long double numerator = x;
  for (int i = 0; i < 15; i++) {
    denominator *= (2 * i + 1) * (i > 0 ? (2 * i) : 1);
    result += (i % 2 ? -1 : 1) * numerator / denominator;
    numerator = numerator * x * x;
  }
  return result;
}

long double my_tan(double x) { return (my_sin(x) / my_cos(x)); }

long double my_exp(double x) {
  long double add_value = 1;
  long double series = 1;
  long double i = 1;
  long double old = 0;
  int flag_minus = 0;
  if (x < 0) {
    x = my_fabs(x);
    flag_minus = 1;
  }
  while (series - old > MY_EPS) {
    add_value *= x / i;
    i++;
    old = series;
    series += add_value;
    if (series > DBL_MAX || series < -DBL_MAX) {
      if (x > 0) {
        series = MY_INFINITY;
        break;
      }
    }
  }
  if (flag_minus == 1) {
    series = 1. / series;
  }
  return series;
}

long double my_p(long double  x, int n)
{
  long double result = 1;
  if (x == 1 || n == 0) { result = 1;
  } else { for (int i = 0; i < n; i++)
  { result = result * x;}}
  return result;
}

long double my_asin(double x) {
  long double result = 0;
  long double Oldresult = 1;
  int sign= 0;
  long double numerator = 0;
  long double denominator = 0;
  int n = 0;
 
  if (x > 0.5) { x = my_sqrt(1 - x * x); sign = 1;
  } else if (x < -0.5 ) { x = my_sqrt(1 - x * x); sign = -1; 
  } else if (my_fabs(x) > 1) { result = MY_NAN; 
  }  
  while (my_fabs(Oldresult - result) > MY_EPS*1e-22 && result != MY_NAN)
  {
    numerator = factoriamy_d( 2 * n ) * my_p( x, ( 2 * n + 1 ));
    denominator = my_p(2, ( 2 * n )) * factoriamy_d( n ) * factoriamy_d( n ) * (2 * n + 1);
    Oldresult = result;
    result = result + numerator/denominator;
    n = n + 1;
  }
  if (sign != 0) { result = (MY_PI / 2 - result) * sign;}
  return result;
}

long double my_acos(double x) { return (MY_PI / 2 - my_asin(x)); }

long double my_atan(double x) {
  double sign = 1;
  if (x < 0) { sign = -1;}
  return sign * my_acos(1 / my_sqrt(1 + x * x));
}

long double my_log(double x) {
  long double returnValue = eps;
  long double counterStepen = 0.0L;
  long double counterMinusStepen = 0.0L;
  if (x == -MY_INFINITY) {
    returnValue = MY_NAN;
  } else if (x != x) {
    returnValue = MY_NAN;
  } else if (!(x != x) && x - x != x - x) {
    returnValue = MY_INFINITY;
  } else {
    //
    if (x < 0) {
      returnValue = MY_NAN;
    } else if (x == 0) {  // вот тут получается надо именно 0
      returnValue = -MY_INFINITY;
    }
    if (returnValue == eps) {
      while (my_floor(x) < 0.1) {
        counterMinusStepen++;
        x = x * 10;
      }
      while (my_floor(x) > eps) {
        counterStepen++;
        x = x / 10;
      }
      x = x - 1;
      long double rememberX = x;
      returnValue = x;
      int minusOne = 1;
      for (int k = 2; k <= 1000;
           k++) {  // чем большее число в логарифм? тем больше шагов надо тут
        x = x * rememberX;
        minusOne = minusOne * (-1);
        returnValue = returnValue + minusOne * x / k;
      }
      returnValue =
          returnValue + counterStepen * lnTEN - counterMinusStepen * lnTEN;
    }
  }
  return returnValue;
}

long double my_pow(double base, double e) {
  long double returnValue = 0.0L;
  int infinitySign = 1;
  if (base == -MY_INFINITY && my_fmod(my_fabs(e), 2.) == 1) {
    infinitySign = -1;
  }
  if (base == 0. && e == 0.) {
    returnValue = 1.;
  } else if ((my_fabs(base) == 1. && my_fabs(e) == MY_INFINITY) ||
             (base == 1. && e != e)) {
    returnValue = 1.;
  } else if ((my_fabs(base) > 1. && e == MY_INFINITY) ||
             (my_fabs(base) < 1. && e == -MY_INFINITY)) {
    returnValue = MY_INFINITY;
  } else if ((my_fabs(base) < 1. && e == MY_INFINITY) ||
             (my_fabs(base) > 1. && e == -MY_INFINITY)) {
    returnValue = 0.;
  } else if (my_fabs(base) == MY_INFINITY && e == 0.) {
    returnValue = 1.;
  } else if (my_fabs(base) == MY_INFINITY && e < 0.) {
    returnValue = 0.;
  } else if (my_fabs(base) > 1. && e == -DBL_MAX) {
    returnValue = 0.;
  } else if (my_fabs(base) == 1. && e == -DBL_MAX) {
    returnValue = 1.;
  } else if (base > -1. && base < 0. && e == -DBL_MAX) {
    returnValue = MY_INFINITY;
  } else if (base == -MY_INFINITY) {
    returnValue = MY_INFINITY;
  } else if (base > 1 && e == DBL_MIN) {
    returnValue = 1;
  } else if (base == DBL_MAX && e == DBL_MAX) {
    returnValue = MY_INFINITY;
  } else {
    returnValue = my_exp(my_log(base) * e);
  }
  return infinitySign * returnValue;
}

long double my_sqrt(double x) {
  long double startX = 0.0L;

  startX = x / 2.;
  if (startX < 0) {
    startX = MY_NAN;
  } else if (!(startX != startX) && (startX - startX != startX - startX)) {
    startX = MY_INFINITY;
  } else if (startX > 0) {
    for (int i = 1; i < 1000; i++) {
      startX = 1. / 2 * (startX + x / startX);
    }
  } else if (startX != startX) {
    startX = MY_NAN;
  } else {
    startX = 0;
  }

  return startX;
}

long double my_fmod(double x, double y) {
  long double res = 0.0L;
  int nan = __builtin_isnan(x);
  if ((x < DOUBLE_MIN && x > -DOUBLE_MIN) &&
      !(y < DOUBLE_MIN && y > -DOUBLE_MIN)) {
    res = (long double)x;
  } else if (nan || x == MY_INFINITY || x == 0 || y == 0) {
    res = (long double)MY_NAN;
  } else if (((y < DOUBLE_MIN && y > -DOUBLE_MIN) || my_fabs(y) == DBL_MIN) &&
             my_fabs(x) != MY_INFINITY) {
    res = 0.0L;
  } else {
    long double fabs_x = my_fabs(x);
    long double fabs_y = my_fabs(y);
    long double substract = fabs_y;
    while (fabs_x > substract) substract = substract + substract;
    if (fabs_x < substract) substract = substract - substract;
    long double fabs_res = fabs_x - substract;
    while (fabs_res >= fabs_y) fabs_res = fabs_res - fabs_y;
    res = (x < 0.0L) ? -fabs_res : fabs_res;
  }
  return res;
}
