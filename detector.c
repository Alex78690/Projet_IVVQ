#include <stdio.h>
#include <bcm2835.h>

int main(){
  if(!bcm2835_init()){
    printf("Echec init bcm2835 lib");
    return 1;
  }

  int capteur = 21;
  int light_R = 12;
  int light_J = 16;
  int light_V = 20;

  int delaySwitchToRed = 2000;
  int _delay = 0;

  int status = -1; // detecter status = 1 / non detecter status = 0

  // initialisation
  bcm2835_gpio_fsel(capteur, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_set_pud(capteur, BCM2835_GPIO_PUD_UP);

  bcm2835_gpio_fsel(light_R, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(light_J, BCM2835_GPIO_FSEL_OUTP);
  bcm2835_gpio_fsel(light_V, BCM2835_GPIO_FSEL_OUTP);

  while(1){
    if(!bcm2835_gpio_lev(capteur)) // test si capteur detecte un element
    {
      if(status != 1){
        status = 1;
        _delay = 0;
        bcm2835_gpio_set(light_J);
        bcm2835_gpio_clr(light_R);
        bcm2835_gpio_clr(light_V);
      }
      else if((status == 1) && (_delay == delaySwitchToRed))
      {
        bcm2835_gpio_set(light_R);
        bcm2835_gpio_clr(light_J);
        bcm2835_gpio_clr(light_V);
      }
      else
      {
        _delay ++;
      }
    }
    else if(status != 0)
    {
      status = 0;
      bcm2835_gpio_set(light_V);
      bcm2835_gpio_clr(light_J);
      bcm2835_gpio_clr(light_R);
    }
    bcm2835_delay(1);
  }
}
