//#ifndef Morko_h
//#define	Morko_h

#include <avr/pgmspace.h>

// Assign your channel in pins (PCINT0 and PCINT1)
#define THROTTLE_IN_PIN 8
#define STEERING_IN_PIN 9

// These bit flags are set in bUpdateFlagsShared to indicate which
// channels have new signals bits (1,2,4,8,etc)
#define THROTTLE_FLAG 1
#define STEERING_FLAG 2


// holds the update flags defined above
volatile uint8_t bUpdateFlagsShared;

// shared variables are updated by the ISR and read by loop.
// In loop we immediatley take local copies so that the ISR can keep ownership of the 
// shared ones. To access these in loop
// we first turn interrupts off with noInterrupts
// we take a copy to use in loop and the turn interrupts back on
// as quickly as possible, this ensures that we are always able to receive new signals
volatile uint16_t unThrottleInShared;
volatile uint16_t unSteeringInShared;


// These are used to record the rising edge of a pulse in the calcInput functions
// They do not need to be volatile as they are only used in the ISR. If we wanted
// to refer to these in loop and the ISR then they would need to be declared volatile
uint32_t ulThrottleStart;
uint32_t ulSteeringStart;

// UART comm stuff
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
uint8_t uiState = 0;


const char main_0[] PROGMEM = "1 = Aseta PWM taajuus\n";   // "String 0" etc are strings to store - change to suit.
const char main_1[] PROGMEM = "2 = Aseta toimintatila\n";
const char main_2[] PROGMEM = "3 = Lisa-asetukset\n";
const char main_3[] PROGMEM = "4 = Debugtila\n";
const char main_4[] PROGMEM = "5 = Tallenna muutokset ja palaa\n";
const char main_5[] PROGMEM = "Anna valintasi:\n";

PGM_P const mainTable[] PROGMEM  = 	   // change "string_table" name to suit
{   
  main_0,
  main_1,
  main_2,
  main_3,
  main_4,
  main_5 };

const char lisa_0[] PROGMEM = "";   // "String 0" etc are strings to store - change to suit.
const char lisa_1[] PROGMEM = "1 = RESERVED\n";
const char lisa_2[] PROGMEM = "2 = RESERVED\n";
const char lisa_3[] PROGMEM = "3 = RESERVED\n";
const char lisa_4[] PROGMEM = "4 = Takaisin\n";
const char lisa_5[] PROGMEM = "Anna valintasi:\n";

PGM_P const lisaTable[] PROGMEM  = 	   // change "string_table" name to suit
{   
  lisa_0,
  lisa_1,
  lisa_2,
  lisa_3,
  lisa_4,
  lisa_5 };
  
const char pwm_0[] PROGMEM = "PWM-taajuuden valinta\n";   // "String 0" etc are strings to store - change to suit.
const char pwm_1[] PROGMEM = "1 = 490 Hz\n";
const char pwm_2[] PROGMEM = "2 = 3920 Hz\n";
const char pwm_3[] PROGMEM = "3 = 31370 Hz\n";
const char pwm_4[] PROGMEM = "4 = Takaisin\n";
const char pwm_5[] PROGMEM = "Anna valintasi:\n";

PGM_P const pwmTable[] PROGMEM  = 	   // change "string_table" name to suit
{   
  pwm_0,
  pwm_1,
  pwm_2,
  pwm_3,
  pwm_4,
  pwm_5 };  
  
const char status_0[] PROGMEM = "Toimintatilan valinta:\n";   // "String 0" etc are strings to store - change to suit.
const char status_1[] PROGMEM = "1 = Diff moottorit (Konehirvi)\n";
const char status_2[] PROGMEM = "2 = Moottori + Servo\n";
const char status_3[] PROGMEM = "3 = RESERVED\n";
const char status_4[] PROGMEM = "4 = Takaisin\n";
const char status_5[] PROGMEM = "Anna valintasi:\n";

PGM_P const statusTable[] PROGMEM  = 	   // change "string_table" name to suit
{   
  status_0,
  status_1,
  status_2,
  status_3,
  status_4,
  status_5 };  


char buffer[30];    // make sure this is large enough for the largest string it must hold