#include <stdio.h>
#include <bcm2835.h>

#define pinOut 12

int main(){
  printf("Hello World!\n");
  if(!bcm2835_init()){
    printf("Echeque init bcm2835 lib");
    return 1;
  }

  bcm2835_gpio_fsel(pinOut, BCM2835_GPIO_FSEL_OUTP);

  int delay = 100;

  while(1){
    bcm2835_gpio_set(pinOut);     //envois de courent depuis la pinOut
    bcm2835_delay(delay);
    bcm2835_gpio_clr(pinOut); //stop le courent de la pinOut
    bcm2835_delay(delay);
  }
}
