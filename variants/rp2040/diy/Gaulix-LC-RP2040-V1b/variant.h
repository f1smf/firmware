// varian carte gaulix
//#define RADIOLIB_DEBUG_BASIC        (1)   // basic debugging (e.g. reporting GPIO timeouts or module not being found)
//#define RADIOLIB_DEBUG_PROTOCOL     (1)   // protocol information (e.g. LoRaWAN internal information)
//#define RADIOLIB_DEBUG_SPI          (1)   // verbose transcription of all SPI communication - produces large debug logs!

#define ARDUINO_ARCH_AVR

//#define debug_pcn 

#ifdef debug_pcn
//#define log_e(...) Serial2.printf(__VA_ARGS__)
//#define log_i(...) Serial2.printf(__VA_ARGS__)
#define log_d(...) Serial2.printf(__VA_ARGS__)
#endif

#undef MAX_NUM_NODES
#define MAX_NUM_NODES 250

// #define USE_SH1106 1

// Define I2C pins to ensure correct usage of both ports
#define I2C_SDA 20  // i2c channel 0 on external IO connector
#define I2C_SCL 21  // i2c channel 0 on external IO connector

#define I2C_SDA1 10  // i2c channel 1 on external IO connector
#define I2C_SCL1 11  // Second i2c channel 1on external IO connector

// Serial
#undef PIN_SERIAL1_TX
#undef PIN_SERIAL1_RX
#undef PIN_SERIAL2_TX
#undef PIN_SERIAL2_RX

#define PIN_SERIAL1_TX 0
#define PIN_SERIAL1_RX 1

#define PIN_SERIAL2_TX 8
#define PIN_SERIAL2_RX 9

// Waveshare Pico GPS L76B pins: (board uart0)
#define HAS_GPS 1
#define PIN_GPS_RESET -1
#define PIN_GPS_EN 22
#define GPS_RX_PIN PIN_SERIAL1_RX
#define GPS_TX_PIN PIN_SERIAL1_TX
#undef PIN_GPS_RESET  // No GPS reset available

#define EXT_NOTIFY_OUT -1  // 22 notify out

#define BUTTON_PIN 12      //botton 
#define BUTTON_NEED_PULLUP

#define LED_PIN PIN_LED

#define BATTERY_PIN 26
// Ratio of voltage divider = 3.0 (R17=200k, R18=100k)
//#define ADC_MULTIPLIER 3.1 // 3.0 + a bit for being optimistic
#define ADC_MULTIPLIER 3.05 //3.065 //3.33 //1.84
#define BATTERY_SENSE_RESOLUTION_BITS ADC_RESOLUTION
#define CELL_TYPE_LION // same curve for liion/lipo
#define NUM_CELLS 1

#define HAS_CPU_SHUTDOWN 1
#define USE_SX1262

#undef LORA_SCK
#undef LORA_MISO
#undef LORA_MOSI
#undef LORA_CS

// https://www.waveshare.com/rp2040-lora.htm
// https://www.waveshare.com/img/devkit/RP2040-LoRa-HF/RP2040-LoRa-HF-details-11.jpg
#define LORA_SCK 14  // GPIO14
#define LORA_MISO 24 // GPIO24
#define LORA_MOSI 15 // GPIO15
#define LORA_CS 13   // GPIO13

#define LORA_DIO0 RADIOLIB_NC // No GPIO connection
#define LORA_RESET 23         // GPIO23
#define LORA_BUSY 18          // GPIO18
#define LORA_DIO1 16          // GPIO16
#define LORA_DIO2 RADIOLIB_NC // Antenna switching, no GPIO connection
#define LORA_DIO3 RADIOLIB_NC // No GPIO connection
#define LORA_DIO4 17          // GPIO17

// On rp2040-lora board the antenna switch is wired and works with complementary-pin control logic.
// See PE4259 datasheet page 4

#ifdef USE_SX1262
#define SX126X_CS LORA_CS
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY LORA_BUSY
#define SX126X_RESET LORA_RESET
#define SX126X_DIO2_AS_RF_SWITCH   // Antenna switch CTRL
#define SX126X_RXEN LORA_DIO4    // Antenna switch !CTRL via GPIO17
#define SX126X_DIO3_TCXO_VOLTAGE 1.8

#endif