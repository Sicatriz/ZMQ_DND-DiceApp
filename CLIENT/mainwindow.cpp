#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <zmq.hpp>
#include <QString>
#include <QStringList>
#include <QDebug>
#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#define sleep(n)    Sleep(n)
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


// sent and receive dice topic => show result in txtResult
int MainWindow::zmqSent(QString dice, QString amount, QString name)
{
    try
    {
        zmq::context_t context(1);

        zmq::socket_t ventilator(context, ZMQ_PUSH);
        ventilator.connect("tcp://benternet.pxl-ea-ict.be:24041");

        //Incoming messages come in here
        zmq::socket_t subscriber(context, ZMQ_SUB);

        subscriber.connect("tcp://benternet.pxl-ea-ict.be:24042");

        std::string topicStrSub = "DnD!>Dice>";
        subscriber.setsockopt(ZMQ_SUBSCRIBE, topicStrSub.c_str(), topicStrSub.length());

        QString topicStrPub = "DnD?>Dice";
        //Combine message to send
        QStringList msgPubList;
        QString diceCombo;
        QString sep = ">";
        QString msgToSend;

        diceCombo.append(amount);
        diceCombo.append("D");
        diceCombo.append(dice);
        qDebug() << diceCombo;

        msgPubList.append(topicStrPub);
        msgPubList.append(diceCombo);
        msgPubList.append(name);
        msgToSend = msgPubList.join(sep);

        ventilator.send(msgToSend.toStdString().c_str(), msgToSend.length());

        zmq::message_t msg; // Removed the pointer declaration
        QString qstr;
        QStringList reqVal;
        QString space = " ";
        QString targetPlayer;
        QString targetTrows;


        // Receive the message directly into msg
        //Incoming messages come in here

        while(1)
        {
            subscriber.recv(&msg);

            std::string received_msg = std::string(static_cast<char*>(msg.data()), msg.size());
            std::cout << "Subscribed : [" << received_msg << "]" << std::endl;

            qstr = QString::fromStdString(received_msg);

            if (qstr.startsWith( "DnD!>Dice>"+name))
            {
                std::cout << "Received from server : " << qstr.toStdString() << std::endl;
                break;
            }

        }

        // Split # of dice, dice type and player name
        reqVal = qstr.split('>');
        targetPlayer = reqVal.at(2);
        targetTrows = reqVal.at(3);
        //qDebug() << userName;

        std::cout << "player : " << targetPlayer.toStdString() << std::endl;
        std::cout << "trows : " << targetTrows.toStdString() << std::endl;

        // show result
        ui->txtResult->setText(targetPlayer + " " + targetTrows);

    }
    catch (zmq::error_t &ex)
    {
        std::cerr << "Caught an exception : " << ex.what();
    }
}


void MainWindow::on_btnD4_P_1_clicked()
{
    amount = ui->txtNdiceP_1->text();
    name = ui->txtNameP_1->text();

    zmqSent("4",amount,name);
}

void MainWindow::on_btnD4_P_2_clicked()
{
    amount = ui->txtNdiceP_2->text();
    name = ui->txtNameP_2->text();

    zmqSent("4",amount,name);
}


void MainWindow::on_btnD4_P_3_clicked()
{
    amount = ui->txtNdiceP_3->text();
    name = ui->txtNameP_3->text();

    zmqSent("4",amount,name);
}


void MainWindow::on_btnD4_P_4_clicked()
{
    amount = ui->txtNdiceP_4->text();
    name = ui->txtNameP_4->text();

    zmqSent("4",amount,name);
}


void MainWindow::on_btnD4_P_5_clicked()
{
    amount = ui->txtNdiceP_5->text();
    name = ui->txtNameP_5->text();

    zmqSent("4",amount,name);
}


void MainWindow::on_btnD4_P_6_clicked()
{
    amount = ui->txtNdiceP_6->text();
    name = ui->txtNameP_6->text();

    zmqSent("4",amount,name);
}


void MainWindow::on_btnD4_P_7_clicked()
{
    amount = ui->txtNdiceP_7->text();
    name = ui->txtNameP_7->text();

    zmqSent("4",amount,name);
}


void MainWindow::on_btnD4_P_8_clicked()
{
    amount = ui->txtNdiceP_8->text();
    name = ui->txtNameP_8->text();

    zmqSent("4",amount,name);
}

void MainWindow::on_btnD6_P_1_clicked()
{
    amount = ui->txtNdiceP_1->text();
    name = ui->txtNameP_1->text();

    zmqSent("6",amount,name);
}

void MainWindow::on_btnD6_P_2_clicked()
{
    amount = ui->txtNdiceP_2->text();
    name = ui->txtNameP_2->text();

    zmqSent("6",amount,name);
}


void MainWindow::on_btnD6_P_3_clicked()
{
    amount = ui->txtNdiceP_3->text();
    name = ui->txtNameP_3->text();

    zmqSent("6",amount,name);
}


void MainWindow::on_btnD6_P_4_clicked()
{
    amount = ui->txtNdiceP_4->text();
    name = ui->txtNameP_4->text();

    zmqSent("6",amount,name);
}


void MainWindow::on_btnD6_P_5_clicked()
{
    amount = ui->txtNdiceP_5->text();
    name = ui->txtNameP_5->text();

    zmqSent("6",amount,name);
}


void MainWindow::on_btnD6_P_6_clicked()
{
    amount = ui->txtNdiceP_6->text();
    name = ui->txtNameP_6->text();

    zmqSent("6",amount,name);
}


void MainWindow::on_btnD6_P_7_clicked()
{
    amount = ui->txtNdiceP_7->text();
    name = ui->txtNameP_7->text();

    zmqSent("6",amount,name);
}


void MainWindow::on_btnD6_P_8_clicked()
{
    amount = ui->txtNdiceP_8->text();
    name = ui->txtNameP_8->text();

    zmqSent("6",amount,name);
}


void MainWindow::on_btnD8_P_1_clicked()
{
    amount = ui->txtNdiceP_1->text();
    name = ui->txtNameP_1->text();

    zmqSent("8",amount,name);
}

void MainWindow::on_btnD8_P_2_clicked()
{
    amount = ui->txtNdiceP_2->text();
    name = ui->txtNameP_2->text();

    zmqSent("8",amount,name);
}


void MainWindow::on_btnD8_P_3_clicked()
{
    amount = ui->txtNdiceP_3->text();
    name = ui->txtNameP_3->text();

    zmqSent("8",amount,name);
}


void MainWindow::on_btnD8_P_4_clicked()
{
    amount = ui->txtNdiceP_4->text();
    name = ui->txtNameP_4->text();

    zmqSent("8",amount,name);
}


void MainWindow::on_btnD8_P_5_clicked()
{
    amount = ui->txtNdiceP_5->text();
    name = ui->txtNameP_5->text();

    zmqSent("8",amount,name);
}


void MainWindow::on_btnD8_P_6_clicked()
{
    amount = ui->txtNdiceP_6->text();
    name = ui->txtNameP_6->text();

    zmqSent("8",amount,name);
}


void MainWindow::on_btnD8_P_7_clicked()
{
    amount = ui->txtNdiceP_7->text();
    name = ui->txtNameP_7->text();

    zmqSent("8",amount,name);
}


void MainWindow::on_btnD8_P_8_clicked()
{
    amount = ui->txtNdiceP_8->text();
    name = ui->txtNameP_8->text();

    zmqSent("8",amount,name);
}

void MainWindow::on_btnD10_P_1_clicked()
{
    amount = ui->txtNdiceP_1->text();
    name = ui->txtNameP_1->text();

    zmqSent("10",amount,name);
}

void MainWindow::on_btnD10_P_2_clicked()
{
    amount = ui->txtNdiceP_2->text();
    name = ui->txtNameP_2->text();

    zmqSent("10",amount,name);
}


void MainWindow::on_btnD10_P_3_clicked()
{
    amount = ui->txtNdiceP_3->text();
    name = ui->txtNameP_3->text();

    zmqSent("10",amount,name);
}


void MainWindow::on_btnD10_P_4_clicked()
{
    amount = ui->txtNdiceP_4->text();
    name = ui->txtNameP_4->text();

    zmqSent("10",amount,name);
}


void MainWindow::on_btnD10_P_5_clicked()
{
    amount = ui->txtNdiceP_5->text();
    name = ui->txtNameP_5->text();

    zmqSent("10",amount,name);
}


void MainWindow::on_btnD10_P_6_clicked()
{
    amount = ui->txtNdiceP_6->text();
    name = ui->txtNameP_6->text();

    zmqSent("10",amount,name);
}


void MainWindow::on_btnD10_P_7_clicked()
{
    amount = ui->txtNdiceP_7->text();
    name = ui->txtNameP_7->text();

    zmqSent("10",amount,name);
}


void MainWindow::on_btnD10_P_8_clicked()
{
    amount = ui->txtNdiceP_8->text();
    name = ui->txtNameP_8->text();

    zmqSent("10",amount,name);
}


void MainWindow::on_btnD12_P_1_clicked()
{
    amount = ui->txtNdiceP_1->text();
    name = ui->txtNameP_1->text();

    zmqSent("12",amount,name);
}

void MainWindow::on_btnD12_P_2_clicked()
{
    amount = ui->txtNdiceP_2->text();
    name = ui->txtNameP_2->text();

    zmqSent("12",amount,name);
}


void MainWindow::on_btnD12_P_3_clicked()
{
    amount = ui->txtNdiceP_3->text();
    name = ui->txtNameP_3->text();

    zmqSent("12",amount,name);
}


void MainWindow::on_btnD12_P_4_clicked()
{
    amount = ui->txtNdiceP_4->text();
    name = ui->txtNameP_4->text();

    zmqSent("12",amount,name);
}


void MainWindow::on_btnD12_P_5_clicked()
{
    amount = ui->txtNdiceP_5->text();
    name = ui->txtNameP_5->text();

    zmqSent("12",amount,name);
}


void MainWindow::on_btnD12_P_6_clicked()
{
    amount = ui->txtNdiceP_6->text();
    name = ui->txtNameP_6->text();

    zmqSent("12",amount,name);
}


void MainWindow::on_btnD12_P_7_clicked()
{
    amount = ui->txtNdiceP_7->text();
    name = ui->txtNameP_7->text();

    zmqSent("12",amount,name);
}


void MainWindow::on_btnD12_P_8_clicked()
{
    amount = ui->txtNdiceP_8->text();
    name = ui->txtNameP_8->text();

    zmqSent("12",amount,name);
}

void MainWindow::on_btnD20_P_1_clicked()
{
    amount = ui->txtNdiceP_1->text();
    name = ui->txtNameP_1->text();

    zmqSent("20",amount,name);
}

void MainWindow::on_btnD20_P_2_clicked()
{
    amount = ui->txtNdiceP_2->text();
    name = ui->txtNameP_2->text();

    zmqSent("20",amount,name);
}


void MainWindow::on_btnD20_P_3_clicked()
{
    amount = ui->txtNdiceP_3->text();
    name = ui->txtNameP_3->text();

    zmqSent("20",amount,name);
}


void MainWindow::on_btnD20_P_4_clicked()
{
    amount = ui->txtNdiceP_4->text();
    name = ui->txtNameP_4->text();

    zmqSent("20",amount,name);
}


void MainWindow::on_btnD20_P_5_clicked()
{
    amount = ui->txtNdiceP_5->text();
    name = ui->txtNameP_5->text();

    zmqSent("20",amount,name);
}


void MainWindow::on_btnD20_P_6_clicked()
{
    amount = ui->txtNdiceP_6->text();
    name = ui->txtNameP_6->text();

    zmqSent("20",amount,name);
}


void MainWindow::on_btnD20_P_7_clicked()
{
    amount = ui->txtNdiceP_7->text();
    name = ui->txtNameP_7->text();

    zmqSent("20",amount,name);
}


void MainWindow::on_btnD20_P_8_clicked()
{
    amount = ui->txtNdiceP_8->text();
    name = ui->txtNameP_8->text();

    zmqSent("20",amount,name);
}
