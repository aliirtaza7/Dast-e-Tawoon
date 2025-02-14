#ifndef NGO_SIGN_IN_H
#define NGO_SIGN_IN_H

#include <QDialog>
#include <QString>
#include "databasemanagement.h"
#include "ngo.h"
namespace Ui {
class Ngo_Sign_in;
}

class Ngo_Sign_in : public QDialog
{
    Q_OBJECT

public:
    explicit Ngo_Sign_in(QWidget *parent = nullptr);
    ~Ngo_Sign_in();

private slots:
    void on_ngo_signin_pushButton_clicked();
    void on_pushButton_clicked();

private:
    Ui::Ngo_Sign_in *ui;
    NGO *ngo;
     Databasemanagement dbmanagement;
       bool insertNGOSignupData(const QString &reg, const QString &username,const QString &password); // Function declaration
};

#endif // NGO_SIGN_IN_H
