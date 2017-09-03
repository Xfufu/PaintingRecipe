/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
    property var stack
    signal addView()
    signal removePage()
    //    ColorDisplay{
    //        id: colorDisplay
    //        anchors.top: parent.top
    //        anchors.bottom: bottomRow.top
    //        anchors.left: displayRow.right
    //        anchors.right: parent.right
    //    }
    Row{
        id: displayRow
        anchors.top: parent.top
        anchors.bottom: bottomRow.top
        anchors.left: parent.left
        width: parent.width
        spacing: 10
        Text {
            id: recipeText
            //            anchors.top: parent.top
            text: "recipe"
        }
        Rectangle {
            height: parent.height
            width: parent.width - recipeText.width - colorDisplay.width
            color: "transparent"
            ListView {
                id: recipeListView
                anchors.fill: parent
                height: parent.height
                highlight: Rectangle {
                    color: "lightsteelblue"
                    radius: 5
                }
                focus: true
                model: recipeList
                delegate: Text {
                    width: parent.width //contentWidth
                    height: contentHeight
                    text: recipe
                    //            color: "blue"
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
                Component.onCompleted: {
                    index: -1
                }
            }
        }
        ColorDisplay{
            id: colorDisplay
            height: parent.height
            width: 96
        }
    }
    Row {
        id: bottomRow
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        height: childrenRect.height
        ToolButton {
            height: 32
            width: 32
            Image {
                anchors.fill: parent
                source: "qrc:/icons/add.svg"
            }
            onClicked: {
                addView()
            }
        }
        ToolButton {
            height: 32
            width: 32
            Image {
                anchors.fill: parent
                source: "qrc:/icons/trash.svg"
            }
            onClicked:{
                removePage()
            }
        }
        ToolButton {
            height: 32
            width: 32
            text: "edit"
        }
    }
}
