#include "Polygon.hpp"

namespace jbrush
{
/* Constructors */
Polygon::Polygon(const std::vector<QPoint>& points, FillProperties props)
    : FilledShape(points.front(), props), m_points(points)
{}

Polygon::Polygon(const QPoint& point, FillProperties props)
    : FilledShape(point, props)
{
    m_points.push_back(point);
}

/* Getters */
std::vector<QPoint> Polygon::getPoints() const
{
    return m_points;
}

/* Setters */
void Polygon::setPoint(uint index, const QPoint& pt)
{
    if(index < m_points.size())
        m_points[index] = pt;
}

void Polygon::setPoints(const std::vector<QPoint>& newPoints)
{
    m_points = newPoints;
}

void Polygon::addPoint(const QPoint& point)
{
    m_points.push_back(point);
}

/* Render */
void Polygon::draw(QPainter& qp) const
{
    applyProps(qp);
    qp.drawPolygon(m_points.data(), static_cast<int>(m_points.size()));
}

/* Polygon Information */
double Polygon::area() const
{
    double area = 0;
    uint pointCount = m_points.size();

    for(uint i = 0; i < pointCount; i++)
    {
        area += m_points[i].x() * m_points[(i + 1) % pointCount].y() - m_points[(i + 1) % pointCount].x() * m_points[i].y();
    }

    return qFabs(area / 2.0);
}

double Polygon::perimeter() const
{
    double perimeter = 0;
    uint pointCount = m_points.size();

    for(uint i = 0; i < pointCount; i++)
    {
        QPoint resultant = m_points[i] - m_points[(i + 1) % pointCount];
        perimeter += qSqrt(qPow(resultant.x(), 2) + qPow(resultant.y(), 2));
    }

    return perimeter;
}

QString Polygon::toString() const
{
    QString id = QString::number(getId());
    QString type = "Polygon";
    QString dim;

    for(uint i = 0; i < m_points.size(); i++)
    {
        dim += QString::number(m_points[i].x()) + " " + QString::number(m_points[i].y());
        dim += (i != m_points.size() - 1? " " : "");
    }

    return "Shape Id: "        + id   + "\r\n" +
           "ShapeType: "       + type + "\r\n" +
           "ShapeDimensions: " + dim  + "\r\n" +
           toStringProps();
}
}
