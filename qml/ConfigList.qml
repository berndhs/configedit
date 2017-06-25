

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
import QtQuick 2.2
import QtQuick.Controls 2.0


Rectangle {
    id: configListRect
  property real normalWidth: 800
  property real widthRatio: 0.25
  property real keyFieldWidth: normalWidth*widthRatio
  property real valueFieldWidth: normalWidth*(1 - widthRatio)
  property real shrinkDelay: 250
  property real itemHeight: 32
  property bool isShown: true
  property string valueBackgroundColor: "#c7f0f0"
  property string keyBackgroundColor: "#f0f0f0"
  property real topMargin: 0
  property real leftMargin: 0
  property real rightMargin: 0
  signal updateConfigItem (string theGroup, string theKey, string newValue)
  signal restartConfig ()
  signal doneConfig ()
  signal resetConfig ()
  function hide () {
    console.log ("ConfList hide")
    shrinkScale.running = true
    isShown = false
  }
  function show () {
    console.log ("ConfList show")
    expandScale.running = true
    isShown = true
  }
  color: "transparent"
//  anchors.top: configListRect.top
//  anchors.left: configListRect.left
////  anchors.topMargin: 0
////  anchors.leftMargin: leftMargin
//  width: configListRect.width - leftMargin
//  height: configListRect.height
  PropertyAnimation on scale { 
    id: shrinkScale
    running: false
    to: 0
    duration: shrinkDelay
  }
  PropertyAnimation on scale { 
    id: expandScale
    running: false
    to: 1
    duration: shrinkDelay
  }
  Rectangle {
    id: buttonRow
    height: childrenRect.height
    width: childrenRect.width
    anchors { horizontalCenter: parent.horizontalCenter }
    color: "transparent"
    Button {
      id: saveConfigButton
      height: itemHeight * 1.2
//      radius: height * 0.3333
      text: qsTr("Restart")
      onClicked: { console.log ("Restart config clicked "); restartConfig() }
    }
    Button {
      id: doneConfigButton
      anchors { left: saveConfigButton.right }
      height: itemHeight * 1.2
//      radius: height * 0.3333
      text: qsTr("Done")
      onClicked: { console.log ("Done config clicked "); doneConfig () }
    }
    Button {
      id: resetConfigButton
      anchors { left: doneConfigButton.right }
      height: itemHeight * 1.2
//      radius: height * 0.3333
      text: qsTr("Reset to Defaults")
      onClicked: { console.log ("Reset config clicked "); resetConfig (); }
    }
  }
  Component {
    id: verticalConfigDelegate
    Rectangle {
      width: parent.width
      height: itemHeight; 
      color: "transparent"
      anchors.topMargin: 2
      Column { 
        id: keyColumn
        anchors.topMargin: 4
        height: itemHeight
        width: keyFieldWidth   
        Rectangle {
          id: keyColumnRect
          anchors { topMargin: 2 }
          width: parent.width
          height: parent.height - 2
          color: keyBackgroundColor  
          z: parent.z + 1
          Text {  
            anchors.left: parent.left
            x: parent.x + 2
            width:parent.width; wrapMode:Text.Wrap
            text:  (confHasValue ? "..." + confKey : "<b>" + confKey + "</b" )
          }
        } 
      }
      Column {
        id: valueColumn
        width: valueFieldWidth
        height: itemHeight
        anchors.left: keyColumn.right
        Rectangle {
          id: valueColumnRect
          anchors.topMargin: 2
          anchors.leftMargin: confLevel * 10
          width: parent.width
          height: parent.height -2
          color: valueBackgroundColor
          z: parent.z + 1
          TextInput {
            id: valueField
            width: parent.width - 2
            enabled: confHasValue
            autoScroll: true
            text:  confValue
            selectByMouse: true
            focus: true
          }
        }
        Keys.onEnterPressed: { 
          updateConfigItem (confGroup, confKey, valueField.text)
        }
        Keys.onReturnPressed: { 
          updateConfigItem (confGroup, confKey, valueField.text)
        }
      }
      MouseArea {
        anchors.fill: parent
        onClicked: {
          console.log ("clicked item " + index + " key " + confKey)
        }
      }
    }
  }
  ListView {
    id: configListView
    visible: true
    delegate: verticalConfigDelegate
    clip: true
    width: parent.width 
    height: parent.height -itemHeight - buttonRow.height
    currentIndex: -1
    contentWidth: childrenRect.width; contentHeight: childrenRect.height
    anchors.top: buttonRow.bottom
    anchors.topMargin: 6
    orientation: ListView.Vertical
    model: configModel
    snapMode: ListView.SnapToItem
    highlight: Rectangle { color: "#ffbbbb"}
  }
}
