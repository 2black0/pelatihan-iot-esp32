# 📡 IoT ESP32 Training Series — Hands-On Microcontroller Projects

> A curated collection of **hands-on ESP32 IoT tutorials** designed for students, educators, and makers to **build, explore, and prototype** real-world connected systems.

📘 **Presentation Slides:**  
👉 [View the Slide Deck on Google Docs](https://docs.google.com/presentation/d/1WnVEKUaGO5LBkF7HZw2vwt1iBwb0_tYoa3d919wDCec/edit#slide=id.p)

---

## 📁 Project Structure

```plaintext
.
├── LICENSE
├── README.md
└── Tutorial
    ├── button-slider-dashboard/        # Real-time control using sliders and buttons
    ├── dataloggger-google-sheets/      # Send ESP32 data to Google Sheets
    ├── echo-telegramBot/               # Telegram Bot that echoes user messages
    ├── kirim-baca-telegramBot/         # Send/Receive data via Telegram Bot
    ├── komunikasi-mqtt/                # Connect ESP32 to MQTT broker (HiveMQ)
    ├── over-the-air-esp32-basic/       # Basic OTA update via Arduino IDE
    ├── over-the-air-esp32-dashboard/   # OTA firmware update via web dashboard
    ├── simple-dashboard/               # Minimal HTML-based control panel
    └── websocket-server/               # Real-time bi-directional control via WebSocket
```

---

## 🚀 Features & What You'll Learn

✅ Control LEDs and relays via web or Telegram
✅ Push sensor data to **Google Sheets** (no database needed!)
✅ Perform **OTA updates** (Over-the-Air firmware upgrades)
✅ Learn **MQTT messaging** and remote automation
✅ Build **custom dashboards** using HTML/CSS served from ESP32
✅ Enable **real-time WebSocket communication**

---

## 🧰 Prerequisites

1. **Arduino IDE** installed
2. **ESP32 board package** added via Board Manager
3. Required libraries:

   * `WiFi.h`
   * `ESPAsyncWebServer.h`
   * `ESPAsyncTCP.h`
   * `PubSubClient`
   * `UniversalTelegramBot`
   * `WiFiClientSecure`
   * `ArduinoJson`
   * `HTTPClient`

---

## 🛠️ Getting Started

1. **Clone the repository:**

   ```bash
   git clone https://github.com/yourusername/iot-esp32-training.git
   cd iot-esp32-training/Tutorial
   ```

2. **Open any `.ino` file** inside Arduino IDE

3. **Update your Wi-Fi and credentials** in each sketch:

   ```cpp
   const char* ssid = "YOUR_WIFI_SSID";
   const char* password = "YOUR_WIFI_PASSWORD";
   ```

4. **Upload to ESP32 board**, open **Serial Monitor**, and watch the magic happen!

---

## 📷 Project Highlights

### 🌐 WebSocket Dashboard

> Real-time control with zero lag!

---

### 📲 Telegram Bot Integration

> Control your ESP32 from anywhere using Telegram

```
User: /status
ESP32: Temp: 28°C, Relay: ON
```

---

### 🧪 Google Sheets Logger

> Log sensor data directly to Google Sheets using HTTP POST

---

### 💻 OTA Update Dashboard

> Update your ESP32 firmware from a browser. No cables needed!
> 
---

## 💬 Recommended Use Cases

* 👩‍🏫 **STEM & IoT workshops**
* 🎓 **Capstone & thesis projects**
* 🛠️ **Rapid prototyping**
* 🧠 Self-study for embedded systems & cloud connectivity

---

## 📚 References

* 📘 [ESP32 Documentation (Espressif)](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
* 🌐 [HiveMQ MQTT Web Client](https://www.hivemq.com/demos/websocket-client/)
* 🧠 [ESPAsyncWebServer GitHub](https://github.com/me-no-dev/ESPAsyncWebServer)

---

## ❤️ Credits & Contact

Created with passion by **Ardy Seto Priambodo**
📬 [2black0@gmail.com](mailto:2black0@gmail.com)
🌐 [github.com/2black0](https://github.com/2black0)

---

## 📌 License

This project is licensed under the [MIT License](LICENSE).
Feel free to use, remix, and share — with attribution.

---

## 🌟 Support This Project

If you found this helpful:

* ⭐ Star this repo
* 🛠 Fork it
* 📢 Share with others

> Let’s bring **IoT education** to more people!