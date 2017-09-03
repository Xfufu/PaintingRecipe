#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "recipelist.h"
#include "colorlist.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    RecipeList recipeList;
    engine.rootContext()->setContextProperty("recipeList", &recipeList);
    engine.rootContext()->setContextProperty("colorList", &(ColorList::instance()));

    engine.load(QUrl(QLatin1String("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
