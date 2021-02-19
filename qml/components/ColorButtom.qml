import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0

Rectangle{
    id:root
    property var _width
    property var _height
    property var _imageWidth
    property var _imageHeight
    property var _color
    property var _enteredColor
    property var _image
    property var _enteredImage
    width: _width
    height:_height
    color:_color

    Image{
        id:image
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: _image
        width:  _imageWidth
        height:_imageHeight
    }


    MouseArea{
        anchors.fill: parent
        hoverEnabled:true
        onEntered: {
            root.color =  _enteredColor
            image.source = _enteredImage
        }
        onExited: {
            root.color = _color
            image.source =_image
        }

    }
}


