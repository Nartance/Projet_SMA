#ifndef NORMAL_HPP
#define NORMAL_HPP

#include "main.hpp"

class Normal : public QGraphicsItem
{
    public :
        Normal(const int & angle = 0);

        void setColor(const int & couleur = 0);

        QRectF boundingRect() const;
        QPainterPath shape() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    protected:
        void advance(int step);

    private :
        qreal angle;
        qreal vitesse;

        int couleur;

};

#endif // NORMAL_HPP
