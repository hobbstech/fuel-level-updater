#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define HTTP_GET_METHOD 0
#define HTTP_POST_METHOD 1 
#define HTTP_PUT_METHOD 2 

const char *ssid = "HobbsTech";
const char *password = "qwertyuiop";

void setupWifi() {
  Serial.println("---> Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

String doHttpCall(String url, String payload, int httpMethod) {

  Serial.print("-----> ");
  Serial.println(url);
  Serial.print("-----> ");
  Serial.println(payload);

  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    http.begin(url);

    int httpCode;

    switch (httpMethod) {

      case HTTP_GET_METHOD :
        httpCode = http.GET();
        break;

      case HTTP_POST_METHOD :
        http.addHeader("Content-Type", "application/json");
        httpCode = http.POST(payload);
        break;

      case HTTP_PUT_METHOD :
        http.addHeader("Content-Type", "application/json");
        httpCode = http.PUT(payload);
        break;

    }

    String responsePayload = http.getString();

    Serial.print("---> Response : ");
    Serial.print(httpCode);
    Serial.print(" : ");
    Serial.println(responsePayload);

    http.end();

    return responsePayload;

  } else {

    Serial.println("---> WiFi is not connected, could not send data");

  }
}
