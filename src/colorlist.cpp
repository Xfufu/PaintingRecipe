#include "ColorList.h"
#include "ColorXmlReader.h"

#include <QDebug>

ColorList::ColorList()
{}

ColorList::~ColorList()
{}

void ColorList::init()
{
    ColorXmlReader reader;
    connect(&reader, ColorXmlReader::addColor,
            this, ColorList::onAddColor);
    reader.readColors();
}

ColorList &ColorList::instance()
{
    static ColorList *_instance = 0;
    if ( _instance == 0 ) {
        _instance = new ColorList();
        _instance->init();
    }
    return *_instance;

}

QString ColorList::getHexColor(QString id) const
{
    qDebug() << __FUNCTION__ << " " << id;
    for (int i = 0; i < _colorList.size(); ++i) {
        if (_colorList[i]->getId() == id) {
            qDebug() << _colorList[i]->getColor();
            return _colorList[i]->getColor();
        }
    }
    return "";
}

bool ColorList::insertRows(int row, int count, QString id, QString hexColor, QString name, const QModelIndex &parent)
{
    Q_UNUSED(count);
    beginInsertRows(parent, row, row);
    _colorList.append(new Color(id, hexColor, name));
    endInsertRows();
    return true;
}

int ColorList::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _colorList.size();
}

QVariant ColorList::data(const QModelIndex &index, int role) const
{
    switch(role) {
    case idRole:
        return _colorList[index.row()]->getId();
    case hexColorRecipe:
        return _colorList[index.row()]->getColor();
    case nameRole:
        return _colorList[index.row()]->getName();
    default:
        return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> ColorList::roleNames() const
{
    QHash<int, QByteArray> names;
    names[idRole] = "iid";
    names[hexColorRecipe] = "hexColor";
    names[nameRole] = "name";
    return names;
}

void ColorList::onAddColor(QString id, QString hexColor, QString name)
{
    insertRows(_colorList.size(), 1, id, hexColor, name);
}
