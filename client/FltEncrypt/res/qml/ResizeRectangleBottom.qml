import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

Rectangle {
    id: resizeRectangleBottom
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.bottom: parent.bottom
    height: resizeRectangleSize
    color: Material.background

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: containsMouse ? Qt.SizeVerCursor : Qt.ArrowCursor
        onPressed: {
            window.startSystemResize(Qt.BottomEdge)
        }
    }
}
