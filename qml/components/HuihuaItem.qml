import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0


Rectangle{
    property var headImage
    property var nickname
    property var content
    property var datetime
    property var isSelect: false
    property var isEntered: false
    width:parent.width
    height: 65
    color: isSelect||isEntered?"#C4C4C4":"#00000000"

    MouseArea{
        anchors.fill: parent
        hoverEnabled:true
        onEntered: {
           // parent.color = "#C4C4C4"
            isEntered = true
        }
        onExited: {
            isEntered = false
           // if(_isSelect)return
          //  parent.color = "#00000000"
        }

    }

    Rectangle{
        width:parent.width *0.95
        height:65 *0.75
        color: "#00000000"
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter  : parent.horizontalCenter

        ImageButton{
            width: parent.height
            height: parent.height
            _isNetWork:true
            _source: "https://g.csdnimg.cn/static/face/monkey2/023.png"
        }

        Rectangle{
            width:parent.width*0.78
            height: parent.height
            color: "#00000000"
            anchors.right: parent.right
            Text {
                text: qsTr("te1111")
                font.weight: Font.Bold
                font.pointSize: 12
                anchors.top:parent.top
                width: parent.width*0.5
                elide: Text.ElideRight
            }
            Text{
                text: qsTr("t545ssssssssssskvdf")
                verticalAlignment: Text.AlignBottom
                anchors.bottom: parent.bottom
                font.pointSize: 12
                width: parent.width*0.7
                color: "#808080"
                elide: Text.ElideRight
            }
            Text{
                color: "#808080"
                text: qsTr("01/02/19")
                verticalAlignment: Text.AlignBottom
                anchors.top: parent.top
                anchors.right: parent.right
                font.pointSize: 12
                // width: parent.width*0.7
                //  elide: Text.ElideRight
            }

        }


    }



}
