#include "Assassin.hpp"

Assassin::Assassin(const int & angle = 0, bool affichage) : Personnage(angle), affichage_(affichage)
{
    origine_tir_ = QPointF(-10,-10);
    visee_ = NULL;
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

void Assassin::action(const QList<QGraphicsItem *> & liste_item)
{
    // Modifier en 6 avec l'arrivée des murs avec porte
    QGraphicsItem * item = liste_item[liste_item.size() - 4];
    angle_ = normalise_angle(360 - QLineF(this->pos(), item->pos()).angle());

    if(visee_ == NULL)
    {
        visee_ = new QTime();
        visee_->start();
    }

    // 5000 en realite
    if(visee_->elapsed() > 5000)
    {
        ((Cible *) item)->mort();
        origine_tir_ = this->pos();
    }
    else
    {
        std::cout << visee_->elapsed() << std::endl;
    }
}

void Assassin::move(const qreal & angle, const qreal & vitesse)
{
    setRotation(angle);
    setPos(mapToParent(0,0));
}
