#ifndef SEC_H
#define SEC_H

#include <QDialog>

namespace Ui {
class Sec;
}

class Sec : public QDialog
{
    Q_OBJECT

public:
    explicit Sec(QWidget *parent = nullptr);
    ~Sec();

private:
    Ui::Sec *ui;
};

#endif // SEC_H
