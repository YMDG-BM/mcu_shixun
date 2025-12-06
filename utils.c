#include "utils.h"

void Delay_ms(unsigned int n) {
    unsigned char i, j;
    while(n--) {
        i = 30;
        j = 43;
        do {
            while (--j);
        } while (--i);
    }
}

void Delay_us(unsigned char n) {
    while(n--) {
        _nop_(); _nop_(); _nop_(); _nop_();
        _nop_(); _nop_(); _nop_(); _nop_();
    }
}