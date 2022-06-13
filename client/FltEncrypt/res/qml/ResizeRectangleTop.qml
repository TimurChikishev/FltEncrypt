import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

Rectangle {
    id: resizeRectangleTop
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.top: parent.top
    height: resizeRectangleSize
    color: Material.toolBarColor

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: containsMouse ? Qt.SizeVerCursor : Qt.ArrowCursor
        onPressed: {
            window.startSystemResize(Qt.TopEdge)
        }
    }
}
