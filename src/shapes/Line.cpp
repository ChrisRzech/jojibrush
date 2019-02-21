#include "Line.hpp"

namespace jbrush
{
/* Constructors */
Line::Line(const QPoint& pos, const QPoint& end, BorderProperties props)
    : GeometricShape(pos, props), m_end(end)
{}

Line::Line(int x1, int y1, int x2, int y2, BorderProperties props)
    : GeometricShape(QPoint(x1,y1), props), m_end(QPoint(x2,y2))
{}

/* Getters */
QPoint Line::getStart() const
{
    return m_position;
}

QPoint Line::getEnd() const
{
    return m_end;
}

/* Setters */
void Line::setStart(const QPoint& start)
{
    m_position = start;
}

void Line::setEnd(const QPoint& end)
{
    m_end = end;
}

/* Render */
void Line::draw(QPainter& qp) const
{
    applyProps(qp);
    qp.drawLine(m_position, m_end);
}

/* Line Information */
double Line::area() const
{
    return 0;
}

double Line::perimeter() const
{
    return 0;
}

QString Line::toString() const
{
    QString id = QString::number(getId());
    QString type = "Line";
    QString dim = QString::number(m_position.x()) + " " +
                  QString::number(m_position.y()) + " " +
                  QString::number(m_end.x())      + " " +
                  QString::number(m_end.y());

    return "Shape Id: "        + id   + "\r\n" +
           "ShapeType: "       + type + "\r\n" +
           "ShapeDimensions: " + dim  + "\r\n" +
           toStringProps();
}
}
