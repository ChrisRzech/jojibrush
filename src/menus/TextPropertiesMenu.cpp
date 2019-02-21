#include "TextPropertiesMenu.hpp"
#include "ui_TextPropertiesMenu.h"
#include "src/utils/constants.hpp"
using namespace jbrush::constants;

/* Constructors */
TextPropertiesMenu::TextPropertiesMenu(QWidget* parent)
    : QWidget(parent), m_ui(new Ui::TextPropertiesMenu)
{
    m_ui->setupUi(this);

    /* Initial properties */
    m_props.textAlignment  = TEXT_ALIGN_MAP[m_ui->comboBox_align->currentText()];
    m_props.textColor      = COLOR_MAP[m_ui->comboBox_color->currentText()];
    m_props.textFontStyle  = TEXT_STYLE_MAP[m_ui->comboBox_style->currentText()];
    m_props.textFontWeight = TEXT_WEIGHT_MAP[m_ui->comboBox_weight->currentText()];
    m_props.textFontFamily = m_ui->comboBox_font->currentText();
    m_props.textSize       = m_ui->spinBox_size->value();
}

/* Destructor */
TextPropertiesMenu::~TextPropertiesMenu()
{
    delete m_ui;
}

/* Getters */
jbrush::TextProperties TextPropertiesMenu::getProperties() const
{
    return m_props;
}

void TextPropertiesMenu::on_comboBox_align_activated(const QString& arg1)
{
    m_props.textAlignment = TEXT_ALIGN_MAP[arg1];
    onItemChanged(m_props);
}

void TextPropertiesMenu::on_comboBox_color_activated(const QString& arg1)
{
    m_props.textColor = COLOR_MAP[arg1];
    onItemChanged(m_props);
}

void TextPropertiesMenu::on_comboBox_style_activated(const QString& arg1)
{
    m_props.textFontStyle = TEXT_STYLE_MAP[arg1];
    onItemChanged(m_props);
}

void TextPropertiesMenu::on_comboBox_weight_activated(const QString& arg1)
{
    m_props.textFontWeight = TEXT_WEIGHT_MAP[arg1];
    onItemChanged(m_props);
}

void TextPropertiesMenu::on_comboBox_font_currentFontChanged(const QFont& arg1)
{
    m_props.textFontFamily = arg1.family();
    onItemChanged(m_props);
}

void TextPropertiesMenu::on_spinBox_size_valueChanged(int arg1)
{
    m_props.textSize = arg1;
    onItemChanged(m_props);
}
