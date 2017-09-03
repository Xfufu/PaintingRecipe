/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamAttributes>
#include <QDebug>

#include "ColorXmlReader.h"

ColorXmlReader::ColorXmlReader()
{

}

ColorXmlReader::~ColorXmlReader()
{

}

void ColorXmlReader::readColors()
{
    QFile sourceDocument;
    sourceDocument.setFileName(":/color/pa.xml");
    sourceDocument.open(QIODevice::ReadOnly);

    QXmlStreamReader stream;
    stream.setDevice(&sourceDocument);
    while (!stream.isEndDocument()) {
        if (stream.hasError())
        {
            qDebug("XML error: ");
            qDebug(stream.errorString().toStdString().c_str());
            return;
        }
        stream.readNext();
        if (stream.isStartElement()) {
            if (stream.name().toString() == "color") {
                QString id;
                QString name;
                QString hexColor;
                QXmlStreamAttributes attr = stream.attributes();
                for (int i = 0; i < attr.length(); ++i) {
                    if (attr.at(i).name().toString() == "id") {
                        id = attr.at(i).value().toString();
                    } else if (attr.at(i).name().toString() == "name") {
                        name = attr.at(i).value().toString();
                    } else if (attr.at(i).name().toString() == "hexColor") {
                        hexColor = attr.at(i).value().toString();
                    }
                }
                emit addColor(id, hexColor, name);
            }
        }
    }
}
