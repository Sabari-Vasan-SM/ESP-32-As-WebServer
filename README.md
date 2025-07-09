 ESP32 Web Server
This Arduino sketch configures the ESP32 as a standalone Wi-Fi access point and hosts a basic web server that can be accessed without any external router or internet connection. When powered on, the ESP32 creates a Wi-Fi hotspot named "ESP32_Hotspot" with the password "12345678". Devices like smartphones or laptops can connect to this network directly.

Once connected, users can open a browser and navigate to http://192.168.4.1 (the default IP address of the ESP32 AP).


Creates an Access Point (AP):

SSID: ESP32_Hotspot

Password: 12345678

Default AP IP: 192.168.4.1

Starts a Web Server on port 80.


📶 How to Use:
Upload this sketch to your ESP32.

Open the Serial Monitor at 115200 baud.

ESP32 will display:

nginx
Copy
Edit

Access Point IP: 192.168.4.1
On your phone/laptop:

Go to Wi-Fi settings.

Connect to ESP32_Hotspot using password 12345678.

✅ Features:
No external Wi-Fi router required.

ESP32 acts as a Wi-Fi hotspot and web server.

Simple and lightweight HTML content.

Great for local/offline embedded applications.


Open a browser and go to:
👉 http://192.168.4.1
