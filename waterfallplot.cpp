#include "waterfallplot.h"
#include <QtDataVisualization/Q3DSurface>


WaterFallPlot::WaterFallPlot()
{
    m_surface = new QtDataVisualization::Q3DSurface();
    m_surface->setFlags(m_surface->flags() ^ Qt::FramelessWindowHint);
}

QtDataVisualization::Q3DSurface* WaterFallPlot::getSurface()
{
    return m_surface;
}
