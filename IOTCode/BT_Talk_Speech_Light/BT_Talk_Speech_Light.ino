#include <SoftwareSerial.h>   // 引用程式庫
#define LedPin 13
#define ascStart 48
char getdata ;  // 儲存接收資料的變數

// 定義連接藍牙模組的序列埠
SoftwareSerial BT(0, 1); // 接收腳, 傳送腳

void setup() {
  
  pinMode(LedPin , OUTPUT) ;    // set Button pin as input data
  
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial.println("BT is ready!");

  // 設定藍牙模組的連線速率
  // 如果是HC-05，請改成38400
  BT.begin(9600);
   allLightOn() ;
   delay(1000);
   allLightOff() ;
}

void loop() {
     
    getdata = '@'; 
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if (BT.available()) {
    getdata = BT.read();
    Serial.print(getdata, HEX);
  }

    if (getdata == '0')
        {
          allLightOff() ;
        }

    if (getdata == '1')
        {
          digitalWrite(LedPin, HIGH) ;
        }

}

void allLightOn()
{
            digitalWrite(LedPin, HIGH) ;
}

void allLightOff()
{
         digitalWrite(LedPin, LOW) ;
}


