/**
* Reference:
*  https://randomnerdtutorials.com/esp8266-pinout-reference-gpios
*  https://www.electronicwings.com/nodemcu/nodemcu-gpio-with-arduino-ide
*  https://gist.github.com/dvinciguerra/00f8e48046e62c137e4f689eb5d1e38e
*/

// nodemcu
#define D0    16 // high at boot (no PWMm or I2C support)
#define D1    05 // SCL
#define D2    04 // SDA
#define D3    00 // boot failure if pulled LOW
#define D4    02 // high at boot and boot failure if pulled LOW (on-board led)
#define D5    14
#define D6    12
#define D7    13
#define D8    15 // boot failure if pulled HIGH
#define RX    03 // rx pin high at boot
#define TX    01 // tx pin high at boot and boot failure if pulled LOW
#define ADC0  A0 // analogic
