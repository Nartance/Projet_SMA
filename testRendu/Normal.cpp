#include "Normal.hpp"

QPointF points[3] = { QPointF(0, -7), QPointF(15,0), QPointF(0, 8) };

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += 360;
    while (angle > 360)
        angle -= 360;
    return angle;
}

Normal::Normal(const int & angleT) : angle(angleT), vitesse(0)
{

}

/*void Normal::setColor(const int & couleurT)
{
    couleur = couleurT;
}*/

// Forme englobante
QRectF Normal::boundingRect() const
{
    return QRectF(-7.5, -7.5, 22.5, 15);
}

// Forme détaillé
QPainterPath Normal::shape() const
{
    QPainterPath path;

    // on considère que le rond pour les collisions.
    path.addEllipse(-7.5,-7.5,15,15);

    return path;
}

void Normal::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // Couleur du trace
    painter->setPen(QPen(QColor(0,0,0)));

    // Regard
    painter->drawPolyline(points, 3);

    // Fond pour le corps
    /*switch(couleur)
    {
        case 0: // normal*/
            painter->setBrush(QBrush(QColor(220,220,220)));
            /*break;

        case 1 : // assassin
            painter->setBrush(QBrush(QColor(255,0,0)));
            break;

        case 2 : // surveillant
            painter->setBrush(QBrush(QColor(0,255,0)));
            break;

        case 3 : // cible
            painter->setBrush(QBrush(QColor(0,0,255)));
    }*/

    // Corps
    painter->drawEllipse(-7.5,-7.5,15,15);
}

void Normal::advance(int phase)
{
    if(!phase)
        return;

    QLineF projection_gauche(QPointF(0, 0), mapFromScene(50 + 15, this->y()));
    QLineF projection_haute(QPoint(0, 0), mapFromScene(this->x(), 50 + 15));
    QLineF projection_droite(QPointF(0, 0), mapFromScene(scene()->width() - 15 - 50, this->y()));
    QLineF projection_basse(QPointF(0, 0), mapFromScene(this->x(), scene()->height() - 15 - 50));

    // Trouver la distance la plus courte
    QLineF projection_courte_H;
    QLineF projection_courte_V;
    QLineF projection_courte;

    int contact_H = 0;
    int contact_V = 0;
    int contact = 0; // 1 -> haute, 2 -> basse, 3 -> gauche, 4 -> droite

    if(qMin(projection_haute.length(), projection_basse.length()) == projection_haute.length())
    {
        projection_courte_V = projection_haute;
        contact_V = 1;
    }
    else
    {
        projection_courte_V = projection_basse;
        contact_V = 2;
    }

    if(qMin(projection_gauche.length(), projection_droite.length()) == projection_gauche.length())
    {
        projection_courte_H = projection_gauche;
        contact_H = 3;
    }
    else
    {
        projection_courte_H = projection_droite;
        contact_H = 4;
    }

    if(qMin(projection_courte_H.length(), projection_courte_V.length()) == projection_courte_H.length())
    {
        projection_courte = projection_courte_H;
        contact = contact_H;
    }
    else
    {
        projection_courte = projection_courte_V;
        contact = contact_V;
    }

    // Changer la trajectoire si besoin
    if(projection_courte.length() < 20)
    {
        int dir_H = 0;

        angle = normalizeAngle(angle);

        // Direction
        if(angle < 90 || angle > 270)
            dir_H = 1;
        else
            dir_H = -1;

        qreal angle_approche = 360 - angle;

        if(angle < 180)
        {
            angle += (contact == 2) ? dir_H * (-5) : dir_H * 5;
        }
        else
        {
            if(angle_approche < 90)
                angle += (contact == 1) ? 5 : -5;
            else
                angle += (contact == 3) ? 5 : -5;
        }
    }

    setRotation(angle);
    setPos(mapToParent(6,0));

    // Try not to crash with any other mice
    /*QList<QGraphicsItem *> dangerMice = scene()->items(QPolygonF() << mapToScene(0, 0) << mapToScene(-30, -50) << mapToScene(30, -50));
    foreach (QGraphicsItem *item, dangerMice) {
        if (item == this)
            continue;

        QLineF lineToMouse(QPointF(0, 0), mapFromItem(item, 0, 0));
        qreal angleToMouse = ::acos(lineToMouse.dx() / lineToMouse.length());
        if (lineToMouse.dy() < 0)
            angleToMouse = TwoPi - angleToMouse;
        angleToMouse = normalizeAngle((Pi - angleToMouse) + Pi / 2);

        if (angleToMouse >= 0 && angleToMouse < Pi / 2) {
            // Rotate right
            angle += 0.5;
        } else if (angleToMouse <= TwoPi && angleToMouse > (TwoPi - Pi / 2)) {
            // Rotate left
            angle -= 0.5;
        }
    }*/






    //vitesse += (-50 + qrand() % 100) / 100.0;
    //qreal dx = ::sin(angle) * 10;

    //setRotation(rotation());
    //setPos(mapToParent(0, -(3 + sin(vitesse) * 3)));
    //setPos(this->x() + 1, this->y() + 0.5);


    /*
    if (!step)
        return;

    // Recadrage de l'element
    if(this->x() < 0)



    // Esquive des autres
    QList<QGraphicsItem *> liste_element = scene()->items(QPolygonF() << mapToScene(0, 0) << mapToScene(-30, -50) << mapToScene(30, -50));
    foreach (QGraphicsItem * element, liste_element)
    {
        // on passe l'element que l'on traite
        if (element == this)
            continue;
    }

    //variation de la vitesse
    //vitesse += (-50 + qrand() % 100) / 100.0;

    setPos(this->x(), this->y() - 1);
    std::cout << "X = " << this->x() << std::endl;
    std::cout << "Y = " << this->y() << std::endl;
    */
}
