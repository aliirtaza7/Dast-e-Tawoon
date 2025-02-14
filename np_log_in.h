#ifndef NP_LOG_IN_H
#define NP_LOG_IN_H

#include <QDialog>
#include "databasemanagement.h"
#include "np_sign_in.h"
#include "needyperson.h"
namespace Ui {
class Np_Log_in;
}

class Np_Log_in : public QDialog
{
    Q_OBJECT

public:
    explicit Np_Log_in(QWidget *parent = nullptr);
    ~Np_Log_in();

private slots:
    void on_nplogin_button_clicked();

    void on_npnewacc_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::Np_Log_in *ui;
    Np_Sign_in *np_sign_in;
    NeedyPerson *needyperson;
    Databasemanagement dbmanagement;
    bool verifyNeedyLogin(const QString &username, const QString &nppassword); // Function declaration
};

#endif // NP_LOG_IN_H
