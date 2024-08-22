#include "ampenvelspectrumwidget.h"

#include <QLayout>
#include <QLabel>
#include <QSpacerItem>
#include <QComboBox>

AmpEnvelSpectrumWIdget::AmpEnvelSpectrumWIdget(QWidget *parent)
    : QWidget(parent),
      chart{new QtCharts::QChart()},
      chartView{new QtCharts::QChartView(chart, this)},
      series{new QtCharts::QLineSeries()},
      chartLayout{new QVBoxLayout()},
      comboLayout{new QVBoxLayout()},
      mainLayout{new QHBoxLayout(this)},
      comboLbl{new QLabel("Files:", this)},
      chartCapLbl{new QLabel(this)},
      filesCmb{new QComboBox(this)},
      axisX{new QtCharts::QValueAxis},
      axisY{new QtCharts::QValueAxis}
{
    //chart->addSeries(series);
    //chart->createDefaultAxes();
    //chart->axisX()->setTitleText("Frequency");
    //chart->axisY()->setTitleText("Amplitude");
    chartView->setRubberBand(QtCharts::QChartView::HorizontalRubberBand);
    chartLayout->addWidget(chartCapLbl);
    chartLayout->addWidget(chartView);
    chartLayout->setStretch(0,1);
    chartLayout->setStretch(1,5);

    comboLayout->addWidget(comboLbl);
    comboLayout->addWidget(filesCmb);
    //comboLayout->addItem(new QSpacerItem(40,40,QSizePolicy::Expanding,QSizePolicy::Minimum));


    mainLayout->addLayout(chartLayout);
    mainLayout->addLayout(comboLayout);
    mainLayout->setStretch(0,5);
    mainLayout->setStretch(1,1);

    //chart->setTitle("Amplitude spectrum and its envelope");
    //layout()->addItem(chartLayout);
    //layout()->addItem(comboLayout);

    setLayout(mainLayout);
}

AmpEnvelSpectrumWIdget::~AmpEnvelSpectrumWIdget()
{
    delete chart;
}

void AmpEnvelSpectrumWIdget::setSeries(const std::vector<double>& envelope)
{
    QtCharts::QLineSeries *envelopeSeries = new QtCharts::QLineSeries();
    int sampleRate = 106;
    for (size_t i = 0; i < envelope.size(); ++i)
    {
        envelopeSeries->append(i * sampleRate / envelope.size(), envelope[i]);
    }

    chart->addSeries(envelopeSeries);
    axisX->setTitleText("Frequency (Hz)");
    axisX->setLabelFormat("%i");
    //axisX->setTickCount(static_cast<int>(spectrum.size()));
    chart->addAxis(axisX, Qt::AlignBottom);
    envelopeSeries->attachAxis(axisX);


    axisY->setTitleText("Amplitude");
    axisY->setLabelFormat("%.2f");
    chart->addAxis(axisY, Qt::AlignLeft);
    envelopeSeries->attachAxis(axisY);

    //axisX->setRange(0, values.size() - 1);
    //axisY->setRange(*std::min_element(values.begin(), values.end()), *std::max_element(values.begin(), values.end()));

    //series->replace(points);
//    chart->setAxisX(axisX, series);
//    chart->setAxisY(axisY, series);
//
}

void AmpEnvelSpectrumWIdget::setChartCaption(QString caption)
{
    chartCapLbl->setText(caption);
}
