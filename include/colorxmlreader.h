/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

#ifndef COLORXMLREADER_H
#define COLORXMLREADER_H

#include <QObject>

class ColorXmlReader: public QObject
{
    Q_OBJECT
public:
    ColorXmlReader();
    virtual ~ColorXmlReader();
    void readColors();
signals:
    void addColor(QString id, QString hexColor, QString name);
};

#endif // COLORXMLREADER_H
