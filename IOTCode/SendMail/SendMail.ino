#include <WiFi.h>
uint8_t MacData[6];
char ssid[] = "IOT";      // your network SSID (name)
char pass[] = "0123456789";     // your network password
WiFiClient client;
char server[] = "ms1.hinet.net";    // name address for Google (using DNS)
IPAddress  Meip ,Megateway ,Mesubnet ;
String MacAddress ;
int status = WL_IDLE_STATUS;



void ShowMac()
{
  
     Serial.print("MAC:");
     Serial.print(MacAddress);
     Serial.print("\n");

}




String GetWifiMac()
{
   String tt ;
    String t1,t2,t3,t4,t5,t6 ;
    WiFi.status();    //this method must be used for get MAC
  WiFi.macAddress(MacData);
  
  Serial.print("Mac:");
   Serial.print(MacData[0],HEX) ;
   Serial.print("/");
   Serial.print(MacData[1],HEX) ;
   Serial.print("/");
   Serial.print(MacData[2],HEX) ;
   Serial.print("/");
   Serial.print(MacData[3],HEX) ;
   Serial.print("/");
   Serial.print(MacData[4],HEX) ;
   Serial.print("/");
   Serial.print(MacData[5],HEX) ;
   Serial.print("~");
   
   t1 = print2HEX((int)MacData[0]);
   t2 = print2HEX((int)MacData[1]);
   t3 = print2HEX((int)MacData[2]);
   t4 = print2HEX((int)MacData[3]);
   t5 = print2HEX((int)MacData[4]);
   t6 = print2HEX((int)MacData[5]);
 tt = (t1+t2+t3+t4+t5+t6) ;
Serial.print(tt);
Serial.print("\n");
  
  return tt ;
}
String  print2HEX(int number) {
  String ttt ;
  if (number >= 0 && number < 16)
  {
    ttt = String("0") + String(number,HEX);
  }
  else
  {
      ttt = String(number,HEX);
  }
  return ttt ;
}





void printWifiData() 
{
  // print your WiFi shield's IP address:
  Meip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(Meip);
  Serial.print("\n");

  // print your MAC address:
  byte mac[6];
  WiFi.macAddress(mac);
  Serial.print("MAC address: ");
  Serial.print(mac[5], HEX);
  Serial.print(":");
  Serial.print(mac[4], HEX);
  Serial.print(":");
  Serial.print(mac[3], HEX);
  Serial.print(":");
  Serial.print(mac[2], HEX);
  Serial.print(":");
  Serial.print(mac[1], HEX);
  Serial.print(":");
  Serial.println(mac[0], HEX);

  // print your subnet mask:
  Mesubnet = WiFi.subnetMask();
  Serial.print("NetMask: ");
  Serial.println(Mesubnet);

  // print your gateway address:
  Megateway = WiFi.gatewayIP();
  Serial.print("Gateway: ");
  Serial.println(Megateway);
}

void ShowInternetStatus()
{
    
        if (WiFi.status())
          {
               Meip = WiFi.localIP();
               Serial.print("Get IP is:");
               Serial.print(Meip);
               Serial.print("\n");
              
          }
          else
          {
                       Serial.print("DisConnected:");
                       Serial.print("\n");
          }

}

void initializeWiFi() {
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);
   // status = WiFi.begin(ssid);

    // wait 10 seconds for connection:
    delay(10000);
  }
  Serial.print("\n Success to connect AP:") ;
  Serial.print(ssid) ;
  Serial.print("\n") ;
  
}

void setup() {
    Serial.begin(9600);
    Serial.println("Program Start") ;
    MacAddress = GetWifiMac() ; // get MacAddress
    ShowMac() ;       //Show Mac Address
        initializeWiFi();
        printWifiData() ;
   delay(2000);
  Serial.println(F("Ready. Press 'e' to send."));
        
}

void loop() { // run over and over
    byte inChar;
 
  inChar = Serial.read();
 
  if(inChar == 'e')
  {
      if(sendEmail()) Serial.println(F("Email sent"));
      else Serial.println(F("Email failed"));
  }
}
byte sendEmail()
{
  byte thisByte = 0;
  byte respCode;
 
  if(client.connect(server,25) == 1) {
    Serial.println(F("connected"));
  } else {
    Serial.println(F("connection failed"));
    return 0;
  }
 
  if(!eRcv()) return 0;
  Serial.println(F("Sending helo"));
 
// change to your public ip
  client.print(F("helo "));
  client.println(Meip); 
  
  if(!eRcv()) return 0;
  Serial.println(F("Sending From"));
 
// change to your email address (sender)
  client.println(F("MAIL From: <tyc6095@ms1.hinet.net>"));
 
  if(!eRcv()) return 0;
 
// change to recipient address
  Serial.println(F("Sending To"));
  client.println(F("RCPT To: <tyc6095@ms1.hinet.net>"));
 
  if(!eRcv()) return 0;
 
  Serial.println(F("Sending DATA"));
  client.println(F("DATA"));
 
  if(!eRcv()) return 0;
 
  Serial.println(F("Sending email"));
 
// change to recipient address
  client.println(F("To: You <tyc6095@ms1.hinet.net>"));
 
// change to your address
  client.println(F("From: Me <tyc6095@ms1.hinet.net>"));
 
  client.println(F("Subject: Arduino email test\r\n"));
 
  client.println(F("This is from my Arduino!"));
 
  client.println(F("."));
 //  client.print("\r\n");
  if(!eRcv()) return 0;
 
  Serial.println(F("Sending QUIT"));
  client.println(F("QUIT"));
 
  if(!eRcv()) return 0;
 
  client.stop();
 
  Serial.println(F("disconnected"));
 
  return 1;
}
 
byte eRcv()
{
  byte respCode;
  byte thisByte;
  int loopCount = 0;
 
  while(!client.available()) {
    delay(1);
    loopCount++;
 
    // if nothing received for 10 seconds, timeout
    if(loopCount > 10000) {
      client.stop();
      Serial.println(F("\r\nTimeout"));
      return 0;
    }
  }
 
  respCode = client.peek();
 
  while(client.available())
  {  
    thisByte = client.read();    
    Serial.write(thisByte);
  }
 
  if(respCode >= '4')
  {
    efail();
    return 0;  
  }
 
  return 1;
}
 
 
void efail()
{
  byte thisByte = 0;
  int loopCount = 0;
 
  client.println(F("QUIT"));
 
  while(!client.available()) {
    delay(1);
    loopCount++;
 
    // if nothing received for 10 seconds, timeout
    if(loopCount > 10000) {
      client.stop();
      Serial.println(F("\r\nTimeout"));
      return;
    }
  }
 
  while(client.available())
  {  
    thisByte = client.read();    
    Serial.write(thisByte);
  }
 
  client.stop();
 
  Serial.println(F("disconnected"));
}
