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
