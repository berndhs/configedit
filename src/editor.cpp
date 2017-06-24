#include "editor.h"

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
#include <QDebug>

Editor::Editor(QApplication & app,
               QWidget *parent) :
  QWidget(parent),
  m_app(&app),
  m_edit(Q_NULLPTR)
{
  qDebug() << Q_FUNC_INFO << m_app << parent;
}

Editor::~Editor()
{

  qDebug() << Q_FUNC_INFO ;
}

void Editor::run(const QString &fn)
{
  qDebug() << Q_FUNC_INFO << fn;
  m_edit = new deliberate::QmlConfigEdit (this);
  m_edit->Load(fn);
}

void Editor::quit()
{
  if (m_app) {
    m_app->quit();
  } else {
    exit(1);
  }
}
