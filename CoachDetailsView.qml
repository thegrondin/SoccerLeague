import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.11

Page {

    header: ToolBar {
        Button {
            anchors.left: parent.left
            text: qsTr("Revenir vers les entraineurs")
            onClicked: {
                stackView.pop()
            }
        }
    }

    Column {
        id: column
        x: 0
        y: 0
        width: 640
        height: 440
    }

    Text {
        id: element
        x: 26
        y: 21
        text: qsTr("Entraineur: Marc Laberge")
        font.pixelSize: 18
    }

    Text {
        id: element1
        x: 26
        y: 49
        text: qsTr("Endroit de la graduation : Montreal")
        font.pixelSize: 12
    }

    Button {
        id: button
        x: 23
        y: 78
        text: qsTr("Ajouter un nouveau palmares")
        onClicked: {
            stackView.push("AddTitleView.qml")
        }
    }

    ScrollView {
        id: scrollView
        x: 23
        y: 180
        width: 576
        height: 260

        ListView {
            id: listView
            x: 0
            y: 0
            width: scrollView.width
            height: scrollView.height
            delegate: ItemDelegate {
                x: 5
                width: parent.width
                height: 40
                onClicked: {

                }
                Row {
                    Text {
                        text: modelData.name
                        font.bold: true
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    spacing: 10
                }
            }
            model: coachViewModelContext.titles
        }
    }




}









/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
