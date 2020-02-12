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
                text: qsTr("Retourner vers le club")
                onClicked: {
                    playerActionsViewModelContext.clear()
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
                        text: qsTr("Informations de base sur le joueur")
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
                            id: playerFirstnameField
                            text: playerActionsViewModelContext.player.firstname
                            placeholderText: "Prenom"
                        }

                        Binding {
                            target: playerActionsViewModelContext.player
                            property: "firstname"
                            value: playerFirstnameField.text
                        }

                        TextField {
                            id: playerLastnameField
                            text: playerActionsViewModelContext.player.lastname
                            placeholderText: "Nom de famille"
                        }

                        Binding {
                            target: playerActionsViewModelContext.player
                            property: "lastname"
                            value: playerLastnameField.text
                        }

                        TextField {
                            id: playerBirthCityField
                            text: playerActionsViewModelContext.player.birthCity
                            placeholderText: "Ville de naissance"
                        }

                        Binding {
                            target: playerActionsViewModelContext.player
                            property: "birthCity"
                            value: playerBirthCityField.text
                        }

                        TextField {
                            id: playerWeightField
                            text: playerActionsViewModelContext.player.weight
                            placeholderText: "Poid"
                        }

                        Binding {
                            target: playerActionsViewModelContext.player
                            property: "weight"
                            value: playerWeightField.text
                        }


                    }

                    RowLayout {
                        id: rowLayout
                        width: 100
                        height: 50

                        Button {
                            id: button
                            onClicked: {
                                playerActionsViewModelContext.clear()
                                stackView.pop()
                            }

                            text: qsTr("Annuler")
                        }

                        Button {
                            id: button1
                            onClicked: {
                                playerActionsViewModelContext.savePlayer()
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
