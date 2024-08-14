#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class WaterFallPlot;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QWidget* container;
    WaterFallPlot* waterFallPlot;
};
#endif // MAINWINDOW_H
