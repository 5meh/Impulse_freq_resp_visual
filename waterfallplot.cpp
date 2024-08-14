#include "waterfallplot.h"
#include <QtDataVisualization/Q3DSurface>


WaterFallPlot::WaterFallPlot()
{
    m_graph = new QtDataVisualization::Q3DSurface();
}

QtDataVisualization::Q3DSurface* WaterFallPlot::getSurface()
{
    return m_graph;
}
