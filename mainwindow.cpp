#include "mainwindow.h"
#include "waterfallplot.h"
#include <QtDataVisualization/Q3DSurface>
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    waterFallPlot = new WaterFallPlot();

    container = QWidget::createWindowContainer(waterFallPlot->getSurface());

    //PlotWidget *plotWidget = new PlotWidget(centralWidget);
    layout->addWidget(container);
}

MainWindow::~MainWindow()
{
}

