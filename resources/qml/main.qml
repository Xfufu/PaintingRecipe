/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: rootWindow
    visible: true
    width: 800
    height: 600
    title: qsTr("PaintingRecipe")

    background: Rectangle {
        color: "#9c8072"
        gradient: Gradient {
            GradientStop {
                position: 0.00;
                color: "#b98a8a";
            }
            GradientStop {
                position: 1.00;
                color: "#ffffff";
            }
        }
    }
    Component {
        id: addComponent
        AddView {
            onBack: {
                stackView.pop()
            }
        }
    }
    Component {
        id: removeComponent
        RemovePage {
            onBack: {
                stackView.pop()
            }
        }
    }
    Component {
        id: mainComponent
        MainPage {
            stack: stackView
            onAddView: {
                stack.push(addComponent)
            }
            onRemovePage: {
                stack.push(removeComponent)
            }
        }
    }
    StackView {
        id: stackView
        anchors.fill: parent
        popEnter: Transition {
            PropertyAnimation{
                properties: "opacity"
                from: 0
                to: 1
                duration: 500
            }
            PropertyAnimation{
                properties: "scale"
                from: 0
                to: 1
                duration: 500
            }
        }
        popExit: Transition {
            PropertyAnimation{
                properties: "opacity"
                from: 1
                to: 0
                duration: 500
            }
            PropertyAnimation{
                properties: "scale"
                from: 1
                to: 0
                duration: 500
            }
        }
        pushEnter: Transition {
            PropertyAnimation{
                properties: "opacity"
                from: 0
                to: 1
                duration: 500
            }
            PropertyAnimation{
                properties: "scale"
                from: 0
                to: 1
                duration: 500
            }
        }
        pushExit: Transition {
            PropertyAnimation{
                properties: "opacity"
                from: 1
                to: 0
                duration: 500
            }
            PropertyAnimation{
                properties: "scale"
                from: 1
                to: 0
                duration: 500
            }
        }
    }
    Component.onCompleted: {
        //        Window.showFullScreen()
        //rootWindow.showFullScreen()
        stackView.push(mainComponent)
        recipeList.init()
    }
}
