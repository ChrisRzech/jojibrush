#pragma once
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <vector>
#include "account.hpp"
#include "utils/constants.hpp"
#include "shapes/Shapes.hpp"

namespace jbrush
{
class Canvas : public QWidget
{
    Q_OBJECT

public:
    /* Constructors */
    Canvas(QWidget *parent = nullptr);

    /* Destructor */
    ~Canvas() override;

    /* Getters */
    std::vector<Shape*> getShapes();

    /* Setters */
    void setDrawShapeIds(bool);
    void setShapeType(constants::ShapeType);
    void setBorderProperties(BorderProperties);
    void setFillProperties(FillProperties);
    void setTextProperties(TextProperties);

    /* Files */
    bool loadFromFile(QString& file);

    /* Shapes */
    void addShape(Shape*);
    void removeShape(uint id);
    void clearShapes();

public slots:
    void updateShapeType(constants::ShapeType);
    void updateBorderProperties(BorderProperties);
    void updateFillProperties(FillProperties);
    void updateTextProperties(TextProperties);

protected:
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void paintEvent(QPaintEvent*) override;

private:
    constants::ShapeType m_type;
    BorderProperties m_borderProps;
    FillProperties m_fillProps;
    TextProperties m_textProps;

    bool m_drawID;
    std::vector<Shape*> m_shapes;
    Line* m_line;
    Rectangle* m_rect;
    Ellipse* m_ellipse;
    Polygon* m_polygon;
    Polyline* m_polyline;
    Text* m_text;
};
};
