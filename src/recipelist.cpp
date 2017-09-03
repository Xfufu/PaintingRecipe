/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

#include "RecipeList.h"
#include "ColorList.h"
#include <QList>
#include <QDebug>
#include <iterator>

RecipeList::RecipeList()
{}

RecipeList::~RecipeList()
{}

void RecipeList::init()
{
    qDebug() << __FUNCTION__;
    connect(&_reader, XmlReader::addRecipe,
            this, RecipeList::onAddRecip);
    connect(&_reader, XmlReader::addColor,
            this, RecipeList::onAddColor);
    _reader.readRecipes();
}

bool RecipeList::insertRows(int row, int count, QString recipe, const QModelIndex &parent)
{
    Q_UNUSED(count);
    beginInsertRows(parent, row, row);

    _recipeList.append(new Recipe(recipe));
    endInsertRows();
    return true;
}

int RecipeList::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _recipeList.size();
}

QVariant RecipeList::data(const QModelIndex &index, int role) const
{
    switch(role) {
    case recipeRole:
        return _recipeList[index.row()]->getRecipe();
    case commentRecipe:
        return _recipeList[index.row()]->getRecipe();
    case categoryRole:
        return _recipeList[index.row()]->getRecipe();
    case colorRole:
        return _recipeList[index.row()]->getRecipe();
    case baseRole:
        return ColorList::instance().getHexColor(_recipeList[index.row()]->getBase());
    case lightRole :
        return ColorList::instance().getHexColor(_recipeList[index.row()]->getLight());
    case shadowRole:
        return ColorList::instance().getHexColor(_recipeList[index.row()]->getShadow());
    default:
        return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> RecipeList::roleNames() const
{
    QHash<int, QByteArray> names;
    names[recipeRole] = "recipe";
    names[commentRecipe] = "comment";
    names[colorRole] = "color";
    names[categoryRole] = "category";
    names[baseRole] = "base";
    names[lightRole] = "light";
    names[shadowRole] = "shadow";
    return names;
}

void RecipeList::onAddRecip(QString recipe)
{
    qDebug() << __FUNCTION__;
    insertRows(_recipeList.size(), 1, recipe);
}

void RecipeList::onAddColor(QString recipe, QString id, QString type, QString level)
{
    qDebug() << __FUNCTION__ << " " << recipe << " " << id;
    Q_UNUSED(level);
    for (int i = 0; i < _recipeList.size(); ++i) {
        Recipe *recipeObj = _recipeList[i];
        if (recipeObj->getRecipe() == recipe) {
            if (type == "base") {
                recipeObj->setBase(id);
            } else if (type == "light") {
                recipeObj->setLight(id);
            } else if (type == "shadow") {
                recipeObj->setShadow(id);
            }
        }
    }
}

void RecipeList::save(QString name, QString category, QString light, QString base, QString shadow, QString comment)
{
    qDebug() << __FUNCTION__;
    onAddRecip(name);
    onAddColor(name, light, "light", "1");
    onAddColor(name, base, "base", "1");
    onAddColor(name, shadow, "shadow", "1");
    _reader.saveRecipe(name, category, light, base, shadow, comment);
}

void RecipeList::remove(QString name)
{
_reader.removeRecipe(name);
}
