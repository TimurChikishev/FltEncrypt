import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    flags: Qt.Window | Qt.FramelessWindowHint
    Material.theme: Material.Dark

    property int resizeRectangleSize: 5

    DrawerView {
        id: drawer
        dragMargin: 0
        height: window.height
        width: 300
    }

    header: AppBar {
        RowAppBar {
            anchors.fill: parent
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: homePage
    }

    HomePage {
        id: homePage
    }

    SettingsPage {
        id: settingsPage
        visible: false
    }

    ResizeRectangleRight {
        id: resizeRectangleRight
    }
    ResizeRectangleLeft {
        id: resizeRectangleLeft
    }
    ResizeRectangleBottom {
        id: resizeRectangleBottom
    }
}
