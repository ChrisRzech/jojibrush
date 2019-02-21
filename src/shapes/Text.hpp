#pragma once
#include "Shape.hpp"
#include "properties.hpp"

namespace jbrush
{
class Text final : public Shape
{
public:
    /* Constructor */
    Text(const QPoint&, int width, int height, const QString&, TextProperties);

    /* Getters */
    QString getText() const;
    int getWidth() const;
    int getHeight() const;
    TextProperties getTextProps() const;

    /* Setters */
    void setText(const QString&);
    void setWidth(int);
    void setHeight(int);
    void setTextProps(TextProperties);

    /* Text modifiers */
    void addChar(char);
    void popChar();

    /* Render */
    virtual void draw(QPainter&) const override;

    /* Text Information */
    virtual double area() const override;
    virtual double perimeter() const override;
    virtual QString toString() const override;

private:
    /* Properties */
    void applyProps(QPainter&) const;
    QString toStringProps() const;

    int m_width;
    int m_height;
    QString m_text;
    TextProperties m_props;
};
}
