#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//class WaterFallPlot;
class AmpEnvelSpectrumWIdget;
class QTabWidget;
class QMenu;
class QAction;

#include "Parser/iparser.h"
#include "Algorithms/ialgorithm.h"
class DataManager;
//class IAlgorithm;
//class IParser;


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

    QTabWidget* tabs;
    AmpEnvelSpectrumWIdget* ampEnvelScetr;
    DataManager* dataManager_;
    //IAlgorithm* algorithm;
    //IParser* parser;
};
#endif // MAINWINDOW_H
