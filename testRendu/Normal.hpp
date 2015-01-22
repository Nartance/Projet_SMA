#ifndef NORMAL_HPP
#define NORMAL_HPP

#include "General.hpp"
#include "Personnage.hpp"

class Normal : public Personnage
{
    public :
        Normal(const int &, bool affichage = false);
        void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
        void type();

    protected:
        void action(const QList<QGraphicsItem *> &);
        void move();

    private :
        bool affichage_;

        QTime * pause_;
};

#endif // NORMAL_HPP
