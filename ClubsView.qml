import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.11

Page {

    header: ToolBar {
        Button {
            anchors.left: parent.left
            text: qsTr("Retourner vers la liste des ligues")
            onClicked: {
                stackView.pop()
            }
        }
    }

    GridLayout {
        id: grid
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        layer.enabled: false
        columns: 1
        clip: false
        rowSpacing: 5

        rows: 3


        RowLayout {
             Layout.fillHeight: true
             Layout.fillWidth: true
             Layout.row: 1
             width: grid.width
             Text {
                 id: mainTitle
                 Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                 anchors.verticalCenter: parent.verticalCenter
                 text: qsTr("Clubs")
                 font.pixelSize: 20
                 Layout.leftMargin: 30
                 Layout.topMargin: 15
                 Layout.bottomMargin: 15
            }

        }

        RowLayout {
             Layout.leftMargin: 30
             Layout.fillHeight: true
             Layout.fillWidth: true
             Layout.row: 2
             width: grid.width


                RowLayout {
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    Rectangle {
                        Layout.columnSpan: 2
                        Layout.row: 1
                        RowLayout {
                            Label {
                                text: "Nombre de clubs:"
                            }

                            Text {
                                text: leagueViewModelContext.clubAmount
                            }
                        }
                    }


                    Rectangle {
                        Layout.topMargin: 20
                        Layout.columnSpan: 2
                        Layout.row: 2
                        Layout.rightMargin: 40
                        RowLayout {
                            Label {
                                text: "Nom de la ligue:"
                            }

                            Text {
                                text: leagueViewModelContext.leagueName
                            }
                        }
                    }


                /*RowLayout {
                    Label {
                        text: "Description de la ligue"

                        Layout.columnSpan: 2
                        Layout.row: 2
                    }
                }

                RowLayout {
                    Label {
                        text: "Lorem ipsum dolor sit amet, consectetur adipiscing elit, <br />sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. <br />Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris <br />nisi ut aliquip ex ea commodo consequat."
                        Layout.columnSpan: 2
                        Layout.row: 3
                    }
                }*/
            }
        }

        RowLayout {
             Layout.leftMargin: 30
             Layout.fillHeight: true
             Layout.fillWidth: true
             Layout.row: 4
             width: grid.width

             Layout.bottomMargin: 20
             Layout.topMargin: 20

             Button {
                 text: "Supprimer"
                 //onClicked: model.submit()
             }

            Button {
                text: "Ajouter un nouveau club"
                onClicked: {
                    stackView.push("AddClubView.qml")
                }
            }
        }


        RowLayout {
            Layout.leftMargin: 30
            Layout.topMargin: 15
            Layout.bottomMargin: 15
             Layout.fillHeight: true
             Layout.fillWidth: true
             Layout.row: 5

             ScrollView {
                 Layout.fillHeight: true
                 Layout.fillWidth: true
                 clip: true

                 ListView {
                     Layout.fillHeight: true
                     Layout.fillWidth: true
                     model: leagueViewModelContext.clubs
                     delegate: ItemDelegate {
                         width: parent.width
                         height: 70
                         onClicked: {
                             clubViewModelContext.selectClub(modelData.id)
                             stackView.push("ClubView.qml")
                         }

                         Row {
                             anchors.verticalCenter: parent.verticalCenter

                             Text {
                                 text: "Club " + modelData.id + " - " + modelData.cityName
                                 anchors.verticalCenter: parent.verticalCenter
                             }

                             CheckBox {


                             }
                         }
                     }
                 }
             }
        }

    }





}

