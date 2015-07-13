#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void closeEvent(QCloseEvent *e);

    void showEvent(QShowEvent *e);

    void loadPlayLinks();

private slots:
    void startOrStop_slot();

    void play_slot();

private:
    Ui::MainWindow *ui;
    QMap<QString, QString> playLinks_;
};

#endif // MAINWINDOW_H
