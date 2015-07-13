#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <ppbox/IPpbox.h>
#include <string>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    playLinks_["test"] = "http://127.0.0.1:9006/record.m3u8?type=ppvod2&playlink=17306824%3Fft%3D2%26bwtype%3D2%26platform%3Dlauncher%26type%3Dppbox.launcher.vip%26sv%3D3.1.0&mux.M3U8.segment_duration=5&chunked=true&serialnum=796";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    PPBOX_StopP2PEngine();
    return QMainWindow::closeEvent(e);
}

void MainWindow::showEvent(QShowEvent *e)
{
    loadPlayLinks();
    return QMainWindow::showEvent(e);
}

void MainWindow::loadPlayLinks()
{
    ui->playLink_cmb->clear();
    ui->playLink_cmb->addItems(playLinks_.keys());
}

void MainWindow::startOrStop_slot()
{
    if (ui->start_btn->text() == "start") {
        std::string pid, uid, auth;
        PPBOX_StartP2PEngine(pid.c_str(), uid.c_str(), auth.c_str());
        int port = PPBOX_GetPort("http");
        ui->port_lab->setText(QString("port:%1").arg(port));

        ui->start_btn->setText("stop");
    } else {
        PPBOX_StopP2PEngine();
        ui->port_lab->setText(tr("port:"));
        ui->start_btn->setText("start");
    }
}

void MainWindow::play_slot()
{
    QString playLink = playLinks_[ui->playLink_cmb->currentText()];
    if ( playLink.isEmpty() )
        return;
    QString program = "ffplay";
    QStringList arguments;
    arguments << playLink;
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program, arguments);
    int x = 0;
}
