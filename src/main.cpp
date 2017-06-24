
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

#include <QGuiApplication>
#include <QSettings>
#include <QString>
#include <QStringList>
#include <QDebug>
#include "version.h"
#include "deliberate.h"

int
main (int argc, char *argv[])
{
  QStringList arglist;
  for (int a=0;a<argc;++a) {
    arglist << QString(argv[a]);
  }
  qDebug() << Q_FUNC_INFO << argc << arglist;
  QGuiApplication::setOrganizationName ("BerndStramm");
  QGuiApplication::setOrganizationDomain ("berndhs.world");
  QGuiApplication::setApplicationName ("config");
  deliberate::ProgramVersion pv ("ConfigEdit");
  QGuiApplication::setApplicationVersion (pv.Version());
  QSettings  settings;

  deliberate::InitSettings ();
  deliberate::SetSettings (settings);
  settings.setValue ("program",pv.MyName());

  return 0;
}
