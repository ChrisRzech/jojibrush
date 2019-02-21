#pragma once
#include "src/shapes/Shapes.hpp"

namespace jbrush
{
namespace filehandler
{
    void saveShapesToFile(const std::vector<Shape*>&, const QString&);
    std::vector<Shape*> loadShapesFromFile(const QString&);
}
}
