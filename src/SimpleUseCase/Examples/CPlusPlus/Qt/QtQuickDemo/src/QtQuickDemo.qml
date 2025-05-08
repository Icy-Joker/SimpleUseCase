import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

import QtQuick.Dialogs

ApplicationWindow {
  visible: true
  //visibility: ApplicationWindow.FullScreen
  title: "Qt Quick Example"
  
  width: 640
  height: 480
  
  RowLayout {
    GroupBox {
      //id: groupBox
      title: "输入类"
      GridLayout {
        rows: 6
        columns: 2
        
        Label {
          text: "文本框"
        }
        TextField {
          //id: textField
          placeholderText: "请输入内容"
        }
        
        Label {
          text: "整数输入框"
        }
        SpinBox {
          //id: spinBox
          from: 0
          to: 100
        }
        
        Label {
          text: "浮点数输入框"
        }
        TextField {
          //id: textField
          placeholderText: "请输入浮点数"
          validator: DoubleValidator {
            bottom: 0.0      // 设置最小值
            top: 100.0      // 设置最大值
            decimals: 2     // 限制小数位数
          }
          onTextChanged: {
            console.log("当前输入:", text)
          }
        }
        
        Label {
          text: "日期选择框"
        }
        TextField {
          //id: textField
          placeholderText: "请输入浮点数"
          validator: DoubleValidator {
            bottom: 0.0      // 设置最小值
            top: 100.0      // 设置最大值
            decimals: 2     // 限制小数位数
          }
          onTextChanged: {
            console.log("当前输入:", text)
          }
        }
        
        Label {
          text: "时间选择框"
        }
        TextField {
          //id: textField
          placeholderText: "请输入浮点数"
          validator: DoubleValidator {
            bottom: 0.0      // 设置最小值
            top: 100.0      // 设置最大值
            decimals: 2     // 限制小数位数
          }
          onTextChanged: {
            console.log("当前输入:", text)
          }
        }
        
        Label {
          text: "字体选择框"
        }
        TextField {
          //id: textField
          placeholderText: "请输入浮点数"
          validator: DoubleValidator {
            bottom: 0.0      // 设置最小值
            top: 100.0      // 设置最大值
            decimals: 2     // 限制小数位数
          }
          onTextChanged: {
            console.log("当前输入:", text)
          }
        }
      }
    }
    GroupBox {
      //id: groupBox
      title: "按钮类"
      ColumnLayout {
        GroupBox {
          //id: groupBox
          title: "单选框"
          Layout.fillWidth: true
          Layout.fillHeight: true
          RowLayout {
            RadioButton {
              //id: radioButton
              text: "RadioButton"
              onClicked: {
                console.log("clicked")
              }
            }
            RadioButton {
              //id: radioButton
              text: "RadioButton"
              onClicked: {
                console.log("clicked")
              }
            }
            RadioButton {
              //id: radioButton
              text: "RadioButton"
              onClicked: {
                console.log("clicked")
              }
            }
          }
        }
        GroupBox {
          //id: groupBox
          title: "复选框"
          Layout.fillWidth: true
          Layout.fillHeight: true
          RowLayout {
            CheckBox {
              //id: checkBox
              text: "CheckBox"
              onClicked: {
                console.log("Option 1 is " + (checkBox.checked ? "checked" : "unchecked"))
              }
            }
            
            CheckBox {
              //id: checkBox
              text: "CheckBox"
              onClicked: {
                console.log("Option 2 is " + (checkBox.checked ? "checked" : "unchecked"))
              }
            }
            
            CheckBox {
              //id: checkBox
              text: "CheckBox"
              onClicked: {
                console.log("Option 3 is " + (checkBox.checked ? "checked" : "unchecked"))
              }
            }
          }
        }
        GroupBox {
          //id: groupBox
          title: "输出信息框"
          Layout.fillWidth: true
          Layout.fillHeight: true
          RowLayout {
            MessageDialog {
              id: messageDialog
              title: "Information"
              text: "This is a message dialog."
              onAccepted: {
                console.log("User clicked OK")
              }
            }
            Button {
              text: "信息"
              //id: button
              onClicked: {
                messageDialog.open()
              }
            }
            
            Button {
              //id: button
              text: "警告"
              onClicked: {
                console.log("Option 2 is " + (button.checked ? "checked" : "unchecked"))
              }
            }
            
            Button {
              //id: button
              text: "询问"
              onClicked: {
                console.log("Option 3 is " + (button.checked ? "checked" : "unchecked"))
              }
            }
            
            Button {
              //id: button
              text: "错误"
              onClicked: {
                console.log("Option 4 is " + (button.checked ? "checked" : "unchecked"))
              }
            }
          }
        }
      }
    }
  }
}
