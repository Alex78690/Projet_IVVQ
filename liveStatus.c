#include <stdio.h>
#include <bcm2835.h>

int main(){
  if(!bcm2835_init()){
    printf("Echeque init bcm2835 lib");
    return 1;
  }

  int pins[] = {5, 6, 13, 19, 26, 12, 16, 20, 21};

  int status[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  int oldStatus[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

  for(int i = 0; i < 9; i++)
  {
    bcm2835_gpio_fsel(pins[i], BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_set_pud(pins[i], BCM2835_GPIO_PUD_UP);

    status[i] = bcm2835_gpio_lev(pins[i]);
    oldStatus[i] = status[i];
  }

  while(1){
    

  }
}
