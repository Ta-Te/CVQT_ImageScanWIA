//
// A demonstration program to show image scanning using WIA
//
// Ta-Te Lin
// National Taiwan University
// 2017/07/28
//
// Reference websites:
// https://github.com/hudongcheng/TestWia
// https://msdn.microsoft.com/en-us/library/windows/desktop/ms630368(v=vs.85).aspx
//

#include "cvqt_imagescanwia.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CVQT_ImageScanWIA w;
    w.show();

    return a.exec();
}
