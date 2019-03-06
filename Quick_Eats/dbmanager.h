#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QDebug>
#include <QVector>
#include <restaurant.h>

using namespace std;

class DbManager
{
public:
    DbManager(const QString& path);
    ~DbManager();

    bool isOpen() const;

    bool loadRestaurants(QVector<restaurant>& vRestaurants);
    bool loadItems(QVector<item>& vMenus);
    QSqlDatabase getDb();

private:
    QSqlDatabase m_db;

};

#endif // DBMANAGER_H
