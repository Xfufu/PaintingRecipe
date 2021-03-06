/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

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
