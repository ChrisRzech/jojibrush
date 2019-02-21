#include "Canvas.hpp"
#include "utils/exceptions.hpp"
#include "utils/filehandler.hpp"

namespace jbrush
{
/* Constructors */
Canvas::Canvas(QWidget* parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    m_drawID = false;
    m_polygon = nullptr;
    m_polyline = nullptr;
    m_line = nullptr;
    m_rect = nullptr;
    m_ellipse = nullptr;
    m_text = nullptr;
}

/* Destructor */
Canvas::~Canvas()
{
    clearShapes();
}

/* Getters */
std::vector<Shape*> Canvas::getShapes()
{
    return m_shapes;
}

/* Setters */
void Canvas::setDrawShapeIds(bool value)
{
    m_drawID = value;
    repaint();
}

void Canvas::setShapeType(constants::ShapeType type)
{
    m_type = type;
    repaint();
}

void Canvas::setBorderProperties(BorderProperties props)
{
    m_borderProps = props;
    repaint();
}

void Canvas::setFillProperties(FillProperties props)
{
    m_fillProps = props;
    repaint();
}

void Canvas::setTextProperties(TextProperties props)
{
    m_textProps = props;
    repaint();
}

/* Files */
bool Canvas::loadFromFile(QString &fileDir)
{
    std::vector<Shape*> shapes = filehandler::loadShapesFromFile(fileDir);

    if(!shapes.empty())
    {
        clearShapes();
        m_shapes = shapes;
        repaint();

        return true;
    }

    return false;
}

/* Shapes */
void Canvas::addShape(Shape* shape)
{
    m_shapes.push_back(shape);
    repaint();
}

void Canvas::removeShape(uint id)
{
    for(auto i = m_shapes.begin(); i < m_shapes.end(); ++i)
    {
        if((*i)->getId() == id)
        {
            m_shapes.erase(i);
            return;
        }
    }
}

void Canvas::clearShapes()
{
    for(Shape* shape : m_shapes)
    {
        delete shape;
    }

    m_shapes.clear();

    repaint();
}

/* Public slots */
void Canvas::updateShapeType(constants::ShapeType type)
{
    m_type = type;
    m_line = nullptr;
    m_rect = nullptr;
    m_ellipse = nullptr;
    m_polygon = nullptr;
    m_polyline = nullptr;
    m_text = nullptr;

}

void Canvas::updateBorderProperties(BorderProperties props)
{
    m_borderProps = props;

    switch(m_type)
    {
    case constants::ShapeType::LINE:
        m_line->setBorderProps(props);
        break;
    case constants::ShapeType::RECTANGLE:
        m_rect->setBorderProps(props);
        break;
    case constants::ShapeType::ELLIPSE:
        m_ellipse->setBorderProps(props);
        break;
    case constants::ShapeType::POLYGON:
        m_polygon->setBorderProps(props);
        break;
    case constants::ShapeType::POLYLINE:
        m_polyline->setBorderProps(props);
        break;
    default:
        break;
    }

    repaint();
}

void Canvas::updateFillProperties(FillProperties props)
{
    m_fillProps = props;

    switch(m_type)
    {
    case constants::ShapeType::RECTANGLE:
        m_rect->setFillProps(props);
        break;
    case constants::ShapeType::ELLIPSE:
        m_ellipse->setFillProps(props);
        break;
    case constants::ShapeType::POLYGON:
        m_polygon->setFillProps(props);
        break;
    default:
        break;
    }

    repaint();
}

void Canvas::updateTextProperties(TextProperties props)
{
    m_textProps = props;
    m_text->setTextProps(props);
    repaint();
}

/* Event handlers */
void Canvas::mousePressEvent(QMouseEvent* event)
{
    if(Account::type != Account::Type::ADMIN)
        return;

    QPoint point = event->pos();

    switch(m_type)
    {
    case constants::ShapeType::LINE:
        m_line = new Line(point, point, m_borderProps);
        addShape(m_line);
        break;
    case constants::ShapeType::POLYLINE:
        if(m_polyline == nullptr)
        {
            m_polygon = nullptr;
            m_polyline = new Polyline(point, m_borderProps);
            addShape(m_polyline);
        }
        else
        {
            m_polyline->addPoint(point);
        }
        break;
    case constants::ShapeType::POLYGON:
        if(m_polygon == nullptr)
        {
            m_polyline = nullptr;
            m_polygon = new Polygon(point, m_fillProps);
            addShape(m_polygon);
        }
        else
        {
            m_polygon->addPoint(point);
        }
        break;
    case constants::ShapeType::RECTANGLE:
        m_rect = new Rectangle(point, point, m_fillProps);
        addShape(m_rect);
        break;
    case constants::ShapeType::ELLIPSE:
        m_ellipse = new Ellipse(point, 0, 0, m_fillProps);
        addShape(m_ellipse);
        break;
    case constants::ShapeType::TEXT:
        m_text = new Text(point, 100, 100, "", m_textProps);
        addShape(m_text);
        break;
    }

    repaint();
}

void Canvas::mouseMoveEvent(QMouseEvent* event)
{
    if(Account::type != Account::Type::ADMIN)
        return;

    QPoint point = event->pos();

    switch(m_type)
    {
    case constants::ShapeType::LINE:
        m_line->setEnd(point);
        break;
    case constants::ShapeType::RECTANGLE:
        m_rect->setHeight(point.y() - m_rect->getPosition().y());
        m_rect->setWidth(point.x() - m_rect->getPosition().x());
        break;
    case constants::ShapeType::ELLIPSE:
        m_ellipse->setHeight(point.y() - m_ellipse->getPosition().y());
        m_ellipse->setWidth(point.x() - m_ellipse->getPosition().x());
        break;
    case constants::ShapeType::TEXT:
        m_text->setWidth(point.x() - m_text->getPosition().x());
        m_text->setHeight(point.y() - m_text->getPosition().y());
        m_text->setText("Hello World");
        break;
    case constants::ShapeType::POLYGON:
    {
        std::vector<QPoint> points = m_polygon->getPoints();
        m_polygon->setPoint(points.size() - 1, point);
        break;
    }
    case constants::ShapeType::POLYLINE:
    {
        std::vector<QPoint> points = m_polyline->getPoints();
        m_polyline->setPoint(points.size() - 1, point);
        break;
    }
    }

    repaint();
}

void Canvas::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    for(Shape* shape : m_shapes)
    {
        shape->draw(painter);

        //Resets the pen to default QPen
        painter.setPen(QPen());

        if(m_drawID)
        {
            painter.drawText(shape->getPosition(), "#" + QString::number(shape->getId()));
        }
    }

    painter.end();
}
}
