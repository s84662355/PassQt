import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0
import MyImageCache 1.0

Rectangle{
    property var _width
    property var _height
    property var  _source
    property var  _isNetWork : false
    property var  _color : "#00000000"
    property var  test : "#00000000"
    property var imageSource

    width:_width
    height:_height
    color: _color

    function loadimage(){
        console.log(_source+"2222222222222")
        imageCache.loadImage()
    }


    ImageCache{
        id:imageCache
        //cacheDir:"./fdkdfkl"
        errorImage:"qrc:/image/newyear.png"
        imageUrl:_source
        jsCallback:function(x,y,z,e){
            console.log(x,y,z,e)
            _image.source = ""
            _image.source = "file:///"+z
 console.log( _image.source)
            //  _source = "file:///"+z

        }
    }

    Component.onCompleted: {
        if(_isNetWork){
            imageCache.loadImage()
        }else{
            ImageSource =  _source
        }

    }

    Image{
        id:_image
        //    source:imageSource
        anchors.fill: parent
        sourceSize: Qt.size(parent.size, parent.size)
        antialiasing: true
        opacity: 1
        smooth: false
        visible: false
        asynchronous: true;
        cache: true
    }
    Rectangle {
        id: _mask
        color: "black"
        anchors.fill: parent
        radius: width / 8
        visible: false
        antialiasing: true
        smooth: true
    }
    OpacityMask {
        id: mask_image
        anchors.fill: _image
        source: _image
        maskSource: _mask
        visible: true
        antialiasing: true
    }


}
