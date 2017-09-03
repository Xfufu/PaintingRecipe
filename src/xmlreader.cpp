#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamAttributes>
#include <QXmlStreamWriter>
#include <QDebug>
#include <QString>

#include "XmlReader.h"

XmlReader::XmlReader()
{
    //   Q_INIT_RESOURCE(recipes);
}

XmlReader::~XmlReader()
{}

void XmlReader::readRecipes()
{
    QFile sourceDocument;
    sourceDocument.setFileName("userRecipes.xml");
    sourceDocument.open(QIODevice::ReadOnly);

    QXmlStreamReader stream;
    stream.setDevice(&sourceDocument);
    QString recipe;
    while (!stream.isEndDocument()) {
        if (stream.hasError())
        {
            qDebug("XML error: ");
            qDebug(stream.errorString().toStdString().c_str());
            return;
        }
        stream.readNext();
        if (stream.isStartElement()) {
            if (stream.name().toString() == "recipe") {
                QXmlStreamAttributes attr = stream.attributes();
                recipe = attr.at(0).value().toString();
                emit addRecipe(recipe);
            } else if (stream.name().toString() == "comment") {
                QString comment("");
                comment =  stream.readElementText();
                emit addComment(recipe, comment);
            } else if (stream.name().toString() == "category") {
                QString category("");
                category =  stream.readElementText();
                emit addCategory(recipe, category);
            } else if (stream.name().toString() == "color") {
                QString id;
                QString type;
                QString level;
                QXmlStreamAttributes attr = stream.attributes();
                for (int i = 0; i < attr.length(); ++i) {
                    if (attr.at(i).name().toString() == "id") {
                        id = attr.at(i).value().toString();
                    } else if (attr.at(i).name().toString() == "type") {
                        type = attr.at(i).value().toString();
                    } else if (attr.at(i).name().toString() == "level") {
                        level = attr.at(i).value().toString();
                    }
                }
                emit addColor(recipe, id, type, level);
            }
        }
    }
}

void XmlReader::saveRecipe(QString name, QString category, QString light, QString base, QString shadow, QString comment)
{
    QFile sourceDocument;
    sourceDocument.setFileName("userRecipes.xml");
    sourceDocument.open(QIODevice::ReadOnly);

    QXmlStreamReader reader;
    reader.setDevice(&sourceDocument);

    QFile out;
    out.setFileName("userRecipes.xml");
    out.open(QIODevice::ReadWrite);
    QXmlStreamWriter writer;
    //    QString out;
    writer.setDevice(&out);

    while(!reader.atEnd())
    {
        if(reader.isStartDocument()) {
            writer.writeStartDocument();
        }
        if(reader.isStartElement()) {
            writer.writeStartElement(reader.name().toString());
            //if (reader.name().toString() == "recipe") {
            writer.writeAttributes(reader.attributes());
            //}
        }
        if(reader.isCharacters())
            writer.writeCharacters(reader.text().toString());

        if(reader.isEndElement())
        {
            if (reader.name().toString() == "recipes") {
                writer.writeStartElement("recipe");
                QXmlStreamAttribute attrRecipe("id", name);
                writer.writeAttribute(attrRecipe);

                writer.writeStartElement("category");
                writer.writeCharacters(category);
                writer.writeEndElement();

                writer.writeStartElement("color");
                QXmlStreamAttribute idRecipe("id", light);
                writer.writeAttribute(idRecipe);
                QXmlStreamAttribute typeRecipe("type", "light");
                writer.writeAttribute(typeRecipe);
                QXmlStreamAttribute levelRecipe("level", "1");
                writer.writeAttribute(levelRecipe);
                writer.writeEndElement();

                writer.writeStartElement("color");
                QXmlStreamAttribute idBaseRecipe("id", base);
                writer.writeAttribute(idBaseRecipe);
                QXmlStreamAttribute typeBaseRecipe("type", "base");
                writer.writeAttribute(typeBaseRecipe);
                QXmlStreamAttribute levelBaseRecipe("level", "1");
                writer.writeAttribute(levelBaseRecipe);
                writer.writeEndElement();

                writer.writeStartElement("color");
                QXmlStreamAttribute idShadowRecipe("id", shadow);
                writer.writeAttribute(idShadowRecipe);
                QXmlStreamAttribute typeShadowRecipe("type", "shadow");
                writer.writeAttribute(typeShadowRecipe);
                QXmlStreamAttribute levelShadowRecipe("level", "1");
                writer.writeAttribute(levelShadowRecipe);
                writer.writeEndElement();

                writer.writeStartElement("comment");
                writer.writeCharacters(comment);
                writer.writeEndElement();

                writer.writeEndElement();
            }
            writer.writeEndElement();
        }
        if(reader.isEndDocument())
            writer.writeEndElement();

        reader.readNext();
    }
}

void XmlReader::removeRecipe(QString name)
{
    qDebug() << __FUNCTION__ << " " << name;
    QFile sourceDocument;
    sourceDocument.setFileName("userRecipes.xml");
    sourceDocument.open(QIODevice::ReadOnly);

    QXmlStreamReader reader;
    reader.setDevice(&sourceDocument);

    QFile out;
    out.setFileName("userRecipes.xml");
    out.open(QIODevice::Truncate);
    QXmlStreamWriter writer;
    writer.setDevice(&out);
    writer.setAutoFormatting(true);
    while(!reader.atEnd())
    {
        qDebug() << "reader name : " << reader.name().toString();
        if(reader.isStartDocument()) {
            writer.writeStartDocument();
        }
        if(reader.isStartElement()) {
            if (reader.name().toString() == "recipe") {
                if (reader.attributes().at(0).value().toString() == name) {
                    //reader.readNext();
                    while (!(reader.isEndElement() && (reader.name().toString() == "recipe"))) {
                        qDebug() << "while :" << reader.name().toString();
                        reader.readNext();
                    }
                    reader.readNext();
                } else {
                    qDebug() << "is not name :" << reader.name().toString();
                    writer.writeStartElement(reader.name().toString());
                    writer.writeAttributes(reader.attributes());
                }
            }else {
                qDebug() << "is not recipe :" << reader.name().toString();
                writer.writeStartElement(reader.name().toString());
                writer.writeAttributes(reader.attributes());
            }
        }
        if(reader.isCharacters()) {
            qDebug() << "isCharacters " << reader.text().toString();
            writer.writeCharacters(reader.text().toString());
        }
        if(reader.isEndElement()){
            qDebug() << "isEndElement " << reader.name().toString();
            writer.writeEndElement();
        }
        if(reader.isEndDocument())
            qDebug() << "isEndDocument " <<reader.name().toString();
            writer.writeEndElement();

        reader.readNext();
    }
}
