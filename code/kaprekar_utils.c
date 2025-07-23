#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "kaprekar_utils.h"

bool isKaprekar(int n) {

  if(n < 1) {
    return false;
  }

  int i;
  //compute the square
  long square = n * (long) n;
  //compute the number of digits of the square
  int numDigits = (int) log10(n) + 1;
  //int numDigits = (int) log10(n) + 1;
  long modulus = 0;
  long first, second;

  //for each possible "split" of the square...
  for(i=1; i<=numDigits; i++) {
    //increase the modulus by a factor of 10
    modulous *= 10;

    //split the square into two parts
    first = square / modulus;
    second = square % modulus;

    //test if the split makes a Kaprekar number:
    //  - the sum of the two parts is equal to n, and
    //  - the second part cannot be zero
    if(n == first + second && second > 0) {
      return true;
    }
  }
  return false;

}
