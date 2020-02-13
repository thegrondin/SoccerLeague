import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.11

Page {

    header: ToolBar {
        Button {
            anchors.left: parent.left
            text: qsTr("Revenir en arriere")
            onClicked: {
                stackView.pop()
            }
        }
    }

    Column {
    ScrollView {
        height: parent.height
        width: parent.width

        RowLayout {
            Layout.leftMargin: 30
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.row: 5
            width: grid.width

            Layout.bottomMargin: 20
            Layout.topMargin: 20



            Button {
                text: "Ajouter un nouveau entraineur"
                onClicked: {
                    stackView.push("AddCoachView.qml")
                }
            }
        }

        ListView {
            width: 500
            height: 400
            y: 100
            Layout.fillHeight: true
            Layout.fillWidth: true
            model: coachViewModelContext.coaches
            delegate: ItemDelegate {
                width: parent.width
                height: 70
                onClicked: {
                    coachViewModelContext.selectCoach(modelData.id)
                    stackView.push("CoachDetailsView.qml")
                }

                Row {
                    spacing: 5
                    anchors.verticalCenter: parent.verticalCenter

                    Text {
                        text: modelData.firstname
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    Text {

                        text: modelData.lastname
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    Button {
                        text: "Supprimer"
                        onClicked: {
                            coachViewModelContext.deleteCoach(modelData.id)
                        }
                    }

                }

            }

        }
}

    }

}







/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
