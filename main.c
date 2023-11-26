#include <SPI.h>
#include <WiFi.h>
char ssid[] = "";      // your network SSID (name)
char pass[] = "";   // your network password
int status;
WiFiServer server(80);
void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  // attempt to connect to Wifi network:
    status = WiFi.begin(ssid, pass);
    delay(10000);
    server.begin();
  // you're connected now, so print out the status:
  printWifiStatus();
}


void loop() {
  // listen for incoming clients
  WiFiClient client = server.available();
  while (client.connected()) {
      if (client.available()) {
            int sensorReading = analogRead(A3);
            client.print("analog input ");
            client.print(" is ");
            client.print(sensorReading);
            }
        // give the web browser time to receive the data
    delay(1);

    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
}


void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
