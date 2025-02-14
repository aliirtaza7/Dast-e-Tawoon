#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ngo_log_in.h"
#include "np_log_in.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_check_clicked();

private:
    Ui::MainWindow *ui;
    Ngo_Log_in *ngo_log_in;
    Np_Log_in *np_log_in;
};
#endif // MAINWINDOW_H
