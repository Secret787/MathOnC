#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_math.h"

START_TEST(my_abs_test) {
  ck_assert_int_eq(my_abs(-1), abs(-1));
  ck_assert_int_eq(my_abs(5), abs(5));
  ck_assert_int_eq(my_abs(-15), abs(-15));
  ck_assert_int_eq(my_abs(378), abs(378));
  ck_assert_int_eq(my_abs(0), abs(0));
}
END_TEST

START_TEST(my_ceil_test) {
  ck_assert_ldouble_eq_tol(my_ceil(5), ceill(5), 1e-6);
  ck_assert_ldouble_eq_tol(my_ceil(-33), ceill(-33), 1e-6);
  ck_assert_ldouble_eq_tol(my_ceil(55.33), ceill(55.33), 1e-6);
  ck_assert_ldouble_eq_tol(my_ceil(155.87), ceill(155.87), 1e-6);
  ck_assert_ldouble_eq_tol(my_ceil(-155.87), ceill(-155.87), 1e-6);
  ck_assert_ldouble_eq_tol(my_ceil(-55.33), ceill(-55.33), 1e-6);
  ck_assert_ldouble_eq_tol(my_ceil(DBL_MAX), ceill(DBL_MAX), 1e-6);
  ck_assert_ldouble_eq_tol(my_ceil(-DBL_MAX), ceill(-DBL_MAX), 1e-6);
  ck_assert_ldouble_eq_tol(my_ceil(DBL_MIN), ceill(DBL_MIN), 1e-6);
  ck_assert_ldouble_eq_tol(my_ceil(-DBL_MIN), ceill(-DBL_MIN), 1e-6);
  for (long double i = -1000; i < 1000; i += 0.3) {
    ck_assert_ldouble_eq_tol(my_ceil(i), ceill(i), 1e-6);
  }
  ck_assert_ldouble_infinite(my_ceil(MY_INFINITY));
  ck_assert_ldouble_infinite(my_ceil(-MY_INFINITY));
  ck_assert_ldouble_nan(my_ceil(MY_NAN));
}
END_TEST

START_TEST(my_asin_test) {
  ck_assert_ldouble_eq_tol(my_asin(0.456123), asinl(0.456123), 1e-6);
  ck_assert_ldouble_eq_tol(my_asin(0.216875), asinl(0.216875), 1e-6);
  ck_assert_ldouble_eq_tol(my_asin(0.978464), asinl(0.978464), 1e-6);
  ck_assert_ldouble_eq_tol(my_asin(1), asinl(1), 1e-6);
  ck_assert_ldouble_eq_tol(my_asin(-1), asinl(-1), 1e-6);
  ck_assert_ldouble_eq_tol(my_asin(0.532), asinl(0.532), 1e-6);
  ck_assert_ldouble_nan(my_asin(5));
  for (long double i = -1; i < 1; i += 0.01) {
    ck_assert_ldouble_eq_tol(my_asin(i), asinl(i), 1e-6);
  }
  ck_assert_ldouble_eq_tol(my_asin(0.532), asinl(0.532), 1e-6);
  ck_assert_ldouble_nan(my_asin(5));
  ck_assert_ldouble_nan(my_asin(-10));
  ck_assert_ldouble_nan(my_asin(MY_INFINITY));
  ck_assert_ldouble_nan(my_asin(-MY_INFINITY));
  ck_assert_ldouble_nan(my_asin(MY_NAN));
}
END_TEST

START_TEST(my_acos_test) {
  ck_assert_ldouble_eq_tol(my_acos(0.456123), acosl(0.456123), 1e-6);
  ck_assert_ldouble_eq_tol(my_acos(0.216875), acosl(0.216875), 1e-6);
  ck_assert_ldouble_eq_tol(my_acos(0.978464), acosl(0.978464), 1e-6);
  ck_assert_ldouble_eq_tol(my_acos(1), acosl(1), 1e-6);
  ck_assert_ldouble_eq_tol(my_acos(-1), acosl(-1), 1e-6);
  for (long double i = -1; i < 1; i += 0.01) {
    ck_assert_ldouble_eq_tol(my_acos(i), acosl(i), 1e-6);
  }
  ck_assert_ldouble_eq_tol(my_acos(0.532), acosl(0.532), 1e-6);
  ck_assert_ldouble_nan(my_acos(5));
  ck_assert_ldouble_nan(my_acos(-10));
  ck_assert_ldouble_nan(my_acos(MY_INFINITY));
  ck_assert_ldouble_nan(my_acos(-MY_INFINITY));
  ck_assert_ldouble_nan(my_acos(MY_NAN));
}
END_TEST

START_TEST(my_atan_test) {
  ck_assert_ldouble_eq_tol(my_atan(0.456123), atanl(0.456123), 1e-6);
  ck_assert_ldouble_eq_tol(my_atan(0.216875), atanl(0.216875), 1e-6);
  ck_assert_ldouble_eq_tol(my_atan(0.978464), atanl(0.978464), 1e-6);
  ck_assert_ldouble_eq_tol(my_atan(500), atanl(500), 1e-6);
  ck_assert_ldouble_eq_tol(my_atan(-3000), atanl(-3000), 1e-6);
  ck_assert_ldouble_eq_tol(my_atan(MY_PI / 2), atanl(MY_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(my_atan(0), atanl(0), 1e-6);
  ck_assert_ldouble_eq_tol(my_atan(0.3), atanl(0.3), 1e-6);
  ck_assert_ldouble_eq_tol(my_atan(-0.84), atanl(-0.84), 1e-6);
  ck_assert_ldouble_eq_tol(my_atan(-MY_INFINITY), atanl(-MY_INFINITY), 1e-6);
  ck_assert_ldouble_eq_tol(my_atan(MY_INFINITY), atanl(MY_INFINITY), 1e-6);
  ck_assert_ldouble_nan(my_atan(MY_NAN));
}
END_TEST

START_TEST(my_sin_test) {
  ck_assert_ldouble_eq_tol(my_sin(0.456123), sinl(0.456123), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(0.216875), sinl(0.216875), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(0.978464), sinl(0.978464), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(1), sinl(1), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(-1), sinl(-1), 1e-6);
  for (long double i = -5; i < 5; i += 0.03) {
    ck_assert_ldouble_eq_tol(my_sin(i), sinl(i), 1e-6);
  }
  ck_assert_ldouble_eq_tol(my_sin(0), sinl(0), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(MY_PI), sinl(MY_PI), 1e-6);
  ck_assert_ldouble_eq_tol(my_sin(MY_PI / 2), sinl(MY_PI / 2), 1e-6);
  ck_assert_ldouble_nan(my_sin(MY_NAN));
  ck_assert_ldouble_nan(my_sin(MY_INFINITY));
  ck_assert_ldouble_nan(my_sin(-MY_INFINITY));
}
END_TEST

START_TEST(my_cos_test) {
  ck_assert_ldouble_eq_tol(my_cos(0.456123), cosl(0.456123), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(0.216875), cosl(0.216875), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(0.978464), cosl(0.978464), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(1), cosl(1), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(-1), cosl(-1), 1e-6);
  for (long double i = -5; i < 5; i += 0.03) {
    ck_assert_ldouble_eq_tol(my_cos(i), cosl(i), 1e-6);
    
  }
  ck_assert_ldouble_eq_tol(my_cos(0), cosl(0), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(MY_PI), cosl(MY_PI), 1e-6);
  ck_assert_ldouble_eq_tol(my_cos(MY_PI / 2), cosl(MY_PI / 2), 1e-6);
  ck_assert_ldouble_nan(my_cos(MY_NAN));
  ck_assert_ldouble_nan(my_cos(MY_INFINITY));
  ck_assert_ldouble_nan(my_cos(-MY_INFINITY));
}
END_TEST

START_TEST(my_tan_test) {
  ck_assert_ldouble_eq_tol(my_tan(0.456123), tanl(0.456123), 1e-6);
  ck_assert_ldouble_eq_tol(my_tan(0.216875), tanl(0.216875), 1e-6);
  ck_assert_ldouble_eq_tol(my_tan(0.978464), tanl(0.978464), 1e-6);
  ck_assert_ldouble_eq_tol(my_tan(1), tanl(1), 1e-6);
  ck_assert_ldouble_eq_tol(my_tan(-1), tanl(-1), 1e-6);
  for (long double i = -5; i < 5; i += 0.03) {
    ck_assert_ldouble_eq_tol(my_tan(i), tanl(i), 1e-6);
  }
  ck_assert_ldouble_eq_tol(my_tan(0), tanl(0), 1e-6);
  ck_assert_ldouble_eq_tol(my_tan(MY_PI), tanl(MY_PI), 1e-6);
  ck_assert_ldouble_nan(my_tan(MY_NAN));
  ck_assert_ldouble_nan(my_tan(MY_INFINITY));
  ck_assert_ldouble_nan(my_tan(-MY_INFINITY));
}
END_TEST

START_TEST(my_log_test) {
  ck_assert_ldouble_eq_tol(my_log(0.456123), logl(0.456123), 1e-6);
  ck_assert_ldouble_eq_tol(my_log(0.216875), logl(0.216875), 1e-6);
  ck_assert_ldouble_eq_tol(my_log(0.978464), logl(0.978464), 1e-6);
  ck_assert_ldouble_eq_tol(my_log(1), logl(1), 1e-6);
  ck_assert_ldouble_eq_tol(my_log(2.71), logl(2.71), 1e-6);
  ck_assert_ldouble_eq_tol(my_log(0.6), logl(0.6), 1e-6);
  ck_assert_ldouble_eq_tol(my_log(3000), logl(3000), 1e-6);
  ck_assert_ldouble_eq_tol(my_log(535.64), logl(535.64), 1e-6);
  ck_assert_ldouble_infinite(my_log(MY_INFINITY));
  ck_assert_ldouble_nan(my_log(-MY_INFINITY));
  ck_assert_ldouble_nan(my_log(MY_NAN));
}
END_TEST

START_TEST(my_pow_test) {
  ck_assert_ldouble_eq_tol(my_pow(10, 1.5), powl(10, 1.5), 1e-6);
  ck_assert_ldouble_eq_tol(my_pow(1.5, 1.5), powl(1.5, 1.5), 1e-6);
  ck_assert_ldouble_eq_tol(my_pow(0, 1), powl(0, 1), 1e-6);
  ck_assert_ldouble_eq_tol(my_pow(1, 0), powl(1, 0), 1e-6);
  ck_assert_ldouble_eq_tol(my_pow(1.000, 0.000), powl(1.000, 0.000), 1e-6);
  ck_assert_ldouble_eq_tol(my_pow(0.215, 0.215), powl(0.215, 0.215), 1e-6);
  ck_assert_ldouble_eq_tol(my_pow(0.215, MY_INFINITY), powl(0.215, MY_INFINITY), 1e-6);
  ck_assert_ldouble_eq_tol(my_pow(1.215, -MY_INFINITY), powl(1.215, -MY_INFINITY),
                           1e-6);
  ck_assert_ldouble_eq_tol(my_pow(62, 3), powl(62, 3), 1e-6);
  ck_assert_ldouble_eq_tol(my_pow(2, 10), powl(2, 10), 1e-6);
  ck_assert_ldouble_eq_tol(my_pow(2.6, 10), powl(2.6, 10), 1e-6);
  ck_assert_ldouble_eq_tol(my_pow(6.325, 5.623632), powl(6.325, 5.623632),
                           1e-6);
  ck_assert_ldouble_nan(my_pow(-6.325, 5.623632));
  ck_assert_ldouble_infinite(my_pow(-MY_INFINITY, 5));
  ck_assert_ldouble_infinite(my_pow(MY_INFINITY, 5));
  ck_assert_ldouble_infinite(my_pow(0.5, -MY_INFINITY));
  ck_assert_ldouble_infinite(my_pow(2, MY_INFINITY));
  ck_assert_ldouble_nan(my_pow(MY_NAN, 5));
  ck_assert_ldouble_nan(my_pow(5, MY_NAN));
}
END_TEST

START_TEST(my_exp_test) {
  ck_assert_ldouble_eq_tol(my_exp(0.456123), expl(0.456123), 1e-6);
  ck_assert_ldouble_eq_tol(my_exp(0.216875), expl(0.216875), 1e-6);
  ck_assert_ldouble_eq_tol(my_exp(0.978464), expl(0.978464), 1e-6);
  ck_assert_ldouble_eq_tol(my_exp(0), expl(0), 1e-6);
  ck_assert_ldouble_eq_tol(my_exp(1), expl(1), 1e-6);
  ck_assert_ldouble_eq_tol(my_exp(11.09), expl(11.09), 1e-6);
  ck_assert_ldouble_eq_tol(my_exp(5), expl(5), 1e-6);
  ck_assert_ldouble_eq_tol(my_exp(3.756), expl(3.756), 1e-6);
  ck_assert_ldouble_eq_tol(my_exp(-1), expl(-1), 1e-6);
  ck_assert_ldouble_eq_tol(my_exp(-5.5), expl(-5.5), 1e-6);
  // ck_assert_ldouble_eq_tol(my_exp(-MY_INFINITY), expl(-MY_INFINITY), 1e-6);
  // ck_assert_ldouble_infinite(my_exp(MY_INFINITY));
  ck_assert_ldouble_nan(my_exp(MY_NAN));
}
END_TEST

START_TEST(my_sqrt_test) {
  ck_assert_ldouble_eq_tol(my_sqrt(0.456123), sqrtl(0.456123), 1e-6);
  ck_assert_ldouble_eq_tol(my_sqrt(0.216875), sqrtl(0.216875), 1e-6);
  ck_assert_ldouble_eq_tol(my_sqrt(0.978464), sqrtl(0.978464), 1e-6);
  ck_assert_ldouble_eq_tol(my_sqrt(5.5), sqrtl(5.5), 1e-6);
  ck_assert_ldouble_eq_tol(my_sqrt(0), sqrtl(0), 1e-6);
  ck_assert_ldouble_eq_tol(my_sqrt(1), sqrtl(1), 1e-6);
  ck_assert_ldouble_eq_tol(my_sqrt(0.35), sqrtl(0.35), 1e-6);
  ck_assert_ldouble_eq_tol(my_sqrt(25), sqrtl(25), 1e-6);
  ck_assert_ldouble_eq_tol(my_sqrt(532.3), sqrtl(532.3), 1e-6);
  ck_assert_ldouble_infinite(my_sqrt(MY_INFINITY));
  ck_assert_ldouble_nan(my_sqrt(MY_NAN));
  ck_assert_ldouble_nan(my_sqrt(-MY_INFINITY));
  ck_assert_ldouble_nan(my_sqrt(-5));
}
END_TEST

START_TEST(my_fabs_test) {
  ck_assert_ldouble_eq_tol(my_fabs(-1), fabsl(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(my_fabs(5), fabsl(5.0), 1e-6);
  ck_assert_ldouble_eq_tol(my_fabs(-15), fabsl(-15.0), 1e-6);
  ck_assert_ldouble_eq_tol(my_fabs(378), fabsl(378.0), 1e-6);
  ck_assert_ldouble_eq_tol(my_fabs(0), fabsl(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(my_fabs(-1.375), fabsl(-1.375), 1e-6);
  ck_assert_ldouble_eq_tol(my_fabs(5.698), fabsl(5.698), 1e-6);
  ck_assert_ldouble_eq_tol(my_fabs(-15.1), fabsl(-15.1), 1e-6);
  ck_assert_ldouble_eq_tol(my_fabs(378.555), fabsl(378.555), 1e-6);
  ck_assert_ldouble_infinite(my_fabs(MY_INFINITY));
  ck_assert_ldouble_infinite(my_fabs(-MY_INFINITY));
  ck_assert_ldouble_nan(my_fabs(MY_NAN));
}
END_TEST

START_TEST(my_floor_test) {
  ck_assert_ldouble_eq_tol(my_floor(5), floorl(5), 1e-6);
  ck_assert_ldouble_eq_tol(my_floor(-33), floorl(-33), 1e-6);
  ck_assert_ldouble_eq_tol(my_floor(55.33), floorl(55.33), 1e-6);
  ck_assert_ldouble_eq_tol(my_floor(155.87), floorl(155.87), 1e-6);
  ck_assert_ldouble_eq_tol(my_floor(-155.87), floorl(-155.87), 1e-6);
  ck_assert_ldouble_eq_tol(my_floor(-55.33), floorl(-55.33), 1e-6);
  ck_assert_ldouble_eq_tol(my_floor(DBL_MAX), floorl(DBL_MAX), 1e-6);
 
  
  ck_assert_ldouble_infinite(my_floor(MY_INFINITY));
  ck_assert_ldouble_infinite(my_floor(-MY_INFINITY));
  ck_assert_ldouble_nan(my_floor(MY_NAN));
}
END_TEST

START_TEST(my_fmod_test) {
  ck_assert_ldouble_eq_tol(my_fmod(-5.3, 3.3), fmodl(-5.3, 3.3), 1e-6);
  ck_assert_ldouble_eq_tol(my_fmod(9874.785, 15.15), fmodl(9874.785, 15.15),
                           1e-6);
  ck_assert_ldouble_eq_tol(my_fmod(-9874.785, 15.15), fmodl(-9874.785, 15.15),
                           1e-6);
  ck_assert_ldouble_eq_tol(my_fmod(-3465.001, 8.8), fmodl(-3465.001, 8.8),
                           1e-6);
  ck_assert_ldouble_eq_tol(my_fmod(3465.001, 8.8), fmodl(3465.001, 8.8), 1e-6);
  ck_assert_ldouble_eq_tol(my_fmod(0.215, 0.215), fmodl(0.215, 0.215), 1e-6);
  ck_assert_ldouble_eq_tol(my_fmod(0.978464, 5), fmodl(0.978464, 5), 1e-6);
  ck_assert_ldouble_eq_tol(my_fmod(6.325, 5.623632), fmodl(6.325, 5.623632),
                           1e-6);
  ck_assert_ldouble_eq_tol(my_fmod(-6.325, 5.623632), fmodl(-6.325, 5.623632),
                           1e-6);
  ck_assert_ldouble_eq_tol(my_fmod(6.325, -5.623632), fmodl(6.325, -5.623632),
                           1e-6);
  ck_assert_ldouble_eq_tol(my_fmod(6.325, 15.623632), fmodl(6.325, 15.623632),
                           1e-6);
  ck_assert_ldouble_eq_tol(my_fmod(-6.325, 15.623632),
                           fmodl(-6.325, 15.623632), 1e-6);
  ck_assert_ldouble_eq_tol(my_fmod(6.325, -15.623632),
                           fmodl(6.325, -15.623632), 1e-6);
  ck_assert_ldouble_nan(my_fmod(6.325, MY_NAN));
  ck_assert_ldouble_nan(my_fmod(MY_NAN, 4));
  ck_assert_ldouble_nan(my_fmod(MY_INFINITY, MY_INFINITY));
}
END_TEST

int main() {
  Suite *suite = suite_create("my_MATH");
  SRunner *srunner = srunner_create(suite);

  TCase *my_abs_tcase = tcase_create("my_abs_test");
  suite_add_tcase(suite, my_abs_tcase);
  tcase_add_test(my_abs_tcase, my_abs_test);

  TCase *my_ceil_tcase = tcase_create("my_ceimy_test");
  suite_add_tcase(suite, my_ceil_tcase);
  tcase_add_test(my_ceil_tcase, my_ceil_test);

  TCase *my_asin_tcase = tcase_create("my_asin_test");
  suite_add_tcase(suite, my_asin_tcase);
  tcase_add_test(my_asin_tcase, my_asin_test);

  TCase *my_acos_tcase = tcase_create("my_acos_test");
  suite_add_tcase(suite, my_acos_tcase);
  tcase_add_test(my_acos_tcase, my_acos_test);

  TCase *my_atan_tcase = tcase_create("my_atan_test");
  suite_add_tcase(suite, my_atan_tcase);
  tcase_add_test(my_atan_tcase, my_atan_test);

  TCase *my_sin_tcase = tcase_create("my_sin_test");
  suite_add_tcase(suite, my_sin_tcase);
  tcase_add_test(my_sin_tcase, my_sin_test);

  TCase *my_cos_tcase = tcase_create("my_cos_test");
  suite_add_tcase(suite, my_cos_tcase);
  tcase_add_test(my_cos_tcase, my_cos_test);

  TCase *my_tan_tcase = tcase_create("my_tan_test");
  suite_add_tcase(suite, my_tan_tcase);
  tcase_add_test(my_tan_tcase, my_tan_test);

  TCase *my_exp_tcase = tcase_create("my_exp_test");
  suite_add_tcase(suite, my_exp_tcase);
  tcase_add_test(my_exp_tcase, my_exp_test);

  TCase *my_fabs_tcase = tcase_create("my_fabs_test");
  suite_add_tcase(suite, my_fabs_tcase);
  tcase_add_test(my_fabs_tcase, my_fabs_test);

  TCase *my_floor_tcase = tcase_create("my_floor_test");
  suite_add_tcase(suite, my_floor_tcase);
  tcase_add_test(my_floor_tcase, my_floor_test);

  TCase *my_log_tcase = tcase_create("my_log_test");
  suite_add_tcase(suite, my_log_tcase);
  tcase_add_test(my_log_tcase, my_log_test);

  TCase *my_pow_tcase = tcase_create("my_pow_test");
  suite_add_tcase(suite, my_pow_tcase);
  tcase_add_test(my_pow_tcase, my_pow_test);

  TCase *my_sqrt_tcase = tcase_create("my_sqrt_test");
  suite_add_tcase(suite, my_sqrt_tcase);
  tcase_add_test(my_sqrt_tcase, my_sqrt_test);

  TCase *my_fmod_tcase = tcase_create("my_fmod_test");
  suite_add_tcase(suite, my_fmod_tcase);
  tcase_add_test(my_fmod_tcase, my_fmod_test);

  srunner_run_all(srunner, CK_VERBOSE);
  srunner_free(srunner);

  return 0;
}
