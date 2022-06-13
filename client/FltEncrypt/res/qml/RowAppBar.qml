import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts 1.15

RowLayout {
    property bool fullScreen: false

    ToolButton {
        onClicked: drawer.open()
        Image {
            source: "qrc:/icons/ic_segment.svg"
            fillMode: Image.PreserveAspectFit
            anchors.fill: parent
            anchors.margins: 12
        }
    }
    Item {
        Layout.fillWidth: true
    }
    ToolButton {
        Layout.alignment: Qt.AlignRight
        onClicked: {
            window.showMinimized()
        }
        Image {
            source: "qrc:/icons/ic_maximize.svg"
            fillMode: Image.PreserveAspectFit // For not stretching image (optional)
            anchors.fill: parent
            anchors.topMargin: 22
            anchors.margins: 10 // Leaving space between image and borders (optional)
        }
    }
    ToolButton {
        Layout.alignment: Qt.AlignRight
        onClicked: {
            if (fullScreen) {
                window.visibility = "Windowed"
                imageFullScreen.source = "qrc:/icons/ic_fullscreen.svg"
                fullScreen = false
            } else {
                window.visibility = "FullScreen"
                imageFullScreen.source = "qrc:/icons/ic_fullscreen_exit.svg"
                fullScreen = true
            }
        }
        Image {
            id: imageFullScreen
            source: "qrc:/icons/ic_fullscreen.svg"
            fillMode: Image.PreserveAspectFit // For not stretching image (optional)
            anchors.fill: parent
            anchors.margins: 12 // Leaving space between image and borders (optional)
        }
    }
    ToolButton {
        Layout.alignment: Qt.AlignRight
        onClicked: window.close()
        Image {
            source: "qrc:/icons/ic_close.svg"
            fillMode: Image.PreserveAspectFit // For not stretching image (optional)
            anchors.fill: parent
            anchors.margins: 12 // Leaving space between image and borders (optional)
        }
    }
}
