#ifndef EDITOR_H
#define EDITOR_H

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
#include <QApplication>
#include <QString>
#include <QWidget>
#include <QProcess>
#include "config-edit.h"
#include "configview.h"

class Editor : public QWidget
{
  Q_OBJECT
public:
  explicit Editor(QApplication & app,QWidget *parent = 0);
  ~Editor ();

  void run (const QString &fn);




signals:

public slots:

  void quit();
  void wantSave();
  void wantReload();
  void wantRestart();
  void wantGedit();
  void doneGedit();

private:

  void connectSigs();

  QApplication  *m_app;
  deliberate::QmlConfigEdit *m_edit;
  ConfigView                *m_viewer;
  QString                   m_fileName;
  QProcess                  *m_process;

};

#endif // EDITOR_H
