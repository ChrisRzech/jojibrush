#pragma once
#include "GeometricShape.hpp"

namespace jbrush 
{
class FilledShape : public GeometricShape
{
protected:
    /* Constructor */
    FilledShape(const QPoint&, FillProperties);

public:
    /* Getters */
    FillProperties getFillProps() const;

    /* Setters */
    void setFillProps(FillProperties);

protected:
    /* Properties */
    virtual void applyProps(QPainter&) const;
    virtual QString toStringProps() const;

    FillProperties m_fillProps;
};
}
