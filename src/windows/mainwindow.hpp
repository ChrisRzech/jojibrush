#pragma once
#include <QMainWindow>
#include "src/Canvas.hpp"
#include "src/account.hpp"
#include "aboutus.hpp"
#include "src/menus/ShapeSelectMenu.hpp"
#include "src/menus/PropertiesMenu.hpp"
#include "src/menus/TextPropertiesMenu.hpp"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /* Constructors */
    explicit MainWindow(QWidget* parent = nullptr);

    /* Destructor */
    ~MainWindow() override;

private slots:
    /* File */
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_actionExport_triggered();

    /* View */
    void on_actionShowShapeID_toggled(bool);

    /* Reports */
    void on_actionReportID_triggered();
    void on_actionReportArea_triggered();
    void on_actionReportPerimeter_triggered();

    /* Help */
    void on_actionAboutUs_triggered();

private:
    void updatePropertiesMenus();

    Ui::MainWindow* m_ui;
    jbrush::Canvas* m_canvas;
    QString m_currentFile;
    AboutUs m_about;

    ShapeSelectMenu* m_shapeSelectMenu;
    PropertiesMenu* m_propsMenu;
    TextPropertiesMenu* m_textPropsMenu;
};
