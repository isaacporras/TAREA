#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    reader.writeFile();

}

void MainWindow::on_CargarButton_clicked()
{
    FILE *file;                                                                                                         //crea una variable de tipo File
    int number;
    std::cout<< "no se abrio" <<std::endl;
    file = fopen("archivo.bin","rb");                                                                                   //Abre el archivo
    if(file == NULL){
        std::cout<< "no se abrio" <<std::endl;
    }
    else{
        int contador = 0;
        int pagina = 2;
        ui->PaginaCompleta->addItem("----Se encuentra en la pagina : " + QString::number(1) + "-------------------");
        while(fread(&number, sizeof(int),1,file)){
            if(contador == 100){

                ui->PaginaCompleta->addItem("-----------------Se encuentra en la pagina : " + QString::number(pagina) + "--------------------");
                pagina = pagina + 1;
                contador = 0;

            }
            ui->PaginaCompleta->addItem("El numero es: " + QString::number(number) + ", Posicion: "+QString::number(contador) );
            contador = contador + 1;



        }

    }
}

void MainWindow::on_OKButton_clicked()
{
    ui->Pag1Check->setChecked(false);
    ui->Pag2Check->setChecked(false);
    ui->Pag3Check->setChecked(false);
    ui->Pag4Check->setChecked(false);

    Pagina pagina = memoria.cargarpagina(ui->LineaDeTexto->text().toInt());
    std::cout<< "El numero de mi pagina es :" + *pagina.numerodepagina <<std::endl;
    std::cout<< "Igualo la pagina" <<std::endl;
    if(*pagina.numerodepagina == *memoria.pagina1.numerodepagina){
        ui->Pagina1->clear();
        ui->Pag1Check->click();
         ui->Pagina1->addItem("LA PAGINA QUE CARGO ES LA : " + QString::number(*pagina.numerodepagina));
    for(int contador = 0; contador <100; contador++){
        ui->Pagina1->addItem("El numero es: " + QString::number(pagina.elementos[contador]) + ", Posicion: "+QString::number(contador));
    }
    }
    if(*pagina.numerodepagina == *memoria.pagina2.numerodepagina){
        ui->Pagina2->clear();
        ui->Pag2Check->click();
        ui->Pagina2->addItem("LA PAGINA QUE CARGO ES LA : " + QString::number(*pagina.numerodepagina));
    for(int contador = 0; contador <100; contador++){
        ui->Pagina2->addItem("El numero es: " + QString::number(pagina.elementos[contador]) + ", Posicion: "+QString::number(contador));
    }
    }
    if(*pagina.numerodepagina == *memoria.pagina3.numerodepagina){
        ui->Pagina3->clear();
        ui->Pag3Check->click();
        ui->Pagina3->addItem("LA PAGINA QUE CARGO ES LA : " + QString::number(*pagina.numerodepagina));
    for(int contador = 0; contador <100; contador++){
        ui->Pagina3->addItem("El numero es: " + QString::number(pagina.elementos[contador]) + ", Posicion: "+ QString::number(contador));
    }
    }

    if(*pagina.numerodepagina == *memoria.pagina4.numerodepagina){
        ui->Pagina4->clear();
        ui->Pag4Check->click();
        ui->Pagina4->addItem("LA PAGINA QUE CARGO ES LA : " + QString::number(*pagina.numerodepagina));
    for(int contador = 0; contador <100; contador++){
        ui->Pagina4->addItem("El numero es: " + QString::number(pagina.elementos[contador]) + ", Posicion: "+QString::number(contador));
    }
    }
}
