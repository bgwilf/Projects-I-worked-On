#include <stdlib.h>
#include <SoftwareSerial.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
#define SSID "Gilles's iPhone" //replace XXXXX by your router SSID
#define PASS "elossab33" //replace YYYYY by your router password
#define IP "184.106.153.149" // thingspeak.com IP
#define DHT22_PIN 2
#define DHTTYPE DHT11;

String GET = "GET /update?key=ZZZZZ&field1="; //replace ZZZZZ by your ThingSpeak channel write key
SoftwareSerial monitor(10, 11); //Serial communication to ESP8266 module (RX, TX)

//DHT dht;
DHT dht(DHT_PIN, DHTTYPE); 
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

//Variables
int luminancePin = A0;
int uvPin = A1;
int dustPin = 8;
unsigned long duration;
unsigned long starttime;
unsigned long sampletime_ms = 30000;
unsigned long delay_time = 60000;
unsigned long lowpulseoccupancy = 0;
float ratio = 0;
float concentration = 0;

//setup
void setup()
{
  //start serial communications
  Serial.begin(9600);
  monitor.begin(9600);
  Serial.println("Initializing...");

  //configure Arduino pins
  pinMode(dustPin, INPUT);
  
  //initialize pressure sensor
  Serial.println("Detecting BMP085 pressure sensor...");
  if(!bmp.begin())
  {
    Serial.println("BMP085 sensor wasn't detected. Verify your connections or I2C ADDR!");
    while(1);
   }
   Serial.println("BMP085 detected!");

    //communication with wifi module
    monitor.flush();
    monitor.println("AT");
    delay(2000);
    
    if(monitor.find("OK")){
      Serial.println("Communication with ESP8266 module: OK");
    }
    else {
      Serial.println("ESP8266 module ERROR");
    }

  //connect wifi router  
  connectWiFi(); 
     
  Serial.print("Sampling (");
  Serial.print(sampletime_ms/1000);
  Serial.println("s)...");
  
  //initialize timer
  starttime = millis();

}

void loop(){

  //measuring dust particles
  duration = pulseIn(dustPin, LOW);
  lowpulseoccupancy = lowpulseoccupancy + duration;
  
  //30 seconds cicle
  if ((millis() - starttime) >= sampletime_ms)
  {
    ratio = lowpulseoccupancy/(sampletime_ms*10.0);  // percentage (de 0 a 100%)
    concentration = 1.1*pow(ratio,3)-3.8*pow(ratio,2)+520*ratio+0.62; // from datsheet
    lowpulseoccupancy = 0;
    
    //read other sensors
    char buffer[10];
    //light sensor
    float luminance = analogRead(luminancePin);
    //UV sensor
    float uv = analogRead(uvPin);
    uv = uv * 0.0049; //convert values to volts
    uv = uv * 307; //convert to mW/m²
    uv = uv/200; //calculate UV index
    //temperature and humidity
    int chk = DHT.read22(DHT22_PIN);
    float humidity = DHT.humidity;
    float temperature = DHT.temperature;
    //pressure and temperature1
    sensors_event_t event;
    bmp.getEvent(&event);
    float pressure = 0;
    float temperature1 = 0;
    if (event.pressure)
    {
      pressure = event.pressure;
      bmp.getTemperature(&temperature1);
    }

    //convert sensor values to strings
    String luminanceStr = dtostrf(luminance, 4, 1, buffer);
    luminanceStr.replace(" ","");
    String uvStr = dtostrf(uv, 4, 1, buffer);
    uvStr.replace(" ","");
    String humidityStr = dtostrf(humidity, 4, 1, buffer);
    humidityStr.replace(" ","");
    String temperatureStr = dtostrf(temperature, 4, 1, buffer);
    temperatureStr.replace(" ","");
    String dustStr = dtostrf(concentration, 4, 1, buffer);
    dustStr.replace(" ","");
    String pressureStr = dtostrf(pressure, 4, 1, buffer);
    pressureStr.replace(" ","");
    String temperature1Str = dtostrf(temperature1, 4, 1, buffer);
    temperature1Str.replace(" ","");
        
    //send data to ThingSpeak
    updateSensors(luminanceStr, humidityStr, temperatureStr, uvStr, dustStr, pressureStr, temperature1Str);

    //wait next sampling cycle
    Serial.print("Wait ");
    Serial.print(delay_time/1000);
    Serial.println("s for next sampling");
    Serial.println();
    delay(delay_time);
    
    //initialize new cycle
    Serial.println();
    Serial.print("Sampling (");
    Serial.print(sampletime_ms/1000);
    Serial.println("s)...");
    starttime = millis();
  }
}

//Send data to ThingSpeak
void updateSensors(String luminanceStr, String humidityStr, String temperatureStr, String uvStr, String dustStr, String pressureStr, String temperature1Str) {

  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  monitor.println(cmd);
  delay(2000);
 
  cmd = GET;
  cmd += luminanceStr;
  cmd += "&field2=";
  cmd += humidityStr;
  cmd += "&field3=";
  cmd += temperatureStr;
  cmd += "&field4=";
  cmd += uvStr;
  cmd += "&field5=";
  cmd += dustStr;
  cmd += "&field6=";
  cmd += pressureStr;
  cmd += "&field7=";
  cmd += temperature1Str;
  cmd += "\r\n";
  delay(1000);
  int strsize = cmd.length();
  monitor.println("AT+CIPSEND=" + String(strsize));
  delay(2000);
  
  monitor.print(cmd);
  if(monitor.find("OK")){
    Serial.println("Transmission completed with success");
  }else{
    Serial.println("Transmission failed!");
  }
}

void sendDebug(String cmd){
  Serial.print("SEND: ");
  Serial.println(cmd);
  monitor.println(cmd);
} 
 
boolean connectWiFi(){
  Serial.println("Connecting wi-fi...");
  String cmd ="AT+CWMODE=1";
  monitor.println(cmd);
  delay(2000);
  monitor.flush(); //clear buffer
  cmd="AT+CWJAP=\"";
  cmd+=SSID;
  cmd+="\",\"";
  cmd+=PASS;
  cmd+="\"";
  monitor.println(cmd);
  delay(5000);
  
  if(monitor.find("OK")){
    Serial.println("Connection succeeded!");
    return true;
  }else{
    Serial.println("Connection failed!");
    return false;
  }
  Serial.println();
}
