#ifndef GENERAL_HPP
#define GENERAL_HPP

#include <algorithm>
#include <cmath>
#include <iostream>

#include <QtGlobal>
#include <QtCore/qmath.h>

#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPen>
#include <QTimer>

#include "General.hpp"
#include "Mur.hpp"

#include "Personnage.hpp"
#include "Normal.hpp"

class minimum_distance_QLineF
{
public :
    minimum_distance_QLineF() {}
    bool operator() (const QLineF & l1, const QLineF & l2)
    {
        return (l1.length() < l2.length());
    }
};

qreal normalise_angle(qreal);
QPoint change_repere(QPoint);
void afficher_QPointF(QPointF);
void afficher_QRectF(QRectF);

#endif // GENERAL_HPP
