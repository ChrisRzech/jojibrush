#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include "windows/mainwindow.hpp"
#include "windows/login.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QSplashScreen splash(QPixmap(":/res/global/icons/giantlogo.png"));
    const int SPLASH_TIME_MS = 1000;

    MainWindow mainwindow;
    Login login(&mainwindow);

    splash.show();
    QTimer::singleShot(SPLASH_TIME_MS, &splash, SLOT(close()));
    QTimer::singleShot(SPLASH_TIME_MS, &login, SLOT(show()));

    return app.exec();
}
