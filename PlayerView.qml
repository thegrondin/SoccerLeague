import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4

Page {

    header: ToolBar {
        Button {
            anchors.left: parent.left
            text: qsTr("Retour en arriere")
            onClicked: {
                stackView.pop()
            }
        }
    }


    Label {
        id: label
        x: 35
        y: 30
        text: playersViewModelContext.player.firstname
    }

    Label {
        id: label1
        x: 35
        y: 56
        text: playersViewModelContext.player.lastname
    }

    Label {
        id: label2
        x: 35
        y: 82
        text: playersViewModelContext.player.weight
    }

    Label {
        id: label3
        x: 35
        y: 110
        text: playersViewModelContext.player.birthCity
    }

    ListView {
        id: listView
        x: 30
        y: 160
        width: 484
        height: 215
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
        }
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                id: row1
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                }

                Text {
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
                spacing: 10
            }
        }
    }



}
