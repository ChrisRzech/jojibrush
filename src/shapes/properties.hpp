#pragma once
#include <QPen>
#include <QFont>

namespace jbrush
{
struct BorderProperties
{
    Qt::GlobalColor penColor = Qt::GlobalColor::black;
    int penWidth = 1;
    Qt::PenStyle penStyle = Qt::PenStyle::SolidLine;
    Qt::PenCapStyle penCapStyle = Qt::PenCapStyle::FlatCap;
    Qt::PenJoinStyle penJoinStyle = Qt::PenJoinStyle::MiterJoin;
};

struct FillProperties
{
    BorderProperties border;
    Qt::GlobalColor brushColor = Qt::GlobalColor::black;
    Qt::BrushStyle brushStyle = Qt::BrushStyle::NoBrush;
};

struct TextProperties
{
    Qt::GlobalColor textColor = Qt::GlobalColor::black;
    Qt::AlignmentFlag textAlignment = Qt::AlignmentFlag::AlignLeft;
    int textSize = 12;
    QString textFontFamily = "Comic Sans MS";
    QFont::Style textFontStyle = QFont::Style::StyleNormal;
    QFont::Weight textFontWeight = QFont::Weight::Normal;
};
}
