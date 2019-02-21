#include "Polyline.hpp"

namespace jbrush
{
/* Constructors */
Polyline::Polyline(const std::vector<QPoint>& points, BorderProperties props)
    : GeometricShape(points.front(), props), m_points(points)
{}

Polyline::Polyline(const QPoint& point, BorderProperties props)
    : GeometricShape(point, props)
{
    m_points.push_back(point);
}

/* Getters */
std::vector<QPoint> Polyline::getPoints() const
{
    return m_points;
}

/* Setters */
void Polyline::setPoint(uint index, const QPoint& pt)
{
    if(index < m_points.size())
        m_points[index] = pt;
}

void Polyline::setPoints(const std::vector<QPoint>& newPoints)
{
    m_points = newPoints;
}

void Polyline::addPoint(const QPoint& point)
{
    m_points.push_back(point);
}

/* Render */
void Polyline::draw(QPainter& qp) const
{
    applyProps(qp);
    qp.drawPolyline(m_points.data(), static_cast<int>(m_points.size()));
}

/* Polyline Information */
double Polyline::area() const
{
    return 0;
}

double Polyline::perimeter() const
{
    return 0;
}

QString Polyline::toString() const
{
    QString id = QString::number(getId());
    QString type = "Polyline";
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
