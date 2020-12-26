#include <stdint.h>

// GPIO Register Interface Definitions 
#define GPIOB_BASE  0x48000400
#define GPIOE_BASE  0x48001000
#define GPIOA_BASE  0x48000000
#define RCC_BASE    0x40021000

#define GPIOA_MODER     (*((volatile unsigned int*) (GPIOA_BASE+0x00)))
#define GPIOA_IDR       (*((volatile unsigned int*) (GPIOA_BASE+0x10)))
#define GPIOA_PUPDR     (*((volatile unsigned int*) (GPIOA_BASE+0x0C)))

#define GPIOB_MODER     (*((volatile unsigned int*) (GPIOB_BASE+0x00)))
#define GPIOB_ODR       (*((volatile unsigned int*) (GPIOB_BASE+0x14)))

#define GPIOE_MODER     (*((volatile unsigned int*) (GPIOE_BASE+0x00)))
#define GPIOE_ODR       (*((volatile unsigned int*) (GPIOE_BASE+0x14)))

#define RCC_AHB2ENR     (*((volatile uint32_t *) (RCC_BASE+0x4C)))

int main(void)
{
    unsigned int tmp;

    RCC_AHB2ENR |= 0x02;    // enable port B clock          
    RCC_AHB2ENR |= 0x01;    // enable port A clock          
    RCC_AHB2ENR |= 0x10;    // enable port E clock

    GPIOA_MODER &= ~(3UL);      // set mode as input
    GPIOA_PUPDR &= ~(3UL);      // set port as no pull up / no pull down

    // setting mode as input
    tmp = GPIOB_MODER;
    tmp&=~(3UL<<4);    
    tmp |= 1UL<<4;
    GPIOB_MODER = tmp;

    // setting mode as input
    tmp = GPIOE_MODER;
    tmp&=~(3UL<<16);  
    tmp |= 1UL<<16;
    GPIOE_MODER = tmp;

    while(1) {

        // if the button is pressed and held, red will turn on otherwise green led is on
        if((GPIOA_IDR & 0x1) == 0x1) {      // button is hardware debounced already 
            GPIOB_ODR = (1UL << 2);
            GPIOE_ODR = ~(3UL << 8);
        } 
        else if((GPIOA_IDR & 0x1) == 0x00) {
            GPIOB_ODR = ~(1UL << 2);
            GPIOE_ODR = (3UL << 8);
        }

        /*GPIOB_ODR = ~(3UL << 2);
        GPIOE_ODR = ~(3UL << 8);
        for(unsigned int i=0; i < 0x200000; i++){}
        GPIOE_ODR = (1UL << 8);
        GPIOB_ODR = (1UL << 2);
        for(unsigned int i=0; i < 0x200000; i++){}*/
    }
    return(0);
}
