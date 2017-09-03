/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

import QtQuick 2.0

Item {
    property color light: "transparent"
    property color base: "transparent"
    property color shadow: "transparent"
    Rectangle{
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: (light===""?"transparent":light) }
            GradientStop { position: 0.5; color: (base===""?"transparent":base) }
            GradientStop { position: 1.0; color: (shadow===""?"transparent":shadow) }
        }
    }
}
