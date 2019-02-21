#include "FillPropertiesMenu.hpp"
#include "ui_FillPropertiesMenu.h"
#include "src/utils/constants.hpp"
using namespace jbrush::constants;

/* Constructors */
FillPropertiesMenu::FillPropertiesMenu(QWidget* parent)
    : QWidget(parent), m_ui(new Ui::FillPropertiesMenu)
{
    m_ui->setupUi(this);

    /* Initial properties */
    m_props.brushColor = COLOR_MAP[m_ui->comboBox_color->currentText()];
    m_props.brushStyle = BRUSH_STYLE_MAP[m_ui->comboBox_pattern->currentText()];
}

/* Destructor */
FillPropertiesMenu::~FillPropertiesMenu()
{
    delete m_ui;
}

/* Getters */
jbrush::FillProperties FillPropertiesMenu::getProperties() const
{
    return m_props;
}

void FillPropertiesMenu::on_comboBox_color_activated(const QString& arg1)
{
    m_props.brushColor = COLOR_MAP[arg1];
    onItemChanged(m_props);
}

void FillPropertiesMenu::on_comboBox_pattern_activated(const QString& arg1)
{
    m_props.brushStyle = BRUSH_STYLE_MAP[arg1];
    onItemChanged(m_props);
}
