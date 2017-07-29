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
#include "ui_cvqt_imagescanwia.h"

// Global Variables
cv::Mat image;
cv::Mat image1;
cv::Mat image2;
cv::Mat image3;
QString message;


CVQT_ImageScanWIA::CVQT_ImageScanWIA(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CVQT_ImageScanWIA)
{
    ui->setupUi(this);
}

CVQT_ImageScanWIA::~CVQT_ImageScanWIA()
{
    delete ui;
}


/////////////////////////////////////////////////////////////////////////////////////////
// Exit the program
/////////////////////////////////////////////////////////////////////////////////////////
void CVQT_ImageScanWIA::on_actionExit_triggered()
{
    close();
}

/////////////////////////////////////////////////////////////////////////////////////////
// Open image file
/////////////////////////////////////////////////////////////////////////////////////////
void CVQT_ImageScanWIA::on_actionOpen_triggered()
{

    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), ".",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp"));

    if(fileName != NULL)
    {
        image = cv::imread(fileName.toStdString().data());
        cvtColor(image, image2, 4 );  // 4 for original CV_BGR2RGB

        // Resize the image to fit the display screen
        cv::resize(image2, image2, Size(ui->label->width(), ui->label->height()));

        // Qt image
        QImage img = QImage((const unsigned char*) (image2.data),
                            image2.cols, image2.rows, QImage::Format_RGB888);

        // Display on label
        ui->label->setPixmap(QPixmap::fromImage(img));

        message = "<< Image file " + QString::fromUtf8(fileName.toStdString().data()) + " successfully loaded >>";
        ui->textEdit->append(message);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
// Save image file
/////////////////////////////////////////////////////////////////////////////////////////
void CVQT_ImageScanWIA::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"), ".", tr("*.jpg") );
    if(fileName != NULL)
    {
        imwrite(fileName.toStdString().data(), image);

        message = "<< Image file " + QString::fromUtf8(fileName.toStdString().data()) + " successfully saved >>";
        ui->textEdit->append(message);
    }
}


/////////////////////////////////////////////////////////////////////////////////////////
// Acquire image from a scanner using WIA
/////////////////////////////////////////////////////////////////////////////////////////


// Function to create WIA manager
HRESULT CreateWiaDeviceManager(IWiaDevMgr2** ppWiaDevMgr)
{
    // Validate arguments
    if (NULL == ppWiaDevMgr)
    {
        return E_INVALIDARG;
    }

    // Initialize out variables
    *ppWiaDevMgr = NULL;

    // Create an instance of the device manager
    HRESULT hr = CoCreateInstance(CLSID_WiaDevMgr2, NULL, CLSCTX_LOCAL_SERVER, IID_IWiaDevMgr2, (void**)ppWiaDevMgr);

    // Return the result of creating the device manager
    return hr;
}

// Function to create WIA device
HRESULT CreateWiaDevice( IWiaDevMgr2 *pWiaDevMgr, BSTR bstrDeviceID, IWiaItem2 **ppWiaDevice )
{
    // Validate arguments
    if (NULL == pWiaDevMgr || NULL == bstrDeviceID || NULL == ppWiaDevice)
    {
        return E_INVALIDARG;
    }

    // Initialize out variables
    *ppWiaDevice = NULL;

    // Create the WIA Device
    HRESULT hr = pWiaDevMgr->CreateDevice(0, bstrDeviceID, ppWiaDevice );

    // Return the result of creating the device
    return hr;
}


// Scan an image from scanner, save it in a temporary file, and load the image file
void CVQT_ImageScanWIA::on_actionScan_triggered()
{
    HRESULT hr;
    BSTR *bstrDeviceID = new BSTR[0];
    IWiaItem2 *pItemRoot = NULL;


    // Initializes the COM library on the current thread and identifies the concurrency model as single-thread apartment (STA)
    CoInitialize(NULL);

    // Create WIA device manager
    IWiaDevMgr2 *pWiaDevMgr = NULL;
    CreateWiaDeviceManager(&pWiaDevMgr);

    if (NULL == pWiaDevMgr)
    {
        message = "<< Fail to create WIA device manager! >>";
        ui->textEdit->append(message);
    }

    hr = pWiaDevMgr->SelectDeviceDlg(NULL, 0, 0, bstrDeviceID, &pItemRoot);

    if (S_OK == hr)
    {
        _bstr_t FolderName("./");                     // Save the temporary file from scanner in the current directory
        _bstr_t FileName("TempFileFromScanner");      // File of the temporary file from scanner
        LONG x = 0L;
        BSTR *files = new BSTR[0];
        pItemRoot->DeviceDlg(0, NULL, FolderName, FileName, &x, &files, &pItemRoot);
        // Output the message (optional)
        for(int i=0; i<x; i++)
        {
            wprintf(L"file name: %s\n", files[i]);
        }
        CoTaskMemFree(files); // Frees a block of task memory previously allocated through a call to the CoTaskMemAlloc or CoTaskMemRealloc function

        //
        // Load and display the scanned image from the temporary file
        //

        image = cv::imread("TempFileFromScanner.jpg");   // read the temporary file from scanner
        QFile file ("TempFileFromScanner.jpg");
        file.remove();                                   // remove the temporary file from scanner

        // Display the scanned image
        cvtColor(image, image2, 4 );  // 4 for original CV_BGR2RGB

        // Resize the image to fit the display screen
        cv::resize(image2, image2, Size(ui->label->width(), ui->label->height()));

        // Qt image
        QImage img = QImage((const unsigned char*) (image2.data),
                            image2.cols, image2.rows, QImage::Format_RGB888);

        // Display on label
        ui->label->setPixmap(QPixmap::fromImage(img));

        // Output the message of successful scanning
        message = "<< Scanned image successfully loaded >>";
        ui->textEdit->append(message);
    }
}
