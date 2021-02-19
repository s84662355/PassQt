import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
Item{
    id: root
    property var m_widgetWidth: 0
    property var m_widgetHeight: 0
    signal sendClose()
    signal sendLogin(string username,string password)

    function isLoginFunc(  code ,   msg ){
          console.log(code+ " mbfgiopju903b j940b j " +msg)
    }


    Rectangle{
        color: "#fbfbfb"
        anchors.fill: parent
        Rectangle{
            id:topMeun
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            height: 30
            color: "#00000000"
            Text {
                color: "#dbdbdb"
                text: qsTr("Pass")
                anchors.leftMargin: 5
                font.pointSize: 13
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
            Rectangle{
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                width:40
                height: 30
                color: "#00000000"
                MouseArea{
                    propagateComposedEvents: true
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: { //监听鼠标进入
                        parent.color = "red"
                        closeIcon.source ="qrc:/image/loginclose2.png"
                    }
                    onExited: { //监听鼠标移出
                        parent.color = "#00000000"
                        closeIcon.source = "qrc:/image/loginclose1.png"
                    }
                    onClicked: {
                        root.sendClose();
                        console.log("loginclose")
                    }
                }
                Image {
                    id: closeIcon
                    width:20
                    height: 20
                    anchors.horizontalCenter:   parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:/image/loginclose1.png"
                    autoTransform: true //图像是否自动变换，默认为false
                }

            }
        }

        Rectangle{
            color: "#fbfbfb"
            anchors.top:topMeun.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            MouseArea{
                propagateComposedEvents: true
                anchors.fill: parent
            }
            Image{
                id:logo
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top:parent.top
                anchors.topMargin: 30
                width:100
                height: 100
                source: "qrc:/image/newyear.png"
                autoTransform: true //图像是否自动变换，默认为false
            }
            Rectangle{
                color: "#fbfbfb"
                anchors.top:logo.bottom
                anchors.topMargin: 40
                anchors.bottom: parent.bottom
                width:parent.width

                Row{
                    id:usernameRow
                    anchors.horizontalCenter: parent.horizontalCenter
                    width:parent.width*0.8
                    height: 35
                    Text {
                        id:usernameText
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left:parent.left
                        text: qsTr("用户名称：")
                    }

                    Rectangle {
                        height: parent.height*0.8
                        border.color: "grey"
                        anchors.right: parent.right
                        anchors.left: usernameText.right
                        anchors.verticalCenter: parent.verticalCenter
                        TextInput {
                            id:username
                            anchors.fill: parent
                            height: parent.height
                            anchors.margins: 2
                            font.pointSize: 10
                            focus: true
                            maximumLength:18
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }


                Row{
                    id:passwordRow
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top:usernameRow.bottom
                    anchors.topMargin: 20
                    width:parent.width*0.8
                    height: 35
                    Text {
                        id:passwordText
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left:parent.left
                        text: qsTr("用户密码：")
                    }

                    Rectangle {
                        height: parent.height*0.8
                        border.color: "grey"
                        anchors.right: parent.right
                        anchors.left: passwordText.right
                        anchors.verticalCenter: parent.verticalCenter
                        TextInput {
                            id:password
                            anchors.fill: parent
                            height: parent.height
                            echoMode: TextInput.Password
                            passwordCharacter: "**"
                            anchors.margins: 2
                            font.pointSize: 10
                            focus: true
                            maximumLength:18
                            verticalAlignment: Text.AlignVCenter

                        }
                    }
                }

                Rectangle{
                    id:loginMeun
                    width:parent.width  *0.8
                    anchors.horizontalCenter:   parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 30
                    height: 40
                    color: "#07d214"
                    Text {
                        width: 35
                        color: "#fdfdfd"
                        anchors.horizontalCenter:   parent.horizontalCenter
                        anchors.verticalCenter:    parent.verticalCenter
                        text: qsTr("登录")
                    }
                    MouseArea{
                        propagateComposedEvents: true
                        anchors.fill: parent
                        hoverEnabled: true
                        onExited: { //监听鼠标移出
                            parent.color = "#07d214"
                        }
                        onEntered: {
                            parent.color = "#019713"
                        }

                        onClicked:  {
                          //  popup.showMask = chk.checked;
                           //    popup.animationType = 'size';
                            ///   popup. open()
                            console.log("senfLogin:",username.text,password.text)
                            root.sendLogin(username.text,password.text)
                        }
                    }

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
