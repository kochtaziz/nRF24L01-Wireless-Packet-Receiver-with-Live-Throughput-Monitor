# nRF24L01 Wireless Packet Receiver with Live Throughput Monitor

This Arduino project listens for incoming packets using the **nRF24L01+ RF module** and counts the number of packets received per second. The result is printed to the Serial Monitor in real-time. This tool is useful for **testing signal strength**, **monitoring transmission quality**, or **debugging communication between two RF modules**.

---

## 📟 Features

- Receives 2.4GHz wireless data using the nRF24L01+ module
- Displays packets received per second (live throughput)
- Works with matching transmitter code (using same channel/address)
- Optionally prints received payloads for debugging
- Non-blocking `millis()`-based timing for stable performance

---

## 🧰 Requirements

- Arduino board (Uno, Nano, Mega, etc.)
- nRF24L01+ RF module
- 10µF capacitor across VCC and GND (recommended for stability)
- Matching transmitter using the same RF24 settings
- Arduino IDE with **RF24** library installed

---

## 🔌 Wiring (for Arduino Uno)

| nRF24L01+ Pin | Arduino Pin |
|---------------|-------------|
| VCC           | 3.3V        |
| GND           | GND         |
| CE            | 9           |
| CSN           | 10          |
| SCK           | 13          |
| MOSI          | 11          |
| MISO          | 12          |

> ⚠️ **Note:** Do *not* connect VCC to 5V — use only 3.3V!

---

## 🔧 Configuration

Make sure the following radio settings match between the **receiver** and your **transmitter**:

```cpp
radio.setChannel(100);
radio.setPALevel(RF24_PA_LOW);
radio.setDataRate(RF24_2MBPS);
const byte address[5] = {'J','U','N','K','1'};
