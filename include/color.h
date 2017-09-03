#ifndef COLOR_H
#define COLOR_H

#include <QString>

class Color
{
public:
    Color(QString id, QString color, QString name);
    virtual ~Color();
    QString getId() const;
    QString getColor() const;
    QString getName() const;
private:
    const QString _id;
    const QString _color;
    const QString _name;
};

#endif // COLOR_H
