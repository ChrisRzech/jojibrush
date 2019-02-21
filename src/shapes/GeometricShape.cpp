#include "GeometricShape.hpp"

namespace jbrush
{
/* Constructor */
GeometricShape::GeometricShape(const QPoint& pos, BorderProperties props)
    : Shape(pos), m_borderProps(props)
{}

/* Getters */
BorderProperties GeometricShape::getBorderProps() const
{
    return m_borderProps;
}

/* Setters */
void GeometricShape::setBorderProps(BorderProperties props)
{
    m_borderProps = props;
}

/* Properties */
void GeometricShape::applyProps(QPainter& qp) const
{
    QPen pen;
    pen.setColor(m_borderProps.penColor);
    pen.setWidth(m_borderProps.penWidth);
    pen.setStyle(m_borderProps.penStyle);
    pen.setCapStyle(m_borderProps.penCapStyle);
    pen.setJoinStyle(m_borderProps.penJoinStyle);
    qp.setPen(pen);
}

QString GeometricShape::toStringProps() const
{
    QString penColor;
    QString penWidth = QString::number(m_borderProps.penWidth);
    QString penStyle;
    QString penCapStyle;
    QString penJoinStyle;

    switch(m_borderProps.penColor)
    {
    case Qt::GlobalColor::white:
        penColor = "white";
        break;
    case Qt::GlobalColor::black:
        penColor = "black";
        break;
    case Qt::GlobalColor::red:
        penColor = "red";
        break;
    case Qt::GlobalColor::green:
        penColor = "green";
        break;
    case Qt::GlobalColor::blue:
        penColor = "blue";
        break;
    case Qt::GlobalColor::cyan:
        penColor = "cyan";
        break;
    case Qt::GlobalColor::magenta:
        penColor = "magenta";
        break;
    case Qt::GlobalColor::yellow:
        penColor = "yellow";
        break;
    case Qt::GlobalColor::gray:
        penColor = "gray";
        break;
    default: //Gets rid of the warnings
        break;
    }

    switch(m_borderProps.penStyle)
    {
    case Qt::PenStyle::NoPen:
        penStyle = "NoPen";
        break;
    case Qt::PenStyle::SolidLine:
        penStyle = "SolidLine";
        break;
    case Qt::PenStyle::DashLine:
        penStyle = "DashLine";
        break;
    case Qt::PenStyle::DotLine:
        penStyle = "DotLine";
        break;
    case Qt::PenStyle::DashDotLine:
        penStyle = "DashDotLine";
        break;
    case Qt::PenStyle::DashDotDotLine:
        penStyle = "DashDotDotLine";
        break;
    default: //Gets rid of the warnings
        break;
    }

    switch(m_borderProps.penCapStyle)
    {
    case Qt::PenCapStyle::FlatCap:
        penCapStyle = "FlatCap";
        break;
    case Qt::PenCapStyle::SquareCap:
        penCapStyle = "SquareCap";
        break;
    case Qt::PenCapStyle::RoundCap:
        penCapStyle = "RoundCap";
        break;
    default: //Gets rid of the warnings
        break;
    }

    switch(m_borderProps.penJoinStyle)
    {
    case Qt::PenJoinStyle::MiterJoin:
        penJoinStyle = "MiterJoin";
        break;
    case Qt::PenJoinStyle::BevelJoin:
        penJoinStyle = "BevelJoin";
        break;
    case Qt::PenJoinStyle::RoundJoin:
        penJoinStyle = "RoundJoin";
        break;
    default: //Gets rid of the warnings
        break;
    }

    return "PenColor: "     + penColor     + "\r\n" +
           "PenWidth: "     + penWidth     + "\r\n" +
           "PenStyle: "     + penStyle     + "\r\n" +
           "PenCapStyle: "  + penCapStyle  + "\r\n" +
           "PenJoinStyle: " + penJoinStyle + "\r\n";
}
}
