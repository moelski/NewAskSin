#define SER_DBG																					// serial debug messages

//- load library's --------------------------------------------------------------------------------------------------------
#include "register.h"																			// configuration sheet
#include <AS.h>																					// ask sin framework


//- arduino functions -----------------------------------------------------------------------------------------------------
void setup() {

	// - Hardware setup ---------------------------------------
	// - everything off ---------------------------------------

	EIMSK = 0;																					// disable external interrupts
	ADCSRA = 0;																					// ADC off
	power_all_disable();																		// and everything else
	
	DDRB = DDRC = DDRD = 0x00;																	// everything as input
	PORTB = PORTC = PORTD = 0x00;																// pullup's off

	// todo: timer0 and SPI should enable internally
	power_timer0_enable();
	power_spi_enable();																			// enable only needed functions

	// enable only what is really needed

	#ifdef SER_DBG																				// some debug
	dbgStart();																					// serial setup
	dbg << F("HM_LC_SW1_BA_PCB\n");	
	dbg << F(LIB_VERSION_STRING);
	//_delay_ms (50);																			// ...and some information
	#endif

	
	// - AskSin related ---------------------------------------
	hm.init();																					// init the asksin framework
	sei();																						// enable interrupts

	// - user related -----------------------------------------
	#ifdef SER_DBG
		dbg << F("HMID: ") << _HEX(HMID,3) << F(", MAID: ") << _HEX(MAID,3) << F("\n\n");		// some debug
	#endif

	//uint8_t xtemp[] = {0x33,0x11,0x22,0x01,0x02,0x00,0x00};
	//hm.ee.addPeers(1, xtemp, xtemp+5);
	//dbg << "x:" << _HEX(xtemp, 7) << "\n";
}

void loop() {
	// - AskSin related ---------------------------------------
	hm.poll();																					// poll the homematic main loop
	
	// - user related -----------------------------------------
	
}


//- user functions --------------------------------------------------------------------------------------------------------
void cmSwitch::initSwitch(uint8_t channel) {
// setting the relay pin as output, could be done also by pinMode(3, OUTPUT)
	#ifdef SER_DBG
		dbg << F("initRly: ") << channel << "\n";
	#endif
	
	SET_PIN_OUTPUT(PIN_D3);																		// init the relay pins
	SET_PIN_LOW(PIN_D3);																		// set relay pin to ground
}

void cmSwitch::switchSwitch(uint8_t channel, uint8_t status) {
// switching the relay, could be done also by digitalWrite(3,HIGH or LOW)
	#ifdef SER_DBG
		dbg << F("switchRly: ") << channel << ", " << status << "\n";
	#endif

	if (status) SET_PIN_HIGH(PIN_D3);															// check status and set relay pin accordingly
	else SET_PIN_LOW(PIN_D3);
}


//- predefined functions --------------------------------------------------------------------------------------------------
void serialEvent() {
	#ifdef SER_DBG
	
	static uint8_t i = 0;																		// it is a high byte next time
	while (Serial.available()) {
		uint8_t inChar = (uint8_t)Serial.read();												// read a byte
		if (inChar == '\n') {																	// send to receive routine
			i = 0;
			hm.sn.active = 1;
		}
		
		if      ((inChar>96) && (inChar<103)) inChar-=87;										// a - f
		else if ((inChar>64) && (inChar<71))  inChar-=55;										// A - F
		else if ((inChar>47) && (inChar<58))  inChar-=48;										// 0 - 9
		else continue;
		
		if (i % 2 == 0) hm.sn.buf[i/2] = inChar << 4;											// high byte
		else hm.sn.buf[i/2] |= inChar;															// low byte
		
		i++;
	}
	#endif
}
