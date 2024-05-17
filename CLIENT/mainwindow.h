#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <zmq.hpp>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

 //   zmq::socket_t subscriber();
 //   zmq::socket_t ventilator();
    int zmqSent(QString dice, QString amount, QString name);
    QString amount, name;

private slots:
    void on_btnD4_P_1_clicked();

    void on_btnD4_P_2_clicked();

    void on_btnD4_P_3_clicked();

    void on_btnD4_P_4_clicked();

    void on_btnD4_P_5_clicked();

    void on_btnD4_P_6_clicked();

    void on_btnD4_P_7_clicked();

    void on_btnD4_P_8_clicked();

    void on_btnD6_P_1_clicked();

    void on_btnD6_P_2_clicked();

    void on_btnD6_P_3_clicked();

    void on_btnD6_P_4_clicked();

    void on_btnD6_P_5_clicked();

    void on_btnD6_P_6_clicked();

    void on_btnD6_P_7_clicked();

    void on_btnD6_P_8_clicked();

    void on_btnD8_P_1_clicked();

    void on_btnD8_P_2_clicked();

    void on_btnD8_P_3_clicked();

    void on_btnD8_P_4_clicked();

    void on_btnD8_P_5_clicked();

    void on_btnD8_P_6_clicked();

    void on_btnD8_P_7_clicked();

    void on_btnD8_P_8_clicked();

    void on_btnD10_P_1_clicked();

    void on_btnD10_P_2_clicked();

    void on_btnD10_P_3_clicked();

    void on_btnD10_P_4_clicked();

    void on_btnD10_P_5_clicked();

    void on_btnD10_P_6_clicked();

    void on_btnD10_P_7_clicked();

    void on_btnD10_P_8_clicked();

    void on_btnD12_P_1_clicked();

    void on_btnD12_P_2_clicked();

    void on_btnD12_P_3_clicked();

    void on_btnD12_P_4_clicked();

    void on_btnD12_P_5_clicked();

    void on_btnD12_P_6_clicked();

    void on_btnD12_P_7_clicked();

    void on_btnD12_P_8_clicked();

    void on_btnD20_P_1_clicked();

    void on_btnD20_P_2_clicked();

    void on_btnD20_P_3_clicked();

    void on_btnD20_P_4_clicked();

    void on_btnD20_P_5_clicked();

    void on_btnD20_P_6_clicked();

    void on_btnD20_P_7_clicked();

    void on_btnD20_P_8_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
