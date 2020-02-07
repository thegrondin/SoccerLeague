import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4

Page {
    background: Rectangle {
            visible: !styleData.hasColor
            color: "steelblue"
    }
    Label {
        text: "Bienvenu dans la page d'accueil"
    }
}
