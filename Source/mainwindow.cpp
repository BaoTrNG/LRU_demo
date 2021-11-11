#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sec.h"
#include <QInputDialog>
#include<iostream>
#include<QString>
#include <list>
#include<sstream>
#include<fstream>
#include<QTime>
#include<QMovie>
using namespace std;
void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
void LRU_Cache(int pages[],int cache_size,int total_page)
{
    int page_hit=0,page_fault=0;
    list<int> cache;
      ofstream out1("dat.txt");
      ofstream out2("cmd.txt");
    for(int i=0;i<total_page;i++)
    {
        list<int>::iterator index;
        index=find(cache.begin(),cache.end(),pages[i]);

    //    cout<<" itr "<<*itr<<" "<<pages[i]<<" "<<i<<endl;

        if(index==cache.end())
        {
            page_fault++;
            int rand_size=cache.size();


            if(rand_size==cache_size)
            {
                out2<<"cache day nhung phan tu khong bi trung; loai-> "<<cache.front()<<", them->"<<pages[i]<<endl;

                cache.pop_front();
                cache.push_back(pages[i]);
            }
            else
            {
               out2<<"cache trong, phan tu duoc them vao-> "<<pages[i]<<endl;
               cache.push_back(pages[i]);
            }
        }
        else
        {
            out2<<"phan tu bi trung-> "<<pages[i]<<"; loai-> "<<cache.front()<<", them-> "<<pages[i]<<endl;
            page_hit++;
            cache.remove(pages[i]);
            cache.push_back(pages[i]);
        }

       for(auto &i:cache)
         {
           out1<<i<<" ";

         }
        out1<<endl;


    }
    out2<<page_hit<<" "<<page_fault<<" "<<cache_size<<" "<<total_page<<endl;

    out1.close();
    out2.close();

}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);








}
void AddInt(string temp,vector <int> &test)
{
    stringstream iss(temp);
    vector<string> ar1;
    for(string a; iss>>a;)
    {
        ar1.push_back(a);
    }
  //  int count=0;
  //  int ar2[ar1.size()];
    for(int i=0; i<ar1.size(); i++)
       {
         stringstream go(ar1[i]);
         int number;
         go >>number;
        test.push_back(number);
       }
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
     num1 = QInputDialog::getInt(this,"Input","Nhập vào số page (giá trị nhỏ hơn 5) ");
     if(num1 >4)
     {
      num1 =75;
      QFont f("Times New Roman",10);
      ui->pushButton->setFont(f);
      ui->pushButton->setText("page phải bé hơn 5");
     }
     else
     {
     QFont f("Times New Roman",20);
     ui->pushButton->setFont(f);
     ui->pushButton->setText(QString::number(num1));
     }
}


void MainWindow::on_pushButton_2_clicked()
{

    num3 = QInputDialog::getText(this,"Input","nhập vào các page tối đa 7 phần tử và cách 1 khoảng trắng");
    QFont f("Times New Roman",20);
    ui->pushButton_2->setFont(f);
    ui->pushButton_2->setText(QString(num3));

}


void MainWindow::on_input3_clicked()
{
    string num2;
    num2 = num3.toStdString();
     QFont f("Times New Roman",20);
     vector<int> res;
      AddInt(num2,res);
      int result[res.size()];
      for(int i=0 ; i<res.size(); i++ )
      {
          result[i]=res[i];
      //    cout<<result[i]<<" ";
      }
   if( num1 == 75 || num1 == NULL|| num2.empty() )
     {
       ui->error->setFont(f);
       ui->error->setText("<font color='red'>thiếu giá trị </font>");
       delay(3000);
        ui->error->setText("<font color='blue'> </font>");
     }
   else if(num1 > res.size())
   {
        QFont t("Times New Roman",10);
       ui->error->setFont(t);
       ui->error->setText("<font color='red'>số khung trang phải bé hơn số phần tử của chuỗi </font>");
       delay(3000);
        ui->error->setText("<font color='blue'> </font>");
   }
   else if(num1 ==0)
   {
        ui->error->setFont(f);
        ui->error->setText("<font color='red'>số khung phải >0 </font>");
        delay(3000);
         ui->error->setText("<font color='blue'> </font>");
   }
   else if(res.size() >7)
   {
       QFont t("Times New Roman",10);
      ui->error2->setFont(t);
      ui->error2->setText("<font color='red'>số phần tử phải nhó hơn 8 </font>");
      delay(3000);
       ui->error->setText("<font color='blue'> </font>");
   }
   else
   {
       ui->error->setFont(f);
       ui->error->setText("<font color='blue'>Thành Công </font>");
       LRU_Cache(result,num1,res.size());
     //  delay(3000);



       QMovie *test = new QMovie(":/Image/bear3.gif");
       if (!test->isValid())
       {
           cout<<"failed";
       }
       ui->gif->setVisible(1);
       ui->gif->setScaledContents(1);
       ui->gif->setMovie(test);
       test->start();
       delay(1200);
       ui->gif->setVisible(0);
       Sec d;
       d.exec();
       ui->error->setText("<font color='blue'> </font>");


   }

}

