import QtQuick 1.1
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
Rectangle {
  id: button
  signal clicked ()
  signal pressAndHold ()
  property alias labelText : label.text
  property alias labelHeight: label.height
  property real commonMargin: 4
  width: 100
  height: 100
  radius: 5
  color: "#d3d3d3"
  anchors { 
    topMargin: commonMargin; bottomMargin: commonMargin; 
    leftMargin: commonMargin; rightMargin: commonMargin
  }
  MouseArea {
    anchors.fill: parent
    onClicked: { parent.clicked () }
    onPressAndHold: { parent: pressAndHold () }
  }
  Text { 
    id: label
    text: "Button"
    z: parent.z
    wrapMode:Text.Wrap
    width: parent.width
    anchors.centerIn: parent 
    horizontalAlignment: Text.AlignHCenter
 }
}
