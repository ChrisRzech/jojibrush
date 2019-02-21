#pragma once
#include "FilledShape.hpp"

namespace jbrush
{
class Rectangle final : public FilledShape
{
public:
    /* Constructors */
    Rectangle(const QPoint& topL, const QPoint& botR, FillProperties);
    Rectangle(const QPoint& topL, int width, int height, FillProperties);
    Rectangle(int x, int y, int width, int height, FillProperties);

    /* Getters */
    int getWidth() const;
    int getHeight() const;

    /* Setters */
    void setWidth(int);
    void setHeight(int);

    /* Render */
    virtual void draw(QPainter&) const override;

    /* Rect Information */
    virtual double area() const override;
    virtual double perimeter() const override;
    virtual QString toString() const override;

private:
    int m_width;
    int m_height;
};
}
