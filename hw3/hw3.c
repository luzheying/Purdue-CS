/*
 * Zheying Lu, hw3.c, CS 24000, Fall 2018
 * Last updated September 26, 2018
 */

#include"hw3.h"

#include<math.h>

/*
 * This function adds two arguments together
 * and returns the sum as a result.
 */

complex complex_add(complex c1, complex c2) {
  complex result;
  result.x = c1.x + c2.x;
  result.y = c1.y + c2.y;
  return result;
} /* complex_add() */

/*
 * This function returns the negative form of the argument.
 */

complex complex_neg(complex c1) {
  complex result;
  result.x = c1.x * (-1.0);
  result.y = c1.y * (-1.0);
  return result;
} /* complex_neg() */

/*
 * This function substracts the second argument from the
 * first one and return the result.
 */

complex complex_sub(complex c1, complex c2) {
  complex result;
  result = complex_add(c1, complex_neg(c2));
  return result;
} /* complex_sub() */

/*
 * This function calculates the dot product of the two arguments
 * and returns the result.
 */

double complex_dot(complex c1, complex c2) {
  double result = 0.0;
  result = (c1.x * c2.x) + (c1.y * c2.y);
  return result;
} /* complex_dot() */

/*
 * This function calculates the reciprocal of the argument
 * and returns the result.
 */

complex complex_inv(complex c1) {
  complex result;
  result.x = c1.x / (c1.x * c1.x + c1.y * c1.y);
  result.y = - c1.y / (c1.x * c1.x + c1.y * c1.y);
  return result;
} /* complex_inv() */

/*
 * This function multiples the two arguments
 * and returns the result.
 */

complex complex_mul(complex c1, complex c2) {
  complex result;
  result.x = (c1.x * c2.x) - (c1.y * c2.y);
  result.y = (c1.x * c2.y) + (c1.y * c2.x);
  return result;
} /* complex_mul() */

/*
 * This function calculates the division of the first argument by the second
 * and returns the result.
 */

complex complex_div(complex c1, complex c2) {
  complex result;
  result = complex_mul(c1, complex_inv(c2));
  return result;
} /* complex_div() */

/*
 * This function computes the complex exponential function with the argument
 * and returns the result.
 */

complex complex_exp(complex c1) {
  complex result;
  result.x = exp(c1.x) * cos(c1.y);
  result.y = exp(c1.x) * sin(c1.y);
  return result;
} /* complex_exp() */

/*
 * This function computes the function Z = Z + C^2 again and again until the
 * absolute nagnitude of Z is larger than 2.0, where Z is assigned to 0 at
 * first and c is the argument. It returns the total count of how many times
 * the function has been repreated.
 */

int mandelbrot(complex c1) {
  int count = 0;
  complex z;
  z.x = 0;
  z.y = 0;
  while (complex_dot(z, z) <= 4) {
    count++;
    if (count >= MAX_MANDELBROT) {
      break;
    }
    z = complex_mul(z, z);
    z = complex_add(z, c1);
  }
  return count;
} /* mandelbrot() */
