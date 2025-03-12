#include <iostream>
#include <cstring>
#include "persoana.h"

Persoana::Persoana()
{
    nume = new char[1]();
    varsta = 0;
}

Persoana::Persoana(const Persoana &p)
{
    
    nume = new char[(strlen(p.nume)) + 1];
    strcpy(nume, p.nume);
    
    varsta = p.varsta;
}

Persoana::Persoana(char *n, int v)
{

    nume = new char[strlen(n) + 1];
    std::strncpy(nume, n, strlen(n) + 1);
    varsta = v;
}
Persoana::~Persoana()
{
    if (nume)
        delete[] nume;
}
void Persoana::afiseaza()
{
    std::cout << "Nume = " << nume << " varsta = " << varsta << std::endl;
}

Persoana::Persoana(Persoana &&p)
{
    nume = p.nume;
    varsta = p.varsta;
    p.nume = NULL;
    p.varsta = 0;
}

bool Persoana::compara(Persoana p)
{
    if (varsta > p.varsta)
    {
        return true;
    }
    else
    {
        return false;
    }
}