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
      comboLbl{new QLabel(this)},
      chartCapLbl{new QLabel(this)},
      filesCmb{new QComboBox(this)}
{
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axisX()->setTitleText("Frequency");
    chart->axisY()->setTitleText("Amplitude");

    chartLayout->addWidget(chartCapLbl);
    chartLayout->addWidget(chartView);
    chartLayout->setStretch(0,1);
    chartLayout->setStretch(1,5);

    comboLayout->addWidget(comboLbl);
    comboLayout->addWidget(filesCmb);
    comboLayout->addItem(new QSpacerItem(40,40,QSizePolicy::Expanding,QSizePolicy::Minimum));


    mainLayout->addLayout(chartLayout);
    mainLayout->addLayout(comboLayout);

    //layout()->addItem(chartLayout);
    //layout()->addItem(comboLayout);

    setLayout(mainLayout);
}

AmpEnvelSpectrumWIdget::~AmpEnvelSpectrumWIdget()
{
    delete chart;
}

void AmpEnvelSpectrumWIdget::setSeries(const std::vector<double>& values)
{
    QVector<QPointF> points;
    for (size_t i = 0; i < values.size(); ++i)
    {
        points.append(QPointF(i, values[i]));
    }

    series->replace(points);
}
