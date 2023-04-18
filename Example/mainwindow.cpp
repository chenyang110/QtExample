#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QThread>
#include <QtGlobal>

#include <QtConcurrent>

#include "customtablemodel.h"

//耗时操作
void spendtime()
{
    QThread::sleep(10);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initconnect();
    initview();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initconnect()
{
    {
        auto result = connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(pushButton_2Slot()));
        Q_ASSERT(result);
    }
    {
        auto result = connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::pushButtonSlot);
        Q_ASSERT(result);
    }
    {
        auto result = connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::pushButton_3Slot);
        Q_ASSERT(result);
    }
    {
        auto result = connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::pushButton_4Slot);
        Q_ASSERT(result);
    }
    {
        auto result = connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::pushButton_5Slot);
        Q_ASSERT(result);
    }

    {
        auto result = connect(this, QOverload<int>::of(&MainWindow::customDataSignal), this,  QOverload<int>::of(&MainWindow::customDataSlot));
        Q_ASSERT(result);
    }

    {
        auto result = connect(this, QOverload<double>::of(&MainWindow::customDataSignal), this,  QOverload<double>::of(&MainWindow::customDataSlot));
        Q_ASSERT(result);
    }

    {
        auto result = connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(qConcurrentSlot()));
        Q_ASSERT(result);
    }
}

void MainWindow:: initview()
{
    mModel = new customTableModel(ui->tableView);
    ui->tableView->setModel(mModel);
}

void MainWindow::pushButton_2Slot()
{
    ui->textEdit->append(QStringLiteral("信号槽 SIGNAL， SLOT 连接! "));
}

void MainWindow::pushButtonSlot()
{
    ui->textEdit->append(QStringLiteral("信号槽 QT5连接方式 连接! "));
}

void MainWindow::pushButton_3Slot()
{
    emit customDataSignal(1);
    emit customDataSignal(1.1);
}

void MainWindow::pushButton_4Slot()
{
    ui->textEdit->append(QStringLiteral("10耗时操作，此时界面会卡住，无法拖动! "));
    spendtime();
     ui->textEdit->append(QStringLiteral("10耗时操作完成! 界面不在卡住，恢复正常 "));
}

void MainWindow::pushButton_5Slot()
{
    auto th = QThread::create(spendtime);
    th->start();
     ui->textEdit->append(QStringLiteral("10耗时操作，多线程处理耗时操作!界面正常不卡, 可正常拖动 "));
}

void MainWindow::customDataSlot(int num)
{
    ui->textEdit->append(QStringLiteral("信号槽  重载 连接! 参数 int：%1 ").arg(num));
}

void MainWindow::customDataSlot(double num)
{
    ui->textEdit->append(QStringLiteral("信号槽  重载 连接! 参数 double：%1 ").arg(num));
}

void MainWindow::qConcurrentSlot()
{
     ui->textEdit->append(QStringLiteral("concurrent 处理耗时操作"));
     QtConcurrent::run(spendtime);
}



