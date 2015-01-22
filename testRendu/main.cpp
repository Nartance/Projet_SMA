#include "General.hpp"

int hauteur_ = 400;
int largeur_ = 400;

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    scene.setBackgroundBrush(QBrush(QColor(255,255,255)));
    scene.setSceneRect(QRect(0,0,largeur_ + 100,hauteur_ + 100));
    scene.addRect(QRect(50,50,largeur_,hauteur_), QPen(QColor(255,255,255)), QBrush(QColor(255,255,255)));

    /*
    for (int i = 0; i < MouseCount; ++i) {
        Mouse *mouse = new Mouse;
        mouse->setPos(::sin((i * 6.28) / MouseCount) * 200,
                      ::cos((i * 6.28) / MouseCount) * 200);
        scene.addItem(mouse);
    }
    */

    // Création des murs

    Mur * mur_droit = new Mur(0);
    scene.addItem(mur_droit);
    Mur * mur_bas = new Mur(1);
    scene.addItem(mur_bas);
    Mur * mur_gauche = new Mur(2);
    scene.addItem(mur_gauche);
    Mur * mur_haut = new Mur(3);
    scene.addItem(mur_haut);

    // Création d'un normal

    Normal * normal = new Normal(0, true);
    normal->setPos(change_repere(QPoint(340,200)));
    scene.addItem(normal);

    Normal * normal0 = new Normal(0);
    normal0->setPos(change_repere(QPoint(60,200)));
    scene.addItem(normal0);

    Normal * normal1 = new Normal(143);
    normal1->setPos(change_repere(QPoint(120,120)));
    scene.addItem(normal1);

    Normal * normal2 = new Normal(300);
    normal2->setPos(change_repere(QPoint(180,180)));
    scene.addItem(normal2);

    Normal * normal3 = new Normal(256);
    normal3->setPos(change_repere(QPoint(240,240)));
    scene.addItem(normal3);

    Normal * normal4 = new Normal(75);
    normal4->setPos(change_repere(QPoint(340,15)));
    scene.addItem(normal4);

    // Appel de la vue

    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(QBrush(QColor(220,220,220)));
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Test de rendu"));
    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    // Temps de rafraichissement en micro-secondes
    timer.start(1000/30/*1000/33*/);

    return app.exec();
}


