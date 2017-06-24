
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
#include "main.h"

int
main (int argc, char *argv[])
{
  qDebug() << Q_FUNC_INFO;
  QApplication::setOrganizationName ("BerndStramm");
  QApplication::setOrganizationDomain ("berndhs.world");
  QApplication::setApplicationName ("cfgedit");
  deliberate::ProgramVersion pv ("cfgedit");
  QApplication::setApplicationVersion (pv.Version());
  QSettings  settings;

  deliberate::InitSettings ();
  deliberate::SetSettings (settings);
  settings.setValue ("program",pv.MyName());


  QStringList  configMessages;

  deliberate::CmdOptions  opts (pv.MyName());
  opts.AddSoloOption ("debug","D",QObject::tr("show Debug log window"));
  opts.AddStringOption ("logdebug","L",QObject::tr("write Debug log to file"));

  bool optsOk = opts.Parse (argc, argv);
  QStringList arglist;
  arglist << opts.Arguments();

  if (!optsOk) {
    opts.Usage ();
    return(1);
  }
  if (opts.WantVersion() || opts.WantHelp ()) {
    opts.Usage ();
    pv.CLIVersion ();
    configMessages.append (QString("Built on %1 %2")
                           .arg (__DATE__).arg(__TIME__));
    configMessages.append (QObject::tr("Build with Qt %1").arg(QT_VERSION_STR));
    configMessages.append (QObject::tr("Running with Qt %1").arg(qVersion()));
    for (int cm=0; cm<configMessages.size(); cm++) {
      deliberate::StdOut () << configMessages[cm] << endl;
    }
    if (opts.WantVersion ()) {
      return (0);
    }
  }
  bool showDebug = opts.SeenOpt ("debug");
  int result;
  QApplication  app (argc, argv);

  Editor editor (app);
  editor.run(arglist[0]);

  QTimer::singleShot(3000,&editor,SLOT(quit()));

  result = app.exec();

  return result;
}
