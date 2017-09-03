/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.1

Item {
    signal back()
    signal save(string name, string category, string light, string base, string shadow, string comment)
    ColorDisplay {
        id: colorDisplay
        anchors.top: parent.top
        anchors.bottom: bottomRow.top
        anchors.left: recipeColumn.right
        width: 96
    }
    Column {
        id: recipeColumn
        anchors.top: parent.top
        anchors.bottom: bottomRow.top
        width: parent.width - 96
        spacing: 2
        Row {
            width: parent.width
            height: parent.height/6
            spacing: 2
            Text {
                text: "name"
                width: 96
            }
            Rectangle {
                height: parent.height
                width: parent.width - 96
                border.color: "#000000"
                color: "transparent"
                TextEdit {
                    id: nameTextEdit
                    anchors.fill: parent
                    cursorVisible: true
                }
            }
        }
        Row {
            width: parent.width
            height: parent.height/6
            spacing: 2
            Text {
                width: 96
                text: "category"
            }
            Rectangle {
                height: parent.height
                width: parent.width - 96
                border.color: "#000000"
                color: "transparent"
                TextEdit {
                    id: categoryTextEdit
                    anchors.fill: parent
                    cursorVisible: true
                }
            }
        }
        Row {
            width: parent.width
            height: parent.height/6
            spacing: 2
            Text {
                id: lightText
                width: 96
                text: "light"
            }
            ScrollView {
                width: parent.width - 96
                height: parent.height
                clip: true
                //                style: ScrollViewStyle {
                //                    scrollBarBackground: Rectangle {
                //                        color: "grey"
                //                    }
                //                    //transientScrollBars: false
                //                }
                ListView{
                    id: lightListView
                    anchors.fill: parent
                    clip: true
                    model: colorList
                    delegate :Row {
                        property string colorId: iid
                        height: lightTextDelegate.height
                        width: parent.width
                        Rectangle {
                            height: parent.height
                            width: parent.height
                            color: (hexColor===""?"transparent":hexColor)
                        }
                        Text {
                            id: lightTextDelegate
                            height: contentHeight
                            width: parent.width
                            text: iid + " - " + name
                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    lightListView.currentIndex = index
                                    colorDisplay.light = hexColor
                                }
                            }
                        }
                    }
                }
            }
        }
        Row {
            width: parent.width
            height: parent.height/6
            spacing: 2
            Text {
                id: baseText
                width: 96
                text: "base"
            }
            ScrollView {
                width: parent.width - 96
                height: parent.height
                clip: true
                //                style: ScrollViewStyle {
                //                    scrollBarBackground: Rectangle {
                //                        color: "grey"
                //                    }
                //                    transientScrollBars: false
                //                }
                ListView{
                    id: baseListView
                    anchors.fill: parent
                    clip: true
                    model: colorList
                    delegate: Row {
                        property string colorId: iid
                        height: baseTextDelegate.height
                        width: parent.width
                        Rectangle {
                            height: parent.height
                            width: parent.height
                            color: (hexColor===""?"transparent":hexColor)
                        }
                        Text {
                            id: baseTextDelegate
                            height: contentHeight
                            width: parent.width
                            text: iid + " - " + name
                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    baseListView.currentIndex = index
                                    colorDisplay.base = hexColor
                                }
                            }
                        }
                    }
                    Component.onCompleted: {
                        console.log(count)
                    }
                }
            }
        }
        Row {
            width: parent.width
            height: parent.height/6
            spacing: 2
            Text {
                id: shadowText
                width: 96
                text: "shadow"
            }
            ScrollView {
                width: parent.width - 96
                height: parent.height
                clip: true
                //                style: ScrollViewStyle {
                //                    scrollBarBackground: Rectangle {
                //                        color: "grey"
                //                    }
                //                    transientScrollBars: false
                //                }
                ListView{
                    id: shadowListView
                    anchors.fill: parent
                    interactive: true
                    model: colorList
                    clip: true
                    delegate: Row {
                        property string colorId: iid
                        height: shadowTextDelegate.height
                        width: parent.width
                        Rectangle {
                            height: parent.height
                            width: parent.height
                            color: (hexColor===""?"transparent":hexColor)
                        }
                        Text {
                            id: shadowTextDelegate
                            height: contentHeight
                            width: parent.width
                            text: iid + " - " + name
                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    shadowListView.currentIndex = index
                                    colorDisplay.shadow = hexColor
                                }
                            }
                        }
                    }
                }
            }
        }
        Row {
            width: parent.width
            height: parent.height/6
            spacing: 2
            Text {
                width: 96
                text: "comment"
            }
            Rectangle {
                height: parent.height
                width: parent.width - 96
                border.color: "#000000"
                color: "transparent"
                TextEdit {
                    id: commentTextEdit
                    anchors.fill: parent
                    cursorVisible: true
                }
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
            text: "prev"
            onClicked: {
                console.log(lightListView.currentIndex + " " + lightListView.currentItem.colorId)
                console.log(baseListView.currentIndex + " " + baseListView.currentItem.colorId)
                console.log(shadowListView.currentIndex + " " + shadowListView.currentItem.colorId)
                recipeList.save(nameTextEdit.text,
                                categoryTextEdit.text,
                                lightListView.currentItem.colorId,
                                baseListView.currentItem.colorId,
                                shadowListView.currentItem.colorId,
                                commentTextEdit.text)
                back();
            }
        }
    }
}
