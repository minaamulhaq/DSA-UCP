#include <iostream>
using namespace std;

class ComplexNumber {
private:
    int real;
    int imag;

public:
    ComplexNumber(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }
    ComplexNumber(const ComplexNumber& other){
        real = other.real;
        imag = other.imag;
    }
   
    ComplexNumber operator+(const ComplexNumber& other) {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    ComplexNumber operator-(const ComplexNumber& other) {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    
    ComplexNumber operator*(const ComplexNumber& other) {
        int r = (real * other.real) - (imag * other.imag);
        int i = (real * other.imag) + (imag * other.real);
        return ComplexNumber(r, i);
    }

    
    ComplexNumber operator/(const ComplexNumber& other) {
        int denominator = (other.real * other.real) + (other.imag * other.imag);

        int r = ((real * other.real) + (imag * other.imag)) / denominator;
        int i = ((imag * other.real) - (real * other.imag)) / denominator;

        return ComplexNumber(r, i);
    }


    void display() const {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i" << endl;
        else
            cout << " - " << -imag << "i" << endl;
    }
};

int main() {
    ComplexNumber c1(3, 2);
    ComplexNumber c2(1, 4);

    ComplexNumber c3 = c1 + c2;
    ComplexNumber c4 = c1 - c2;
    ComplexNumber c5 = c1 * c2;
    ComplexNumber c6 = c1 / c2;

    cout << "Addition: ";
    c3.display();

    cout << "Subtraction: ";
    c4.display();

    cout << "Multiplication: ";
    c5.display();

    cout << "Division: ";
    c6.display();

    return 0;
}