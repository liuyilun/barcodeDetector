#include "barcodedetector.h"

BarCodeDetector::BarCodeDetector():
    mFilePath( "" )
{

}

int handleError( int status, const char* func_name,
            const char* err_msg, const char* file_name,
            int line, void* userdata )
{
    //Do nothing -- will suppress console output
    return 0;   //Return value is not used
}

bool BarCodeDetector::loadBarCodeFile(const std::string &filePath)
{
    cv::redirectError(handleError);
    try {
        mFilePath = filePath;
        mInputFile = cv::imread(mFilePath);

        if( mInputFile.rows == 0 || mInputFile.cols == 0 )
            throw( ErrorFilePath() );
    }
    catch( ErrorFilePath )
    {
        mFilePath = "";
        return false;
    }

    return true;
}

void BarCodeDetector::detectBarCode()
{
    preprocessing();
    linesDetection();
}

void BarCodeDetector::preprocessing()
{
    cv::cvtColor( mInputFile, mInputGrayFile, CV_BGR2GRAY );
    cv::Mat tempImg;
    // Sharpnes
    cv::GaussianBlur( mInputGrayFile, tempImg, cv::Size(0, 0), 3 );
    cv::addWeighted( mInputGrayFile, 1.5, tempImg, -0.5, 0, mInputSharpImg);

    cv::threshold( mInputSharpImg, mInputBinaryImage, 125, 255, cv::THRESH_BINARY);

    cv::Canny( mInputSharpImg, mInputCannyImage, 100, 200);

    cv::imshow("GrayScale", mInputGrayFile );
    cv::imshow("Sharp", mInputSharpImg );
    cv::imshow("Binary", mInputBinaryImage );
    cv::imshow("Canny", mInputCannyImage );

}

void BarCodeDetector::linesDetection()
{
    std::vector<cv::Vec4i> lines;

    cv::HoughLinesP(mInputCannyImage, lines, 1, CV_PI/180, 50 );

    for( size_t i = 0; i < lines.size(); i++ )
    {
        cv::Vec4i l = lines[i];
        cv::line( mInputFile, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(0,0,255) );
    }

    cv::imshow("Lines", mInputFile);
}
