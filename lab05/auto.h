class Auto
{
private:
    char *culoare;
    unsigned int an_fab;
public:
    Auto(char *c = "Rosu", unsigned int a = 2003);
    ~Auto();
    Auto(const Auto &a);
    Auto(Auto &&a);
    void Afisare();
    void Schimba(char *c);
    void Compara();
};
