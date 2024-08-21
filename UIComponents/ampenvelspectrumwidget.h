#ifndef AMPENVELSPECTRUMWIDGET_H
#define AMPENVELSPECTRUMWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <vector>

QT_FORWARD_DECLARE_CLASS(QVBoxLayout)
QT_FORWARD_DECLARE_CLASS(QLabel)
QT_FORWARD_DECLARE_CLASS(QComboBox)
QT_FORWARD_DECLARE_CLASS(QHBoxLayout)

class AmpEnvelSpectrumWIdget : public QWidget
{
    Q_OBJECT
public:
    explicit AmpEnvelSpectrumWIdget(QWidget *parent = nullptr);
    ~AmpEnvelSpectrumWIdget();

signals:
public slots:
    void setSeries(const std::vector<double>& values);
private:
    QtCharts::QChart* chart;
    QtCharts::QChartView* chartView;
    QtCharts::QLineSeries* series;

    QVBoxLayout* chartLayout;
    QVBoxLayout* comboLayout;
    QHBoxLayout* mainLayout;

    QLabel* chartCapLbl;
    QLabel* comboLbl;
    QComboBox* filesCmb;

};

#endif // AMPENVELSPECTRUMWIDGET_H
