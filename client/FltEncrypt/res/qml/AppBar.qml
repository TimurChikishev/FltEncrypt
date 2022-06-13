import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

ToolBar {

    MouseArea {
        anchors.fill: parent

        onContainsMouseChanged: {
            window.startSystemMove()
        }

        ResizeRectangleTop {
            id: resizeRectangleTop
        }

        ResizeRectangleLeft {
            color: Material.toolBarColor
        }

        ResizeRectangleRight {
            color: Material.toolBarColor
        }
    }
}
