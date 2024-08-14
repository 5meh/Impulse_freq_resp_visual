#ifndef WATERFALLPLOT_H
#define WATERFALLPLOT_H
#include <QtGlobal>

//QT_FORWARD_DECLARE_CLASS(Q3DSurface);
#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataArray>
#include <QtDataVisualization/QSurface3DSeries>
//QT_FORWARD_DECLARE_CLASS(QSurfaceDataArray)
//QT_FORWARD_DECLARE_CLASS(QSurface3DSeries)//TODO:make working forward declaration

class WaterFallPlot
{
    //Q_OBJECT
public:
    WaterFallPlot();
    ~WaterFallPlot();

    QtDataVisualization::Q3DSurface* getSurface();//TODO:check later for safety
private:
    QtDataVisualization::Q3DSurface* m_surface;
    QtDataVisualization::QSurfaceDataArray* m_dataArray;
    QtDataVisualization::QSurface3DSeries* m_series;
};

#endif // WATERFALLPLOT_H
