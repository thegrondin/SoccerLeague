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
                text: qsTr("Retourner vers la liste de clubs")
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
                            id: clubColorField
                            text: clubActionsViewModelContext.club.color
                            placeholderText: "Couleur du club"
                        }

                        Binding {
                            target: clubActionsViewModelContext.club
                            property: "color"
                            value: clubColorField.text
                        }

                        TextField {
                            id: textField3
                            text: clubActionsViewModelContext.club.createdAt
                            placeholderText: "Annee de creation"
                        }

                        TextField {
                            id: clubCityNameField
                            text: clubActionsViewModelContext.club.cityName
                            placeholderText: "Ville du club"
                        }

                        Binding {
                            target: clubActionsViewModelContext.club
                            property: "cityName"
                            value: clubCityNameField.text
                        }

                        /*

                        ComboBox {
                            id: stadeCombo
                            width: 200
                            textRole: ""
                            model: ListModel {
                                id: model
                                ListElement { text: "Banana" }
                                ListElement { text: "Apple" }
                                ListElement { text: "Coconut" }
                            }

                            onCurrentIndexChanged: {
                                console.log(model.get(stadeCombo.currentIndex).text)
                            }
                            flat: true
                        }


                          */

                        ComboBox {
                            id: stadeCombo
                            width: 200
                            textRole: "name"
                            model: clubActionsViewModelContext.stades
                            onCurrentIndexChanged: {
                                clubActionsViewModelContext.club.stadium = clubActionsViewModelContext.stades[0]
                                //clubActionsViewModelContext.club.stadium = clubActionsViewModelContext.stades.get(stadeCombo.currentIndex).text
                            }
                            delegate: ItemDelegate {
                                width: parent.width
                                height: 40
                                x: 10
                                onClicked: {
                                    //stadeCombo.currentValue = modelData
                                    //clubViewModelContext.selectClub(modelData.id)
                                    //stackView.push("ClubView.qml")
                                }
                                Text {
                                    text: modelData.name
                                    anchors.verticalCenter: parent.verticalCenter
                                }

                            }
                            flat: true
                        }

                        TextArea {
                            id: textArea
                            text: clubActionsViewModelContext.club.history
                            placeholderText: "Histoire du club"
                            Layout.columnSpan: 2
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                        }
                    }

                    RowLayout {
                        id: rowLayout
                        width: 100
                        height: 50

                        Button {
                            id: button
                            onClicked: {
                                clubActionsViewModelContext.clear()
                                stackView.pop()
                            }

                            text: qsTr("Annuler")
                        }

                        Button {
                            id: button1
                            onClicked: {
                                clubActionsViewModelContext.saveClub()
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
