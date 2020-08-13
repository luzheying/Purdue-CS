/* Name, hw0.c, CS 24000, Fall 2018
 * Last updated August 16, 2018 
 */

/* Add any includes here */

#include "hw0.h"

/* Define compute_hailstone here */

/* This function set length to an array.
 * It also passes first value to that array.
 * Depends on the assigned first array value,
 * it generates following values with specific algorithm.
 * It returns the sum of all values in the array.
 */

int compute_hailstone(int start_num, int length){
  g_hailstone_array[0] = start_num;
  if ((start_num <= 0) || 
      (length <= 0)){
    return HAILSTONE_ERROR;
  }
  for (int i = 1; i < length; i++){
    if ((start_num % 2 == 0) && 
        (start_num > 0)){
      start_num = start_num/2;
    }
    else if ((start_num %2 != 0) && 
                 (start_num > 0)){
      start_num = start_num * 3 + 1;
    }
    else{
      return HAILSTONE_ERROR;
    }
    g_hailstone_array[i] = start_num;
  }
  int sum = 0;
  for(int j = 0; j < length; j++){
    sum += g_hailstone_array[j];
  }
  return sum;
}/* compute_hailstion() */

/* Define check_hailstone here */

/* This function checks the validity of a specific array.
 * It gets a number which is the index to be checked from users.
 * it returns correct if the array is a valid array. 
 * It returns the index of the first wrong value if the array is invalid.
 */


int check_hailstone(int limit){
  if((limit < 1) || 
    (g_hailstone_array[0] < 1)){
        return HAILSTONE_ERROR;
  }
  for (int i = 0; i < limit-1; i++){
    if(g_hailstone_array[i] < 1){
		return i + 1;
    }
    if ((g_hailstone_array[i] % 2 == 1) && 
        (g_hailstone_array[i] > 0)){
         if ((g_hailstone_array[i] * 3 + 1) == 
             (g_hailstone_array[i + 1])){
           ;
         }
         else {
           return i + 1;
         }
    }
    if ((g_hailstone_array[i] % 2 == 0) && 
        (g_hailstone_array[i] > 0)){
         if ((g_hailstone_array[i] / 2) == 
             (g_hailstone_array[i + 1])){
           ;
         }
         else{
           return i + 1;
         }
    }
  }
  return HAILSTONE_CORRECT;
}/* check_hailstone() */

/* Remember, you don't need a main function!
 * it is provided by hw0_main.c or hw0_test.o
 */


