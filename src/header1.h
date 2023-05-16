#define DELAY 5000
#define ON 0x01
#define OFF 0x00
#define NUM_LEDS 0x03


#define PIN_2 0x40000 //EW Red
#define PIN_7 0x800000 //EW Yellow
#define PIN_8 0x1 //EW Green
#define PIN_9 0x2 // Pedastrian Red
#define PIN_17 0x800 //NS Red
#define PIN_18 0x1000 //NS yellow
#define PIN_12 0x10 //button 1
#define PIN_11 0x8 //button 2
#define PIN_10 0x04 // button 3
#define PIN_3 0x80000 //button 4
#define PIN_19 0x2000 //NS green
#define PIN_6 0x400000 //Pedastrian Green


void setupGPIO();
int setLED(int color, int state);
int delay(int milliseconds);
int checkBot();