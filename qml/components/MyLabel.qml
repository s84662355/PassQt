import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0

Rectangle {
    id: root
    width: 300
    height: 300


    TextArea {
        id: lbl_name_show

        anchors{
            left:lab_name.right
            top:lab_name.top
        }
        verticalScrollBarPolicy: Qt.ScrollBarAlwaysOff
        implicitHeight: lab_name.height
        antialiasing: true
        readOnly: true
        frameVisible : false
        backgroundVisible : false
        contentItem : TextArea{
            id: lab_txt
            text:"三个程序员fffffdasasdsadsadasasdsadsadsadsadffffffffff"
            readOnly: true
            font.pixelSize: 16
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 4
            frameVisible : false
            backgroundVisible : false
        }

        visible: true
    }

}

