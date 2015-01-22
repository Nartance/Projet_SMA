#include "Normal.hpp"

Normal::Normal(const int & angle = 0, bool affichage) : Personnage(angle), affichage_(affichage)
{

}

void Normal::paint(QPainter * painter, const QStyleOptionGraphicsItem * qsogt, QWidget * qw)
{
    painter->setBrush(QBrush(QColor(220,220,220)));
    Personnage::paint(painter, qsogt, qw);
}

void Normal::type()
{
    std::cout << "Normal" << std::endl;
}

void Normal::action(const QList<QGraphicsItem *> & liste_item)
{

}

void Normal::move(const qreal & angle, const qreal & vitesse)
{
    setRotation(angle);
    setPos(mapToParent(vitesse,0));
}
