#include <QFileDialog>
#include <QTextStream>
#include <algorithm>
#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "src/utils/filehandler.hpp"
#include "src/utils/constants.hpp"

/* Constructors */
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);

    /* Put widgets in their respective placeholders */
    m_canvas = new jbrush::Canvas(m_ui->canvasWidget);
    m_shapeSelectMenu = new ShapeSelectMenu(m_ui->shapeSelectMenuWidget);
    m_propsMenu = new PropertiesMenu(m_ui->shapePropertiesMenuWidget);
    m_textPropsMenu = new TextPropertiesMenu(m_ui->shapePropertiesMenuWidget);

    m_canvas->setGeometry(0, 0, width(), height());

    /* Initial properties */
    m_canvas->setShapeType(m_shapeSelectMenu->getSelected());
    m_canvas->setBorderProperties(m_propsMenu->getBorderPropertiesMenu()->getProperties());
    m_canvas->setFillProperties(m_propsMenu->getFillPropertiesMenu()->getProperties());
    m_canvas->setTextProperties(m_textPropsMenu->getProperties());

    updatePropertiesMenus();

    /* Signals will update when slots are triggered */
    connect(m_shapeSelectMenu, &ShapeSelectMenu::onSelection,
            this             , &MainWindow::updatePropertiesMenus);

    connect(m_shapeSelectMenu, &ShapeSelectMenu::onSelection,
            m_canvas         , &jbrush::Canvas::updateShapeType);

    connect(m_propsMenu->getBorderPropertiesMenu(), &BorderPropertiesMenu::onItemChanged,
            m_canvas                              , &jbrush::Canvas::updateBorderProperties);

    connect(m_propsMenu->getFillPropertiesMenu(), &FillPropertiesMenu::onItemChanged,
            m_canvas                            , &jbrush::Canvas::updateFillProperties);

    connect(m_textPropsMenu, &TextPropertiesMenu::onItemChanged,
            m_canvas       , &jbrush::Canvas::updateTextProperties);
}

/* Destructor */
MainWindow::~MainWindow()
{
    delete m_ui;
    delete m_canvas;
    delete m_shapeSelectMenu;
    delete m_propsMenu;
    delete m_textPropsMenu;
}

/* File */
void MainWindow::on_actionNew_triggered()
{
    m_canvas->clearShapes();
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileDir = QFileDialog::getOpenFileName(this, "Open", m_currentFile, jbrush::constants::FILE_TYPE);

    if(!fileDir.isEmpty())
    {
        if(m_canvas->loadFromFile(fileDir))
        {
            //If loading was successful, update the current file
            m_currentFile = fileDir;
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    if(!m_currentFile.isEmpty())
    {
        //Save to the current file
        jbrush::filehandler::saveShapesToFile(m_canvas->getShapes(), m_currentFile);
    }
    else
    {
        /* Ask for a new file */
        QString fileDir = QFileDialog::getSaveFileName(this, "Save", m_currentFile, jbrush::constants::FILE_TYPE);

        if(!fileDir.isEmpty())
        {
            jbrush::filehandler::saveShapesToFile(m_canvas->getShapes(), fileDir);
            m_currentFile = fileDir;
        }
    }
}

void MainWindow::on_actionSaveAs_triggered()
{
    QString fileDir = QFileDialog::getSaveFileName(this, "Save As", m_currentFile, jbrush::constants::FILE_TYPE);

    if(!fileDir.isEmpty())
    {
        jbrush::filehandler::saveShapesToFile(m_canvas->getShapes(), fileDir);

        if(!m_currentFile.isEmpty())
        {
            m_currentFile = fileDir;
        }
    }
}

void MainWindow::on_actionExport_triggered()
{
    QString imgDir;
    QPixmap pixmap = m_canvas->grab(m_canvas->rect());
    imgDir = QFileDialog::getSaveFileName(this, "Export image", nullptr, "Images (*.png *.jpg *.bmp)");
    pixmap.save(imgDir);
}

/* View */
void MainWindow::on_actionShowShapeID_toggled(bool checked)
{
    m_canvas->setDrawShapeIds(checked);
}

/* Reports */
void MainWindow::on_actionReportID_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save ID report", nullptr, "Text File (*.txt)");

    if(!filename.isEmpty())
    {
        QFile file(filename);
        QTextStream qout(&file);
        file.open(QIODevice::WriteOnly);

        std::vector<jbrush::Shape*> shapes = m_canvas->getShapes();
        std::sort(shapes.begin(), shapes.end(), jbrush::Shape::compareId);

        for(jbrush::Shape* shape : shapes)
        {
            qout << shape->toString() << endl;
        }

        file.close();
    }
}

void MainWindow::on_actionReportArea_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save area report", nullptr, "Text File (*.txt)");

    if(!filename.isEmpty())
    {
        QFile file(filename);
        QTextStream qout(&file);
        file.open(QIODevice::WriteOnly);

        std::vector<jbrush::Shape*> shapes = m_canvas->getShapes();
        std::sort(shapes.begin(), shapes.end(), jbrush::Shape::compareArea);

        for(jbrush::Shape* shape : shapes)
        {
            qout << "Shape Area: " << shape->area() << endl
                 << shape->toString() << endl;
        }

        file.close();
    }
}

void MainWindow::on_actionReportPerimeter_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save perimeter report", nullptr, "Text File (*.txt)");

    if(!filename.isEmpty())
    {
        QFile file(filename);
        QTextStream qout(&file);
        file.open(QIODevice::WriteOnly);

        std::vector<jbrush::Shape*> shapes = m_canvas->getShapes();
        std::sort(shapes.begin(), shapes.end(), jbrush::Shape::comparePerimeter);

        for(jbrush::Shape* shape : shapes)
        {
            qout << "Shape Perimeter: " << shape->perimeter() << endl
                 << shape->toString() << endl;
        }

        file.close();
    }
}

/* Help */
void MainWindow::on_actionAboutUs_triggered()
{
    m_about.setModal(true);
    m_about.exec();
}

void MainWindow::updatePropertiesMenus()
{
    if(m_shapeSelectMenu->getSelected() == jbrush::constants::ShapeType::TEXT)
    {
        //If text is selected, only text properties need to be shown
        m_propsMenu->hide();
        m_textPropsMenu->show();
    }
    else
    {
        m_textPropsMenu->hide();
        m_propsMenu->show();

        /* Display fill properties when the shape type selected isn't a line or polyline */
        bool display = m_shapeSelectMenu->getSelected() != jbrush::constants::ShapeType::LINE &&
                       m_shapeSelectMenu->getSelected() != jbrush::constants::ShapeType::POLYLINE;

        m_propsMenu->displayFillPropertiesMenu(display);
    }
}
