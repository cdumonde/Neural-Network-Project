#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include "fonctions.h"
#include "Sources/Data.h"
#include "Sources/Network.h"

using namespace cv;
using namespace std;

vector<string> nom_sorties;
vector<QPushButton*> label;
vector<QLineEdit*> probs;
vector<Data> datas;
vector<Mat*> alphabet;
Network *net;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    label.push_back(ui->pushButton_4);
    label.push_back(ui->pushButton_5);
    label.push_back(ui->pushButton_6);
    label.push_back(ui->pushButton_7);
    label.push_back(ui->pushButton_8);
    label.push_back(ui->pushButton_9);
    label.push_back(ui->pushButton_10);
    label.push_back(ui->pushButton_11);
    label.push_back(ui->pushButton_12);
    label.push_back(ui->pushButton_13);
    label.push_back(ui->pushButton_14);
    label.push_back(ui->pushButton_15);
    label.push_back(ui->pushButton_16);
    label.push_back(ui->pushButton_17);
    label.push_back(ui->pushButton_18);
    label.push_back(ui->pushButton_19);
    label.push_back(ui->pushButton_20);
    label.push_back(ui->pushButton_21);
    label.push_back(ui->pushButton_22);
    label.push_back(ui->pushButton_23);
    label.push_back(ui->pushButton_24);
    label.push_back(ui->pushButton_25);
    label.push_back(ui->pushButton_26);
    label.push_back(ui->pushButton_27);
    label.push_back(ui->pushButton_28);
    label.push_back(ui->pushButton_29);
    label.push_back(ui->pushButton_30);
    label.push_back(ui->pushButton_31);
    label.push_back(ui->pushButton_32);
    label.push_back(ui->pushButton_33);
    label.push_back(ui->pushButton_34);
    label.push_back(ui->pushButton_35);
    label.push_back(ui->pushButton_36);
    label.push_back(ui->pushButton_37);
    label.push_back(ui->pushButton_38);
    label.push_back(ui->pushButton_39);
    for(unsigned int i = 0; i < label.size(); i++ )
    {
        label[i]->hide();
    }
    probs.push_back(ui->lineEdit_4);
    probs.push_back(ui->lineEdit_5);
    probs.push_back(ui->lineEdit_6);
    probs.push_back(ui->lineEdit_7);
    probs.push_back(ui->lineEdit_8);
    probs.push_back(ui->lineEdit_9);
    probs.push_back(ui->lineEdit_10);
    probs.push_back(ui->lineEdit_11);
    probs.push_back(ui->lineEdit_12);
    probs.push_back(ui->lineEdit_13);
    probs.push_back(ui->lineEdit_14);
    probs.push_back(ui->lineEdit_15);
    probs.push_back(ui->lineEdit_16);
    probs.push_back(ui->lineEdit_17);
    probs.push_back(ui->lineEdit_18);
    probs.push_back(ui->lineEdit_19);
    probs.push_back(ui->lineEdit_20);
    probs.push_back(ui->lineEdit_21);
    probs.push_back(ui->lineEdit_22);
    probs.push_back(ui->lineEdit_23);
    probs.push_back(ui->lineEdit_24);
    probs.push_back(ui->lineEdit_25);
    probs.push_back(ui->lineEdit_26);
    probs.push_back(ui->lineEdit_27);
    probs.push_back(ui->lineEdit_28);
    probs.push_back(ui->lineEdit_29);
    nom_sorties.push_back("A");
    nom_sorties.push_back("B");
    nom_sorties.push_back("C");
    nom_sorties.push_back("D");
    nom_sorties.push_back("E");
    nom_sorties.push_back("F");
    nom_sorties.push_back("G");
    nom_sorties.push_back("H");
    nom_sorties.push_back("I");
    nom_sorties.push_back("J");
    nom_sorties.push_back("K");
    nom_sorties.push_back("L");
    nom_sorties.push_back("M");
    nom_sorties.push_back("N");
    nom_sorties.push_back("O");
    nom_sorties.push_back("P");
    nom_sorties.push_back("Q");
    nom_sorties.push_back("R");
    nom_sorties.push_back("S");
    nom_sorties.push_back("T");
    nom_sorties.push_back("U");
    nom_sorties.push_back("V");
    nom_sorties.push_back("W");
    nom_sorties.push_back("X");
    nom_sorties.push_back("Y");
    nom_sorties.push_back("Z");
    net = new Network(WIDTH*HEIGHT, nom_sorties.size(), 3, SIGMOID, nom_sorties);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Mat image;
    image = imread(ui->lineEdit_2->text().toUtf8().constData(), IMREAD_GRAYSCALE);
    if(image.data)
    {
        ui->lineEdit->setText("");
        alphabet = get_letter(image);

        for(unsigned int i = 0; i < label.size(); i++ )
        {
            label[i]->hide();
        }
        for(unsigned int i = 0; i < alphabet.size(); i++ )
        {
            label[i]->setIcon(QIcon(QPixmap::fromImage(QImage(alphabet[i]->data, alphabet[i]->cols, alphabet[i]->rows, alphabet[i]->step, QImage::Format_Indexed8))));
            label[i]->show();
        }
    }
    else
    {
        ui->lineEdit->setText("Couldn't open file");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    exit(1);
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{

}

void MainWindow::on_pushButton_3_clicked()
{
    datas.clear();
    for(unsigned int i = 0; i < label.size(); i++ )
    {
        if(label[i]->isChecked())
        {
            datas.push_back(Data((unsigned char*)alphabet[i]->data, alphabet[i]->cols*alphabet[i]->rows));
        }
    }
    if(ui->horizontalSlider->value() == 0)
    {
        for(unsigned int i = 0; i < datas.size(); i++) {
            datas[i].normalize();
        }
        float p = 0;
        while(p < 90) {
            p = net->train(0.01, 0.95, datas, ui->lineEdit->text().toUtf8().constData());
        }
        ui->lineEdit_3->setText(QString::number(p));
        for(unsigned int i = 0; i < probs.size(); i++)
        {
            probs[i]->setText(QString::number(net->get_prob(nom_sorties[i])));
        }
        ui->lineEdit->setText("Training Completed !");
    }
    else
    {
        for(unsigned int i = 0; i < datas.size(); i++) {
             datas[i].normalize();
             cout << "Detection Image "<< i << " : " << net->detect(datas[i]) << endl;
             for(unsigned int i = 0; i < probs.size(); i++)
             {
                 probs[i]->setText(QString::number(net->get_prob(nom_sorties[i])));
             }
        }
    }
}
