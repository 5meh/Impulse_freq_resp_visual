#include "mainwindow.h"
#include "waterfallplot.h"
#include <QtDataVisualization/Q3DSurface>
#include <QVBoxLayout>
#include <QAction>
#include <QMenu>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    waterFallPlot = new WaterFallPlot();

    container = QWidget::createWindowContainer(waterFallPlot->getSurface());
    layout->addWidget(container);
}

void MainWindow::openFiles()
{

}

void MainWindow::creatActions()
{
    openFiles = new QAction(tr("&Open files"), this);
    openFiles->setStatusTip(tr("Open files with data."));
    connect(openFiles, &QAction::triggered, this, &MainWindow::openFiles);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&Open"));
    fileMenu->addAction(openFiles);
}

MainWindow::~MainWindow()
{
}

