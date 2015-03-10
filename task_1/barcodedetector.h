#ifndef BARCODEDETECTOR_H
#define BARCODEDETECTOR_H
#include <string>
#include <opencv/cv.h>
#include <opencv/highgui.h>

class ErrorFilePath{};

class BarCodeDetector
{
public:
    BarCodeDetector();
    bool loadBarCodeFile(const std::string &filePath);
    void detectBarCode();

private:
    std::string mFilePath;
    cv::Mat mInputFile;
    cv::Mat mInputGrayFile;
    cv::Mat mInputSharpImg;
    cv::Mat mInputBinaryImage;
    cv::Mat mInputCannyImage;

    void preprocessing();
    void linesDetection();
};

#endif // BARCODEDETECTOR_H
