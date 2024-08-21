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
private slots:
    void openFiles();
private:
    void createActions();
    void createMenus();

    QMenu* openFilesMenu;
    QAction* openFilesAct;

    QWidget* container;
    QTabWidget* tabs;
    WaterFallPlot* waterFallPlot;
};
#endif // MAINWINDOW_H
