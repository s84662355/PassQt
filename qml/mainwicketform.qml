import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0
import "./components"

Item{
    id: root

    Rectangle{
        anchors.fill: parent
        color: "#fbfbfb"
        Rectangle{
            id:topTitle
            width:parent.width
            height:60
            color: "#fbfbfb"
            Rectangle{
                width:parent.width
                anchors.bottom: parent.bottom
                height: 1
                color: "#e4dfdf"
            }



            Label{
                text: "ndbdfb"
                anchors.left: parent.left
                anchors.leftMargin: 20
                font.pointSize: 15
                font.weight: Font.ExtraBold
                anchors.verticalCenter: parent.verticalCenter

            }


            Rectangle{
                height: 25
                color:"#00000000"
                width: 100
                anchors.right: parent.right
                anchors.top:parent.top


                ColorButtom{
                    id:closeButton
                    anchors.right: parent.right
                    anchors.top: parent.top
                    _width:33
                    _height:25
                    _imageWidth:8
                    _imageHeight:8
                    _color:"#00000000"
                    _enteredColor:"red"
                    _image:"qrc:/image/close1.png"
                    _enteredImage:"qrc:/image/close2.png"
                }

                ColorButtom{
                    id:xiaohuaButton
                    anchors.right: closeButton.left
                    anchors.top: parent.top
                    _width:33
                    _height:25
                    _imageWidth:8
                    _imageHeight:8
                    _color:"#00000000"
                    _enteredColor:"#EAEAEA"
                    _image:"qrc:/image/zuixiaohua1.png"
                    _enteredImage:"qrc:/image/zuixiaohua2.png"
                }




            }
        }

    }


}




/*##^##
Designer {
    D{i:0;autoSize:true;height:380;width:280}
}
##^##*/
