#include <WiFi.h>
#include <WiFiClientSecure.h>

//String key = "KEY";
//String event = "Event"; 

void appIFTTT() {
const char* ssid     = "SSID";
const char* password = "Password";
const char* host = "maker.ifttt.com";
const int httpsPort = 443;

  int16_t x, y;
  ttgo->tft->fillScreen(TFT_PURPLE);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {}
 while (ttgo->getTouch(x, y)) {}
 
 WiFiClient client;
  const int httpPort = 80;
  client.connect(host, httpPort);
  String url = "/trigger/" + event +"/with/key/" + key;
//  Serial.print("requesting URL: ");
//  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP32\r\n" +
               "Connection: close\r\n\r\n");
//  Serial.println("request sent");

  while (client.connected()) {

    String line = client.readStringUntil('\n');

    if (line == "\r") {

     // Serial.println("headers received");

      break;

    }

  }

  String line = client.readStringUntil('\n');

  ttgo->tft->setTextSize(2);
  ttgo->tft->setTextColor(TFT_GREEN);
  ttgo->tft->setCursor(40, 90);

  ttgo->tft->println("IFTTT Trigger");
  ttgo->tft->setCursor(70, 130);
  ttgo->tft->println("Completed");
  
  client.stop();
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);

  while (!ttgo->getTouch(x, y)) {} // wait until you touching
  while (ttgo->getTouch(x, y)) {}
  ttgo->tft->fillScreen(TFT_BLACK);

 // Serial.println("reply was:");

 // Serial.println("==========");

//  Serial.println(line);

 // Serial.println("==========");

//  Serial.println("closing connection");

}

 

