#include <stdint.h>

/* this info is from the stm32l476 disco board data sheet by stm32 */

// this info can be found using the data sheet
#define SRAM_START 0x20000000U
#define SRAM_SIZE (96*1024) // 128KB - note sram1 = 96KB and sram2 = 32KB
#define SRAM_END ((SRAM_START) + (SRAM_SIZE))

#define STACK_START SRAM_END // after sram is done with start up, apply stack in front of sram for data
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _la_data;

int main(void);
void reset_handler(void);

void nmi_handler(void)              __attribute__ ((weak, alias ("default_handler"))); // weak attribute allows me to make changes in src
void hardfault_handler(void)            __attribute__ ((weak, alias ("default_handler")));
void memmanage_handler(void)            __attribute__ ((weak, alias ("default_handler")));
void busfault_handler(void)             __attribute__ ((weak, alias ("default_handler")));
void usagefault_handler(void)           __attribute__ ((weak, alias ("default_handler")));
void svcall_handler(void)               __attribute__ ((weak, alias ("default_handler")));
void debug_handler(void)                __attribute__ ((weak, alias ("default_handler")));
void pendSV_handler(void)               __attribute__ ((weak, alias ("default_handler")));
void systick_handler(void)              __attribute__ ((weak, alias ("default_handler")));
void wwdg_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void pvd_pvm_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void rtc_tamper_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void rtc_wkup_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void flash_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void rcc_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void exit0_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void exit1_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void exit2_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void exit3_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void exit4_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dma1_ch1_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dma1_ch2_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dma1_ch3_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dma1_ch4_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dma1_ch5_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dma1_ch6_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dma1_ch7_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void adc1_2_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void can1_tx_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void can1_rx0_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void can1_rx1_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void can1_sce_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void exitl9_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void tim1_brk_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void tim1_up_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void tim1_trg_com_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void tim1_cc_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void tim2_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void tim3_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void tim4_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void i2c1_ev_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void i2c1_er_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void i2c2_ev_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void i2c2_er_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void spi1_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void spi2_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void usart1_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void usart2_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void usart3_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void exitl15_10_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void rtc_alarm_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dfsdm3_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void tim8_brk_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void tim8_up_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void tim8_trg_com_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void tim8_cc_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void adc3_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void fmc_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void sdmmc1_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void tim5_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void spi3_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void uart4_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void uart5_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void tim6_dacunder_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void tim7_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dma2_ch1_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dma2_ch2_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dma2_ch3_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dma2_ch4_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dma2_ch5_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dfsdm0_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dfsdm1_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dfsdm2_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void comp_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void lptim1_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void lptim2_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void otg_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dma2_ch6_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void dma2_ch7_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void lpuart1_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void quadspi_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void i2c3_ev_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void i2c3_er_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void sai1_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void sai2_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void swpmi1_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void tsc_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void lcd_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void aes_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void rng_irq(void)                     __attribute__ ((weak, alias ("default_handler")));
void fpu_irq(void)                     __attribute__ ((weak, alias ("default_handler")));

// below is data -- however we don't want this to appear in the .data section instead a user defined section space defined below
// this is a list of all the system exceptions and handlers listed in the interrupt vector table
uint32_t vector[] __attribute__ ((section (".isr_vector"))) = {
    STACK_START,
    (uint32_t) reset_handler,
    (uint32_t) nmi_handler,
    (uint32_t) hardfault_handler,
    (uint32_t) memmanage_handler,
    (uint32_t) busfault_handler,
    (uint32_t) usagefault_handler,
    0,
    0,
    0,
    0,
    (uint32_t) svcall_handler,
    (uint32_t) debug_handler,
    0,
    (uint32_t) pendSV_handler,
    (uint32_t) systick_handler,
    (uint32_t) wwdg_irq,
    (uint32_t) pvd_pvm_irq,
    (uint32_t) rtc_tamper_irq,
    (uint32_t) rtc_wkup_irq,
    (uint32_t) flash_irq, // may need to be 0
    (uint32_t) rcc_irq,
    (uint32_t) exit0_irq,
    (uint32_t) exit1_irq,
    (uint32_t) exit2_irq,
    (uint32_t) exit3_irq,
    (uint32_t) exit4_irq,
    (uint32_t) dma1_ch1_irq,
    (uint32_t) dma1_ch2_irq,
    (uint32_t) dma1_ch3_irq,
    (uint32_t) dma1_ch4_irq,
    (uint32_t) dma1_ch5_irq,
    (uint32_t) dma1_ch6_irq,
    (uint32_t) dma1_ch7_irq,
    (uint32_t) adc1_2_irq,
    (uint32_t) can1_tx_irq,
    (uint32_t) can1_rx0_irq,
    (uint32_t) can1_rx1_irq,
    (uint32_t) can1_sce_irq,
    (uint32_t) exitl9_irq,
    (uint32_t) tim1_brk_irq,
    (uint32_t) tim1_up_irq,
    (uint32_t) tim1_trg_com_irq,
    (uint32_t) tim1_cc_irq,
    (uint32_t) tim2_irq,
    (uint32_t) tim3_irq,
    (uint32_t) tim4_irq,
    (uint32_t) i2c1_ev_irq,
    (uint32_t) i2c1_er_irq,
    (uint32_t) i2c2_ev_irq,
    (uint32_t) i2c2_er_irq,
    (uint32_t) spi1_irq,
    (uint32_t) spi2_irq,
    (uint32_t) usart1_irq,
    (uint32_t) usart2_irq,
    (uint32_t) usart3_irq,
    (uint32_t) exitl15_10_irq,
    (uint32_t) rtc_alarm_irq,
    (uint32_t) dfsdm3_irq,
    (uint32_t) tim8_brk_irq,
    (uint32_t) tim8_up_irq,
    (uint32_t) tim8_trg_com_irq,
    (uint32_t) tim8_cc_irq,
    (uint32_t) adc3_irq,
    (uint32_t) fmc_irq,
    (uint32_t) sdmmc1_irq,
    (uint32_t) tim5_irq,
    (uint32_t) spi3_irq,
    (uint32_t) uart4_irq,
    (uint32_t) uart5_irq,
    (uint32_t) tim6_dacunder_irq,
    (uint32_t) tim7_irq,
    (uint32_t) dma2_ch1_irq,
    (uint32_t) dma2_ch2_irq,
    (uint32_t) dma2_ch3_irq,
    (uint32_t) dma2_ch4_irq,
    (uint32_t) dma2_ch5_irq,
    (uint32_t) dfsdm0_irq,
    (uint32_t) dfsdm1_irq,
    (uint32_t) dfsdm2_irq,
    (uint32_t) comp_irq,
    (uint32_t) lptim1_irq,
    (uint32_t) lptim2_irq,
    (uint32_t) otg_irq,
    (uint32_t) dma2_ch6_irq,
    (uint32_t) dma2_ch7_irq,
    (uint32_t) lpuart1_irq,
    (uint32_t) quadspi_irq,
    (uint32_t) i2c3_ev_irq,
    (uint32_t) i2c3_er_irq,
    (uint32_t) sai1_irq,
    (uint32_t) sai2_irq,
    (uint32_t) swpmi1_irq,
    (uint32_t) tsc_irq,
    (uint32_t) lcd_irq,
    (uint32_t) aes_irq,
    (uint32_t) rng_irq,
    (uint32_t) fpu_irq
};

void default_handler(void) {
    while(1);
}

void reset_handler(void) {
    // copy .data section from rom(FLASH) to sram
    uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
    uint8_t *pdst = (uint8_t*)&_sdata; // sram
    uint8_t *psrc = (uint8_t*)&_la_data; // rom

    for(uint32_t i=0; i < size; i++) {
        *pdst++ = *psrc++;
    }

    // init the .bss section to zero in sram
    size = (uint32_t)&_ebss - (uint32_t)&_sbss;
    pdst = (uint8_t*)&_sbss;
    
    for(uint32_t i=0; i < size; i++) {
        *pdst++ = 0;
    }

    // call main()
    main();
}
