#pragma once
#include <QWidget>
#include "src/shapes/properties.hpp"

namespace Ui
{
class FillPropertiesMenu;
}

class FillPropertiesMenu : public QWidget
{
    Q_OBJECT

public:
    /* Constructors */
    explicit FillPropertiesMenu(QWidget* parent = nullptr);

    /* Destructor */
    ~FillPropertiesMenu();

    /* Getters */
    jbrush::FillProperties getProperties() const;

signals:
    void onItemChanged(jbrush::FillProperties);

private slots:
    void on_comboBox_color_activated(const QString&);
    void on_comboBox_pattern_activated(const QString&);

private:
    Ui::FillPropertiesMenu* m_ui;
    jbrush::FillProperties m_props;
};
