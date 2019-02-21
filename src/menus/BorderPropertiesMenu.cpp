#include "BorderPropertiesMenu.hpp"
#include "ui_BorderPropertiesMenu.h"
#include "src/utils/constants.hpp"
using namespace jbrush::constants;

/* Constructors */
BorderPropertiesMenu::BorderPropertiesMenu(QWidget* parent)
    : QWidget(parent), m_ui(new Ui::BorderPropertiesMenu)
{
    m_ui->setupUi(this);

    /* Initial properties */
    m_props.penCapStyle  = PEN_CAP_MAP[m_ui->comboBox_cap->currentText()];
    m_props.penColor     = COLOR_MAP[m_ui->comboBox_color->currentText()];
    m_props.penJoinStyle = PEN_JOIN_MAP[m_ui->comboBox_join->currentText()];
    m_props.penStyle     = PEN_STYLE_MAP[m_ui->comboBox_style->currentText()];
    m_props.penWidth     = m_ui->spinBox_weight->value();
}

/* Destructor */
BorderPropertiesMenu::~BorderPropertiesMenu()
{
    delete m_ui;
}

/* Getters */
jbrush::BorderProperties BorderPropertiesMenu::getProperties() const
{
    return m_props;
}

void BorderPropertiesMenu::on_comboBox_cap_activated(const QString& arg1)
{
    m_props.penCapStyle = PEN_CAP_MAP[arg1];
    onItemChanged(m_props);
}

void BorderPropertiesMenu::on_comboBox_color_activated(const QString& arg1)
{
    m_props.penColor = COLOR_MAP[arg1];
    onItemChanged(m_props);
}

void BorderPropertiesMenu::on_comboBox_join_activated(const QString& arg1)
{
    m_props.penJoinStyle = PEN_JOIN_MAP[arg1];
    onItemChanged(m_props);
}

void BorderPropertiesMenu::on_comboBox_style_activated(const QString& arg1)
{
    m_props.penStyle = PEN_STYLE_MAP[arg1];
    onItemChanged(m_props);
}

void BorderPropertiesMenu::on_spinBox_weight_valueChanged(int arg1)
{
    m_props.penWidth = arg1;
    onItemChanged(m_props);
}
