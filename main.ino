#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "loke J"; // Your Wi-Fi network name
const char* password = "loke1107"; // Your Wi-Fi password
const char* serverURL = "https://wifix.onrender.com/api/data"; // Your Render service API endpoint

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");

  // Example of sending data to your server
  sendData("Hello from ESP32!"); // Send a test message
}

void loop() {
  // Optionally, implement periodic data sending or other logic
}

void sendData(String message) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverURL); // Ensure this is the correct endpoint
    http.addHeader("Content-Type", "application/json");

    String jsonPayload = "{\"message\":\"" + message + "\"}";
    int httpResponseCode = http.POST(jsonPayload);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Response: " + response);
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
}
