#include <iostream>
#include "auto.h"


int main(void)
{
    Auto a("albastru", 2002);
    Auto b("mov", 2020);
    std::cout<<a.Compara(b);;
    int n;
    std::cout<<std::endl<<"numar de autoturisme=";
    std::cin>>n;

    Auto masini[100];

    int i = 0;
    for(i = 0; i < n; i++)
    {
        std::cout<<std::endl<<"Citire:";
        std::cout<<std::endl<<"autoturism "<<i+1<<":"<<std::endl;
        masini[i].Citire();
    }

    for(i = 0; i < n; i++)
    {   std::cout<<std::endl<<"Afisare:";
        std::cout<<std::endl<<"autoturism "<<i+1<<":"<<std::endl;
        masini[i].Afisare();
    }

    int max = 0;
    int j = 0;
    for(i = 0; i < n; i++)
    {
        if(masini[i].getan()>max)
        {
            max = masini[i].getan();
            j = i;
        }
    }

    std::cout<<std::endl<<"Autoturismul cel mai nou:"<<std::endl;
    masini[j].Afisare();
}

