#include "FilledShape.hpp"

namespace jbrush
{
/* Constructor */
FilledShape::FilledShape(const QPoint& pos, FillProperties props)
    : GeometricShape(pos, props.border), m_fillProps(props)
{}

/* Getters */
FillProperties FilledShape::getFillProps() const
{
    return m_fillProps;
}

/* Setters */
void FilledShape::setFillProps(FillProperties props)
{
    m_fillProps = props;
}

/* Properties */
void FilledShape::applyProps(QPainter& qp) const
{
    GeometricShape::applyProps(qp);

    QBrush brush;
    brush.setColor(m_fillProps.brushColor);
    brush.setStyle(m_fillProps.brushStyle);
    qp.setBrush(brush);
}

QString FilledShape::toStringProps() const
{
    QString geoProps = GeometricShape::toStringProps();
    QString brushColor;
    QString brushStyle;

    switch(m_fillProps.brushColor)
    {
    case Qt::GlobalColor::white:
        brushColor = "white";
        break;
    case Qt::GlobalColor::black:
        brushColor = "black";
        break;
    case Qt::GlobalColor::red:
        brushColor = "red";
        break;
    case Qt::GlobalColor::green:
        brushColor = "green";
        break;
    case Qt::GlobalColor::blue:
        brushColor = "blue";
        break;
    case Qt::GlobalColor::cyan:
        brushColor = "cyan";
        break;
    case Qt::GlobalColor::magenta:
        brushColor = "magenta";
        break;
    case Qt::GlobalColor::yellow:
        brushColor = "yellow";
        break;
    case Qt::GlobalColor::gray:
        brushColor = "gray";
        break;
    default: //Gets rid of the warnings
        break;
    }

    switch(m_fillProps.brushStyle)
    {
    case Qt::BrushStyle::SolidPattern:
        brushStyle = "SolidPattern";
        break;
    case Qt::BrushStyle::HorPattern:
        brushStyle = "HorPattern";
        break;
    case Qt::BrushStyle::VerPattern:
        brushStyle = "VerPattern";
        break;
    case Qt::BrushStyle::NoBrush:
        brushStyle = "NoBrush";
        break;
    default: //Gets rid of the warnings
        break;
    }

    return geoProps +
           "BrushColor: " + brushColor + "\r\n" +
           "BrushStyle: " + brushStyle + "\r\n";
}
}
