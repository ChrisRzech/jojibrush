#include "Ellipse.hpp"

namespace jbrush
{
/* Constructors (bounding box) */
Ellipse::Ellipse(const QPoint& topL, const QPoint& botR, FillProperties props)
    : FilledShape(topL, props)
{
    m_width  = botR.x() - topL.x();
    m_height = botR.y() - topL.y();
}

Ellipse::Ellipse(const QPoint& topL, int w, int h, FillProperties props)
    : FilledShape(topL, props), m_width(w), m_height(h)
{}

Ellipse::Ellipse(int x, int y, int w, int h, FillProperties props)
    : FilledShape(QPoint(0,0), props), m_width(w), m_height(h)
{
    QPoint center(x - w, y - h);
    setPosition(center);
}

/* Getters */
int Ellipse::getWidth() const
{
    return m_width;
}

int Ellipse::getHeight() const
{
    return m_height;
}

/* Setters */
void Ellipse::setWidth(int w)
{
    m_width = w;
}

void Ellipse::setHeight(int h)
{
    m_height = h;
}

/* Render */
void Ellipse::draw(QPainter& qp) const
{
    applyProps(qp);

    QRect box(m_position.x(), m_position.y(), m_width, m_height);
    qp.drawEllipse(box);
}

/* Ellipse Information */
double Ellipse::area() const
{
    return qFabs(M_PI * m_width * m_height / 4.0);
}

double Ellipse::perimeter() const
{
    double a = qFabs(m_width / 2);
    double b = qFabs(m_height / 2);

    return M_PI * (3 * (a + b) - qSqrt((3 * a + b) * (a + 3 * b)));
}

QString Ellipse::toString() const
{
    QString id = QString::number(getId());
    QString type = "Ellipse";
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
