#include "mainwindow.h"
#include "matplot/matplot.h"
#include "plotwidget.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    PlotWidget *plotWidget = new PlotWidget(centralWidget);
    layout->addWidget(plotWidget);
}

MainWindow::~MainWindow()
{
}

