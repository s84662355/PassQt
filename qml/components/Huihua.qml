import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0

Rectangle{
    anchors.fill: parent
    color: "#eeeae8"
    property var select_index:0

    Component {
            id: listDelegate;
            HuihuaItem{
               isSelect: select_index == index
               MouseArea{
                   anchors.fill: parent
                   onClicked:{
                           select_index= index
                   }
               }
            }


    }

    ListView {
        highlightFollowsCurrentItem: true
        cacheBuffer: 50
        interactive: true
        anchors.fill: parent
        delegate: listDelegate
        model: [
              {},{},{},{},
              {},{},{},{},
              {},{},{},{},
              {},{},{},{},
              {},{},{},{},
              {},{},{},{},
          ]

    }





}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
