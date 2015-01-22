#ifndef ASSASSIN_HPP
#define ASSASSIN_HPP

#include "Personnage.hpp"

class Assassin : public Personnage
{
    public :
        Assassin(const int &, bool affichage = false);
        void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
        void type();

    protected:

    private :
        bool affichage_;
};

#endif // ASSASSIN_HPP
