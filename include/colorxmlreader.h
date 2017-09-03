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
