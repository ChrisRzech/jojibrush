#include "ShapeSelectMenu.hpp"
#include "ui_ShapeSelectMenu.h"
using jbrush::constants::ShapeType;

/* Constructors */
ShapeSelectMenu::ShapeSelectMenu(QWidget *parent)
    : QWidget(parent), m_ui(new Ui::ShapeSelectMenu), m_selected(ShapeType::LINE)
{
    m_ui->setupUi(this);

    /* Initial shape */
    m_selected = ShapeType::LINE;
}

/* Destructor */
ShapeSelectMenu::~ShapeSelectMenu()
{
    delete m_ui;
}

/* Getters */
ShapeType ShapeSelectMenu::getSelected() const
{
    return m_selected;
}

/* Private slots */
void ShapeSelectMenu::on_pushButtonLine_clicked()
{
    m_selected = ShapeType::LINE;
    onSelection(m_selected);

    //Set this button's icon to its respective selected icon
    m_ui->pushButtonLine->setIcon(QIcon(":/res/menus/shapeselect/line_selected.png"));

    /* Change the non selected icons to their respective unselected icons */
    m_ui->pushButtonRectangle->setIcon(QIcon(":/res/menus/shapeselect/rectangle_unselected.png"));
    m_ui->pushButtonEllipse->setIcon(QIcon(":/res/menus/shapeselect/ellipse_unselected.png"));
    m_ui->pushButtonText->setIcon(QIcon(":/res/menus/shapeselect/text_unselected.png"));
    m_ui->pushButtonPolyline->setIcon(QIcon(":/res/menus/shapeselect/polyline_unselected.png"));
    m_ui->pushButtonPolygon->setIcon(QIcon(":/res/menus/shapeselect/polygon_unselected.png"));
}

void ShapeSelectMenu::on_pushButtonRectangle_clicked()
{
    m_selected = ShapeType::RECTANGLE;
    onSelection(m_selected);

    //Set this button's icon to its respective selected icon
    m_ui->pushButtonRectangle->setIcon(QIcon(":/res/menus/shapeselect/rectangle_selected.png"));

    /* Change the non selected icons to their respective unselected icons */
    m_ui->pushButtonLine->setIcon(QIcon(":/res/menus/shapeselect/line_unselected.png"));
    m_ui->pushButtonEllipse->setIcon(QIcon(":/res/menus/shapeselect/ellipse_unselected.png"));
    m_ui->pushButtonText->setIcon(QIcon(":/res/menus/shapeselect/text_unselected.png"));
    m_ui->pushButtonPolyline->setIcon(QIcon(":/res/menus/shapeselect/polyline_unselected.png"));
    m_ui->pushButtonPolygon->setIcon(QIcon(":/res/menus/shapeselect/polygon_unselected.png"));
}

void ShapeSelectMenu::on_pushButtonEllipse_clicked()
{
    m_selected = ShapeType::ELLIPSE;
    onSelection(m_selected);

    //Set this button's icon to its respective selected icon
    m_ui->pushButtonEllipse->setIcon(QIcon(":/res/menus/shapeselect/ellipse_selected.png"));

    /* Change the non selected icons to their respective unselected icons */
    m_ui->pushButtonLine->setIcon(QIcon(":/res/menus/shapeselect/line_unselected.png"));
    m_ui->pushButtonRectangle->setIcon(QIcon(":/res/menus/shapeselect/rectangle_unselected.png"));
    m_ui->pushButtonText->setIcon(QIcon(":/res/menus/shapeselect/text_unselected.png"));
    m_ui->pushButtonPolyline->setIcon(QIcon(":/res/menus/shapeselect/polyline_unselected.png"));
    m_ui->pushButtonPolygon->setIcon(QIcon(":/res/menus/shapeselect/polygon_unselected.png"));
}

void ShapeSelectMenu::on_pushButtonText_clicked()
{
    m_selected = ShapeType::TEXT;
    onSelection(m_selected);

    //Set this button's icon to its respective selected icon
    m_ui->pushButtonText->setIcon(QIcon(":/res/menus/shapeselect/text_selected.png"));

    /* Change the non selected icons to their respective unselected icons */
    m_ui->pushButtonLine->setIcon(QIcon(":/res/menus/shapeselect/line_unselected.png"));
    m_ui->pushButtonRectangle->setIcon(QIcon(":/res/menus/shapeselect/rectangle_unselected.png"));
    m_ui->pushButtonEllipse->setIcon(QIcon(":/res/menus/shapeselect/ellipse_unselected.png"));
    m_ui->pushButtonPolyline->setIcon(QIcon(":/res/menus/shapeselect/polyline_unselected.png"));
    m_ui->pushButtonPolygon->setIcon(QIcon(":/res/menus/shapeselect/polygon_unselected.png"));
}

void ShapeSelectMenu::on_pushButtonPolyline_clicked()
{
    m_selected = ShapeType::POLYLINE;
    onSelection(m_selected);

    //Set this button's icon to its respective selected icon
    m_ui->pushButtonPolyline->setIcon(QIcon(":/res/menus/shapeselect/polyline_selected.png"));

    /* Change the non selected icons to their respective unselected icons */
    m_ui->pushButtonLine->setIcon(QIcon(":/res/menus/shapeselect/line_unselected.png"));
    m_ui->pushButtonRectangle->setIcon(QIcon(":/res/menus/shapeselect/rectangle_unselected.png"));
    m_ui->pushButtonEllipse->setIcon(QIcon(":/res/menus/shapeselect/ellipse_unselected.png"));
    m_ui->pushButtonText->setIcon(QIcon(":/res/menus/shapeselect/text_unselected.png"));
    m_ui->pushButtonPolygon->setIcon(QIcon(":/res/menus/shapeselect/polygon_unselected.png"));
}

void ShapeSelectMenu::on_pushButtonPolygon_clicked()
{
    m_selected = ShapeType::POLYGON;
    onSelection(m_selected);

    //Set this button's icon to its respective selected icon
    m_ui->pushButtonPolygon->setIcon(QIcon(":/res/menus/shapeselect/polygon_selected.png"));

    /* Change the non selected icons to their respective unselected icons */
    m_ui->pushButtonLine->setIcon(QIcon(":/res/menus/shapeselect/line_unselected.png"));
    m_ui->pushButtonRectangle->setIcon(QIcon(":/res/menus/shapeselect/rectangle_unselected.png"));
    m_ui->pushButtonEllipse->setIcon(QIcon(":/res/menus/shapeselect/ellipse_unselected.png"));
    m_ui->pushButtonText->setIcon(QIcon(":/res/menus/shapeselect/text_unselected.png"));
    m_ui->pushButtonPolyline->setIcon(QIcon(":/res/menus/shapeselect/polyline_unselected.png"));
}
