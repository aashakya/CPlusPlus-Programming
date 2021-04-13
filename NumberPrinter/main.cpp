#include<iostream>
#include <string.h>
#include "NumberPrinter.h"
using namespace std;
/* *********************************************  */
/*                                                */
/* title: NumberPrinter.cpp                       */
/* programmer: Aakrista Shakya                    */
/* date: 2-24-2021                                */
/*                                                */
/* purpose:                                       */
/* this program accepts a number between 0 to 9   */
/*   and displays the size of according to user's */ 
/*   request. Input and  output is through he     */
/*   console.                                     */
/*                                                */
/* inputs: no inputs                              */
/* outputs: the arrays of number                  */
/*
/* notes: no checking of input is performed       */
/* ********************************************* */
int main() {
	MediumPrinter num;// medium printer execute with defalut constructer
    num.print();// printing the medium printer

    SmallPrinter num1(5,7,9);// creating a small printer and giving it 3 values
    num1.print();// printing the small printer

    LargePrinter num2(5,7,9);// creating a large printer and giving it 3 values
    num2.print();// printing the large printer

    //using the setters to change the digits of large printer
    num2.setFirstDigit(4);
    num2.setSecondDigit(7);
    num2.setThirdDigit(8);
   
    num2.print();
   // Array of 9 numbers to print
    NumberPrinter* num3[9];
    // assigning the first three to a smallPrinter
    num3[0] = new SmallPrinter(0,1,2);
    num3[1] = new SmallPrinter(3,4,5);
    num3[2] = new SmallPrinter(6,7,8);
   
   // assigning the first three to a mediumPrinter
    num3[3] = new MediumPrinter(0,1,2);
    num3[4] = new MediumPrinter(3,4,5);
    num3[5] = new MediumPrinter(6,7,8);

   // assigning the first three to a largePrinter
    num3[6] = new LargePrinter(0,1,2);
    num3[7] = new LargePrinter(3,4,5);
    num3[8] = new LargePrinter(6,7,8);

      // printing the number in the array
    for (int i = 0; i < 9; i++){
        num3[i] -> print();
        }
    return 0;
}