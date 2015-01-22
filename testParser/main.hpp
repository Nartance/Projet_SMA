#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <exception>
#include <map>

#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include "Mur.hpp"

typedef std::map<QString, std::vector<QGraphicsItem*> > mapType;

//mapType initMap();
void parser( const QString &, QGraphicsScene *);

#endif // MAIN_HPP
