import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.11

Page {
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

        rows: 2


        RowLayout {
             Layout.fillHeight: true
             Layout.fillWidth: true
             Layout.row: 1
             width: grid.width
             Text {
                 id: mainTitle
                 Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                 anchors.verticalCenter: parent.verticalCenter
                 text: qsTr("Liste des ligues")
                 font.pixelSize: 20
                 Layout.leftMargin: 30
                 Layout.topMargin: 15
                 Layout.bottomMargin: 15
            }

             Button {
                 text: "Supprimer"
                 //onClicked: model.submit()
             }

            Button {
                text: "Ajouter une nouvelle ligue"
                //onClicked: model.submit()
            }
        }


        RowLayout {
            Layout.leftMargin: 30
            Layout.topMargin: 15
            Layout.bottomMargin: 15
             Layout.fillHeight: true
             Layout.fillWidth: true
             Layout.row: 2

             ScrollView {
                 Layout.fillHeight: true
                 Layout.fillWidth: true
                 clip: true

                 ListView {
                     Layout.fillHeight: true
                     Layout.fillWidth: true
                     model: leagueViewModelContext.leagues
                     delegate: ItemDelegate {

                         width: parent.width
                         height: 70
                         Row {
                             anchors.verticalCenter: parent.verticalCenter

                             Text {
                                 text: modelData.name
                                 anchors.verticalCenter: parent.verticalCenter
                             }

                             CheckBox {

                             }
                         }
                         onClicked: {
                             leagueViewModelContext.selectLeague(modelData.id)
                             // TODO: Implement observer pattern instead of view-viewModel comm
                             clubActionsViewModelContext.setLeague(modelData.id)
                             stackView.push("ClubsView.qml")

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
