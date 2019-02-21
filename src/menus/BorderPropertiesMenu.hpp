#pragma once
#include <QWidget>
#include "src/shapes/properties.hpp"

namespace Ui
{
class BorderPropertiesMenu;
}

class BorderPropertiesMenu : public QWidget
{
    Q_OBJECT

public:
    /* Constructors */
    explicit BorderPropertiesMenu(QWidget *parent = nullptr);

    /* Destructor */
    ~BorderPropertiesMenu();

    /* Getters */
    jbrush::BorderProperties getProperties() const;

signals:
    void onItemChanged(jbrush::BorderProperties);

private slots:
    void on_comboBox_cap_activated(const QString&);
    void on_comboBox_color_activated(const QString&);
    void on_comboBox_join_activated(const QString&);
    void on_comboBox_style_activated(const QString&);
    void on_spinBox_weight_valueChanged(int);

private:
    Ui::BorderPropertiesMenu* m_ui;
    jbrush::BorderProperties m_props;
};
