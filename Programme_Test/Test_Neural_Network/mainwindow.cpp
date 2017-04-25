#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include "fonctions.h"
#include "Sources/Data.h"

using namespace cv;
using namespace std;

vector<QPushButton*> label;
vector<Data> datas;
vector<Mat*> alphabet;

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
    switch(position)
    {
        case 0:
            ui->lineEdit->setText("Training...");
        break;
        case 1:
            ui->lineEdit->setText("Detection...");
        break;
    }
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
    cout << "Nombres d'images : " << datas.size() << endl;
    for(unsigned int i = 0; i < datas.size(); i++ )
    {
        cout << "Image " << i << " : " << endl << "SIZE : " << datas[i].get_size() << endl ;
        datas[i].print();
    }
}
