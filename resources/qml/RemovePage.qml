import QtQuick 2.7
import QtQuick.Controls 2.2

Item {
    property var stack
    signal back()
    ColorDisplay{
        id: colorDisplay
        anchors.top: parent.top
        anchors.bottom: bottomRow.top
        anchors.left: recipeListView.right
        anchors.right: parent.right
    }
    ListView {
        id: recipeListView
        anchors.bottom: bottomRow.top
        height: parent.height - bottomRow.height
        width: parent.width - 96
        highlight: Rectangle {
            color: "lightsteelblue"
            radius: 5
        }
        focus: true
        model: recipeList
        delegate: Text {
            property string name : recipe
            width: contentWidth
            height: contentHeight
            text: recipe
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    recipeListView.currentIndex = index
                    colorDisplay.base = base
                    colorDisplay.light = light
                    colorDisplay.shadow = shadow
                }
            }
            Component.onCompleted: {
                console.log("recipe : " + recipe)
            }
        }
    }
    Row {
        id: bottomRow
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        height: 40
        ToolButton {
            height: 32
            width: 32
            Image {
                anchors.fill: parent
                source: "qrc:/icons/home.svg"
                mipmap: true
            }
            onClicked: {
                back()
            }
        }
        ToolButton {
            height: 32
            width: 32
            text: "remove"
            onClicked: {
                recipeList.remove(recipeListView.currentItem.name)
                back()
            }
        }
    }
}
