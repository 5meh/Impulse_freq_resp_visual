//#ifndef PLOTWIDGET_H
//#define PLOTWIDGET_H

//#include <QOpenGLWidget>
////#include "external/matplotplusplus/source/matplot/matplot.h"

//class PlotWidget: public QOpenGLWidget
//{
//public:
//     PlotWidget(QWidget *parent = nullptr);
//protected:
//    void initializeGL() override {
//        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // white background
//    }

//    void resizeGL(int w, int h) override {
//        glViewport(0, 0, w, h);
//    }

//    void paintGL() override {
//        // screan cleaning
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//        auto fig = matplot::figure(true);
//        auto ax = fig->current_axes();
//        ax->plot({1, 2, 3, 4}, {1, 4, 9, 16});
//        ax->title("Simple Plot");
//        fig->draw();

//    }
//private:
//    matplot::figure_handle m_fig;
//};

//#endif // PLOTWIDGET_H
