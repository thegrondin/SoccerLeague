import QtQuick 2.0
import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.11

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
}
