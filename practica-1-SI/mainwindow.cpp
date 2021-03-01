#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPlainTextEdit>
#include <stdlib.h>
#include "iostream"
#include <string>
#include <math.h>


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


void MainWindow::on_new_2_clicked()
{
    this->ui->input->clear();
    this->ui->numero->setValue(1);
    this->ui->output->clear();
    this->ui->entropia->clear();
    this->variable.clear();
}

void MainWindow::on_calcuar_clicked()
{

    valor = this->ui->input->toPlainText();
    letras = valor.toUtf8().constData();
    int j=0, i=0, l = letras.length(), contar=0;
    std::string aux, auxV;

    Caracteres prueba;

    while(j<l){
        aux = letras[j];
        if(aux.compare("\n")==0){
            aux = " ";
        }
        if(variable.empty()){
             prueba.letra = aux;
            if(letras[j]=='\n'){
                //prueba.letra = " ";
                prueba.contador = 2;

            }else{

                prueba.contador = 1;
            }
            variable.push_back(prueba);
            j++;

        }else if(variable.at(i).letra.compare(aux)==0){
            if(letras[j] == '\n'){
                variable.at(i).contador += 2;
            }else{
                variable.at(i).contador++;
            }
            j++;
            i=0;

        }else if(i==variable.size()-1){
            prueba.letra = aux;
            if(letras[j] == '\n'){
                //prueba.letra = " ";
                prueba.contador = 2;
            }else{
                prueba.contador = 1;
            }
            variable.push_back(prueba);
            j++;
            i=0;
        }else{
            i++;
        }

    }
    float total = 0.0;
    float redondear =0.0, segundo = 0.0, entropia = 0.0;
     for(int k = 0; k<variable.size(); k++){
         total += variable.at(k).contador;
     }

    QString a,c, d, poner, e;
    double probabilidad = 0.0;
    for(int k = 0; k<variable.size(); k++){
        //a = QString::fromStdString(variable.at(k).letra);
        //c = QString::number(variable.at(k).contador);

        probabilidad = variable.at(k).contador/total;
        variable.at(k).probabilidad = probabilidad;
        //redondear = roundf(probabilidad*1000)/1000;

        //d = QString::number(redondear);

        //entropia = entropia+probabilidad*log2(probabilidad);

        //poner = poner+a+"\t|\t"+c+"\t|\t"+d+"\n";
    }
    Caracteres temporal;
    for(int m=0; m<variable.size(); m++){
        for(int n=0; n<variable.size()-1; n++){
            std::cout<<n<<","<<m<<EOF;
            //if(variable.at(n).contador<variable.at(n-1).contador){
            if(variable.at(n).contador<variable.at(n+1).contador){
                temporal = variable.at(n);

                variable.at(n)=variable.at(n+1);
                //variable.at(n)=variable.at(n);

                //variable.at(n+1)=temporal;
                variable.at(n+1)=temporal;
            }
        }
    }

    for(int z = 0; z<variable.size(); z++){
        if(variable.at(z).letra.compare(" ")==0){
            variable.at(z).letra = "⌴";
        }
        a = QString::fromStdString(variable.at(z).letra);
        c = QString::number(variable.at(z).contador);
        redondear = roundf(variable.at(z).probabilidad*1000)/1000;

        d = QString::number(redondear);

        entropia = entropia+variable.at(z).probabilidad*log2(variable.at(z).probabilidad);

        poner = poner+a+"\t|\t"+c+"\t|\t"+d+"\n";
    }
    std::wstring p;
    entropia = -entropia;
    entropia = roundf(entropia*1000)/1000;
    c = QString::number(total);
    e = QString::number(entropia);
    poner = poner+"\n\t\t\t\t\t"+c;
    p = poner.toStdWString();
    this->ui->output->setText(QString::fromStdWString(p));
    this->ui->entropia->setText(e);
}
