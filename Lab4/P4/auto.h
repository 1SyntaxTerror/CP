class Auto
{
private:
    char *culoare;
    unsigned int an_fab;
public:
    Auto(const char *c = "negru", unsigned int a = 2003);
    ~Auto();
    Auto(const Auto &a);
    Auto(Auto &&a);
    void Afisare();
    void Schimba(char *c);
    bool Compara(Auto a);
    void Citire();
    unsigned int getan();
};