#ifndef ANALYZATOR_H
#define ANALYZATOR_H
#include <QString>
#include <QtSql>
#include <QSqlQuery>

class Analyzator
{
private:
    QSqlDatabase db;
    QSqlQuery query;
public:
    QString El1;
    QString El2;
    QString kat;
    Analyzator();
    QSqlQuery provesti(QString elem1, QString elem2, QString kat);

};

#endif // ANALYZATOR_H
