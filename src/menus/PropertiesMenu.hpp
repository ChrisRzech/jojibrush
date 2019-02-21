#pragma once
#include <QWidget>
#include "BorderPropertiesMenu.hpp"
#include "FillPropertiesMenu.hpp"
#include "TextPropertiesMenu.hpp"

namespace Ui
{
class PropertiesMenu;
}

class PropertiesMenu : public QWidget
{
    Q_OBJECT

public:
    /* Constructors */
    explicit PropertiesMenu(QWidget* parent = nullptr);

    /* Destructor */
    ~PropertiesMenu();

    /* Getters */
    const BorderPropertiesMenu* getBorderPropertiesMenu() const;
    const FillPropertiesMenu* getFillPropertiesMenu() const;

    void displayFillPropertiesMenu(bool);

private:
    Ui::PropertiesMenu* m_ui;
    BorderPropertiesMenu* m_borderPropsMenu;
    FillPropertiesMenu* m_fillPropsMenu;
};
