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
    void creatActions();
    void createMenus();
    QMenu* openFiles;
    QAction* openFiles;

    QWidget* container;
    WaterFallPlot* waterFallPlot;
};
#endif // MAINWINDOW_H
