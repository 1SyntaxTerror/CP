#include <iostream>
#include "persoana.h"
int main()
{
    Persoana p1((char *)"Pavel", 22);
    p1.afiseaza();
    Persoana p2((char *)"Ana", 43);
    std::cout << p1.compara(p2);
    return 0;
}