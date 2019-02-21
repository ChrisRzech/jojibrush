#include "PropertiesMenu.hpp"
#include "ui_PropertiesMenu.h"

/* Constructors */
PropertiesMenu::PropertiesMenu(QWidget* parent)
    : QWidget(parent), m_ui(new Ui::PropertiesMenu)
{
    m_ui->setupUi(this);

    m_borderPropsMenu = new BorderPropertiesMenu(m_ui->borderPropertiesMenu);
    m_fillPropsMenu = new FillPropertiesMenu(m_ui->fillPropertiesMenu);
}

/* Destructor */
PropertiesMenu::~PropertiesMenu()
{
    delete m_ui;
    delete m_borderPropsMenu;
    delete m_fillPropsMenu;
}

/* Getters */
const BorderPropertiesMenu* PropertiesMenu::getBorderPropertiesMenu() const
{
    return m_borderPropsMenu;
}

const FillPropertiesMenu* PropertiesMenu::getFillPropertiesMenu() const
{
    return m_fillPropsMenu;
}

void PropertiesMenu::displayFillPropertiesMenu(bool display)
{
    if(display)
    {
        m_ui->fillPropertiesMenu->show();
    }
    else
    {
        m_ui->fillPropertiesMenu->hide();
    }
}
