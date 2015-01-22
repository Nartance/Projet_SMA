#include "Normal.hpp"

Normal::Normal(const int & angle = 0, bool affichage) : Personnage(angle), affichage_(affichage)
{
    vitesse_deplacement_ = vitesse_;
    pause_ = NULL;
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
    QGraphicsItem * assassin = liste_item[liste_item.size() - 2];

    if(((Assassin *) assassin)->origine_tir_ != QPointF(-10,-10))
    {
        QPointF origine = ((Assassin *) assassin)->origine_tir_;
        vitesse_deplacement_ = 0;
        qreal angle = angle_;

        if(pause_ == NULL)
        {
            pause_ = new QTime();
            pause_->start();
        }

        if(pause_->elapsed() < 5000)
        {
            vitesse_deplacement_ = (vitesse_ - (vitesse_ / 1000) * pause_->elapsed() > 0)
                    ? vitesse_ - (vitesse_ / 1000) * pause_->elapsed()
                    : 0;
            //angle_ = normalise_angle(360 - QLineF(this->pos(), origine).angle());
            //angle_ = ((qreal) 180 / 5000) * pause_->elapsed();

            qreal signe = angle_ - QLineF(this->pos(), origine).angle() > 180 ? 1 : -1 ;


            /*angle_ -= rotation
            std::cout << rotation << std::endl;*/
        }
        else
        {
            // PANIQUE
        }
    }
}

void Normal::move()
{
    setRotation(angle_);
    setPos(mapToParent(vitesse_deplacement_,0));
}
