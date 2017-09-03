/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

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
