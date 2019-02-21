#include "Shape.hpp"

namespace jbrush
{
/* Static Variables */
uint32_t Shape::nextId = 0;

/* Constructors */
Shape::Shape(const QPoint& pos)
    : m_position(pos), m_id(nextId)
{
    nextId++;
}

/* Destructor */
Shape::~Shape()
{}

/* Position */
QPoint Shape::getPosition() const
{
    return m_position;
}

void Shape::setPosition(const QPoint& point)
{
    m_position = point;
}

/* Shape Information */
uint Shape::getId() const
{
    return m_id;
}

/* Operators */
bool Shape::operator==(const Shape& as) const
{
    return m_id == as.m_id;
}

bool Shape::operator!=(const Shape& as) const
{
    return m_id != as.m_id;
}

/* Predicates */
bool Shape::compareId(const Shape* a, const Shape* b)
{
    return a->getId() < b->getId();
}

bool Shape::compareArea(const Shape* a, const Shape* b)
{
    return a->area() < b->area();
}

bool Shape::comparePerimeter(const Shape* a, const Shape* b)
{
    return a->perimeter() < b->perimeter();
}
}
