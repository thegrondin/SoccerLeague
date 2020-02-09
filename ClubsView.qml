import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4

Item {
    Label {
        text: clubViewModelContext.club.history
    }
    Label {
        x: 0
        y: 20
        text: clubViewModelContext.club.stadium.capacity
    }
    Label {
        x: 0
        y: 40
        text: clubViewModelContext.club.stadium.name
    }

    TextInput {
        id: textInput
        x: 116
        y: 77
        width: 80
        height: 20
        text: qsTr(clubViewModelContext.club.stadium.address)
        font.pixelSize: 12
    }

    Binding {
        target: clubViewModelContext.club.stadium
        property: "address"
        value: textInput.text
    }

    Button {
        x: 244
        y: 361
        width: 113
        height: 37
        anchors.verticalCenterOffset: 140
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        onClicked: clubViewModelContext.executeBtn()
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
