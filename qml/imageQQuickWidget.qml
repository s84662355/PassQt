import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0
import "./components"

Item{
    id: root
    property var imageUrl

    Rectangle{
        anchors.fill: parent
        color: "red"
        Text {

            text: qsTr("text")
        }

    }

}




/*##^##
Designer {
    D{i:0;autoSize:true;height:380;width:280}
}
##^##*/
