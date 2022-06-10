#include<stdio.h>
/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int res,bit_x_1_y_0=0,bit_y_1_x_0=0;
  // 统计在x出现而没有在y上出现的1
  bit_x_1_y_0=x &(~y);
  // 统计在出现而没有在x上出现的1
  bit_y_1_x_0=y &(~x);
  // 将所有的1聚合
  res=~((~bit_x_1_y_0)&(~bit_y_1_x_0));
  return res;

}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  int res=1;
  res=1<<31;
  return res;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // 检查值是否为0x7fffffff
  // 对0x7fffffff进行按位取反和加一都得到0x80000000
  int temp=x+1,res,state;
  // 检测是否是0xffffffff
  state=!!(x+1);
  temp=~temp;
  res=x^temp;
  return (!res)&state;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  // 得到一个奇数位为0偶数为为1的掩码
  int mask=5,temp,res=0;
  mask=(mask<<4)|5;
  mask=(mask<<8)|mask;
  mask=(mask<<16)|mask;
  // 如果x奇数位全为1;temp所有位为1
  temp=mask|x;
  temp=~temp;
  res=!(temp^0);
  return res;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  int res;
  res=~x+1;
  return res;
}
//3
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
  int temp1,mask,temp_res1=0,temp_res2,temp3,res;
  // 计算x-0x4A的结果
  temp_res1=x+(~(0x3A)+1);
  // 计算x与0x7fffffd0的和
  temp1=(0xff<<8)|0xff;
  temp3=(0x7f<<24)|(temp1<<8)|0xd0;
  temp_res2=x+temp3;
  mask=1<<31;
  // 检查两个结果是否是负数
  res=((temp_res1&temp_res2&mask)^mask);
  return !res;
  
  
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int mask,res;
  mask=!!x;
  // 根据x构造一个全0或者全1的掩码
  mask=mask<<1|mask;
  mask=mask<<2|mask;
  mask=mask<<4|mask;
  mask=mask<<8|mask;
  mask=mask<<16|mask;
  // 根据掩码选择y或者z
  res=(mask&y)+((~mask)&z);
  return res;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int mask=1<<31,diff,state_less,state_equal,symbol_x,symbol_less,symbol_y,state_temp1,state_temp2;
  diff=x+(~y+1);
  symbol_less=diff&mask;
  symbol_x=x&mask;
  symbol_y=y&mask;
  // 检测x<y的情况;
  // 1.x y异号;只有x为负数才满足条件
  state_temp1=!!((symbol_x^symbol_y)&symbol_x);
  //2. x,y同号;只有差为负数才才满足条件
  state_temp2=!!((~(symbol_x^symbol_y))&symbol_less);
  state_less=state_temp1|state_temp2;
  
  // 检测x==y的情况
  state_equal=!(x^y);
  return state_less|state_equal;




}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int res=0;
  unsigned int mask;
  // 检测x是否为0;只有x为0最后的掩码才为1
  mask=~x;
  mask=(mask>>16)&mask;
  mask=(mask>>8)&mask;
  mask=(mask>>4)&mask;
  mask=(mask>>2)&mask;
  mask=(mask>>1)&mask;
  return res+mask;

}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int temp,not_zero_mask,is_zero,bit_16,bit_8,bit_4,bit_2,bit_1=0,res;
  // 将负数转换成为正数处理
  temp=x^(x>>31);
  is_zero=!temp;
  // not_zero_mask为0xffffffff
  not_zero_mask=(!(!temp)<<31)>>31;
  // 如果高16位有值则至少需要16位
  bit_16=!(!(temp>>16))<<4;
  temp=temp>>bit_16;
  // 依次类推
  bit_8=!(!(temp>>8))<<3;
  temp=temp>>bit_8;
  bit_4=!(!(temp>>4))<<2;
  temp=temp>>bit_4;
  bit_2=!(!(temp>>2))<<1;
  temp=temp>>bit_2;
  bit_1=!(!(temp>>1));
  // 表示一个正数至少需要两位;在计算bit_1的时候忽略最后一位;同时表示正数时需要比补码多一位；所以需要加上2;
  temp=bit_16+bit_8+bit_4+bit_2+bit_1+2;
  res=is_zero|(temp&not_zero_mask);
  return res;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  int exp = (uf&0x7f800000)>>23;
	int sign = uf&(1<<31);
	if(exp==0) return uf<<1|sign;
	if(exp==255) return uf;
	exp++;
	if(exp==255) return 0x7f800000|sign;
  return (exp<<23)|(uf&0x807fffff);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  int exp = (uf >> 23) & 0xFF;
  int frac = uf & 0x007FFFFF;
  int sign = uf & 0x80000000;
  int bias = exp - 127;

  if (exp == 255 || bias > 30) {
    // exponent is 255 (NaN), or number is too large for an int
    return 0x80000000u;
  } else if (!exp || bias < 0) {
    // number is very small, round down to 0
    return 0;
  }

  // append a 1 to the front to normalize
  frac = frac | 1 << 23;

  // float based on the bias
  if (bias > 23) {
    frac = frac << (bias - 23);
  } else {
    frac = frac >> (23 - bias);
  }

  if (sign) {
    // original number was negative, make the new number negative
    frac = ~(frac) + 1;
  }

  return frac;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  int INF = 0xff<<23;
  int exp = x + 127;
  if(exp <= 0) return 0;
  if(exp >= 255) return INF;
  return exp << 23;
}
