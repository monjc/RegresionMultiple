#ifndef RMULTIPLE_H
#define RMULTIPLE_H

#include <QMainWindow>

namespace Ui {
class RMultiple;
}

class RMultiple : public QMainWindow
{
    Q_OBJECT

public:
    explicit RMultiple(QWidget *parent = 0);
    ~RMultiple();
    double A[8], B[8], C[8], D[3][4], E[8], F[8];

private:
    Ui::RMultiple *ui;
public slots:
    void metodo();
    void borrar();
};

#endif // RMULTIPLE_H
