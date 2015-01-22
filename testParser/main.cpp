#include "parser.h"
#include "main.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    scene.setBackgroundBrush(QBrush(QColor(255,255,255)));

    try
    {
        parser("./Carte_Niveau.txt", &scene);
    }
    catch( const std::exception &e)
    {
        QMessageBox::critical(NULL, "Fichier non trouvé", e.what());
    }

    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(QBrush(QColor(220,220,220)));
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Test parser"));
    view.show();

    return a.exec();
}

/*mapType initMap()
{
    mapType & dicoType ;

    dicoType.insert(std::make_pair("Mur", vector<Mur*>()));
}*/

void parser( const QString & filename, QGraphicsScene * scene )
{
    mapType dicoType;

    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw std::exception("Le fichier spécifié n'existe pas");

    QTextStream flux(&file);
    QString s;
    QStringList ssplit;

    flux.setCodec("UTF-8");

    int hauteur, largeur;

    s = flux.readLine();
    ssplit = s.split(" ");
    largeur = ssplit[1].toInt() - 2;

    s = flux.readLine();
    ssplit = s.split(" ");
    hauteur = ssplit[1].toInt() - 2;

    scene->setSceneRect(QRect(0,0,largeur + 100,hauteur + 100));
    scene->addRect(QRect(50,50,largeur,hauteur), QPen(QColor(255,255,255)), QBrush(QColor(255,255,255)));

    s = flux.readLine();

    while( s != QString("DATA"))
    {
        QPointF limits [2];

        while( (s = flux.readLine()) == QString("MUR"))
        {
            QString type (s[0]);
            type += s.remove(0, 1).toLower();

            for(int i = 0 ; i < 2 ; ++i)
            {
                s = flux.readLine();
                ssplit = s.split(" ");
                limits[ i ] = QPointF((qreal)ssplit[1].toInt(), (qreal)ssplit[2].toInt());
            }

            flux.readLine();

            scene->addItem(new Mur( limits[0], limits[1] ));
        }
    }

    file.close();
}
