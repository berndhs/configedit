import QtQuick 2.0

Item {
    id: biggestBox;
    objectName: "theBigBox";
    width: 700;
    height: 400;
    signal restartConfig ()
    signal doneConfig ()
    signal resetConfig ()
    ConfigList {
        anchors.centerIn: parent;
        onRestartConfig: biggestBox.restartConfig();
        onDoneConfig: {biggestBox.doneConfig(); console.log("forwarded doneConfig()");}
        onResetConfig: biggestBox.resetConfig();
    }

}
