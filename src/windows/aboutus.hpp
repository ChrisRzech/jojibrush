#pragma once
#include <QDialog>

namespace Ui
{
class AboutUs;
}

class AboutUs : public QDialog
{
    Q_OBJECT

public:
    AboutUs();
    ~AboutUs() override;

private:
    Ui::AboutUs* ui;
};
