#ifndef NumberPrinterh
#define NumberPrinterh
#include <string>

class NumberPrinter{
    public:
        //initializes the three digits to zero
        NumberPrinter();
        NumberPrinter(int firstDigit, int secondDigit, int thirdDigit); //initializes each of the digits
        //And three “setter” functions
        void setFirstDigit(int x);
        void setSecondDigit(int x);
        void setThirdDigit(int x);
        virtual void print();
    protected:
        int digitOne;
        int digitTwo;
        int digitThree; 
};

class SmallPrinter : public NumberPrinter{
    public:
        SmallPrinter();
        SmallPrinter(int firstDigit, int secondDigit, int thirdDigit);
        void print() override;
};

class MediumPrinter : public NumberPrinter{
    public:
        MediumPrinter();
        MediumPrinter(int firstDigit, int secondDigit, int thirdDigit);
        void print() override;
};

class LargePrinter : public NumberPrinter{
    public:
        LargePrinter();
        LargePrinter(int firstDigit, int secondDigit, int thirdDigit);
        void print() override;
};
#endif