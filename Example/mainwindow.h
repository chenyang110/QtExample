#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class customTableModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initconnect();
    void initview();

Q_SIGNALS:
    void customDataSignal(int);
    void customDataSignal(double);

public Q_SLOTS:


    void pushButtonSlot();
    void pushButton_2Slot();
    void pushButton_3Slot();
    void pushButton_4Slot();
    void pushButton_5Slot();

    void customDataSlot(int num);
    void customDataSlot(double num);

    void qConcurrentSlot();


private:
    Ui::MainWindow *ui;
    customTableModel* mModel;
};
#endif // MAINWINDOW_H
