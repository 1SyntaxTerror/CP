#include <iostream>
#include "auto.h"
#include <cstring>

Auto::Auto(const char *c, unsigned int a) : an_fab(a), culoare(new char[strlen(c)+1])
{
    strcpy(culoare, c);
}

Auto::Auto(const Auto &a) : an_fab(a.an_fab), culoare(new char[strlen(a.culoare) + 1])
{
    strcpy(culoare, a.culoare);
}

Auto::Auto(Auto &&a) : an_fab(a.an_fab), culoare(a.culoare)
{
    a.an_fab = 0;
    a.culoare = NULL;
}

Auto::~Auto()
{
    culoare = NULL;
}

void Auto::Afisare()
{
    std::cout<<"an fabricatie: "<<an_fab<<std::endl<<"culoare: "<<culoare<<std::endl;
}

void Auto::Schimba(char *c)
{
    strcpy(culoare, c);
}

bool Auto::Compara(Auto a)
{
    if(an_fab > a.an_fab)
    {
        return 1;
    }
    else return 0;
}

void Auto::Citire()
{
    std::cout<<std::endl<<"culoare:";
    std::cin>>culoare;
    std::cout<<std::endl<<"an_fab:"<<std::endl;
    std::cin>>an_fab;
}

unsigned int Auto::getan()
{
    return an_fab;
}