#ifndef DATABASE_H
#define DATABASE_H

namespace SoccerLeague {
namespace Utils {

    class Database
    {
    private:

    public:
        Database();
    };
}
}


/*
 *
 *    const QString Driver("QSQLITE");

    if (QSqlDatabase::isDriverAvailable(Driver)) {
        QSqlDatabase db = QSqlDatabase::addDatabase(Driver);

        //TODO: NEED RELATIVE PATH IN THE FUTURE
        db.setDatabaseName("/home/thomas/TestScrollDesktopApplication/soccerleague.db");
        db.open();

        QSqlQuery testquery;

        testquery.exec("SELECT * from TEST");

        while (testquery.next()) {
            int id = testquery.value(0).toInt();
            QString name = testquery.value(1).toString();
            qDebug() << id << name;
        }

    }*/
#endif // DATABASE_H
