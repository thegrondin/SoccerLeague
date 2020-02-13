import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.11


Page {
    id: page

    header: ToolBar {
        RowLayout {
            Button {
                anchors.left: parent.left
                text: qsTr("Retourner vers la liste des entraineurs")
                onClicked: {
                    clubActionsViewModelContext.clear()
                    stackView.pop()
                }
            }

            Button {
                text: "Annuler"
                //onClicked: model.submit()
            }

            Button {
                text: "Enregistrer"
                //onClicked: model.submit()
            }
        }
    }

    Rectangle {
        anchors.fill: parent

        Column {
            id: column
            x: 8
            y: 8
            width: 624
            height: 419

            Item {
                id: element
                x: 0
                y: 0
                width: column.width
                height: column.height

                ColumnLayout {
                    id: columnLayout
                    x: 0
                    y: 0
                    width: element.width
                    height: element.height
                    spacing: 6.4


                    Text {
                        id: element1
                        text: qsTr("Informations de base du club")
                        font.pixelSize: 12
                    }

                    GridLayout {
                        id: gridLayout
                        width: columnLayout.width
                        height: 100
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        columns: 2

                        TextField {
                            id: coachFirstnameField
                            text: coachViewModelContext.coach.firstname
                            placeholderText: "Prenom"
                        }

                        Binding {
                            target: coachViewModelContext.coach
                            property: "firstname"
                            value: coachFirstnameField.text
                        }

                        TextField {
                            id: coachLastnameField
                            text: coachViewModelContext.coach.lastname
                            placeholderText: "Nom de famille"
                        }

                        Binding {
                            target: coachViewModelContext.coach
                            property: "lastname"
                            value: coachLastnameField.text
                        }

                        TextField {
                            id: coachGraduationField
                            text: coachViewModelContext.coach.graduationLocation
                            placeholderText: "Endroit de la graduation"
                        }

                        Binding {
                            target: coachViewModelContext.coach
                            property: "graduationLocation"
                            value: coachGraduationField.text
                        }

                    }

                    RowLayout {
                        id: rowLayout
                        width: 100
                        height: 50

                        Button {
                            id: button
                            onClicked: {
                                coachViewModelContext.clear()
                                stackView.pop()
                            }

                            text: qsTr("Annuler")
                        }

                        Button {
                            id: button1
                            onClicked: {
                                coachViewModelContext.saveCoach()
                                stackView.pop()
                            }

                            text: qsTr("Enregistrer")
                        }
                    }
                }
            }
        }

        TextFieldStyle {
            textColor: "black"
            background: Rectangle {
                radius: 2
                implicitWidth: 100
                implicitHeight: 24
                border.color: "#333"
                border.width: 1
            }
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:6;anchors_height:440;anchors_width:640}
}
##^##*/
