#include "simpletools.h"

#define UP_SHIFT_PADDLE 12
#define DOWN_SHIFT_PADDLE 13

#define ENGAGE_CLUTCH 5
#define UP_SHIFT_AIR 3
#define DOWN_SHIFT_AIR 4

#define CLUTCH_ENGAUGE_DELAY 70
#define CLUTCH_RELEASE_DELAY 20
#define SHIFT_DELAY 165
#define NEUTRAL_FIND 32

#define DEBOUNCE_TIME 13

#define EEPROM_ADDRESS 0xFFEE

void ShiftCheck( char paddle );
void Shift( char paddle );

int main() {
	char gear = 0;
	int shifts = ee_getInt(EEPROM_ADDRESS);
	
	print( "Shifts: %d\n", ee_getInt( EEPROM_ADDRESS ) );
	pause( 1000 );
	while( 1 ){
		if ( input( UP_SHIFT_PADDLE ) ) {
			ShiftCheck( UP_SHIFT_PADDLE );
			while (input(UP_SHIFT_PADDLE))
       {
         ;// this confuses me
       }
			pause(30);
			shifts++;
			ee_putInt( shifts, EEPROM_ADDRESS );
    		gear++;
		}

		if ( input( DOWN_SHIFT_PADDLE ) ) {
			ShiftCheck( DOWN_SHIFT_PADDLE );
			while (input(DOWN_SHIFT_PADDLE)){
          if (input(UP_SHIFT_PADDLE)){
              pause (DEBOUNCE_TIME);
                if(input(UP_SHIFT_PADDLE)){
          
                high(UP_SHIFT_AIR);
                pause(NEUTRAL_FIND);
                low(UP_SHIFT_AIR);
                while(input(UP_SHIFT_PADDLE));
              }  
          }
      }
			pause(30);
			shifts++;
			ee_putInt( shifts, EEPROM_ADDRESS );
			gear--;
		}
	}
	return 0;
}

void ShiftCheck( char paddle ) {
	int goodpress;
	goodpress = 1;
	pause( 40 );
   if( !input( paddle ) ) {
      goodpress = 0;
   pause( 30 );
   
	}
	if( goodpress == 1 ) {
     if(paddle == UP_SHIFT_PADDLE){
        Shift(UP_SHIFT_AIR);
    }
    if(paddle == DOWN_SHIFT_PADDLE){
    
        Shift(DOWN_SHIFT_AIR);
    }
		goodpress = 0;
	}
}

void Shift( char paddle ) {
	high( ENGAGE_CLUTCH );
	pause( CLUTCH_ENGAUGE_DELAY );
	high( paddle );
	pause( SHIFT_DELAY );
	low( paddle );
	pause( CLUTCH_RELEASE_DELAY );
	low( ENGAGE_CLUTCH );
} 
