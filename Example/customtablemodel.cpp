#include "customtablemodel.h"
#include <QFont>

customTableModel::customTableModel(QObject * parent):
QAbstractTableModel(parent)
{
     setParent(parent);
     initdata();
}

void customTableModel::initdata()
{

    Person tmp1;
    tmp1.age = 12;
    tmp1.strName = QStringLiteral("vc");
    tmp1.StrClass = QStringLiteral("mm");
    mRecord.push_back(tmp1);

    Person tmp;
    tmp.age = 11;
    tmp.strName = QStringLiteral("小明");
    tmp.StrClass = QStringLiteral("一年级");
    mRecord.push_back(tmp);

}


QVariant customTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Orientation::Vertical)
     return QVariant();
    switch (role)
    {

     case Qt::DisplayRole: return headDataDisplay(section);


    }
    return QVariant();
}

QVariant customTableModel::headDataDisplay(int section) const
{
    switch (section)
    {
       case 0 : return QStringLiteral("aa");
       case 1 : return QStringLiteral("bb");
       case 2 : return QStringLiteral("cc");
    }
     return QVariant();
}

QVariant customTableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();
    int row = index.row();
    auto record = mRecord[row];
    switch (role) {
    case Qt::DisplayRole: return rowDispaly(index.column(), record);
    case Qt::FontRole:    return QFont("微软雅黑", 15);
    }
    return QVariant();
}

QVariant customTableModel::rowDispaly(int col, Person data) const
{
    switch (col)
    {
    case 0: return data.strName;
    case 1: return data.StrClass;
    case 2: return QString::number(data.age);
    }
    return QVariant();
}


//3列数据
int customTableModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

int customTableModel::rowCount(const QModelIndex &parent) const
{
    return mRecord.size();
}
