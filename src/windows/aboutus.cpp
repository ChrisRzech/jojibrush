#include "aboutus.hpp"
#include "ui_aboutus.h"

AboutUs::AboutUs()
    : QDialog(nullptr), ui(new Ui::AboutUs)
{
    ui->setupUi(this);

    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint |
                   Qt::WindowSystemMenuHint |
                   Qt::WindowMinimizeButtonHint |
                   Qt::WindowCloseButtonHint);
}

AboutUs::~AboutUs()
{
    delete ui;
}
