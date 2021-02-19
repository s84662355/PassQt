import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0
import "./components"
Item{
    id: root


    signal sendClose()
    signal sendLogin(string username,string password)

    Rectangle{
        id:leftBorder
        width: 60
        height: parent.height
        color: "#282b2e"

        LeftSelectRect{
            id:leftSelectRect
         //   head_source : "qrc:/image/head.jpg"
           head_source :"https://g.csdnimg.cn/static/face/monkey2/008.png"
             select_callBacll:function(id){
                console.log(id)
            }
        }
    }


    Rectangle{
        anchors.left: leftBorder.right
        height: parent.height
        width:250
        Huihua{
          //  HuihuaItem{}

        }

    }






}




/*##^##
Designer {
    D{i:0;autoSize:true;height:380;width:280}
}
##^##*/
