#include "Text.hpp"

namespace jbrush
{
/* Constructors */
Text::Text(const QPoint& pos, int width, int height, const QString& msg, TextProperties props)
    : Shape(pos), m_width(width), m_height(height), m_text(msg), m_props(props)
{}

/* Getters */
QString Text::getText() const
{
    return m_text;
}

int Text::getWidth() const
{
    return m_width;
}

int Text::getHeight() const
{
    return m_height;
}

TextProperties Text::getTextProps() const
{
    return m_props;
}

/* Setters */
void Text::setText(const QString& txt)
{
    m_text = txt;
}

void Text::setWidth(int w)
{
    m_width = w;
}

void Text::setHeight(int h)
{
    m_height = h;
}

void Text::setTextProps(TextProperties props)
{
    m_props = props;
}

/* Text modifiers */
void Text::addChar(char ch)
{
    m_text += ch;
}

void Text::popChar()
{
    m_text.truncate(m_text.size() - 2);
}

/* Render */
void Text::draw(QPainter& qp) const
{
    applyProps(qp);
    qp.drawText(m_position.x(), m_position.y(), m_width, m_height, m_props.textAlignment, m_text);
}

/* Text Information */
double Text::area() const
{
    return 0;
}

double Text::perimeter() const
{
    return 0;
}

QString Text::toString() const
{
    QString id = QString::number(getId());
    QString type = "Text";
    QString dim = QString::number(m_position.x()) + " " +
                  QString::number(m_position.y()) + " " +
                  QString::number(m_width)        + " " +
                  QString::number(m_height);

    return "Shape Id: "        + id   + "\r\n" +
           "ShapeType: "       + type + "\r\n" +
           "ShapeDimensions: " + dim  + "\r\n" +
           toStringProps();
}

/* Properties */
void Text::applyProps(QPainter& qp) const
{
    qp.setPen(m_props.textColor); // QFont doesn't have a color cuz dumb dumb (cmon david be professional)
    QFont font;

    font.setPointSize(m_props.textSize);
    font.setFamily(m_props.textFontFamily);
    font.setStyle(m_props.textFontStyle);

    qp.setFont(font);
}

QString Text::toStringProps() const
{
    QString textColor;
    QString textAlignment;
    QString textPointSize = QString::number(m_props.textSize);
    QString textFontFamily = m_props.textFontFamily;
    QString textFontStyle;
    QString textFontWeight;

    switch(m_props.textColor)
    {
    case Qt::GlobalColor::white:
        textColor = "white";
        break;
    case Qt::GlobalColor::black:
        textColor = "black";
        break;
    case Qt::GlobalColor::red:
        textColor = "red";
        break;
    case Qt::GlobalColor::green:
        textColor = "green";
        break;
    case Qt::GlobalColor::blue:
        textColor = "blue";
        break;
    case Qt::GlobalColor::cyan:
        textColor = "cyan";
        break;
    case Qt::GlobalColor::magenta:
        textColor = "magenta";
        break;
    case Qt::GlobalColor::yellow:
        textColor = "yellow";
        break;
    case Qt::GlobalColor::gray:
        textColor = "gray";
        break;
    default: //Gets rid of the warnings
        break;
    }

    switch(m_props.textAlignment)
    {
    case Qt::AlignmentFlag::AlignLeft:
        textAlignment = "AlignLeft";
        break;
    case Qt::AlignmentFlag::AlignRight:
        textAlignment = "AlignRight";
        break;
    case Qt::AlignmentFlag::AlignTop:
        textAlignment = "AlignTop";
        break;
    case Qt::AlignmentFlag::AlignBottom:
        textAlignment = "AlignBottom";
        break;
    case Qt::AlignmentFlag::AlignCenter:
        textAlignment = "AlignCenter";
        break;
    default: //Gets rid of the warnings
        break;
    }

    switch(m_props.textFontStyle)
    {
    case QFont::Style::StyleNormal:
        textFontStyle = "StyleNormal";
        break;
    case QFont::Style::StyleItalic:
        textFontStyle = "StyleItalic";
        break;
    case QFont::Style::StyleOblique:
        textFontStyle = "StyleOblique";
        break;
    }

    switch(m_props.textFontWeight)
    {
    case QFont::Weight::Thin:
        textFontWeight = "Thin";
        break;
    case QFont::Weight::Light:
        textFontWeight = "Light";
        break;
    case QFont::Weight::Normal:
        textFontWeight = "Normal";
        break;
    case QFont::Weight::Bold:
        textFontWeight = "Bold";
        break;
    default: //Gets rid of the warnings
        break;
    }

    return "TextColor: "      + textColor      + "\r\n"
           "TextAlignment: "  + textAlignment  + "\r\n" +
           "TextPointSize: "  + textPointSize  + "\r\n" +
           "TextFontFamily: " + textFontFamily + "\r\n" +
           "TextFontStyle: "  + textFontStyle  + "\r\n" +
           "TextFontWeight: " + textFontWeight + "\r\n";
}
}
