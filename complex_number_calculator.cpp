#include <iostream>
#include <iomanip>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Parameterized constructor
    Complex(double r, double i) : real(r), imag(i) {}

    // Addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Subtraction
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Multiplication
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }

    // Display in a readable a + bi / a - bi format
    void display() const {
        cout << fixed << setprecision(2) << real;
        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";
    }
};

int main() {
    double r1, i1, r2, i2;

    cout << "COMPLEX NUMBER CALCULATOR\n";
    cout << "Enter real and imaginary parts of first number: ";
    cin >> r1 >> i1;

    cout << "Enter real and imaginary parts of second number: ";
    cin >> r2 >> i2;

    Complex c1(r1, i1), c2(r2, i2);

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;

    cout << "\nFirst complex number: ";
    c1.display();
    cout << "\nSecond complex number: ";
    c2.display();

    cout << "\n\nAddition: ";
    sum.display();
    cout << "\nSubtraction: ";
    difference.display();
    cout << "\nMultiplication: ";
    product.display();
    cout << endl;

    return 0;
}