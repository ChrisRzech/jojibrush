#pragma once
#include <QMap>
#include <QWidget>
#include "src/utils/constants.hpp"

namespace Ui
{
class ShapeSelectMenu;
}

class ShapeSelectMenu : public QWidget
{
    Q_OBJECT

public:
    /* Constructors */
    explicit ShapeSelectMenu(QWidget *parent = nullptr);

    /* Destructor */
    ~ShapeSelectMenu() override;

    /* Getters */
    jbrush::constants::ShapeType getSelected() const;

signals:
    /* Signal emmits when any selection is made */
    void onSelection(jbrush::constants::ShapeType);

private slots:
    void on_pushButtonLine_clicked();
    void on_pushButtonRectangle_clicked();
    void on_pushButtonEllipse_clicked();
    void on_pushButtonText_clicked();
    void on_pushButtonPolyline_clicked();
    void on_pushButtonPolygon_clicked();

private:
    Ui::ShapeSelectMenu* m_ui;
    jbrush::constants::ShapeType m_selected;
};
