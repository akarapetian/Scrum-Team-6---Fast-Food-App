#include <dbmanager.h>

DbManager::~DbManager()
{
    if(m_db.isOpen())
    {
        m_db.close();
    }
}

bool DbManager::isOpen() const
{
    return m_db.isOpen();
}
QSqlDatabase DbManager::getDb()
{
    return m_db;
}

DbManager::DbManager(const QString& path)
{
    m_db=QSqlDatabase::addDatabase("Restaurant");
    m_db.setDatabaseName(path);
    if(!m_db.open())
    {
        qDebug() << "Error: could not connect to Database";
    }
    else
    {
        qDebug() << "Database: connected";
    }
}

bool DbManager::loadRestaurants(QVector<restaurant>& restaurants){
    restaurant temp;
    QSqlQuery query("SELECT * FROM restaurant");
    query.exec();

      while(query.next())
      {
          temp.changeId(query.value(0).toInt());
          temp.changeName(query.value(1).toString());
          temp.changeDistanceSize(query.value(2).toInt());

          restaurants.push_back(temp);
      }
      return restaurants.size() > 0;
}
bool DbManager::loadItems(QVector<item>& tempItem){
    item temp;
    QSqlQuery query("SELECT * FROM item");
    query.exec();

      while(query.next())
      {
          temp.itemId = query.value(0).toInt();
          temp.itemName = query.value(2).toString();
          temp.price = query.value(3).toFloat();

          tempItem.push_back(temp);
      }
      return tempItem.size() > 0;
}
