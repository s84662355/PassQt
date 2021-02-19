import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0

Item{
   id:root

   signal close();
   signal small();

   Rectangle{
       anchors.fill: parent
      // color: "#fbfbfb"
     //  color:rgb(240,240,240)
       color:"#f0f0f0"
       Rectangle{
           height: 25
           color:"#00000000"
         //  color: "red"
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
               MouseArea{
                 anchors.fill: parent
                 onClicked: {
                    root.close()
                     console.log("window close")
                 }
               }
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
               MouseArea{
                 anchors.fill: parent
                 onClicked: {
                    root.small();
                      console.log("window small")
                 }
               }

           }


       }


   }


}

/*##^##
Designer {
    D{i:0;autoSize:true;height:100;width:300}
}
##^##*/
