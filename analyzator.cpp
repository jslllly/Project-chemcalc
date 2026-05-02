#include "analyzator.h"
#include <vector>

Analyzator::Analyzator() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("chem.db");

    if (!db.open())
    {
        qDebug() << "ufvyj jnrhsnfz nf,kbws";
        return;
    }

    query = QSqlQuery(db);
    query.exec("DROP TABLE chem");
    query.exec("CREATE TABLE chem ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "El1 TEXT NOT NULL, "
               "El2 TEXT NOT NULL,"
               "kat TEXT NOT NULL,"
               "res TEXT NOT NULL,"
               "pr TEXT NOT NULL)");


    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'He', '-', '-', 'Отсутствуют')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Li', 't', 'LiH', 'Отсутствуют')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Be', '-', '-', 'Отсутствуют')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'B', '-', '-', 'Отсутствуют')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'C', '-', 'CH4', 'Выделение газа')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'N', 't', 'NH3', 'Выделение газа')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'O2', '-', 'H2O', 'взрыв')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'F2', '-', 'HF', 'взрыв')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Ne', '-', '-', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Na', 't', 'NaH', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Mg', 't', 'MgH2', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Al', 't', 'AlH3', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Si', '-', 'SiH4', 'выделение газа')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'P', 't', 'PH3', 'выделение газа')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'S', '-', 'H2S', 'выделение газа')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Cl2', '-', 'HCl', 'взрыв')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Ar', '-', '-', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'K', '-', 'KH', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Ca', 't', 'CaH2', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Rb', '-', 'RbH', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Fr', '-', 'FrH', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Cs', '-', 'CsH', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Ba', 't', 'BaH2', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Sr', 't', 'SrH2', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Ra', 't', 'RaH2', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'As', 't', 'AsH3', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Se', '-', 'H2Se', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Br2', 't', 'HBr', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Kr', '-', '-', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Te', '-', 'H2Te', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'I2', '-', 'HI', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'Xe', '-', '-', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('H2', 'At2', '-', 'HAt', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('C', 'O2', '-', 'CO2', 'выделение газа')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('C', 'N2', 't', 'C2N2', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('C', 'F2', '-', 'CF4', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('C', 'S', 't', 'CS2', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('C', 'Ca', 't', 'CaC2', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('C', 'Mg', 't', 'MgC2', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('C', 'Na', 't', 'Na2C2', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('C', 'K', 't', 'K2C2', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('C', 'Li', '-', 'Li2C2', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('C', 'Be', 't', 'Be2C', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('C', 'Rb', 't', 'Rb2C2', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('C', 'Cs', 't', 'Cs2C2', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('C', 'Fr', 't', 'Fr2C2', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('C', 'Sr', 't', 'Sr2C2', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('C', 'Ba', 't', 'BaC2', '-')");
    query.exec("INSERT INTO chem (El1, El2, kat, res, pr) VALUES ('C', 'Ra', 't', 'RaC2', '-')");
}



QSqlQuery Analyzator::provesti(QString elem1, QString elem2, QString kat) {
    query.prepare("SELECT res, pr FROM chem WHERE El1 = (:elem1) AND El2 = (:elem2) AND kat = (:kat)");
    query.bindValue(":elem1", elem1);
    query.bindValue(":elem2", elem2);
    query.bindValue(":kat", kat);

    query.exec();
    return query;
}

// QSqlQuery Analyzator::uravnat(QString elem1, QString elem2, QString res, int k1, int k2, int k1r, int k2r)
// {
//     int kR = 1;
//     while(k1 == k2) {
//     if (k1 == k1r, k2 == k2r)
//     {

//     }
//     else
//     {
//         int a;
//         if (k1 < k2) {
//             a = k2 - k1;
//             kn2 = k1 + a
//         }
//         else
//         {
//             a = k1 - k2;
//             kn1 = k1 + a
//         }

//     }
//     }
// }
