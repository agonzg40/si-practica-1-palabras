#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_new_2_clicked();

    void on_calcuar_clicked();

private:

    struct Caracteres{
        std::string letra;
        int contador;
    };

    Ui::MainWindow *ui;
    std::string valores, letras;
    QString valor;
    //Caracteres* variable ;
    std::vector<Caracteres> variable;
};
#endif // MAINWINDOW_H
