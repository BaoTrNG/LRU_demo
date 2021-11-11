#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<iostream>
#include<vector>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     int num1;
     QString num3;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_input3_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
