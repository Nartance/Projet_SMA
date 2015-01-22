#include "Cible.hpp"

Cible::Cible(const int & angle = 0, bool affichage) : Personnage(angle), affichage_(affichage)
{

}

void Cible::paint(QPainter * painter, const QStyleOptionGraphicsItem * qsogt, QWidget * qw)
{
    painter->setBrush(QBrush(QColor(0,0,220)));
    Personnage::paint(painter, qsogt, qw);
}

void Cible::type()
{
    std::cout << "Cible" << std::endl;
}

