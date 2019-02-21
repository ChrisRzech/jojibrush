#pragma once
#include "FilledShape.hpp"

namespace jbrush
{
class Ellipse final : public FilledShape
{
public:
    /* Constructors (bounding box) */
    Ellipse(const QPoint& topL, const QPoint& botR, FillProperties);
    Ellipse(const QPoint& topL, int width, int height, FillProperties);

    /* Constructors (center point) */
    Ellipse(int x, int y, int width, int height, FillProperties);

    /* Getters */
    int getWidth() const;
    int getHeight() const;

    /* Setters */
    void setWidth(int);
    void setHeight(int);

    /* Render */
    virtual void draw(QPainter&) const override;

    /* Ellipse Information */
    virtual double area() const override;
    virtual double perimeter() const override;
    virtual QString toString() const override;

private:
    int m_width;
    int m_height;
};
}
