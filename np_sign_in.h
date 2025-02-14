#ifndef NP_SIGN_IN_H
#define NP_SIGN_IN_H

#include <QDialog>
#include <QString>
#include "databasemanagement.h"
#include "needyperson.h"

namespace Ui {
class Np_Sign_in;
}

class Np_Sign_in : public QDialog
{
    Q_OBJECT

public:
    explicit Np_Sign_in(QWidget *parent = nullptr);
    ~Np_Sign_in();

private slots:
    void on_np_signin_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::Np_Sign_in *ui;
     NeedyPerson *needyperson;
    Databasemanagement dbmanagement;
     bool insertNeedySignupData(const QString &username, const QString &nppassword, const QString &cnic, const QString &phone); // Function declaration
};

#endif // NP_SIGN_IN_H
