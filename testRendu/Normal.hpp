#ifndef NORMAL_HPP
#define NORMAL_HPP

#include "Personnage.hpp"

class Normal : public Personnage
{
    public :
        Normal(const int &, bool affichage = false);

    protected:

    private :
        bool affichage_;
};

#endif // NORMAL_HPP
