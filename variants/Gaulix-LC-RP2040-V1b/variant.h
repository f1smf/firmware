// #define RADIOLIB_CUSTOM_ARDUINO 1
// #define RADIOLIB_TONE_UNSUPPORTED 1
// #define RADIOLIB_SOFTWARE_SERIAL_UNSUPPORTED 1

#define ARDUINO_ARCH_AVR

/*#define RP2040_SLOW_CLOCK

#ifdef RP2040_SLOW_CLOCK
// Redefine UART1 serial log output to avoid collision with UART0 for GPS.
#define SERIAL2_TX 8
#define SERIAL2_RX 9
// Reroute log output in SensorLib when USB is not available
#define log_e(...) Serial2.printf(__VA_ARGS__)
#define log_i(...) Serial2.printf(__VA_ARGS__)
#define log_d(...) Serial2.printf(__VA_ARGS__)
#endif*/

// Define I2C pins to ensure correct usage of both ports
#define I2C_SDA 20
#define I2C_SCL 21
#define I2C_SDA1 2
#define I2C_SCL1 3

#define LED_CONN PIN_LED2
#define LED_PIN LED_BUILTIN
#define ledOff(pin) pinMode(pin, INPUT)

#define BUTTON_PIN 9
#define BUTTON_NEED_PULLUP
#define EXT_NOTIFY_OUT 4

#define BATTERY_PIN PIN_A0 //3 //29     0 //26
// ratio of voltage divider = 3.0 (R17=200k, R18=100k)
#define ADC_MULTIPLIER 1.84 //3.065 //3.33 //1.84
#define BATTERY_SENSE_RESOLUTION_BITS ADC_RESOLUTION

#define DETECTION_SENSOR_EN 28

#define USE_SX1262

#undef LORA_SCK
#undef LORA_MISO
#undef LORA_MOSI
#undef LORA_CS

// RAK BSP somehow uses SPI1 instead of SPI0
/*#define HW_SPI1_DEVICE
#define LORA_SCK (10u)
#define LORA_MOSI (11u)
#define LORA_MISO (12u)
#define LORA_CS (13u)

#define LORA_DIO0 RADIOLIB_NC
#define LORA_RESET 14
#define LORA_DIO1 29
#define LORA_DIO2 15
#define LORA_DIO3 RADIOLIB_NC

#ifdef USE_SX1262
#define SX126X_CS LORA_CS
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY LORA_DIO2
#define SX126X_RESET LORA_RESET
#define SX126X_POWER_EN 25
// DIO2 controlls an antenna switch and the TCXO voltage is controlled by DIO3
#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
#endif*/
// RAK BSP somehow uses SPI1 instead of SPI0
#define HW_SPI1_DEVICE
#define LORA_SCK (14u)
#define LORA_MOSI (15u)
#define LORA_MISO (24u)
#define LORA_CS (13u)

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
#define SX126X_DIO2_AS_RF_SWITCH // Antenna switch CTRL
#define SX126X_RXEN LORA_DIO4    // Antenna switch !CTRL via GPIO17
//#define SX126X_TXEN 19
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
#endif

#define HAS_ETHERNET 1
#define PIN_ETHERNET_RESET 7 // IO3
#define PIN_ETHERNET_SS 17
#define ETH_SPI_PORT SPI

//#define PIN_ETH_POWER_EN 6

#undef  MAX_NUM_NODES
#define MAX_NUM_NODES 500
//#define MAX_NUM_NODES_FS 500

//#define SX126X_MAX_POWER 30