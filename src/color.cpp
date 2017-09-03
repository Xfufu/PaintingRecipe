/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

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
