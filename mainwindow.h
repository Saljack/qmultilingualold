#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "language.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_pushButton_clicked();
    void spbNum_changed();

    void on_actionAbout_Qt_triggered();

    void on_actionSettings_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_QMultilingual_triggered();

private:
    Ui::MainWindow *ui;
    Language* lan[3];

};

#endif // MAINWINDOW_H
