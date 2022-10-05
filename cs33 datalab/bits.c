/* 
 * CS:APP Data Lab 
 * 
 * Gene Bordegaray ID: 005452336
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTES:
  1. Our checker requires that you do NOT define a variable after 
     a statement that does not define a variable.

     For example, this is NOT allowed:

     int illegal_function_for_this_lab(int x, int y) {
      // this statement doesn't define a variable
      x = x + y + 1;
      
      // The checker for this lab does NOT allow the following statement,
      // because this variable definition comes after a statement 
      // that doesn't define a variable
      int z;

      return 0;
     }
     
  2. VERY IMPORTANT: Use the dlc (data lab checker) compiler (described in the handout)
     to check the legality of your solutions.
  3. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  4. Use the btest to check your functions for correctness.
  5. The maximum number of ops for each function is given in the
     header comment for each function. 

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest to verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
       int numMax = ~(1 << 31); //1 shifted left 31 times is 1000... (tmin), complement gives you tmax
       return numMax;
}
/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
  int result = !(x ^ 0); //x ^ 0 will return 0 is x == 0 so use ! to flip that 
  return result; 
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int firstResult = (x & y); //make an initial & comparison between x and y
  int secondResult = (~x & ~y); //make aother & comparison between the complements of x and y

  int finalResult = (~firstResult & ~secondResult); //compare their complements 
  return finalResult;
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
  int firstResult = (x ^ y); //xor between x and y - should return 0 if same number and something else if not 
  int secondResult = !(firstResult); //use the not operator, should hold 1 if x and y are equal and 0 vice versa

  int finalResult = !(secondResult); //use the not operator again, should hold 0 if x and y are equal and 1 vice versa
  return finalResult;
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
  //we want to keep results = to 0 when x is 0 and find way to differentiate between + and -
  int firstResult = (x >> 31) << 1; //-2 if neg, 0 if pos or 0
  int secondResult = !!(x); //1 if pos or neg, 0 if 0
  int finalResult = (firstResult + secondResult); //holds 0 if 0, -1 if neg, 1 if pos
  return finalResult;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int checkTrue = !!x; //holds 1 if non zero holds 0 if zero
  int yResult = (((checkTrue << 31) >> 31) & y); //should hold y val if checkTrue was 1 vice versa
  int zResult = (~((checkTrue << 31) >> 31) & z); //should hold z val if checkTrue was 0 vice versa
  int finalResult = (yResult | zResult); //should just return whichever number holds any value other than 0
  return finalResult;
}
/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
  int shiftResult = 255 << (n << 3); //shift a set of eight ones (byte) to the byte we are replacing
  int deleteResult = (x & ~shiftResult); //sets the byte we are replacing to all 0
  int finalResult = (deleteResult ^ (c << (n << 3))); //sets the indicated byte with replacement parameter
  return finalResult;
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int shiftedUpper = x >> 4; //shift so the 16 is in now in least significant spot
  int upperResult = !(shiftedUpper ^ 3); //check only the first two bits are on

  int lastFourBit = x & 15; //only keeps last 4 bits with ones set on if any
  int lowerEqualNine = !(lastFourBit ^ 9); //1 if equal 0 if diff
  int lowerEqualEight = !(lastFourBit ^ 8); //1 if equal 0 if diff
  int fourthBitOn = !(lastFourBit >> 3); //0 if on 1 if off
  int lowerResult = (fourthBitOn | lowerEqualNine) | (fourthBitOn | lowerEqualEight); //1 if in bound, 0 if not

  int finalResult = upperResult & lowerResult; //return 1 if both upper and lower are 1 (aka pass)
  return finalResult;
}
/* 
 * subtractionOK - Determine if can compute x-y without overflow
 *   Example: subtractionOK(0x80000000,0x80000000) = 1,
 *            subtractionOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subtractionOK(int x, int y) {
int yNeg = ~y + 1; //holds -y value
int diff = x + yNeg; //holds x-y

//overflow occurs when two numbers being added are same sign and the result is the opposite sign
int xSign = x >> 31; //-1 if neg, 0 if pos or 0
int ySign = y >> 31; //-1 if neg, 0 if pos or 0
int diffSign = diff >> 31; //-1 if neg, 0 if pos or 0

int xySignCheck = !(xSign ^ ySign); //1 if same, 0 if diff
int xdiffSignCheck = !(xSign ^ diffSign); //1 if same, 0 if diff
int finalResult = xySignCheck | xdiffSignCheck;
return finalResult;
}
// below are extra credits (4 pts in total)
// 2 points each (1 correctness pt + 1 performance pt)
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 */
int leastBitPos(int x) {
  int xMinusOne = x + (~1 + 1); //gives us x-1 to eliminate x's least significant bit
  int finalResult = (~xMinusOne) & x; //only matching ones should be that of the lest sig bit in x
  return finalResult;
}
/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 */
int greatestBitPos(int x) {
  //this one is hard
  int xPlusOne = x + 1;
  int finalResult = (~xPlusOne) & x;
  return finalResult;
}
