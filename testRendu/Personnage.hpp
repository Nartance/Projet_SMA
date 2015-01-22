#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include "General.hpp"

class Personnage : public QGraphicsItem
{
    public:
        Personnage(const int & angle = 0);
        ~Personnage() = 0;

        QRectF boundingRect() const;
        QPainterPath shape() const;
        void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
        void type();

    protected:
        void advance(int);

        QPointF deplacement_angle() const;
        QPointF regard() const;

        qreal angle_;
        qreal vitesse_;

        qreal angle_modifie_;
        qreal compteur_;
        qreal limite_;
    private:

};

#endif // PERSONNAGE_HPP
