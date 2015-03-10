#include <QCoreApplication>
#include <QDebug>
#include <iostream>

#include "barcodedetector.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::string barCodeFilePath = argv[1];

    BarCodeDetector *detector = new BarCodeDetector( );

    if ( detector->loadBarCodeFile( argv[1] ) )
    {
        std::cout << "File was loaded" << std::endl;
        detector->detectBarCode();
    }
    else
    {
        std::cerr << "Coudn't load file: " << argv[1];
    }

    return a.exec();
}
