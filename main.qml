import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.11

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")

    RowLayout {
            anchors.fill: parent
            spacing: 2
            ScrollView {
                z: 100;
                background: Rectangle {
                        color: "whitesmoke"
                }
                Layout.fillWidth: true
                Layout.minimumWidth: 100
                Layout.preferredWidth: 100
                Layout.maximumWidth: 200
                Layout.minimumHeight: parent.height
                ListView {
                    width: parent.width
                    model: ListModel {
                        id: fruitModel

                        ListElement {
                            name: "Ligues"
                            view: "LeagueDashboardView.qml"
                        }
                        ListElement {
                            name: "Coachs"
                            view: "CoachView.qml"
                        }
                        ListElement {
                            name: "Page 3"
                            view: "page3.qml"
                        }
                    }
                    delegate: ItemDelegate {
                        text: name
                        width: parent.width
                        onClicked: {
                            stackView.pop()
                            stackView.push(view)
                        }
                    }
                }
            }
            StackView {
                Layout.fillWidth: true
                Layout.fillHeight: true
                background: Rectangle {
                        color: "white"
                }
                id: stackView
                initialItem: "home.qml"
            }
        }
}
