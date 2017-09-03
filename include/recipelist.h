#ifndef RECIPELIST_H
#define RECIPELIST_H

#include <QAbstractListModel>
#include "recipe.h"
#include "xmlreader.h"

class RecipeList: public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        recipeRole = Qt::UserRole+1,
        commentRecipe = Qt::UserRole +2,
        categoryRole = Qt::UserRole +3,
        colorRole = Qt::UserRole + 4,
        baseRole = Qt::UserRole + 5,
        lightRole = Qt::UserRole + 6,
        shadowRole
    };
    RecipeList();
    virtual ~RecipeList();
    Q_INVOKABLE void init();
    bool insertRows(int row, int count, QString recipe, const QModelIndex &parent = QModelIndex());
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    Q_INVOKABLE void save(QString name, QString category, QString light, QString base, QString shadow, QString comment);
    Q_INVOKABLE void remove(QString name);
public slots:
    void onAddRecip(QString recipe);
    void onAddColor(QString recipe, QString id, QString type, QString level);
private:
    QList<Recipe *> _recipeList;
    XmlReader _reader;
};

#endif // RECIPELIST_H
