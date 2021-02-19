import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0

Rectangle{
    id:selectRectangle
    width:35
    color: "#c87777"
    anchors.top: parent.top
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.topMargin: 20
    property  var  head_source
    property  var  select_id:0
    property  var  select_callBacll
    Column{
        anchors.fill: parent
        spacing: 30
        ImageButton{
            _height:35
            _width:35
            _isNetWork:true
            _source: head_source
        }

        ImageButton{
            _height:20
            _width:20

            anchors.horizontalCenter: parent.horizontalCenter
            _source: selectRectangle.select_id==0? "qrc:/image/huihua1.png": "qrc:/image/huihua.png"
            MouseArea{
                propagateComposedEvents: true
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    selectRectangle. select_id = 0

                    selectRectangle.select_callBacll (  selectRectangle. select_id)

                }
            }
        }


        ImageButton{
            _height:25
            _width:25

            anchors.horizontalCenter: parent.horizontalCenter
            _source: selectRectangle.select_id==1? "qrc:/image/friend1.png": "qrc:/image/friend.png"
            MouseArea{
                propagateComposedEvents: true
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {

                    selectRectangle. select_id = 1
                    selectRectangle.select_callBacll (  selectRectangle. select_id)


                }
            }
        }

    }
}
