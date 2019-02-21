#pragma once
#include "GeometricShape.hpp"

namespace jbrush
{
class Polyline final : public GeometricShape
{
public:
    /* Constructors */
    Polyline(const std::vector<QPoint>&, BorderProperties);
    Polyline(const QPoint&, BorderProperties);

    /* Getters */
    std::vector<QPoint> getPoints() const;

    /* Setters */
    void setPoint(uint index, const QPoint&);
    void setPoints(const std::vector<QPoint>&);

    void addPoint(const QPoint&);

    /* Render */
    virtual void draw(QPainter&) const override;

    /* Polygon Information */
    virtual double area() const override;
    virtual double perimeter() const override;
    virtual QString toString() const override;

private:
    std::vector<QPoint> m_points;
};
}
