#pragma once
#include <QMap>
#include <QString>
#include <QFont>

namespace jbrush
{
namespace constants
{
const QString FILE_TYPE = "Jojibrush files (*.jbrush)";

const char TITLE_INTERRUPTOR = ':'; //Character at the end of titlesv

// Enum class contains shape types that can be selected and created by the administrator
enum class ShapeType
{
    LINE, POLYLINE, POLYGON,
    RECTANGLE, ELLIPSE, TEXT
};

const QString LINE = "Line";
const QString POLYLINE = "Polyline";
const QString POLYGON = "Polygon";
const QString RECTANGLE = "Rectangle";
const QString ELLIPSE = "Ellipse";
const QString TEXT = "Text";
const QStringList TYPE_LIST = {LINE, POLYLINE, POLYGON, RECTANGLE, ELLIPSE, TEXT};

const QMap<QString, Qt::GlobalColor> COLOR_MAP =
{
    {"white", Qt::GlobalColor::white}, {"black", Qt::GlobalColor::black}, {"red", Qt::GlobalColor::red},
    {"green", Qt::GlobalColor::green}, {"blue", Qt::GlobalColor::blue}, {"cyan", Qt::GlobalColor::cyan},
    {"magenta", Qt::GlobalColor::magenta}, {"yellow", Qt::GlobalColor::yellow}, {"gray", Qt::GlobalColor::gray}
};

const QMap<QString, Qt::PenStyle> PEN_STYLE_MAP =
{
    {"NoPen", Qt::NoPen}, {"SolidLine", Qt::SolidLine}, {"DashLine", Qt::DashLine},
    {"DotLine", Qt::DotLine}, {"DashDotLine", Qt::DashDotLine}, {"DashDotDotLine", Qt::DashDotDotLine},
    {"CustomDashLine", Qt::CustomDashLine}
};

const QMap<QString, Qt::PenCapStyle> PEN_CAP_MAP =
{
    {"SquareCap", Qt::SquareCap}, {"FlatCap", Qt::FlatCap}, {"RoundCap", Qt::RoundCap}
};

const QMap<QString, Qt::PenJoinStyle> PEN_JOIN_MAP =
{
    {"BevelJoin", Qt::BevelJoin}, {"MiterJoin", Qt::MiterJoin}, {"RoundJoin", Qt::RoundJoin}
};

const QMap<QString, Qt::BrushStyle> BRUSH_STYLE_MAP =
{
    {"SolidPattern", Qt::SolidPattern}, {"Dense1Pattern", Qt::Dense1Pattern}, {"Dense2Pattern", Qt::Dense2Pattern},
    {"Dense3Pattern", Qt::Dense3Pattern}, {"Dense4Pattern", Qt::Dense4Pattern}, {"Dense5Pattern", Qt::Dense5Pattern},
    {"Dense6Pattern", Qt::Dense6Pattern}, {"Dense7Pattern", Qt::Dense7Pattern}, {"NoBrush", Qt::NoBrush},
    {"HorPattern", Qt::HorPattern}, {"VerPattern", Qt::VerPattern}, {"CrossPattern", Qt::CrossPattern},
    {"BDiagPattern", Qt::BDiagPattern}, {"FDiagPattern", Qt::FDiagPattern}, {"DiagCrossPattern", Qt::DiagCrossPattern},
    {"LinearGradientPattern", Qt::LinearGradientPattern}, {"LinearGradientPattern", Qt::LinearGradientPattern}, {"ConicalGradientPattern", Qt::ConicalGradientPattern}
};

const QMap<QString, Qt::AlignmentFlag> TEXT_ALIGN_MAP =
{
    {"AlignLeft", Qt::AlignLeft}, {"AlignRight", Qt::AlignRight}, {"AlignTop", Qt::AlignTop},
    {"AlignBottom", Qt::AlignBottom}, {"AlignCenter", Qt::AlignCenter}
};

const QMap<QString, QFont::Style> TEXT_STYLE_MAP =
{
    {"StyleNormal", QFont::StyleNormal}, {"StyleItalic", QFont::StyleItalic}, {"StyleOblique", QFont::StyleOblique}
};

const QMap<QString, QFont::Weight> TEXT_WEIGHT_MAP =
{
    {"Thin", QFont::Thin}, {"ExtraLight", QFont::ExtraLight}, {"Light", QFont::Light},
    {"Normal", QFont::Normal}, {"Medium", QFont::Medium}, {"DemiBold", QFont::DemiBold},
    {"Bold", QFont::Bold}, {"ExtraBold", QFont::ExtraBold}, {"Black", QFont::Black},
};
}
}
