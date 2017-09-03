#include "color.h"

Color::Color(QString id, QString color, QString name) :
    _id(id),
    _color(color),
    _name(name)
{}

Color::~Color()
{}

QString Color::getId() const
{
    return _id;
}

QString Color::getColor() const
{
    return _color;
}

QString Color::getName() const
{
    return _name;
}
