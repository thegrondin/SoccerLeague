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

    ColumnLayout {
        id: columnLayout
        width: 640
        height: 439
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
