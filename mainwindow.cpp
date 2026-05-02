#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    analyzator = Analyzator();

    this->setStyleSheet("background-color: #222A35");

    QPixmap pix(":/new/prefix1/tbl.png");
    ui->label->setScaledContents(true);
    ui->label->setPixmap(pix);

    ui->pushButton->setStyleSheet("background-color: #8FAADC");
    ui->pushButton_3->setStyleSheet("background-color: #8FAADC");
    ui->pushButton_4->setStyleSheet("background-color: #8FAADC");
    ui->lineEdit->setStyleSheet("background-color: #8FAADC");
    ui->lineEdit_2->setStyleSheet("background-color: #8FAADC");
    ui->lineEdit_3->setStyleSheet("background-color: #8FAADC");
    ui->lineEdit_4->setStyleSheet("background-color: #8FAADC");
    ui->textEdit->setStyleSheet("background-color: #8FAADC");

}

// void MainWindow::setupDatabase()
// {
//     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//     db.setDatabaseName("chem.db");

//     if (!db.open())
//     {
//         qDebug() << "ufvyj jnrhsnfz nf,kbws";
//         return;
//     }

//     QSqlQuery query;
//     query.exec("CREATE TABLE IF NOT EXIST chem ("
//                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
//                "El1 TEXT NOT NULL, "
//                "El2 TEXT NOT NULL,"
//                "kat TEXT NOT NULL,"
//                "res TEXT NOT NULL,"
//                "pr TEXT NOT NULL)");

//     query.exec("INSERT INTO chem (El1, El2, kat, res, pr)"
//                 " VALUES ('H2', 'He', '', 'Реакция не идет', 'Отсутствуют');"
//                 "INSERT INTO chem (El1, El2, kat, res, pr)"
//                 " VALUES ('H2', 'Li', 't', 'LiH', 'Отсутствуют');"
//                 "INSERT INTO chem (El1, El2, kat, res, pr)"
//                 " VALUES ('H2', 'Be', '', 'Реакция не идет', 'Отсутствуют');"
//                 "INSERT INTO chem (El1, El2, kat, res, pr)"
//                 " VALUES ('H2', 'B', '', 'Реакция не идет', 'Отсутствуют');"
//                "INSERT INTO chem (El1, El2, kat, res, pr)"
//                " VALUES ('H2', 'C', '', 'CH4', 'Выделение газа');"
//                "INSERT INTO chem (El1, El2, kat, res, pr)"
//                " VALUES ('H2', 'N', 't', 'NH3', 'Выделение газа');"
//                );

// }

MainWindow::~MainWindow()
{
    delete ui;
}



int cp = 0;

void MainWindow::on_pushButton_3_clicked()
{
    if (cp == 0) {
        cp = 1;
        ui->stackedWidget->setCurrentIndex(1);
    }
    else {
        cp = 0;
        ui->stackedWidget->setCurrentIndex(0);
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if (cp == 0) {
        cp = 1;
        ui->stackedWidget->setCurrentIndex(1);
    }
    else {
        cp = 0;
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton_clicked()
{

    // ui->lineEdit_3->va
    QString value1 = ui->lineEdit_3->text();
    QString value2 = ui->lineEdit_2->text();
    QString value_kat = ui->lineEdit->text();


    if (value1.size() == 0)
    {
        ui->lineEdit_3->setPlaceholderText("Это поле обязательно");
    }
    else if (value2.size() == 0)
    {
        ui->lineEdit_2->setPlaceholderText("Это поле обязательно");
    }
    if (value_kat.size() == 0)
    {
        value_kat = "-";
    }

    //provesti
    QSqlQuery query = analyzator.provesti(value1, value2, value_kat);
    QString res;
    QString pr;
    if (query.next()) {
     res = query.value("res").toString();
     pr = query.value("pr").toString();
    }
    else {
        res = "-";
        pr = "-";
    }

    ui->lineEdit_4->setText(res);
    ui->textEdit->setText(pr);

}

