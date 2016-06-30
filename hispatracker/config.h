#ifndef __CONFIG_H__
#define __CONFIG_H__

// --------------------------------------------------------------------------
// APRS config (aprs.c)
// --------------------------------------------------------------------------

// Set your callsign and SSID here. Common values for the SSID are
// (from http://zlhams.wikidot.com/aprs-ssidguide):
//
// - Balloons:  11
// - Cars:       9
// - Home:       0
// - IGate:      5
 #define S_CALLSIGN      "HIPH"
 #define S_CALLSIGN_ID   11

// Destination callsign: APRS (with SSID=0) is usually okay.
 #define D_CALLSIGN      "APRS"
 #define D_CALLSIGN_ID   0

// Digipeating paths:
// (read more about digipeating paths here: http://wa8lmf.net/DigiPaths/ )
// The recommended digi path for a balloon is WIDE2-1 or pathless. The default
// is pathless. Uncomment the following two lines for WIDE2-1 path:
 #define DIGI_PATH1      "WIDE2"
 #define DIGI_PATH1_TTL  1

// --------------------------------------------------------------------------
// AX.25 config (ax25.cpp)
// --------------------------------------------------------------------------

// TX delay in milliseconds
#define TX_DELAY      300

// --------------------------------------------------------------------------
// Tracker config (trackuino.pde)
// --------------------------------------------------------------------------

// APRS packets are slotted so that multiple trackers can be used without
// them stepping on one another. The transmission times are governed by
// the formula:
//
//         APRS_SLOT (seconds) + n * APRS_PERIOD (seconds)
//
// When launching multiple balloons, use the same APRS_PERIOD in all balloons
// and set APRS_SLOT so that the packets are spaced equally in time.
// Eg. for two balloons and APRS_PERIOD = 60, set APRS_SLOT to 0 and 30, 
// respectively. The first balloon will transmit at 00:00:00, 00:01:00, 
// 00:02:00, etc. and the second balloon will transmit at 00:00:30, 00:01:30,
// 00:02:30, etc.
#define APRS_SLOT     -1     // seconds. -1 disables slotted transmissions
#define APRS_PERIOD   30    // seconds

// GPS baud rate (in bits per second). This is also the baud rate at which
// debug data will be printed out the serial port.
#define GPS_BAUDRATE  9600


// --------------------------------------------------------------------------
// Modem config (afsk.cpp)
// --------------------------------------------------------------------------

// AUDIO_PIN is the audio-out pin. The audio is generated by timer 2 using
// PWM, so the only two options are pins 3 and 11.
// Pin 11 doubles as MOSI, so I suggest using pin 3 for PWM and leave 11 free
// in case you ever want to interface with an SPI device.
#define AUDIO_PIN       3

// Pre-emphasize the 2200 tone by 6 dB. This is actually done by 
// de-emphasizing the 1200 tone by 6 dB and it might greatly improve
// reception at the expense of poorer FM deviation, which translates
// into an overall lower amplitude of the received signal. 1 = yes, 0 = no.
#define PRE_EMPHASIS    0

// --------------------------------------------------------------------------
// Serial config
// --------------------------------------------------------------------------
#define RXPIN 8
#define TXPIN 9

// --------------------------------------------------------------------------
// Radio config (radio_hx1.cpp)
// --------------------------------------------------------------------------

// This is the PTT pin
#define PTT_PIN           10

// --------------------------------------------------------------------------
// Sensors config (sensors.cpp)
// --------------------------------------------------------------------------

// Most of the sensors.cpp functions use internal reference voltages (either
// AVCC or 1.1V). If you want to use an external reference, you should
// uncomment the following line:
//
// #define USE_AREF
//
// BEWARE! If you hook up an external voltage to the AREF pin and 
// accidentally set the ADC to any of the internal references, YOU WILL
// FRY YOUR AVR.
//
// It is always advised to connect the AREF pin through a pull-up resistor,
// whose value is defined here in ohms (set to 0 if no pull-up):
//
#define AREF_PULLUP           4700
//
// Since there is already a 32K resistor at the ADC pin, the actual
// voltage read will be VREF * 32 / (32 + AREF_PULLUP)
//
// Read more in the Arduino reference docs:
// http://arduino.cc/en/Reference/AnalogReference?from=Reference.AREF

// Pin mappings for the internal / external temperature sensors. VS refers
// to (arduino) digital pins, whereas VOUT refers to (arduino) analog pins.
#define INTERNAL_LM60_VS_PIN     8
#define INTERNAL_LM60_VOUT_PIN   0
#define EXTERNAL_LM60_VS_PIN     7
#define EXTERNAL_LM60_VOUT_PIN   1

// Units for temperature sensors (Added by: Kyle Crockett)
// 1 = Celsius, 2 = Kelvin, 3 = Fahrenheit
#define TEMP_UNIT 1

// Calibration value in the units selected. Use integer only.
#define CALIBRATION_VAL 0

// Resistors divider for the voltage meter (ohms)
#define VMETER_R1       10000
#define VMETER_R2       3300

// Voltage meter analog pin
#define VMETER_PIN      2

// LED pin (13 on Arduinos). On while is running and off while sleeping
// of the CPU activity.
#define LED_PIN                 13


#endif

