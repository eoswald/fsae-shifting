#include "simpletools.h"

#define UP_SHIFT_PADDLE 12
#define DOWN_SHIFT_PADDLE 13

#define ENGAGE_CLUTCH 5
#define UP_SHITFT_AIR 3
#define DOWN_SHIFT_AIR 4

#define CLUTCH_DELAY 200
#define SHIFT_DELAY 200
#define DEBOUNCE_TIME 13

void Port_Init(void); //Port initializations
void Shift(char paddle);

void main() {
	char gear = 0
	Port_Init();
	while(1) {
		if (input(UP_SHIFT_PADDLE)) {
			Shift(UP_SHIFT_AIR);
			gear++;
		}
		if (input(DOWN_SHIFT)) {
			Shift(DOWN_SHIFT_AIR):
			gear--;
		}

	}
}

void Port_Init(void) {
	DIRA |= 0x0004003E;
	DIRA &= 0xFFFEFFFF;
}

void Shift(char paddle) {
	high(ENGAGE_CLUTCH);
	pause(CLUTCH_DELAY);
	high(paddle);
	pause(SHIFT_DELAY);
	low(paddle);
	pause(CLUTCH_DELAY);
	low(ENGAGE_CLUTCH);
	while(input(paddle);
	pause(DEBOUNCE_TIME);
}
