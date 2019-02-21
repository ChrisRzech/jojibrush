#pragma once
#include "Shape.hpp"
#include "properties.hpp"

namespace jbrush
{
class GeometricShape : public Shape
{
protected:
    /* Constructor */
    GeometricShape(const QPoint&, BorderProperties);

public:
    /* Getters */
    BorderProperties getBorderProps() const;

    /* Setters */
    void setBorderProps(BorderProperties);

protected:
    /* Properties */
    virtual void applyProps(QPainter&) const;
    virtual QString toStringProps() const;

    BorderProperties m_borderProps;
};
}
