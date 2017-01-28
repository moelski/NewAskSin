
#ifndef _HAL_ATMEGA_328_H
#define _HAL_ATMEGA_328_H


#define power_serial_enable()   power_usart0_enable();
#define UCSR                    UCSR0B
#define RXEN                    RXEN0

//- timer definitions -----------------------------------------------------------------------------------------------------
#define hasTimer0
#define hasTimer1
#define hasTimer2
//- -------------------------------------------------------------------------------------------------------------------------


//- power management definitions --------------------------------------------------------------------------------------------
#define backupPwrRegs()         uint8_t xPrr = PRR; PRR = 0xFF;
#define recoverPwrRegs()        PRR = xPrr;
#define offBrownOut()           MCUCR = (1<<BODS)|(1<<BODSE); MCUCR = (1<<BODS);
//- -------------------------------------------------------------------------------------------------------------------------


//- adc definitions ---------------------------------------------------------------------------------------------------------
const uint8_t admux_internal = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);					// internal ADMUX register setup
const uint8_t admux_external = _BV(REFS1) | _BV(REFS0);											// | measurement pin
const uint16_t ref_v_external = 1100;															// internal reference voltage in 10mv
//- -------------------------------------------------------------------------------------------------------------------------


//- pin definition ----------------------------------------------------------------------------------------------------------
#define PCINT_PCIE_SIZE        3																// amount of pin change interrupt vectors

const s_pin_def pin_B0 = { PORTB0, &DDRB, &PORTB, &PINB,  0,  PCINT0, &PCICR, &PCMSK0, PCIE0, 0 };
const s_pin_def pin_B1 = { PORTB1, &DDRB, &PORTB, &PINB,  1,  PCINT1, &PCICR, &PCMSK0, PCIE0, 0 };
const s_pin_def pin_B2 = { PORTB2, &DDRB, &PORTB, &PINB,  2,  PCINT2, &PCICR, &PCMSK0, PCIE0, 0 };
const s_pin_def pin_B3 = { PORTB3, &DDRB, &PORTB, &PINB,  3,  PCINT3, &PCICR, &PCMSK0, PCIE0, 0 };
const s_pin_def pin_B4 = { PORTB4, &DDRB, &PORTB, &PINB,  4,  PCINT4, &PCICR, &PCMSK0, PCIE0, 0 };
const s_pin_def pin_B5 = { PORTB5, &DDRB, &PORTB, &PINB,  5,  PCINT5, &PCICR, &PCMSK0, PCIE0, 0 };
const s_pin_def pin_B6 = { PORTB6, &DDRB, &PORTB, &PINB,  6,  PCINT6, &PCICR, &PCMSK0, PCIE0, 0 };
const s_pin_def pin_B7 = { PORTB7, &DDRB, &PORTB, &PINB,  7,  PCINT7, &PCICR, &PCMSK0, PCIE0, 0 };

const s_pin_def pin_C0 = { PORTC0, &DDRC, &PORTC, &PINC,  8,  PCINT8, &PCICR, &PCMSK1, PCIE1, 1 };
const s_pin_def pin_C1 = { PORTC1, &DDRC, &PORTC, &PINC,  9,  PCINT9, &PCICR, &PCMSK1, PCIE1, 1 };
const s_pin_def pin_C2 = { PORTC2, &DDRC, &PORTC, &PINC, 10, PCINT10, &PCICR, &PCMSK1, PCIE1, 1 };
const s_pin_def pin_C3 = { PORTC3, &DDRC, &PORTC, &PINC, 11, PCINT11, &PCICR, &PCMSK1, PCIE1, 1 };
const s_pin_def pin_C4 = { PORTC4, &DDRC, &PORTC, &PINC, 12, PCINT12, &PCICR, &PCMSK1, PCIE1, 1 };
const s_pin_def pin_C5 = { PORTC5, &DDRC, &PORTC, &PINC, 13, PCINT13, &PCICR, &PCMSK1, PCIE1, 1 };
const s_pin_def pin_C6 = { PORTC6, &DDRC, &PORTC, &PINC, 14, PCINT14, &PCICR, &PCMSK1, PCIE1, 1 };
const s_pin_def pin_C7=  {      7, &DDRC, &PORTC, &PINC, 15,       7, &PCICR, &PCMSK1, PCIE1, 1 }; 

const s_pin_def pin_D0 = { PORTD0, &DDRD, &PORTD, &PIND, 16, PCINT16, &PCICR, &PCMSK2, PCIE2, 2 };
const s_pin_def pin_D1 = { PORTD1, &DDRD, &PORTD, &PIND, 17, PCINT17, &PCICR, &PCMSK2, PCIE2, 2 };
const s_pin_def pin_D2 = { PORTD2, &DDRD, &PORTD, &PIND, 18, PCINT18, &PCICR, &PCMSK2, PCIE2, 2 };
const s_pin_def pin_D3 = { PORTD3, &DDRD, &PORTD, &PIND, 19, PCINT19, &PCICR, &PCMSK2, PCIE2, 2 };
const s_pin_def pin_D4 = { PORTD4, &DDRD, &PORTD, &PIND, 20, PCINT20, &PCICR, &PCMSK2, PCIE2, 2 };
const s_pin_def pin_D5 = { PORTD5, &DDRD, &PORTD, &PIND, 21, PCINT21, &PCICR, &PCMSK2, PCIE2, 2 };
const s_pin_def pin_D6 = { PORTD6, &DDRD, &PORTD, &PIND, 22, PCINT22, &PCICR, &PCMSK2, PCIE2, 2 };
const s_pin_def pin_D7 = { PORTD7, &DDRD, &PORTD, &PIND, 23, PCINT23, &PCICR, &PCMSK2, PCIE2, 2 };
//- -------------------------------------------------------------------------------------------------------------------------



#endif