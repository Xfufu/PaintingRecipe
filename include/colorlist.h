#ifndef COLORLIST_H
#define COLORLIST_H

#include <QAbstractListModel>
#include "Color.h"

class ColorList : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        idRole = Qt::UserRole+1,
        hexColorRecipe = Qt::UserRole +2,
        nameRole = Qt::UserRole + 3
    };
    virtual ~ColorList();
    void init();
    static ColorList & instance();
    QString getHexColor(QString id) const;
    bool insertRows(int row, int count, QString id, QString hexColor, QString name, const QModelIndex &parent = QModelIndex());
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
public slots:
    void onAddColor(QString id, QString hexColor, QString name);
private:
    ColorList();
    QList<Color *> _colorList;
};

#endif // COLORLIST_H
