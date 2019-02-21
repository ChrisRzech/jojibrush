#include "filehandler.hpp"
#include <QTextStream>
#include "exceptions.hpp"
#include "constants.hpp"
using std::vector;

namespace jbrush
{
namespace filehandler
{
QString extractShapeType(QTextStream&);
vector<int> extractDimensions(QTextStream&);
BorderProperties extractBorderProps(QTextStream&);
FillProperties extractFillProps(QTextStream&);
TextProperties extractTextProps(QTextStream&);

vector<QPoint> getPoints(const vector<int>&);

GeometricShape* createGeoShape(const QString&, const vector<int>& dimensions, const BorderProperties&);
FilledShape* createFilledShape(const QString&, const vector<int>& dimensions, const FillProperties&);
Text* createText(const QString&, const vector<int>& dimensions, const TextProperties&);

void getToChar(QTextStream&, char);

void saveShapesToFile(const vector<Shape*>& shapes, const QString& fileString)
{
    QFile file(fileString);
    QTextStream qin(&file);

    file.open(QIODevice::WriteOnly);

    for(auto shape : shapes)
    {
        qin << shape->toString();
        qin << endl;
    }

    file.close();
}

vector<Shape*> loadShapesFromFile(const QString& fileString)
{
    QFile file(fileString);
    QTextStream qin(&file);
    vector<Shape*> shapes;

    try
    {
        if(!file.open(QIODevice::ReadOnly))
        {
           throw BadFile(file);
        }

        Shape* shape;
        QString shapeType;
        vector<int> dimensions;
        BorderProperties borderProps;
        FillProperties filledProps;
        TextProperties textProps;
        QString textMsg;

        while(!qin.atEnd())
        {
            //Ignore the shape id
            qin.readLine();

            shapeType = extractShapeType(qin);
            dimensions = extractDimensions(qin);


            /* Extract properties depending on the shape type */
            if(shapeType == constants::TEXT)
            {
                getToChar(qin, constants::TITLE_INTERRUPTOR);
                textMsg = qin.readLine().trimmed();
                textProps = extractTextProps(qin);
            }
            else if(shapeType == constants::POLYLINE || shapeType == constants::LINE)
            {
                borderProps = extractBorderProps(qin);
            }
            else
            {
                filledProps = extractFillProps(qin);
            }

            //Read the empty line between the shapes
            qin.readLine();
            qin.readLine();

            /* Construct the shape */
            if(shapeType == constants::TEXT)
            {
                shape = createText(textMsg, dimensions, textProps);
            }
            else if(shapeType == constants::LINE || shapeType == constants::POLYLINE)
            {
                shape = createGeoShape(shapeType, dimensions, borderProps);
            }
            else
            {
                shape = createFilledShape(shapeType, dimensions, filledProps);
            }

            shapes.push_back(shape);
        }

        file.close();
    }
    catch(GeneralException& exception)
    {
        /* Delete allocated shapes */
        for(auto shape : shapes)
        {
            delete shape;
        }

        shapes.clear();

        exception.errorWindow();
    }

    return shapes;
}

QString extractShapeType(QTextStream& qin)
{
    /* Get to the shape type then read it */
    getToChar(qin, constants::TITLE_INTERRUPTOR);
    QString shapeType = qin.readLine().trimmed();

    if(qin.atEnd())
    {
        throw BadFileFormat("Unexpected end of file!");
    }

    //If the shape type is invalid, throw an exception
    if(constants::TYPE_LIST.indexOf(shapeType) == -1)
    {
        throw BadFileFormat("Shape type name", shapeType);
    }

    return shapeType;
}

vector<int> extractDimensions(QTextStream& qin)
{
    vector<int> dimensionsList;
    char buffer = '\0';

    //Get ready to read in dimensions
    getToChar(qin, constants::TITLE_INTERRUPTOR);

    /* Keep reading integers until EOL or EOF is reached */
    while(buffer != '\r' && buffer != '\n' && !qin.atEnd())
    {
        int dimension;
        qin >> dimension;
        dimensionsList.push_back(dimension);

        qin >> buffer;
    }

    return dimensionsList;
}

BorderProperties extractBorderProps(QTextStream& qin)
{
    BorderProperties props;
    QString bufferString;
    int bufferInt;

    //Extract the color of the pen
    getToChar(qin, constants::TITLE_INTERRUPTOR);
    qin >> bufferString;
    props.penColor = constants::COLOR_MAP[bufferString];

    //Extract the width of the pen
    getToChar(qin, constants::TITLE_INTERRUPTOR);
    qin >> bufferInt;
    props.penWidth = uint8_t(bufferInt);

    //Extract the pen's style
    getToChar(qin, constants::TITLE_INTERRUPTOR);
    qin >> bufferString;
    props.penStyle = constants::PEN_STYLE_MAP[bufferString];

    //Extract the pen cap style
    getToChar(qin, constants::TITLE_INTERRUPTOR);
    qin >> bufferString;
    props.penCapStyle = constants::PEN_CAP_MAP[bufferString];

    //Extract the join style for the pen
    getToChar(qin, constants::TITLE_INTERRUPTOR);
    qin >> bufferString;
    props.penJoinStyle = constants::PEN_JOIN_MAP[bufferString];

    return props;
}

FillProperties extractFillProps(QTextStream& qin)
{
    FillProperties props;
    QString bufferString;

    //Extract properties for the border of the shape
    props.border = extractBorderProps(qin);

    //Extract the color for the brush
    getToChar(qin, constants::TITLE_INTERRUPTOR);
    qin >> bufferString;
    props.brushColor = constants::COLOR_MAP[bufferString];

    //Extract the style for the brush
    getToChar(qin, constants::TITLE_INTERRUPTOR);
    qin >> bufferString;
    props.brushStyle = constants::BRUSH_STYLE_MAP[bufferString];

    return props;
}

TextProperties extractTextProps(QTextStream& qin)
{
    TextProperties props;
    int pointSize; //Temporary storage for an integer
    QString stringExtracted; //Temporary storage for a string

    //Extract text's color
    getToChar(qin, constants::TITLE_INTERRUPTOR);
    qin >> stringExtracted;
    props.textColor = constants::COLOR_MAP[stringExtracted];

    //Extract text's alignment
    getToChar(qin, constants::TITLE_INTERRUPTOR);
    qin >> stringExtracted;
    props.textAlignment = constants::TEXT_ALIGN_MAP[stringExtracted];

    //Get text size
    getToChar(qin, constants::TITLE_INTERRUPTOR);
    qin >> pointSize;
    props.textSize = int8_t(pointSize);

    //Get font family
    getToChar(qin, constants::TITLE_INTERRUPTOR);
    props.textFontFamily = qin.readLine().trimmed();

    //Get font style
    getToChar(qin, constants::TITLE_INTERRUPTOR);
    qin >> stringExtracted;
    props.textFontStyle = constants::TEXT_STYLE_MAP[stringExtracted];

    //Get font weight
    getToChar(qin, constants::TITLE_INTERRUPTOR);
    qin >> stringExtracted;
    props.textFontWeight = constants::TEXT_WEIGHT_MAP[stringExtracted];

    return props;
}

vector<QPoint> getPoints(const vector<int>& dimensions)
{
    uint totalPoints = dimensions.size() / 2;
    vector<QPoint> points(totalPoints);

    /* Groups the dimensions together as points */
    for(uint i = 0; i < totalPoints; i++)
    {
        QPoint point(dimensions[i * 2], dimensions[(i * 2) + 1]);
        points[i] = point;
    }

    return points;
}

void getToChar(QTextStream& qin, char target)
{
    char buffer = '\0';

    /* Eats up the buffer including the target */
    while(buffer != target && !qin.atEnd())
    {
        qin >> buffer;
    }
}

Text* createText(const QString& msg, const vector<int>& dimensions, const TextProperties& props)
{
    QPoint center(dimensions[0], dimensions[1]);
    int width = dimensions[2];
    int height = dimensions[3];
    return new Text(center, width, height, msg, props);
}

GeometricShape* createGeoShape(const QString& type, const vector<int>& dimensions, const BorderProperties& props)
{
    vector<QPoint> points = getPoints(dimensions);

    if(type == constants::LINE)
    {
        return new Line(points[0], points[1], props);
    }
    else if(type == constants::POLYLINE)
    {
        return new Polyline(points, props);
    }
    else
    {
        throw BadFileFormat("Shape type", type);
    }
}

FilledShape* createFilledShape(const QString& type, const vector<int>& dimensions, const FillProperties& props)
{
    QPoint position(dimensions[0], dimensions[1]);
    int width = dimensions[2];
    int height = dimensions[3];

    if(type == constants::ELLIPSE)
    {
        return new Ellipse(position, width, height, props);
    }
    else if(type == constants::RECTANGLE)
    {
        return new Rectangle(position, width, height, props);
    }
    else if(type == constants::POLYGON)
    {
        return new Polygon(getPoints(dimensions), props);
    }
    else
    {
        throw BadFileFormat("Shape type", type);
    }
}
}
}
