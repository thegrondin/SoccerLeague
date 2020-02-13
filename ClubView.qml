import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.11

Page {

    header: ToolBar {
        Button {
            anchors.left: parent.left
            text: qsTr("Retourner vers la liste de clubs")
            onClicked: {
                stackView.pop()
            }
        }
    }

    ScrollView {
        height: parent.height
        width: parent.width




        GridLayout {
            id: grid
            x: 0
            y: 0
            width: 800
            height: 440
            layer.enabled: false
            columns: 1
            clip: false
            rowSpacing: 5

            rows: 6


            RowLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.row: 1

                Text {
                    id: mainTitle
                    Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                    anchors.verticalCenter: parent.verticalCenter
                    text: qsTr("Club 1")
                    font.pixelSize: 20
                    Layout.leftMargin: 30
                    Layout.topMargin: 15
                    Layout.bottomMargin: 15
                }

            }



            RowLayout {
                Layout.leftMargin: 30
                Layout.fillHeight: false
                Layout.fillWidth: false
                Layout.row: 2

                ColumnLayout {

                    Layout.fillHeight: true
                    Layout.fillWidth: true


                    RowLayout {

                        Text {
                            text: "Couleur du club: " + clubViewModelContext.club.color
                            Layout.column: 1
                            Layout.row: 1
                            Layout.rightMargin: 40
                        }

                        Text {
                            text: "Annee de creation: " + clubViewModelContext.club.createdAt
                            Layout.column: 2
                            Layout.row: 1
                        }
                    }
                    RowLayout {
                        Label {
                            text: "Ville du club: " +  clubViewModelContext.club.cityName

                            Layout.columnSpan: 2
                            Layout.row: 2
                        }
                    }

                    RowLayout {
                        Label {
                            text: "Histoire du club:"

                            Layout.columnSpan: 2
                            Layout.row: 3
                        }
                    }

                    RowLayout {
                        Label {
                            text: clubViewModelContext.club.history
                            Layout.columnSpan: 2
                            Layout.row: 4
                        }
                    }
                }
            }

            RowLayout {
                width: 700
                Layout.leftMargin: 30
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.row: 4

                Layout.bottomMargin: 20
                Layout.topMargin: 20

                Rectangle {
                    width: grid.width
                    Layout.fillWidth: true
                    height: 150
                    color: "#f0f0f0"

                    ColumnLayout {
                        Text {
                            text: clubViewModelContext.club.stadium.name
                            font.pixelSize: 18

                        }

                        Text {
                            text: "Capacité: " + clubViewModelContext.club.stadium.capacity
                        }

                        Text {
                            text: "Qualité du terrain: " + clubViewModelContext.club.stadium.terrainQuality
                        }

                        Text {
                            text: "Adresse: " + clubViewModelContext.club.stadium.address
                        }

                        Button {
                            text: "Acceder a ce stade"
                        }
                    }
                }
            }

            RowLayout {
                Layout.leftMargin: 30
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.row: 5
                width: grid.width

                Layout.bottomMargin: 20
                Layout.topMargin: 20

                Button {
                    text: "Supprimer"
                    //onClicked: model.submit()
                }

                Button {
                    text: "Ajouter un nouveau joueur"
                    onClicked: {
                        stackView.push("AddPlayerView.qml")
                    }
                }

                Button {
                    text: "Ajouter un nouveau palmares"
                    onClicked: {
                        stackView.push("AddTitleView.qml")
                    }
                }
            }


            Row {
                id: row1
                y: 0
                width: 700
                height: 400

                ListView {
                    width: 500
                    height: 400
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    model: playersViewModelContext.players
                    delegate: ItemDelegate {
                        width: parent.width
                        height: 70
                        onClicked: {
                            playersViewModelContext.selectPlayer(modelData.id)
                            stackView.push("PlayerView.qml")
                        }

                        Row {
                            anchors.verticalCenter: parent.verticalCenter

                            Text {
                                text: modelData.firstname + " " + modelData.lastname
                                anchors.verticalCenter: parent.verticalCenter
                            }

                            Button {
                                text: "Supprimer"
                                onClicked: {
                                    playerActionsViewModelContext.deletePlayer(modelData.id)
                                }
                            }
                        }

                    }

                }

                ListView {
                    width: 500
                    height: 400
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    model: 5
                    delegate: ItemDelegate {
                        width: parent.width
                        height: 70
                        onClicked: {
                            stackView.push("PlayerView.qml")
                        }

                        Row {
                            anchors.verticalCenter: parent.verticalCenter

                            Text {
                                text: "Club " + index + " - " + index + " Joueurs"
                                anchors.verticalCenter: parent.verticalCenter
                            }

                            CheckBox {


                            }
                        }
                    }


                }

                ListView {
                    width: 500
                    height: 400
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    model: clubViewModelContext.titles
                    delegate: ItemDelegate {
                        width: parent.width
                        height: 70
                        onClicked: {
                            //TitlesViewModelContext
                            //stackView.push("PlayerView.qml")
                        }

                        Row {
                            spacing: 5
                            anchors.verticalCenter: parent.verticalCenter

                            Text {
                                text: modelData.name
                                anchors.verticalCenter: parent.verticalCenter
                            }

                            Text {

                                text: modelData.date
                                anchors.verticalCenter: parent.verticalCenter
                            }

                        }

                    }

                }
            }


        }
    } }







/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
