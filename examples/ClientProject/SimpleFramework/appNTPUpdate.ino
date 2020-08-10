#include <WiFi.h>
#include "time.h"

// almost entirely taken from https://www.instructables.com/id/Lilygo-T-Watch-2020-Arduino-Framework/

void appNTPUpdate() {

  // WiFi settings ******* Use your network values **********
  const char* ssid     = "SSID";
  const char* password = "Password";

// const char* ntpServer = "pool.ntp.org"; //2.ca.pool.ntp.org
  const char* ntpServer = "2.ca.pool.ntp.org";
  //const long  gmtOffset_sec = -18000; // This seems to put me in the wrong timezone (2 hrs later, so let's remove a couple hours).
  const long  gmtOffset_sec = -25200; 
  const int   daylightOffset_sec = 3600;
  

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {}

  configTime(gmtOffset_sec, daylightOffset_sec , "pool.ntp.org", "time.nis.gov");
  delay(3000);

  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    ttgo->tft->drawString("Failed",  5, 30, 1);
  } else {
    ttgo->tft->setCursor(0, 130);
    ttgo->tft->print(&timeinfo, "%A, %B %d %Y\n%H:%M:%S");
    ttgo->rtc->setDateTime(timeinfo.tm_year, timeinfo.tm_mon + 1, timeinfo.tm_mday, timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
  }
  quickBuzz();
  delay(5000);
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);

  ttgo->tft->fillScreen(TFT_BLACK);
}
