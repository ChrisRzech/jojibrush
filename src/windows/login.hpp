#pragma once
#include <QDialog>
#include "src/account.hpp"

namespace Ui
{
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget* widgetToShow);
    ~Login() override;

private slots:
    void on_pushButton_registered_clicked();
    void on_pushButton_guest_clicked();
    void on_checkBox_showPW_stateChanged(int);

private:
    bool authenticate(QString username, QString password, jbrush::Account::Type&) const;
    void authSuccessful(jbrush::Account::Type) const;
    void authFailed() const;

    Ui::Login* m_ui;
    QWidget* m_widget;
};
