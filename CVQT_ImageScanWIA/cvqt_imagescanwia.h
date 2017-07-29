#ifndef CVQT_IMAGESCANWIA_H
#define CVQT_IMAGESCANWIA_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextEdit>

// include files for OpenCV
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/cvdef.h>

// include files for WIA
#include <Windows.h>
#include <WIA.h>
#include <comdef.h>

#pragma comment(lib, "wiaguid.lib")

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <functional>

using namespace std;
using namespace cv;


namespace Ui {
class CVQT_ImageScanWIA;
}

class CVQT_ImageScanWIA : public QMainWindow
{
    Q_OBJECT

public:
    explicit CVQT_ImageScanWIA(QWidget *parent = 0);
    ~CVQT_ImageScanWIA();

private slots:
    void on_actionExit_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionScan_triggered();

private:
    Ui::CVQT_ImageScanWIA *ui;
};

#endif // CVQT_IMAGESCANWIA_H
