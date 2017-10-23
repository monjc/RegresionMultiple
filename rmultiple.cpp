#include "rmultiple.h"
#include "ui_rmultiple.h"
#include <QString>
#include <cmath>

RMultiple::RMultiple(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RMultiple)
{
    ui->setupUi(this);
    connect(ui->metodo,SIGNAL(clicked()),this,SLOT(metodo()));//Connections slot-buttons
    connect(ui->borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->salir,SIGNAL(clicked()),this,SLOT(close()));
}

RMultiple::~RMultiple()
{
    delete ui;
}

void RMultiple::metodo(){
    QString temp, temp1, temp2, temp3, temp4, temp5;
        double x1=ui->x1->value(); //The value of the spinboxes are assinged to a variable
        double x2=ui->x2->value();
        double x3=ui->x3->value();
        double x4=ui->x4->value();
        double x5=ui->x5->value();
        double x6=ui->x6->value();
        double y1=ui->y1->value();
        double y2=ui->y2->value();
        double y3=ui->y3->value();
        double y4=ui->y4->value();
        double y5=ui->y5->value();
        double y6=ui->y6->value();
        double z1=ui->z1->value();
        double z2=ui->z2->value();
        double z3=ui->z3->value();
        double z4=ui->z4->value();
        double z5=ui->z5->value();
        double z6=ui->z6->value();
        int i, n=6, x, j;
        double sumaX=0,sumaY=0, sumaZ=0, productoXZ=0, productoXY=0, productoYZ=0, sCX=0, sCY=0, sCZ=0, mediaZ=0;
        int a2=0, a1=0, a0=0;
        double r=0, mul, Sr=0, St=0;     //All the variables are declared

        A[0]=x1;A[1]=x2;A[2]=x3; A[3]=x4; A[4]=x5; A[5]=x6;   //Vectors
        B[0]=z1;B[1]=z2;B[2]=z3; B[3]=z4; B[4]=z5; B[5]=z6;
        C[0]=y1;C[1]=y2;C[2]=y3; C[3]=y4; C[4]=y5; C[5]=y6;

        for(i=0;i<6;i++){   //Arrays
            sumaX=sumaX+A[i];
            sumaY=sumaY+C[i];
            sumaZ=sumaZ+B[i];
            productoXZ=productoXZ+(A[i]*B[i]);
            productoXY=productoXY+(A[i]*C[i]);
            productoYZ=productoYZ+(C[i]*B[i]);
            sCX=sCX+(A[i]*A[i]);
            sCY=sCY+(C[i]*C[i]);
            sCZ=sCZ+(B[i]*B[i]);
            E[i]=0;
            F[i]=0;
        }

        mediaZ=sumaZ/n;

        D[0][0]=n;      D[0][1]=sumaX;          D[0][2]=sumaY;           D[0][3]=sumaZ;
        D[1][0]=sumaX;  D[1][1]=sCX;            D[1][2]=productoXY;      D[1][3]=productoXZ;
        D[2][0]=sumaY;  D[2][1]=productoXY;     D[2][2]=sCY;             D[2][3]=productoYZ;

        for(i=1;i<3;i++){

        for (x=i;x<3;x++){
          mul=(D[x][i-1])/(D[i-1][i-1]);

        for(j=0;j<4;j++){
          D[x][j]=(D[x][j]-((D[i-1][j])*mul));
         }
        }
        mul=0;
        }
                                //Gauss
      a2=(D[2][3]/D[2][2]);
      a1=(((D[1][3])-(D[1][2]*a2))/(D[1][1]));
      a0=((D[0][3])-(a2*D[0][2])-(a1*D[0][1]))/(D[0][0]);

      for (x=0;x<6;x++){

         E[x]=(B[x]-mediaZ)*(B[x]-mediaZ);
         F[x]=((B[x])-(a0)-(a1*A[x])-(a2*C[x]))*(B[x]-a0-(a1*A[x])-(a2*C[x]));

      }
      for (i=0;i<6;i++){
          St=St+E[i];
          Sr=Sr+F[i];
      }

      if(Sr==0){
        temp.append("\ny=").append(temp2.setNum(a0)).append("+(").append(temp3.setNum(a1)).append(")x1+(").append(temp4.setNum(a2)).append(")x2\nr=Infinito");
    }

        if(Sr!=0){
        r=sqrt((St-Sr)/Sr);
        temp.append("\ny=").append(temp2.setNum(a0)).append("+").append(temp3.setNum(a1)).append("x1+").append(temp4.setNum(a2)).append("x2").append("\nr=").append(temp1.setNum(r));
    }
     ui->Texto->setText(temp);  //The result is shown
}

void RMultiple::borrar(){ //Variables are cleaned
    ui->x1->setValue(0.0);
    ui->x2->setValue(0.0);
    ui->x3->setValue(0.0);
    ui->x4->setValue(0.0);
    ui->x5->setValue(0.0);
    ui->x6->setValue(0.0);
    ui->y1->setValue(0.0);
    ui->y2->setValue(0.0);
    ui->y3->setValue(0.0);
    ui->y4->setValue(0.0);
    ui->y5->setValue(0.0);
    ui->y6->setValue(0.0);
    ui->z1->setValue(0.0);
    ui->z2->setValue(0.0);
    ui->z3->setValue(0.0);
    ui->z4->setValue(0.0);
    ui->z5->setValue(0.0);
    ui->z6->setValue(0.0);
    ui->Texto->clear();
}
