#include "ampenvelspectrumwidget.h"

#include <QLayout>
#include <QLabel>
#include <QComboBox>

AmpEnvelSpectrumWIdget::AmpEnvelSpectrumWIdget(QWidget *parent)
    : QWidget{parent},
      chart{new QtCharts::QChart()},
      chartView{new QtCharts::QChartView(chart, this)},
      series{new QtCharts::QLineSeries(this)},
      chartLayout{new QVBoxLayout(this)},
      comboLayout{new QVBoxLayout(this)},
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

    comboLayout->addWidget(comboLbl);
    comboLayout->addWidget(filesCmb);

    setLayout(new QHBoxLayout(this));
    layout()->addItem(chartLayout);
    layout()->addItem(comboLayout);
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
