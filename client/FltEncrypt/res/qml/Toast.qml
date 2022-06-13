import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

ToolTip {
    id: toast
    property string message: ""

    width: snackLbl.implicitWidth + parent.contentMargins
    height: parent.contentMargins
    x: (parent.width - width) / 2
    y: parent.height
    bottomMargin: parent.contentMargins / 2
    function show(message) {
        snackLbl.text = message
        open()
    }
    Label {
        id: snackLbl
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        horizontalAlignment: Qt.AlignHCenter
    }
}
