#include "main.hpp"

int largeur_ = 400;
int hauteur_ = 400;

QPoint change_repere(QPoint point);

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    scene.setBackgroundBrush(QBrush(QColor(255,255,255)));
    scene.setSceneRect(QRect(0,0,largeur_ + 100,hauteur_ + 100));
    scene.addRect(QRect(50,50,largeur_,hauteur_), QPen(QColor(0,0,0)), QBrush(QColor(255,255,255)));

    /*
    for (int i = 0; i < MouseCount; ++i) {
        Mouse *mouse = new Mouse;
        mouse->setPos(::sin((i * 6.28) / MouseCount) * 200,
                      ::cos((i * 6.28) / MouseCount) * 200);
        scene.addItem(mouse);
    }
    */

    Normal * normal = new Normal(0);
    normal->setPos(change_repere(QPoint(200,200)));
    scene.addItem(normal);

    /*
    Normal * surv0 = new Normal(82);
    surv0->setColor(2);
    surv0->setPos(change_repere(QPoint(200,100)));
    scene.addItem(surv0);

    Normal * normal1 = new Normal(40);
    normal1->setColor();
    normal1->setPos(change_repere(QPoint(264,34)));
    scene.addItem(normal1);

    Normal * normal2 = new Normal(225);
    normal2->setColor();
    normal2->setPos(change_repere(QPoint(280,60)));
    scene.addItem(normal2);

    Normal * surv3 = new Normal(124);
    surv3->setColor(2);
    surv3->setPos(change_repere(QPoint(125,64)));
    scene.addItem(surv3);

    Normal * surv4 = new Normal(25);
    surv4->setColor(2);
    surv4->setPos(change_repere(QPoint(200,26)));
    scene.addItem(surv4);

    Normal * cible5 = new Normal(100);
    cible5->setColor(3);
    cible5->setPos(change_repere(QPoint(175,64)));
    scene.addItem(cible5);

    Normal * assa6 = new Normal(225);
    assa6->setColor(1);
    assa6->setPos(change_repere(QPoint(380,180)));
    scene.addItem(assa6);
    */

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
    timer.start(100/*1000/33*/);

    return app.exec();
}

QPoint change_repere(QPoint point)
{
    return QPoint(point.x() + 50, point.y() + 50);
}
