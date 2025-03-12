class Complex
{
    int re, im;

public:
    Complex() {}
    Complex(int r, int i);
    Complex aduna(Complex c2);
    void afisare();

    Complex(const Complex &c);
    Complex(Complex &&c);
    ~Complex();
};