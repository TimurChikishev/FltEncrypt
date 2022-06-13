import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts 1.15

Drawer {
    id: drawer
    function selectMenu(id) {
        stackView.replace(id)
        drawer.close()
    }

    Column {
        TabButton {
            width: drawer.width
            leftPadding: 16
            rightPadding: 16
            bottomPadding: 8
            topPadding: 8
            text: "Home"
            onClicked: drawer.selectMenu(homePage)
        }
        TabButton {
            width: drawer.width
            leftPadding: 16
            rightPadding: 16
            bottomPadding: 8
            topPadding: 8
            text: "Settings"
            onClicked: drawer.selectMenu(settingsPage)
        }
    }
}
