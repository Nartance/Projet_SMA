#include "Assassin.hpp"

Assassin::Assassin(const int & angle = 0, bool affichage) : Personnage(angle), affichage_(affichage)
{

}

void Assassin::paint(QPainter * painter, const QStyleOptionGraphicsItem * qsogt, QWidget * qw)
{
    painter->setBrush(QBrush(QColor(220,0,0)));
    Personnage::paint(painter, qsogt, qw);
}


void Assassin::type()
{
    std::cout << "Assassin" << std::endl;
}


