/*
 * main.c
 *
 *  Created on: March 24, 2020
 *      Author: Landon Brown
 */

/**
  *****************************************************************************
  *  LED Control
  *
  *      This program uses the STM32LS476-Discovery board with interactions
  *      between the button presses and the LED's. The center button turns ON
  *      both the red/green LED. Left button turns OFF and then ON the green LED
  *      with each press. Right button turns OFF and then ON the red LED with
  *      each press. Down button turns both LED's OFF. UP button flashes green LED
  *      at 2 Hz.
  *
  *****************************************************************************
  */

#include <stdint.h>

//-- GPIO Register Interface Definitions --------------------------------------
#define GPIOB_BASE  0x48000400
#define GPIOE_BASE  0x48001000
#define RCC_BASE    0x40021000

#define GPIOB_MODER     (*((volatile unsigned int*) (GPIOB_BASE+0x00)))
#define GPIOB_IDR       (*((volatile unsigned int*) (GPIOB_BASE+0x10)))
#define GPIOB_ODR       (*((volatile unsigned int*) (GPIOB_BASE+0x14)))

#define GPIOE_MODER     (*((volatile unsigned int*) (GPIOB_BASE+0x00)))
#define GPIOE_IDR       (*((volatile unsigned int*) (GPIOB_BASE+0x10)))
#define GPIOE_ODR       (*((volatile unsigned int*) (GPIOB_BASE+0x14)))

#define RCC_AHB2ENR     (*((volatile uint32_t *) (RCC_BASE+0x4C)))


/**
*==================================================================== main() ==
*  main()
*      @param  none
*      @return Never returns.  Holds in polling loop.
*      @retval 0 SUCCESS
*
*      Program strategy is simple. Initialize the port resources being used
*      and then continually read the joystick input and update the led as
*      required.
*=============================================================================
*/
int main(void)
{
    unsigned int tmp;

    //-- initialize red led port and pin --------------------------------------
    RCC_AHB2ENR |= 0x02;          // Enable clock of Port B<200b>(second bit)
    tmp = GPIOB_MODER;
    tmp&=~(3UL<<4);    // Clear mode bits<200b>
    tmp |= 1UL<<4;
    GPIOB_MODER = tmp;
    //GPIOB->OTYPER &= ~(1UL<<2);   // Select push-pull output<200b>

    while(1) {
        GPIOB_ODR = ~(3UL << 2);
        for(unsigned int i=0; i < 0x200000; i++){}
        GPIOB_ODR = (1UL << 2);
        for(unsigned int i=0; i < 0x200000; i++){}
    }

    //-- initialize green led port and pin --------------------------------------
/*    RCC_AHB2ENR |= 0x10;              // Enable clock of Port E(fourth bit)
    GPIOE->MODER &= ~(3UL<<16);     // Clear mode bits<200b>
    GPIOE->MODER |= 1UL<<16;        // Set mode to output
    GPIOE->OTYPER &= ~(1UL<<8);     // Select push-pull output<200b>

    //-- initialize joystick port and pin -------------------------------------
    RCC_AHB2ENR |= 0x01;            // Enable clock of Port A<200b>
    GPIOA->MODER &= ~(3UL);         // Set mode to input<200b> for center joystick
    GPIOA->PUPDR &= ~(3UL);         // No pullup/pulldown<200b> for center joystick

    GPIOA->MODER &= ~(3UL<<2);      // set mode to input for left joystick
    GPIOA->PUPDR |= 2UL<<2;         // set pull-down for output type

    GPIOA->MODER &= ~(3UL<<10);     // set mode to input for down joystick
    GPIOA->PUPDR |= 2UL<<10;        // set pull-down for output type

    GPIOA->MODER &= ~(3UL<<4);      // set mode to input for right joystick
    GPIOA->PUPDR |= 2UL<<4;         // set pull-down for output type

    GPIOA->MODER &= ~(3UL<<6);      // set mode to input for up joystick
    GPIOA->PUPDR |= 2UL<<6;         // set pull-down for output type

    int Lpush=0;
    int Rpush=0;
    int Upush=0;
    int Dpush=0;
    int Cpush=0;

    //-- continually poll joystick pin and change led output appropriately ----
    //-- continually poll joystick pin and change led output appropriately ----
    while(1)
    {

        // Center button set toggle on red/green LED
        if(GPIOA->IDR & 0x01){
            Cpush++;
            Dpush=0;
            Rpush=0;
            Lpush=0;
        }
        // Center button turn on red/green LED
        if((Cpush%2)==0){
            GPIOB->ODR &= (1UL << 2);
            GPIOE->ODR &= (1UL << 8);
        }
        else{
            GPIOB->ODR |= (1UL << 2);
            GPIOE->ODR |= (1UL << 8);
        }

        // Left button set toggle on green
        if(GPIOA->IDR & 0x02){
            Lpush++;
            Cpush=0;
            Rpush=1;
        }

        // Right button set toggle on red
        if(GPIOA->IDR & 0x04){
            Rpush++;
            Cpush=0;
            Lpush=1;
        }

        // Up button set toggle flash on green
        if(GPIOA->IDR & 0x08){
            Upush++;
            Rpush=1;
        }

        // Left button toggle green LED
        if((Lpush%2)==0){
            GPIOE->ODR &= ~(1UL << 8);  // YES: Output 0 to turn on green LED
        }
        else{
            GPIOE->ODR |= 1UL << 8;     // NO:  Output 1 to turn off green LED
        }

        // Right button toggle red LED
        if((Rpush%2)==0){
           GPIOB->ODR &= ~(1UL << 2);   // YES: Output 0 to turn on red LED
        }
        else{
            GPIOB->ODR |= 1UL << 2;     // NO:  Output 1 to turn off red LED
        }

        // Up button flash green led at 2 Hz
        if(Upush%2!=0){
            GPIOE->ODR &= ~(1UL << 8);
            for(int i=125000; i!=0; i--){}
            GPIOE->ODR |= (1UL << 8);
            for (int i=125000; i!=0; i--){}
        }

        // Down button clear LEDs
        if(GPIOA->IDR & 0x20){      // down
           GPIOB->ODR &= ~(1UL << 2);      // NO:  Output 1 to turn off red LED
           GPIOE->ODR &= ~(1UL << 8);      // NO:  Output 1 to turn off green LED
           Lpush=0;
           Rpush=0;
           Upush=0;
           Cpush=0;
        }

    }*/

    return(0);

}
