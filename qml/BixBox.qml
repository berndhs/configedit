import QtQuick 2.0

Item {
    id: biggestBox;
    objectName: "theBigBox";
    width: 900;
    height: 600;
    signal restartConfig ()
    signal doneConfig ()
    signal resetConfig ()
    ConfigList {
        normalWidth: parent.width;
        anchors.top: parent.top;
        listWidth: parent.width;
        listHeight: parent.height-100;
        anchors.topMargin: 20;
        onRestartConfig: {biggestBox.restartConfig();}
        onDoneConfig: {biggestBox.doneConfig(); console.log("forwarded doneConfig()");}
        onResetConfig:{ biggestBox.resetConfig();}
    }

}
