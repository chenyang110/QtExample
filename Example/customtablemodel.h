#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H
#include <QAbstractTableModel>
#include <QVector>

#include <structEx.h>

class customTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    customTableModel(QObject * parent = nullptr);

    void initdata();

protected:

QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const ;
QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
int columnCount(const QModelIndex &parent = QModelIndex()) const;
int rowCount(const QModelIndex &parent = QModelIndex()) const;
private:

/*
 * @brief 表头显示数据
 * @para  section  表头的第几个数据
*/
QVariant headDataDisplay(int section) const;

/*
 * @brief 显示列表数据
 * @para col 列
 * @para data 显示的数据
*/
QVariant rowDispaly(int col, Person data) const;

private:
    QVector<Person> mRecord;   //显示的数据
};

#endif // CUSTOMTABLEMODEL_H
