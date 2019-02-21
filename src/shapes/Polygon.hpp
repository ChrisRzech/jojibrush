#pragma once
#include "FilledShape.hpp"

namespace jbrush
{
class Polygon final : public FilledShape
{
public:
    /* Constructors */
    Polygon(const std::vector<QPoint>&, FillProperties);
    Polygon(const QPoint&, FillProperties);

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
