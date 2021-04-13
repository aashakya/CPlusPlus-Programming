#include<iostream>
#include <string.h>
#include "NumberPrinter.h"
using namespace std;

NumberPrinter::NumberPrinter(){
    digitOne = 0;
    digitTwo = 0;
    digitThree = 0;
}//initializes the three digits to zero
void NumberPrinter::print(){

}
//initializes each of the digits
NumberPrinter::NumberPrinter(int firstDigit, int secondDigit, int thirdDigit){
    digitOne = firstDigit;
    digitTwo = secondDigit;
    digitThree = thirdDigit;
}
void NumberPrinter::setFirstDigit(int x){
    digitOne = x;
}
void NumberPrinter::setSecondDigit(int x){
    digitTwo = x;
}
void NumberPrinter::setThirdDigit(int x){
    digitThree = x;
}

// For the small printer
SmallPrinter::SmallPrinter():NumberPrinter(){} // Calling the default parent constructor
SmallPrinter::SmallPrinter(int firstDigit, int secondDigit, int thirdDigit):NumberPrinter(firstDigit, secondDigit, thirdDigit){}// Calling the parent constructor for 3 digits

void SmallPrinter::print(){
    cout << digitOne << " " << digitTwo << " " << digitThree << endl;
};// overwriting the print of the parent class

// For the medium printer
MediumPrinter::MediumPrinter():NumberPrinter(){} // Calling the default parent constructor
MediumPrinter::MediumPrinter(int firstDigit, int secondDigit, int thirdDigit):NumberPrinter(firstDigit, secondDigit, thirdDigit){}// Calling the parent constructor for 3 digits

void MediumPrinter::print(){
    
    string Medium[7][10] = {{" -- ", "    ", " -- ", " -- ","    "," -- "," -- "," -- "," -- "," -- "},
                            {"|  |", "   |", "   |", "   |","|  |","|   ","|   ","   |","|  |","|  |"},
                            {"|  |", "   |", "   |", "   |","|  |","|   ","|   ","   |","|  |","|  |"},
                            {"    ", "    ", " -- ", " -- "," -- "," -- "," -- ","    "," -- "," -- "},
                            {"|  |", "   |", "|   ", "   |","   |","   |","|  |","   |","|  |","   |"},
                            {"|  |", "   |", "|   ", "   |","   |","   |","|  |","   |","|  |","   |"},
                            {" -- ", "    ", " -- ", " -- ","    "," -- "," -- ","    "," -- "," -- "}};
   for (int i = 0; i < 7; i++){
        cout << Medium[i][digitOne]<<" "<<Medium[i][digitTwo]<<" "<<Medium[i][digitThree]<<endl;
    }
};// overwriting the print of the parent class

// For the large printer
LargePrinter::LargePrinter():NumberPrinter(){} // Calling the default parent constructor
LargePrinter::LargePrinter(int firstDigit, int secondDigit, int thirdDigit):NumberPrinter(firstDigit, secondDigit, thirdDigit){}// Calling the parent constructor for 3 digits

void LargePrinter::print(){
    string large[9][10] = {{" --- ", "     ", " --- ", " --- ","     "," --- "," --- "," --- "," --- "," --- "},
                            {"|   |", "    |", "    |", "    |","|   |","|    ","|    ","    |","|   |","|   |"},
                            {"|   |", "    |", "    |", "    |","|   |","|    ","|    ","    |","|   |","|   |"},
                            {"|   |", "    |", "    |", "    |","|   |","|    ","|    ","    |","|   |","|   |"},
                            {"     ", "     ", " --- ", " --- "," --- "," --- "," --- ","     "," --- "," --- "},
                            {"|   |", "    |", "|    ", "    |","    |","    |","|   |","    |","|   |","    |"},
                            {"|   |", "    |", "|    ", "    |","    |","    |","|   |","    |","|   |","    |"},
                            {"|   |", "    |", "|    ", "    |","    |","    |","|   |","    |","|   |","    |"},
                            {" --- ", "     ", " --- ", " --- ","     "," --- "," --- ","     "," --- "," --- "}};
    for (int i = 0; i < 9; i++){
        cout << large[i][digitOne]<<" "<<large[i][digitTwo]<<" "<<large[i][digitThree]<<endl;
    }
};// overwriting the print of the parent class