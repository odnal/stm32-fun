// morse code hello
#include <stdint.h>

#define RCC_BASE        0x40021000
#define RCC_AHB2ENR     (*((volatile unsigned int*) (RCC_BASE+0x4C)))

#define GPIOA_BASE      0x48000000
#define GPIOB_BASE      0x48000400
#define GPIOE_BASE      0x48001000

#define GPIOA_MODER     (*((volatile unsigned int *) (GPIOA_BASE+0x00)))
#define GPIOB_MODER     (*((volatile unsigned int *) (GPIOB_BASE+0x00)))
#define GPIOE_MODER     (*((volatile unsigned int *) (GPIOE_BASE+0x00)))

#define GPIOA_BSRR      (*((volatile unsigned int *) (GPIOA_BASE+0x18)))
#define GPIOB_BSRR      (*((volatile unsigned int *) (GPIOB_BASE+0x18)))
#define GPIOE_BSRR      (*((volatile unsigned int *) (GPIOE_BASE+0x18)))

void delay (unsigned int t) {
    for(t=0; t<=0x20000; t++);
}

// GPIOB3
void H(void) {
    for(int i=0; i<4; i++) {
        GPIOB_BSRR = 1<<(3+0);
        delay(0x20000);
        GPIOB_BSRR = 1<<(3+16); 
        delay(0x20000);
    }
}

// GPIOB2
void E(void) {
    GPIOB_BSRR = 1<<(2+0);
    delay(0x20000);
    GPIOB_BSRR = 1<<(2+16); 
    delay(0x20000);
}

// GPIOE8
void L1(void) {
    GPIOE_BSRR = 1<<(8+0);
    delay(0x20000);
    GPIOE_BSRR = 1<<(8+16); 
    delay(0x20000);
    GPIOE_BSRR = 1<<(8+0);
    for(unsigned int i=0; i<0x40000; i++);
    GPIOE_BSRR = 1<<(8+16); 
    delay(0x20000);

    for(int i=0; i<2; i++) {
        GPIOE_BSRR = 1<<(8+0);
        delay(0x20000);
        GPIOE_BSRR = 1<<(8+16); 
        delay(0x20000);
    }
}

// GPIOA0
void L2(void) {
    GPIOA_BSRR = 1<<(0+0);
    delay(0x20000);
    GPIOA_BSRR = 1<<(0+16); 
    delay(0x20000);
    GPIOA_BSRR = 1<<(0+0);
    for(unsigned int i=0; i<0x40000; i++);
    GPIOA_BSRR = 1<<(0+16); 
    delay(0x20000);

    for(int i=0; i<2; i++) {
        GPIOA_BSRR = 1<<(0+0);
        delay(0x20000);
        GPIOA_BSRR = 1<<(0+16); 
        delay(0x20000);
    }
}

// GPIOA5
void O(void) {
    for(int i=0; i<3; i++) {
        GPIOA_BSRR = 1<<(5+0);
        for(unsigned int i=0; i<0x40000; i++);
        GPIOA_BSRR = 1<<(5+16); 
        delay(0x20000);
    }
}

int main(void) {
    
    unsigned int tmp;

    RCC_AHB2ENR |= 1;       // GPIOA
    RCC_AHB2ENR |= 1<<1;    // GPIOB
    RCC_AHB2ENR |= 1<<4;    // GPIOE

    // GPIOA0
    tmp = GPIOA_MODER;
    tmp &= (~(3<<(0<<1)));
    tmp |= ((1<<(0<<1)));
    GPIOA_MODER = tmp;

    // GPIOA1
    tmp = GPIOA_MODER;
    tmp &= (~(3<<(1<<1)));
    tmp |= ((1<<(1<<1)));
    GPIOA_MODER = tmp;

    // GPIOA5
    tmp = GPIOA_MODER;
    tmp &= (~(3<<(5<<1)));
    tmp |= ((1<<(5<<1)));
    GPIOA_MODER = tmp;

    // GPIOB2
    tmp=GPIOB_MODER;
    tmp&=(~(3<<(2<<1))); 
    tmp|=( (1<<(2<<1)));
    GPIOB_MODER=tmp;

    // GPIOB3
    tmp=GPIOB_MODER;
    tmp&=(~(3<<(3<<1))); 
    tmp|=( (1<<(3<<1)));
    GPIOB_MODER=tmp;

    // GPIOE8
    tmp = GPIOE_MODER;
    tmp &= (~(3<<(8<<1)));
    tmp |= ((1<<(8<<1))); 
    GPIOE_MODER = tmp;

    while(1) {

        H();
        delay(0x20000);
        E();
        delay(0x20000);
        L1();
        delay(0x20000);
        L2();
        delay(0x20000);
        O();
        delay(0x20000);

    }

    return 0;
}
