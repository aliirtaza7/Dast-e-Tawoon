#ifndef NGO_LOG_IN_H
#define NGO_LOG_IN_H

#include <QString>
#include <QDialog>
#include "ngo.h"
#include "ngo_sign_in.h"
#include "databasemanagement.h"
namespace Ui {
class Ngo_Log_in;
}

class Ngo_Log_in : public QDialog
{
    Q_OBJECT

public:
    explicit Ngo_Log_in(QWidget *parent = nullptr);
    ~Ngo_Log_in();


private slots:
    void on_ngologin_button_clicked();
    void on_ngonewacc_button_clicked();
    void on_pushButton_clicked();

private:
    Ui::Ngo_Log_in *ui;
    NGO *ngo;
    Ngo_Sign_in *ngo_sign_in;
    Databasemanagement dbmanagement;
    bool verifyNGOLogin(const QString &username, const QString &password);
};

#endif // NGO_LOG_IN_H
