
// #include <check.h>
#include <gtest/gtest.h>


#include "../model/model.h"

#define EPS 1e-7
#define EPS2 1e-2

// GCOVR_EXCL_START

namespace {



TEST(ExpressionComputation, T0Simple) {
  const char *input_str = "1+2*3";


  double result = 0.0;
  double x_value = 0.0;
  const int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const double expected = 7.0;
  const int ex_expected = 0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}

TEST(ExpressionComputation, T1Simple) {
  const char *input_str = "2.0/(3.0+2.0)*5.0";


  double result = 0.0;
  double x_value = 0.0;
  const int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const double expected = 2.0;
  const int ex_expected = 0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}

TEST(ExpressionComputation, T2SimpleBraces) {
  const char *input_str = "1+2+(3*4)+(5.1+6.8)";


  double result = 0.0;
  double x_value = 0.0;
  const int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const double expected = 26.9;
  const int ex_expected = 0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}

TEST(ExpressionComputation, T3Simple) {
  const char *input_str = "10.0+10.0*10.0";


  double result = 0.0;
  double x_value = 0.0;
  const int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const double expected = 110.0;
  const int ex_expected = 0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}


TEST(ExpressionComputation, T4SimpleMod) {
  const char *input_str = "5.0mod3.0";


  double result = 0.0;
  double x_value = 0.0;
  const int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const double expected = 2.0;
  const int ex_expected = 0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}

TEST(ExpressionComputation, T5SimpleBraces) {
  const char *input_str = "1.0/2.0*(2.0-1.0)";


  double result = 0.0;
  double x_value = 0.0;
  const int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const double expected = 0.5;
  const int ex_expected = 0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}

TEST(ExpressionComputation, T6MoreBraces) {
  const char *input_str = "(1-2-(0-3)-4)-5-(0-6)";


  double result = 0.0;
  double x_value = 0.0;
  const int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const double expected = -1.0;
  const int ex_expected = 0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}

TEST(ExpressionComputation, T7MoreBraces) {
  const char *input_str = "(1+2)*((3-4)+1+(5-6+7))";


  double result = 0.0;
  double x_value = 0.0;
  const int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const double expected = 18.0;
  const int ex_expected = 0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}

TEST(ExpressionComputation, T8MoreBraces) {
  const char *input_str = "sqrt(4)-1/2*sin(3^2-2)";

  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = 1.6715067;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}



TEST(ExpressionComputation, T1Pows)  {
  const char *input_str = "2^3^2";

  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = 512.0;

  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}


// // DON'T!!!!!!!!!!!!!!!!!!!!!
// // DON'T!!!!!!!!!!!!!!!!!!!!!
// // DON'T!!!!!!!!!!!!!!!!!!!!!
// // START_TEST(test_case_11) {
// //   char *input_str = "sin(+3)";
// //   double result = 0;
// //   double x_value = 0;
// //   int ex_code;
// //   ex_code = main_for_calc(input_str, &result, x_value);
// //   ck_assert_int_eq(ex_code, 0);
// //   ck_assert_double_eq_tol(result, 0.1411200, EPS);
// // }
// // END_TEST

TEST(ExpressionComputation, T4Simple) {
  const char *input_str = "-1+8";

  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = 7.0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}


TEST(ExpressionComputation, T1Mod) {
  const char *input_str = "-5.0mod(-3.0)";

  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = -2.0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}


TEST(ExpressionComputation, T1LongEpression) {
  const char *input_str = "4+4*2/(1-5)";

  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = 2.0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}


TEST(ExpressionComputation, T2LongEpression) {
  const char *input_str = "4+4*2/1-5";

  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = 7.0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}


TEST(ExpressionComputation, T3LongEpression) {
  const char *input_str = "4+4*(2/1-5)";

  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = -8.0;

  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}


TEST(ExpressionComputation, T4LongEpression) {
  const char *input_str = "4+(4*2/1-5)";

  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = 7.0;

  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}


TEST(ExpressionComputation, T5LongEpression) {
  const char *input_str = "4+4*(2/1)-5";

  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = 7.0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}


TEST(ExpressionComputation, T6LongEpression) {
  const char *input_str = "4+(4*2/1)-5";

  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = 7.0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}


TEST(ExpressionComputation, T7LongEpression) {
  const char *input_str = "(4+4*2/1)-5";

  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = 7.0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}


TEST(ExpressionComputation, T8LongEpression) {
  const char *input_str = "4+(4*2)/1-5";

  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = 7.0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}


TEST(ExpressionComputation, T9LongEpression) {
  char *input_str = "(4+4*2)/1-5";
  
  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = 7.0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}


TEST(ExpressionComputation, T10LongEpression) {
  const char *input_str = "8*(7+6*4)+3";

  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = 251.0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}


TEST(ExpressionComputation, T11LongEpression) {
  const char *input_str = "2/(3+2)*5";

  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = 2.0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
  
}


TEST(ExpressionComputation, T12LongEpression) {
  const char *input_str = "2+9.3-8^3/4+56.2";

  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = -60.5;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}


TEST(ExpressionComputation, T13LongEpression) {
  const char *input_str = "2+9.3-8^3/(4+56.2)";

  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = 2.7950166;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}


TEST(ExpressionComputation, T14LongEpression) {
  const char *input_str = "2^(3^2)";
 
  double result = 0.0;
  double x_value = 0.0;
  int ex_code = Model::main_for_calc(input_str, &result, x_value);
  const int ex_expected = 0;
  const double expected = 512.0;
  EXPECT_EQ(ex_code, ex_expected);
  EXPECT_NEAR(result, expected, EPS);
}


// START_TEST(test_case_28) {
//   char *input_str = "(2^3)^2";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 64, EPS);
// }
// END_TEST

// START_TEST(test_case_29) {
//   char *input_str = "cos(431.2*2^2/8)";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, -0.3902501, EPS);
// }
// END_TEST

// START_TEST(test_case_30) {
//   char *input_str = "3*sin(4+5)";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 1.2363555, EPS);
// }
// END_TEST

// START_TEST(test_case_31) {
//   char *input_str = "431.2*2^2/8";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 215.6, EPS);
// }
// END_TEST

// START_TEST(test_case_32) {
//   char *input_str = "cos(sin(2+9*6^1.2-tan(1)))";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 0.7421823, EPS);
// }
// END_TEST

// START_TEST(test_case_33) {
//   char *input_str = "sqrt(cos(sin(2+9*6^1.2-tan(1))))";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 0.8615000, EPS);
// }
// END_TEST

// START_TEST(test_case_34) {
//   char *input_str = "sqrt(cos(sin(2+9*6^1.2-tan(1))))mod0.1";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 0.0615000, EPS);
// }
// END_TEST

// START_TEST(test_case_35) {
//   char *input_str = "sqrt(2^2)*5/(4-3mod2)*(4-sqrt(81))";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, -16.6666667, EPS);
// }
// END_TEST

// START_TEST(test_case_36) {
//   char *input_str = "cos(1/3)*sin(1.352^9/(4+3))";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 0.7876032, EPS);
// }
// END_TEST

// START_TEST(test_case_37) {
//   char *input_str = "(cos(1/3)*sin(1.352^9/(4+3))/76.56)*log(150)";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 0.0223863, EPS);
// }
// END_TEST

// START_TEST(test_case_38) {
//   char *input_str = "2+(-(-(-(-1))))";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 3, EPS);
// }
// END_TEST

// START_TEST(test_case_39) {
//   char *input_str = "cos(6*3)/5";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 0.1320633, EPS);
// }
// END_TEST

// START_TEST(test_case_40) {
//   char *input_str = "12.6.9+8";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 1);
// }
// END_TEST

// START_TEST(test_case_41) {
//   char *input_str = "(12+6";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 1);
// }
// END_TEST

// START_TEST(test_case_42) {
//   char *input_str = "(12+6))8*3(";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 1);
// }
// END_TEST

// START_TEST(test_case_43) {
//   char *input_str = "acos1";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 0, EPS);
// }
// END_TEST

// START_TEST(test_case_44) {
//   char *input_str = "acos0.5";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 1.0471975, EPS);
// }
// END_TEST

// START_TEST(test_case_45) {
//   char *input_str = "atan1";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 0.7853981, EPS);
// }
// END_TEST

// START_TEST(test_case_46) {
//   char *input_str = "atan15";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 1.5042281, EPS);
// }
// END_TEST

// START_TEST(test_case_47) {
//   char *input_str = "asin1";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 1.5707963, EPS);
// }
// END_TEST

// START_TEST(test_case_48) {
//   char *input_str = "asin0.5";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 0.5235987, EPS);
// }
// END_TEST

// START_TEST(test_case_49) {
//   char *input_str = "ln1";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 0, EPS);
// }
// END_TEST

// START_TEST(test_case_50) {
//   char *input_str = "ln15";
//   double result = 0;
//   double x_value = 0;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 2.7080502, EPS);
// }
// END_TEST


// // DON'T!!!!!!!!!!!!!!!!!
// // DON'T!!!!!!!!!!!!!!!!!
// // DON'T!!!!!!!!!!!!!!!!!
// // START_TEST(test_case_51) {
// //   char *input_str = "x+15";
// //   double result = 0;
// //   double x_value = 2;
// //   int ex_code;
// //   ex_code = main_for_calc(input_str, &result, x_value);
// //   ck_assert_int_eq(ex_code, 0);
// //   ck_assert_double_eq_tol(result, 17, EPS);
// // }
// // END_TEST

// START_TEST(test_case_52) {
//   char *input_str = "x^2+x*2";
//   double result = 0;
//   double x_value = 3;
//   int ex_code;
//   ex_code = main_for_calc(input_str, &result, x_value);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(result, 15, EPS);
// }
// END_TEST

// START_TEST(test_case_53) {
//   double credit_sum = 100000;
//   int credit_term = 6;
//   float credit_percent = 15;
//   int type = 1;
//   double monthlty_payment;
//   double overpayment;
//   double total_sum;
//   int ex_code;
//   ex_code = credit_calc_fn(credit_sum, credit_term, credit_percent, type,
//                            &monthlty_payment, &overpayment, &total_sum);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(monthlty_payment, 17403.38, EPS2);
//   ck_assert_double_eq_tol(overpayment, 4420.29, EPS2);
//   ck_assert_double_eq_tol(total_sum, 104420.29, EPS2);
// }
// END_TEST

// START_TEST(test_case_54) {
//   double credit_sum = 100000;
//   int credit_term = 6;
//   float credit_percent = 15;
//   int type = 2;
//   double monthlty_payment;
//   double overpayment;
//   double total_sum;
//   int ex_code;
//   ex_code = credit_calc_fn(credit_sum, credit_term, credit_percent, type,
//                            &monthlty_payment, &overpayment, &total_sum);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(monthlty_payment, 17916.67, EPS2);
//   ck_assert_double_eq_tol(overpayment, 4375.00, EPS2);
//   ck_assert_double_eq_tol(total_sum, 104375.00, EPS2);
// }
// END_TEST

// START_TEST(test_case_55) {
//   double deposit_sum = 100000;
//   int deposit_term = 6;
//   float deposit_percent = 7;
//   float tax_percent = 0;
//   int type_cap = 1;
//   int type_pay = 1;
//   double add_sum[6] = {5000, 0, 0, 0, 0, 0};
//   double interest_income;
//   double total_deposit_sum;
//   double tax_sum;
//   int ex_code;
//   ex_code = deposit_calc_fn(deposit_sum, deposit_term, deposit_percent,
//                             tax_percent, type_cap, type_pay, add_sum,
//                             &interest_income, &total_deposit_sum, &tax_sum);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(interest_income, 3675.00, EPS2);
//   ck_assert_double_eq_tol(total_deposit_sum, 108675.00, EPS2);
//   ck_assert_double_eq_tol(tax_sum, 0, EPS2);
// }
// END_TEST

// START_TEST(test_case_56) {
//   double deposit_sum = 100000;
//   int deposit_term = 6;
//   float deposit_percent = 7;
//   float tax_percent = 0;
//   int type_cap = 2;
//   int type_pay = 1;
//   double add_sum[6] = {5000, 0, 0, 0, 0, 0};
//   double interest_income;
//   double total_deposit_sum;
//   double tax_sum;
//   int ex_code;
//   ex_code = deposit_calc_fn(deposit_sum, deposit_term, deposit_percent,
//                             tax_percent, type_cap, type_pay, add_sum,
//                             &interest_income, &total_deposit_sum, &tax_sum);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(interest_income, 3675.00, EPS2);
//   ck_assert_double_eq_tol(total_deposit_sum, 108675.00, EPS2);
//   ck_assert_double_eq_tol(tax_sum, 0, EPS2);
// }
// END_TEST

// START_TEST(test_case_57) {
//   double deposit_sum = 100000;
//   int deposit_term = 6;
//   float deposit_percent = 7;
//   float tax_percent = 0;
//   int type_cap = 1;
//   int type_pay = 2;
//   double add_sum[6] = {5000, 0, 0, 0, 0, 0};
//   double interest_income;
//   double total_deposit_sum;
//   double tax_sum;
//   int ex_code;
//   ex_code = deposit_calc_fn(deposit_sum, deposit_term, deposit_percent,
//                             tax_percent, type_cap, type_pay, add_sum,
//                             &interest_income, &total_deposit_sum, &tax_sum);
//   ck_assert_int_eq(ex_code, 0);
//   ck_assert_double_eq_tol(interest_income, 3729.01, EPS2);
//   ck_assert_double_eq_tol(total_deposit_sum, 108729.01, EPS2);
//   ck_assert_double_eq_tol(tax_sum, 0, EPS2);
// }
// END_TEST

// START_TEST(test_case_58) {
//   double deposit_sum = 100000;
//   int deposit_term = 6;
//   float deposit_percent = 7;
//   float tax_percent = 0;
//   int type_cap = 1;
//   int type_pay = 1;
//   double add_sum[6] = {5000, 0, 0, -1000000, 0, 0};
//   double interest_income;
//   double total_deposit_sum;
//   double tax_sum;
//   int ex_code;
//   ex_code = deposit_calc_fn(deposit_sum, deposit_term, deposit_percent,
//                             tax_percent, type_cap, type_pay, add_sum,
//                             &interest_income, &total_deposit_sum, &tax_sum);
//   ck_assert_int_eq(ex_code, 1);
// }
// END_TEST

// START_TEST(test_case_59) {
//   double deposit_sum = 100000;
//   int deposit_term = 6;
//   float deposit_percent = 7;
//   float tax_percent = 0;
//   int type_cap = 2;
//   int type_pay = 1;
//   double add_sum[6] = {5000, 0, -150000, 0, 0, 0};
//   double interest_income;
//   double total_deposit_sum;
//   double tax_sum;
//   int ex_code;
//   ex_code = deposit_calc_fn(deposit_sum, deposit_term, deposit_percent,
//                             tax_percent, type_cap, type_pay, add_sum,
//                             &interest_income, &total_deposit_sum, &tax_sum);
//   ck_assert_int_eq(ex_code, 1);
// }
// END_TEST

// START_TEST(test_case_60) {
//   double deposit_sum = 100000;
//   int deposit_term = 6;
//   float deposit_percent = 7;
//   float tax_percent = 0;
//   int type_cap = 1;
//   int type_pay = 2;
//   double add_sum[6] = {5000, -150000, 0, 0, 0, 0};
//   double interest_income;
//   double total_deposit_sum;
//   double tax_sum;
//   int ex_code;
//   ex_code = deposit_calc_fn(deposit_sum, deposit_term, deposit_percent,
//                             tax_percent, type_cap, type_pay, add_sum,
//                             &interest_income, &total_deposit_sum, &tax_sum);
//   ck_assert_int_eq(ex_code, 1);
// }
// END_TEST

// int main(void) {
//   Suite *s1 = suite_create("SmartCalc");
//   TCase *smart_calc = tcase_create("SmartCalc");
//   suite_add_tcase(s1, smart_calc);
//   tcase_add_test(smart_calc, test_case_1);
//   tcase_add_test(smart_calc, test_case_2);
//   tcase_add_test(smart_calc, test_case_3);
//   tcase_add_test(smart_calc, test_case_4);
//   tcase_add_test(smart_calc, test_case_5);
//   tcase_add_test(smart_calc, test_case_6);
//   tcase_add_test(smart_calc, test_case_7);
//   tcase_add_test(smart_calc, test_case_8);
//   tcase_add_test(smart_calc, test_case_9);
//   tcase_add_test(smart_calc, test_case_10);
//   // tcase_add_test(smart_calc, test_case_11);
//   tcase_add_test(smart_calc, test_case_12);
//   tcase_add_test(smart_calc, test_case_13);
//   tcase_add_test(smart_calc, test_case_14);
//   tcase_add_test(smart_calc, test_case_15);
//   tcase_add_test(smart_calc, test_case_16);
//   tcase_add_test(smart_calc, test_case_17);
//   tcase_add_test(smart_calc, test_case_18);
//   tcase_add_test(smart_calc, test_case_19);
//   tcase_add_test(smart_calc, test_case_20);
//   tcase_add_test(smart_calc, test_case_21);
//   tcase_add_test(smart_calc, test_case_22);
//   tcase_add_test(smart_calc, test_case_23);
//   tcase_add_test(smart_calc, test_case_24);
//   tcase_add_test(smart_calc, test_case_25);
//   tcase_add_test(smart_calc, test_case_26);
//   tcase_add_test(smart_calc, test_case_27);
//   tcase_add_test(smart_calc, test_case_28);
//   tcase_add_test(smart_calc, test_case_29);
//   tcase_add_test(smart_calc, test_case_30);
//   tcase_add_test(smart_calc, test_case_31);
//   tcase_add_test(smart_calc, test_case_32);
//   tcase_add_test(smart_calc, test_case_33);
//   tcase_add_test(smart_calc, test_case_34);
//   tcase_add_test(smart_calc, test_case_35);
//   tcase_add_test(smart_calc, test_case_36);
//   tcase_add_test(smart_calc, test_case_37);
//   tcase_add_test(smart_calc, test_case_38);
//   tcase_add_test(smart_calc, test_case_39);
//   tcase_add_test(smart_calc, test_case_40);
//   tcase_add_test(smart_calc, test_case_41);
//   tcase_add_test(smart_calc, test_case_42);
//   tcase_add_test(smart_calc, test_case_43);
//   tcase_add_test(smart_calc, test_case_44);
//   tcase_add_test(smart_calc, test_case_45);
//   tcase_add_test(smart_calc, test_case_46);
//   tcase_add_test(smart_calc, test_case_47);
//   tcase_add_test(smart_calc, test_case_48);
//   tcase_add_test(smart_calc, test_case_49);
//   tcase_add_test(smart_calc, test_case_50);
//   // tcase_add_test(smart_calc, test_case_51);
//   tcase_add_test(smart_calc, test_case_52);
//   tcase_add_test(smart_calc, test_case_53);
//   tcase_add_test(smart_calc, test_case_54);
//   tcase_add_test(smart_calc, test_case_55);
//   tcase_add_test(smart_calc, test_case_56);
//   tcase_add_test(smart_calc, test_case_57);
//   tcase_add_test(smart_calc, test_case_58);
//   tcase_add_test(smart_calc, test_case_59);
//   tcase_add_test(smart_calc, test_case_60);

//   SRunner *sr = srunner_create(s1);
//   int nf;
//   srunner_set_fork_status(sr, CK_NOFORK);
//   srunner_run_all(sr, CK_ENV);
//   nf = srunner_ntests_failed(sr);
//   srunner_free(sr);
//   return nf == 0 ? 0 : 1;
// }


} // namespace

// GCOVR_EXCL_STOP