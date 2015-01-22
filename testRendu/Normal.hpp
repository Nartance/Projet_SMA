#ifndef NORMAL_HPP
#define NORMAL_HPP

#include "Personnage.hpp"

class Normal : public Personnage
{
    public :
        Normal(const int &, bool affichage = false);
        void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
        void type();

    protected:
        void action(const QList<QGraphicsItem *> &);
        void move(const qreal &, const qreal &);

    private :
        bool affichage_;
};

#endif // NORMAL_HPP
