#include <iostream>
#include "auto.h"
#include <cstring>

Auto::Auto(char *c, unsigned int a) : culoare(c), an_fab(a)
{

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
    std::cout<<"an fabricatie: "<<an_fab<<std::endl<<"culoare"<<culoare;
}

void Auto::Schimba(char *c)
{
    strcpy(culoare, c);
}

void Auto::Compara()
{
    
}