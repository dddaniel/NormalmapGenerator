#ifndef SOBEL_H
#define SOBEL_H

#include <QImage>
#include "intensitymap.h"

class NormalmapGenerator
{
public:
    enum Kernel {
        SOBEL,
        PREWITT
    };

    NormalmapGenerator(IntensityMap::Mode mode, bool useRed, bool useGreen, bool useBlue, bool useAlpha);
    QImage calculateNormalmap(QImage input, Kernel kernel, double strength = 2.0, bool invert = false, 
                              bool tileable = true, bool keepLargeDetail = true, int largeDetailScale = 25, double largeDetailHeight = 1.0);
    IntensityMap getIntensityMap();

private:
    IntensityMap intensity;
    bool tileable;
    bool useRed, useGreen, useBlue, useAlpha;
    IntensityMap::Mode mode;

    int handleEdges(int iterator, int max);
    int mapComponent(double value);
    QVector3D sobel(double convolution_kernel[3][3], double strength);
    QVector3D prewitt(double convolution_kernel[3][3], double strength);
    int blendSoftLight(int color1, int color2);
};

#endif // SOBEL_H