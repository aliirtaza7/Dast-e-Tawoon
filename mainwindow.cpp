#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_check_clicked()
{
    if (ui->radioButton->isChecked() || ui->radioButton_2->isChecked()) {
        if (ui->radioButton->isChecked()) {
            ngo_log_in = new Ngo_Log_in(this);
            ngo_log_in->show();
        }
        if (ui->radioButton_2->isChecked()) {
            np_log_in = new Np_Log_in(this);
            np_log_in->show();
        }
    } else {
        // Apply custom QSS style to the QMessageBox
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {"
                             "background-color: black;"
                             "color: Red;"
                             "border: none;"
                             "font: bold 14px;"
                             "}");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Selection Error");
        msgBox.setText("Please select a login type.");
        msgBox.exec();
    }
}
