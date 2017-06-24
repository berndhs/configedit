#ifndef DENADA_VERSION_H
#define DENADA_VERSION_H

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


#include <QString>
//#include "delib-debug.h"

namespace deliberate {

class ProgramVersion {

public:

  ProgramVersion (QString pgmname);
  
  static QString Version (); 
  static QString MyName ();
  
  static void ShowVersionWindow ();
  static void CLIVersion ();
  
private:

  static QString VersionNumber;
  static QString ProgramName;
  static QString copyright;

};

}

#endif
