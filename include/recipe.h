#ifndef RECIPE_H
#define RECIPE_H

#include <QString>

class Recipe
{
public:
    Recipe(QString recipe);
    virtual ~Recipe();
    QString getRecipe() const;
    QString getBase() const;
    QString getLight() const;
    QString getShadow() const;
    void setBase(QString base);
    void setLight(QString light);
    void setShadow(QString shadow);
private:
    QString _recipe;
    QString _comment;
    QString _catagory;
    QString _base;
    QString _light;
    QString _shadow;
    //QList<Color> _color;
};

#endif // RECIPE_H
