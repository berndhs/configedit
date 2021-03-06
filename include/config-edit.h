#ifndef DELIBERATE_CONFIG_EDIT_H
#define DELIBERATE_CONFIG_EDIT_H

/****************************************************************
 * This file is distributed under the following license:
 *
 * Copyright (C) 2017, Bernd Stramm

This is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

 ****************************************************************/

#include <QAbstractListModel>
#include <QSettings>
#include <QStringList>
#include <QString>
#include <QVariant>
#include <QList>

namespace deliberate {


class QmlConfigEdit : public QAbstractListModel
{
Q_OBJECT
private:

  class ConfigItem;

public:

  QmlConfigEdit (QObject *parent);
  ~QmlConfigEdit ();
  int rowCount (const QModelIndex & index = QModelIndex()) const;
  QVariant data (const QModelIndex & index, int role = Qt::DisplayRole) const;
  QHash<int, QByteArray> roleNames() const;

  Q_INVOKABLE void loadView ();
  Q_INVOKABLE void saveView ();
  Q_INVOKABLE void testContent ();
  Q_INVOKABLE void updateValue (const QString & group,
                                const QString & key,
                                const QVariant & value);

  void Load (const QString & fileName);

private slots:

  void didInsertRows  ( const QModelIndex & parent, int start, int end );
  void didResetModel ();
  void didChangeData (const QModelIndex & ul, const QModelIndex & lr);

private:

  class ConfigItem
  {
  public:

    enum Kind {
      Kind_None = 0,
      Kind_Header = 1,
      Kind_Value  = 2,
      Kind_TypeName = 3,
      Kind_Bad
    };

    ConfigItem ();
    ConfigItem (const QString & gr,     const QString & ke, 
                const QVariant & val,   Kind ki,
                int lev);
    ConfigItem (const ConfigItem & other);
    const QString  toString() const {
      return QString ("<group:")+group
          + "/ key:" + key
          + QString("/ value: %1").arg(value.toString())
          + QString("/kind: %1").arg(int(kind))
          + QString("/level: %1>").arg(level)
          ;
    }

    QString            group;
    QString            key;
    QVariant           value;
    Kind               kind;
    int                level;
  };


  enum DataType {
     Type_Group = Qt::UserRole+100,
     Type_Key = Qt::UserRole+101,
     Type_Value = Qt::UserRole+102,
     Type_HasValue = Qt::UserRole+103,
     Type_Level = Qt::UserRole+104,
     Type_TypeName = Qt::UserRole+105
  };


  void  Save ();
  void  AddHeader (const QString & title);
  void  AddItem   (const QString & key, const QVariant & value);
  void  addRow (const ConfigItem & item);

  QHash<int, QByteArray> m_roles;
  QStringList          exemptGroups;
  QList <ConfigItem>   configRows;
  QString              m_fileName;
  QSettings            *m_zett;

};


} // namespace


#endif
