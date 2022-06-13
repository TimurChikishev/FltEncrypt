import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

Rectangle {
    id: resizeRectangleRight
    anchors.right: parent.right
    anchors.top: parent.top
    anchors.bottom: parent.bottom
    width: resizeRectangleSize
    color: Material.background

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: containsMouse ? Qt.SizeHorCursor : Qt.ArrowCursor
        onPressed: {
            window.startSystemResize(Qt.RightEdge)
        }
    }
}
