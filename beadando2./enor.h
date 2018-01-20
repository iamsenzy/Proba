#ifndef ENOR_H
#define ENOR_H
#include <string>
#include <fstream>


class Enor
{
    public:
        struct peca{
            std::string name,faj;
            int db;
        };
         struct peca2{
            std::string name,faj;
            int hossz;
        };

        Enor(const std::string &str);
        void first() { f >> df.name >> df.faj>>df.hossz; next();}
        void next();
        bool end() const { return fin;}
        peca current() const { return cur;}
    private:
        std::ifstream f;
        peca2 df;
        peca cur;
        bool fin;

};

#endif // ENOR_H
