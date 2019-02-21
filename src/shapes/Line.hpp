#pragma once
#include "GeometricShape.hpp"

namespace jbrush
{
class Line final : public GeometricShape
{
public:
    /* Constructors */
    Line(const QPoint& start, const QPoint& end, BorderProperties);
    Line(int x1, int y1, int x2, int y2, BorderProperties);

    /* Getters */
    QPoint getStart() const;
    QPoint getEnd() const;

    /* Setters */
    void setStart(const QPoint&);
    void setEnd(const QPoint&);

    /* Render */
    virtual void draw(QPainter&) const override;

    /* Line Information */
    virtual double area() const override;
    virtual double perimeter() const override;
    virtual QString toString() const override;

private:
    QPoint m_end;
};
}
