#include <iostream>
#include <cstring>
class Persoana
{
    char *nume;
    int varsta;

public:
    Persoana();
    Persoana(char *n, int v);
    ~Persoana();
    Persoana(const Persoana &p);
    void afiseaza();
    bool compara(Persoana p);
    Persoana(Persoana &&p);
};