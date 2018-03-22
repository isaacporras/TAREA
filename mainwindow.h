#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "reader.h"
#include "memory.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Reader reader;
    Memory memoria;

private slots:
    void on_CargarButton_clicked();

    void on_OKButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
