#include "simpletools.h"

#define DELAY 200

void Port_Init(void); //Port initializations

void main() {
	Port_Init();
	while(1) {
		OUTA |= 0x0004003E; //Blink outputs
		pause(DELAY);
		OUTA &= ~0x0004003E;
		pause(DELAY);
	}
}

void Port_Init(void) {
	DIRA |= 0x0004003E;
	DIRA &= 0xFFFEFFFF;
}
