#include "beep.h"

void Beep_Config(void) {
	//p4.6
	P4M1 &= ~(1<<6);
	P4M0 |=  (1<<6);
    BEEP(0);
}