#include "sec.h"
#include "ui_sec.h"
#include<iostream>
#include<fstream>
#include<QString>
#include<sstream>
using namespace std;
void ReadFile(vector<string> &cmd,vector<int> &flag)
{

   ifstream in2("cmd.txt");
   string temp;
   while(getline(in2,temp))
   {
       cmd.push_back(temp);
   }
 //  cout<<cmd[cmd.size()-1];
   stringstream iss(cmd[cmd.size()-1]);
   for(int i=0; i<=3; i++)
   {
       int x;
       iss >>x;
       flag.push_back(x);
   }
}
void ReadFile2(vector<vector<string>> &dat)
{
     ifstream in("dat.txt");
     string temp;
     vector<string>is;
     while(getline(in,temp))
     {
         is.push_back(temp);
     }
    /* for(int i=0; i<is.size(); i++)
     {
         cout<<is[i]<<endl;
     } */
   for(int i=0; i< is.size(); i++)
   {
       stringstream iss(is[i]);
       for(string a; iss>>a;)
       {
           dat[i].push_back(a);
       }
       cout<<endl;
   }


 /* for(int i=0; i< dat.size(); i++)
   {

       for(int j=0; j< dat[i].size();j++)
       {
           cout<<dat[i][j]<<" ";

       }
     cout<<endl<<endl;
   } */

}

void OffButton(QPushButton *a[], int size)
{
   for(int i=0; i<size ;i++)
   {
       a[i]->setVisible(0);
   }
}

Sec::Sec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sec)
{
    ui->setupUi(this);
    vector<string>cmd; vector<int> flag; vector<string> res;
ReadFile(cmd,flag);

 QLabel *ar[7];
 ar[0] = ui->l1;
 ar[1] = ui->l2;
 ar[2] = ui->l3;
 ar[3] = ui->l4;
 ar[4] = ui->l5;
 ar[5] = ui->l6;
 ar[6] = ui->l7;
 for(int i=6; i >= flag[3]; i--)
 {
    ar[i]->setVisible(0);
 }

 for(int i=0; i <flag[3]; i++)
 {
     QFont f("Times New Roman",10);
   //  cout<<i<<" ";
   QString temp = QString::fromStdString(cmd[i]);
 //  cout<<cmd[i]<<endl;
   ar[i]->setFont(f);
   ar[i]->setText(temp);
 }

vector<vector<string>> dat(7);

ReadFile2(dat);


QPushButton *down4[4]; down4[0] = ui->b4_4; down4[1] = ui->b5_4;  down4[2] = ui->b6_4;  down4[3] = ui->b7_4;
int d4=4;
QPushButton *down3[5]; down3[0] =ui->b3_3; down3[1] =ui->b4_3; down3[2] =ui->b5_3; down3[3] =ui->b6_3; down3[4] =ui->b7_3;
int d3=5;
QPushButton *down2[6]; down2[0]=ui->b2_2; down2[1]=ui->b3_2; down2[2]=ui->b4_2; down2[3]=ui->b5_2; down2[4]=ui->b6_2; down2[5]=ui->b7_2;
int d2=6;

//clear down
    if(flag[2] ==3)
    {
        OffButton(down4,d4);
    }
   else if(flag[2] ==2)
    {
        OffButton(down4,d4);
        OffButton(down3,d3);
    }
   else if(flag[2] == 1)
    {
        OffButton(down4,d4);
        OffButton(down3,d3);
         OffButton(down2,d2);
    }



int h=4;
QPushButton *hoz7[4]; hoz7[0]=ui->b7; hoz7[1]=ui->b7_2; hoz7[2]=ui->b7_3; hoz7[3]=ui->b7_4;
QPushButton *hoz6[4]; hoz6[0]=ui->b6; hoz6[1]=ui->b6_2; hoz6[2]=ui->b6_3; hoz6[3]=ui->b6_4;
QPushButton *hoz5[4]; hoz5[0]=ui->b5; hoz5[1]=ui->b5_2; hoz5[2]=ui->b5_3; hoz5[3]=ui->b5_4;
QPushButton *hoz4[4]; hoz4[0]=ui->b4; hoz4[1]=ui->b4_2; hoz4[2]=ui->b4_3; hoz4[3]=ui->b4_4;
QPushButton *hoz3[3]; hoz3[0]=ui->b3; hoz3[1]=ui->b3_2; hoz3[2]=ui->b3_3; int h3=3;
QPushButton *hoz2[2]; hoz2[0]=ui->b2; hoz2[1]=ui->b2_2; int h2=2;

//clear horizontal
 if(flag[3] == 6)
   {
   OffButton(hoz7,h);
   }
 else if(flag[3] == 5)
   {
    OffButton(hoz7,h);
    OffButton(hoz6,h);
   }
 else if(flag[3] == 4)
   {
    OffButton(hoz7,h);
    OffButton(hoz6,h);
    OffButton(hoz5,h);
   }
 else if(flag[3] == 3)
   {
    OffButton(hoz7,h);
    OffButton(hoz6,h);
    OffButton(hoz5,h);
    OffButton(hoz4,h);
   }
 else if(flag[3] == 2)
   {
    OffButton(hoz7,h);
    OffButton(hoz6,h);
    OffButton(hoz5,h);
    OffButton(hoz4,h);
    OffButton(hoz3,h3);
   }
 else if(flag[3] == 1)
   {
    OffButton(hoz7,h);
    OffButton(hoz6,h);
    OffButton(hoz5,h);
    OffButton(hoz4,h);
    OffButton(hoz3,h3);
    OffButton(hoz2,h2);
   }

//set error
QString str; str =str+ "page hit: "+QString::number(flag[0]);
QFont t("Times New Roman",12);
ui->hit->setFont(t);
ui->hit->setText(str);
str.clear();
str = "loi trang: "+QString::number(flag[1]);
ui->fault->setFont(t);
ui->fault->setText(str);



//set result
QFont f("Times New Roman",12);
QString temp = QString::fromStdString(dat[0][0]);
ui->b1->setFont(f);  ui->b1->setText(temp);
for(int i=0; i<dat[1].size(); i++)
{
    QFont f("Times New Roman",12);
    QString temp = QString::fromStdString(dat[1][i]);
    hoz2[i]->setFont(f); hoz2[i]->setText(temp);
}

for(int i=0; i<dat[2].size(); i++)
{
    QFont f("Times New Roman",12);
    QString temp = QString::fromStdString(dat[2][i]);
    hoz3[i]->setFont(f); hoz3[i]->setText(temp);
}

for(int i=0; i<dat[3].size(); i++)
{
    QFont f("Times New Roman",12);
    QString temp = QString::fromStdString(dat[3][i]);
    hoz4[i]->setFont(f); hoz4[i]->setText(temp);
}

for(int i=0; i<dat[4].size(); i++)
{
    QFont f("Times New Roman",12);
    QString temp = QString::fromStdString(dat[4][i]);
    hoz5[i]->setFont(f); hoz5[i]->setText(temp);
}

for(int i=0; i<dat[5].size(); i++)
{
    QFont f("Times New Roman",12);
    QString temp = QString::fromStdString(dat[5][i]);
    hoz6[i]->setFont(f); hoz6[i]->setText(temp);
}

for(int i=0; i<dat[6].size(); i++)
{
    QFont f("Times New Roman",12);
    QString temp = QString::fromStdString(dat[6][i]);
    hoz7[i]->setFont(f); hoz7[i]->setText(temp);
}


}




Sec::~Sec()
{
    delete ui;
}
