#include "Rectangle.hpp"

namespace jbrush
{
/* Constructors */
Rectangle::Rectangle(const QPoint& topL, const QPoint& botR, FillProperties props)
    : FilledShape(topL, props)
{
    m_width  = botR.x() - topL.x();
    m_height = botR.y() - topL.y();
}

Rectangle::Rectangle(const QPoint& topL, int w, int h, FillProperties props)
    : FilledShape(topL, props), m_width(w), m_height(h)
{}

Rectangle::Rectangle(int x, int y, int w, int h, FillProperties props)
    : FilledShape(QPoint(x,y), props), m_width(w), m_height(h)
{}

/* Getters */
int Rectangle::getWidth() const
{
    return m_width;
}

int Rectangle::getHeight() const
{
    return m_height;
}

/* Setters */
void Rectangle::setWidth(int w)
{
    m_width = w;
}

void Rectangle::setHeight(int h)
{
    m_height = h;
}

/* Render */
void Rectangle::draw(QPainter& qp) const
{
    applyProps(qp);
    qp.drawRect(m_position.x(), m_position.y(), m_width, m_height);
}

/* Rect information */
double Rectangle::area() const
{
    return qFabs(m_width * m_height);
}

double Rectangle::perimeter() const
{
    return qFabs(m_width + m_height) * 2.0;
}

QString Rectangle::toString() const
{
    QString id = QString::number(getId());
    QString type = "Rectangle";
    QString dim = QString::number(m_position.x()) + " " +
                  QString::number(m_position.y()) + " " +
                  QString::number(m_width)        + " " +
                  QString::number(m_height);

    return "Shape Id: "        + id   + "\r\n" +
           "ShapeType: "       + type + "\r\n" +
           "ShapeDimensions: " + dim  + "\r\n" +
           toStringProps();
}
}
