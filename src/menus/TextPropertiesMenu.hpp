#pragma once
#include <QWidget>
#include "src/shapes/properties.hpp"

namespace Ui
{
class TextPropertiesMenu;
}

class TextPropertiesMenu : public QWidget
{
    Q_OBJECT

public:
    /* Constructors */
    explicit TextPropertiesMenu(QWidget* parent = nullptr);

    /* Destructors */
    ~TextPropertiesMenu();

    /* Getters */
    jbrush::TextProperties getProperties() const;

signals:
    void onItemChanged(jbrush::TextProperties);

private slots:
    void on_comboBox_align_activated(const QString&);
    void on_comboBox_color_activated(const QString&);
    void on_comboBox_style_activated(const QString&);
    void on_comboBox_weight_activated(const QString&);
    void on_comboBox_font_currentFontChanged(const QFont&);
    void on_spinBox_size_valueChanged(int);

private:
    Ui::TextPropertiesMenu* m_ui;
    jbrush::TextProperties m_props;
};
