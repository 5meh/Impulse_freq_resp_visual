#include "mainwindow.h"
#include "waterfallplot.h"
#include <QtDataVisualization/Q3DSurface>
#include <QVBoxLayout>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include <QListView>
#include <QTreeView>
#include "UIComponents/ampenvelspectrumwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      tabs{new QTabWidget(this)},
      ampEnvelScetr{new AmpEnvelSpectrumWIdget(tabs)}
{
    //QWidget *centralWidget = new QWidget(this);
    setCentralWidget(tabs);
    //setLayout(new QVBoxLayout(this));
    //QVBoxLayout *layout = new QVBoxLayout(tabs);
    //waterFallPlot = new WaterFallPlot();
    //container = QWidget::createWindowContainer(waterFallPlot->getSurface());
    //layout()->addWidget(tabs);
    tabs->addTab(ampEnvelScetr,"Envelope");
    //layout->addWidget(container);
    //container->hide();
    createActions();
    createMenus();
    setGeometry(200,200,1000,600);
}

void MainWindow::openFiles()
{
    QFileDialog openFilesDlg(this);
    openFilesDlg.setFileMode(QFileDialog::ExistingFiles);
    openFilesDlg.setOption(QFileDialog::DontUseNativeDialog, true);
    openFilesDlg.setOption(QFileDialog::ShowDirsOnly, false);
    openFilesDlg.setDirectory(QDir::homePath());
    QListView *view = openFilesDlg.findChild<QListView*>("listView");
    if (view)
    {
        view->setSelectionMode(QAbstractItemView::MultiSelection);
    }
    QTreeView *tree = openFilesDlg.findChild<QTreeView*>();
    if (tree)
    {
        tree->setSelectionMode(QAbstractItemView::MultiSelection);
    }

    if (openFilesDlg.exec())
    {
        QStringList selectedPaths = openFilesDlg.selectedFiles();
        //label->setText(selectedPaths.join("\n")); // Отображаем выбранные пути
    }
}

void MainWindow::createActions()
{
    openFilesAct = new QAction(tr("&Open files"), this);
    openFilesAct->setStatusTip(tr("Open files with data."));
    connect(openFilesAct, &QAction::triggered, this, &MainWindow::openFiles);
}

void MainWindow::createMenus()
{
    openFilesMenu = menuBar()->addMenu(tr("&Open"));
    openFilesMenu->addAction(openFilesAct);
}

MainWindow::~MainWindow()
{
}

