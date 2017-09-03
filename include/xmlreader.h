#ifndef XMLREADER_H
#define XMLREADER_H

#include <QObject>

class XmlReader: public QObject
{
    Q_OBJECT
public:
    XmlReader();
    virtual ~XmlReader();
    void readRecipes();
    void saveRecipe(QString name, QString category, QString light, QString base, QString shadow, QString comment);
    void removeRecipe(QString name);
signals:
    void addRecipe(QString recipe);
    void addComment(QString recipe, QString comment);
    void addColor(QString recipe, QString id, QString type, QString level);
    void addCategory(QString recipe, QString category);
};

#endif // XMLREADER_H
