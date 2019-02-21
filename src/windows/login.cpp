#include <QTimer>
#include <QTextStream>
#include "login.hpp"
#include "ui_login.h"
#include "src/utils/exceptions.hpp"

/* Constructor */
Login::Login(QWidget* widget)
    : QDialog(nullptr), m_ui(new Ui::Login), m_widget(widget)
{
    m_ui->setupUi(this);

    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint |
                   Qt::WindowSystemMenuHint |
                   Qt::WindowMinimizeButtonHint |
                   Qt::WindowCloseButtonHint);

    QPixmap pix(":/res/login/image/dark.png");
    m_ui->label_logo->setPixmap(pix.scaled(150, 150, Qt::KeepAspectRatio));
}

/* Destructor */
Login::~Login()
{
    delete m_ui;
}

/* Private slots */
void Login::on_pushButton_registered_clicked()
{
    try
    {
        QString usernameInput = m_ui->lineEdit_username->text();
        QString passwordInput = m_ui->lineEdit_password->text();
        jbrush::Account::Type type;

        if(authenticate(usernameInput, passwordInput, type))
        {
            authSuccessful(type);
        }
        else
        {
            authFailed();
        }
    }
    catch(jbrush::GeneralException& exception)
    {
        exception.errorWindow();
    }
}

void Login::on_pushButton_guest_clicked()
{
    authSuccessful(jbrush::Account::Type::GUEST);
}

void Login::on_checkBox_showPW_stateChanged(int state)
{
    if(state == Qt::CheckState::Checked)
    {
        m_ui->lineEdit_password->setEchoMode(QLineEdit::EchoMode::Normal);
    }
    else
    {
        m_ui->lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password);
    }
}

/* Authentication handling */
bool Login::authenticate(QString usernameInput, QString passwordInput, jbrush::Account::Type& type) const
{
    QFile authFile(":/res/login/auth.txt");
    QTextStream qin(&authFile);

    if(!authFile.open(QIODevice::ReadOnly))
    {
        throw jbrush::BadFile("Authentication failed, contact admin!");
    }

    QString usernameFile;
    QString passwordFile;
    QString accTypeFile;
    bool authValid = false;

    /* Search for correct username and password */
    while(!authValid && !qin.atEnd())
    {
        usernameFile = qin.readLine();
        passwordFile = qin.readLine();
        accTypeFile  = qin.readLine();
        qin.readLine(); //clears the empty line

        if(usernameFile.isEmpty() || passwordFile.isEmpty() || accTypeFile.isEmpty())
        {
            throw jbrush::BadFileFormat("Authentication failed, contact admin!");
        }
        else if(usernameFile == usernameInput && passwordFile == passwordInput)
        {
            authValid = true;

            if(accTypeFile == "admin")
            {
                type = jbrush::Account::Type::ADMIN;
            }
            else if(accTypeFile == "user")
            {
                type = jbrush::Account::Type::USER;
            }
            else
            {
                throw jbrush::BadFileFormat("Authentication failed, contact admin!");
            }
        }
    }

    authFile.close();

    return authValid;
}

void Login::authSuccessful(jbrush::Account::Type type) const
{
    QPixmap pix;

    if(type == jbrush::Account::Type::ADMIN)
    {
        pix.load(":/res/login/image/nani.png");
    }
    else
    {
        pix.load(":/res/login/image/normal.png");
    }

    m_ui->label_logo->setPixmap(pix.scaled(150, 150, Qt::KeepAspectRatio));

    m_ui->label_errorMsg->setStyleSheet(" QLabel { background-color: green; color: white; } ");
    m_ui->label_errorMsg->setText("Login successful");

    jbrush::Account::type = type;

    QTimer::singleShot(500, m_widget, SLOT(show()));
    QTimer::singleShot(500, this, SLOT(close()));
}

void Login::authFailed() const
{
    m_ui->label_errorMsg->setStyleSheet(" QLabel { background-color: red; color: white; }");
    m_ui->label_errorMsg->setText("Username/Password was incorrect");
}
