#ifndef _BEEP_H
#define _BEEP_H

#include "STC15F2K60S2.h"

#define BEEP_PIN P46

#define BEEP(x) (x ? (BEEP_PIN=1) : (BEEP_PIN=0))

void Beep_Config(void);
#endif