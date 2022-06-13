import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

Page {
    Connections {
        target: appCore

        function onConnectSignal(status, message) {
            connectButton.enabled = !status
            disconnectButton.enabled = status
            toast.show(qsTr(message))
        }

        function onDisconnectSignal(status, message) {
            connectButton.enabled = status
            disconnectButton.enabled = !status
            toast.show(qsTr(message))
        }
    }

    Column {
        anchors.centerIn: parent

        Button {
            id: connectButton
            width: parent.width
            text: qsTr("Connect")
            onClicked: appCore.fltConnect()
        }
        Button {
            id: disconnectButton
            enabled: false
            text: qsTr("Disconnect")
            onClicked: appCore.fltDisconnect()
        }
        Text {
            id: labelStatus
        }
    }

    Toast {
        id: toast
        timeout: 500
    }
}
