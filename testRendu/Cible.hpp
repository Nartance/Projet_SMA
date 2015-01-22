#ifndef CIBLE_HPP
#define CIBLE_HPP

#include "Personnage.hpp"

class Cible : public Personnage
{
    public :
        Cible(const int &, bool affichage = false);
        void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
        void type();

    protected:

    private :
        bool affichage_;
};

#endif // CIBLE_HPP

