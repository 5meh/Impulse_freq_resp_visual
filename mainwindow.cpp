#include "mainwindow.h"
#include "waterfallplot.h"
#include "UIComponents/ampenvelspectrumwidget.h"
#include "Parser/iparser.h"
#include "Parser/FileParser/datfileparser.h"
#include "DataToBeProcessed/datamanager.h"
#include "Algorithms/ialgorithm.h"
#include "Algorithms/fftalgorithm.h"
#include "DataToBeProcessed/FileData/datfiledata.h"
#include <QtDataVisualization/Q3DSurface>
#include <QVBoxLayout>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include <QListView>
#include <QTableWidget>
#include <QTreeView>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      tabs(new QTabWidget(this)),
      ampEnvelScetr(new AmpEnvelSpectrumWIdget(tabs))
{
    setCentralWidget(tabs);

    tabs->addTab(ampEnvelScetr,"Envelope");
    tabs->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    createActions();
    createMenus();
    setGeometry(200,200,1000,600);
    tabs->hide();
    dataManager_ = new DataManager(this);//TODO:should i pass this here
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
        for(QString filePath: selectedPaths)
        {
            auto parsedData = DatFileParser().parse(filePath);
            auto datFileData = std::make_unique<DatFileData>(DataSourceType::SourceType::File, filePath, std::move(parsedData));
            dataManager_->addDatFile(std::move(datFileData));
        }
    }
    auto data = dataManager_->getDatFilesData().front()->getData();


    auto envelop = new FFTalgorithmData(DataSourceType::SourceType::AlgorithmOutput,{},data,AlgorithmMetaInfo{});
    std::unique_ptr<FFTalgorithmData> envelopPTr(envelop);
    dataManager_->addAlgorithmResults(std::move(envelopPTr));
    const auto& fftResults = dataManager_->getFFTAlgorithmResults().front()->getData();
    ampEnvelScetr->setSeries(fftResults);
    tabs->show();
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

