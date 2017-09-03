#include "Recipe.h"
#include <QDebug>

Recipe::Recipe(QString recipe): _recipe(recipe)
{}

    Recipe::~Recipe()
{}

QString Recipe::getRecipe() const
{
    qDebug() << __FUNCTION__;
    return _recipe;
}

QString Recipe::getLight() const
{
    qDebug() << __FUNCTION__;
    return _light;
}

QString Recipe::getBase() const
{
    qDebug() << __FUNCTION__;
    return _base;
}

QString Recipe::getShadow() const
{
    qDebug() << __FUNCTION__;
    return _shadow;
}

void Recipe::setBase(QString base)
{
    qDebug() << __FUNCTION__;
    _base = base;
}

void Recipe::setLight(QString light)
{
    qDebug() << __FUNCTION__;
    _light = light;
}

void Recipe::setShadow(QString shadow)
{
    qDebug() << __FUNCTION__;
    _shadow = shadow;
}
