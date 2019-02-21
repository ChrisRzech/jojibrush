#pragma once
#include <QPoint>
#include <QString>
#include <QPainter>
#include <QtMath>

using uint = unsigned int;

namespace jbrush
{
class Shape
{
public:
    /* Constructors */
    Shape(const QPoint&);

    /* Destructor */
    virtual ~Shape();

    /* Getters */
    uint getId() const;
    QPoint getPosition() const;

    /* Setters */
    void setPosition(const QPoint&);

    /* Render */
    virtual void draw(QPainter&) const = 0;

    /* Shape Information */
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual QString toString() const = 0;

    /* Operators */
    bool operator==(const Shape&) const;
    bool operator!=(const Shape&) const;

    /* Predicates */
    static bool compareId(const Shape*, const Shape*);
    static bool compareArea(const Shape*, const Shape*);
    static bool comparePerimeter(const Shape*, const Shape*);

    /* Deleted Members */
    Shape(const Shape&) = delete;
    void operator=(const Shape&) = delete;

protected:
    /* Shape Data */
    QPoint m_position;

private:
    /* Static Variables */
    static uint nextId;

    /* Shape Data */
    uint m_id;
};
}
