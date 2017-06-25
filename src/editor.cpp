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
#include <QQmlContext>
#include <QQuickItem>
#include "configview.h"

Editor::Editor(QApplication & app,
               QWidget *parent) :
  QWidget(parent),
  m_app(&app),
  m_edit(Q_NULLPTR),
  m_viewer(Q_NULLPTR)
{
  qDebug() << Q_FUNC_INFO << m_app << parent;
}

Editor::~Editor()
{
  qDebug() << Q_FUNC_INFO ;
  if (m_edit) {
    m_edit->deleteLater();
  }
  if (m_viewer) {
    m_viewer->deleteLater();
  }
}

void Editor::run(const QString &fn)
{
  qDebug() << Q_FUNC_INFO << fn;
  m_edit = new deliberate::QmlConfigEdit (this);
  m_edit->Load(fn);
  m_viewer = new ConfigView;
  QQmlContext *ctxt = m_viewer->rootContext();
  ctxt->setContextProperty("configModel",m_edit);
  m_viewer->setResizeMode(QQuickView::SizeViewToRootObject);
  m_viewer->setSource(QUrl("qrc:/BigBox.qml"));
  connectSigs();
  m_viewer->show();
}

void Editor::quit()
{
  if (m_app) {
    m_app->quit();
  } else {
    exit(1);
  }
}

void Editor::wantSave()
{
  qDebug() << Q_FUNC_INFO ;
  if (m_edit) {
    m_edit->saveView();
  }
  quit();
}

void Editor::wantReload()
{
  qDebug() << Q_FUNC_INFO ;
}

void Editor::wantRestart()
{
  qDebug() << Q_FUNC_INFO ;
}

void Editor::connectSigs()
{
  QQuickItem * root = m_viewer->rootObject();
  qDebug() << Q_FUNC_INFO << " root is at " << root;
  connect (root,SIGNAL(doneConfig()),this,SLOT(wantSave()));
  connect (root,SIGNAL(restartConfig()),this,SLOT(wantRestrt()));
  connect (root,SIGNAL(reloadConfig()),this,SLOT(wantReload()));
}
