#include<lpc17xx.h>

unsigned int i = 0, j = 0;
unsigned int nightRider = 0x0;
unsigned int led_shift = 4;

void delay(unsigned int);

void delay(unsigned int delay) {
	while(delay-- >  0);
}

int main() {
	LPC_GPIO0->FIODIR |= 0xFF << led_shift;
	while(1) {
		for(i = 0; i < 5; i++) {
			nightRider = 0;
			for(j = 0; j < 8; j++) {
				nightRider <<= 1;
				nightRider++;
				LPC_GPIO0->FIOCLR |= 0xFF << led_shift;
				LPC_GPIO0->FIOSET |= nightRider << led_shift;
				delay(50000);
			}
			for(j = 0; j < 8; j++) {
				nightRider <<= 1;
				nightRider &= 0xFF;
				LPC_GPIO0->FIOCLR |= 0xFF << led_shift;
				LPC_GPIO0->FIOSET |= nightRider << led_shift;
				delay(50000);
			}
		}
		
		for(i = 0; i < 2; i ++) {
			LPC_GPIO0->FIOSET |= 0xFF << led_shift;
			delay(100000);
			LPC_GPIO0->FIOCLR |= 0xFF << led_shift;
			delay(100000);
		}
	}
}