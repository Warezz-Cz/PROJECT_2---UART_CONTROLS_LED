#include "main.h"
#include "milis.h"
#include <stdbool.h>
#include <stm8s.h>
// #include "delay.h"
#include "sonboard.h"
#include "uart1.h"
#include <stdio.h>

// Discovery Board
#ifdef STM8S003
#define LED_PORT GPIOD
#define LED_PIN GPIO_PIN_0
#define BTN_PORT GPIOB
#define BTN_PIN GPIO_PIN_7
#endif
// Dero Board
#ifdef STM8S103
#define LED_PORT GPIOD
#define LED_PIN GPIO_PIN_4
#endif
// Discovery Board
#ifdef STM8S105
#define LED_PORT GPIOD
#define LED_PIN GPIO_PIN_0
#endif
// Nucleo Kit
#ifdef STM8S208
#define LED_PORT GPIOC
#define LED_PIN GPIO_PIN_5
#define BTN_PORT GPIOE
#define BTN_PIN GPIO_PIN_4
#endif


extern uint16_t ledtime;
extern char regime;
extern bool stop;
extern bool show;

void init(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // taktovani MCU na 16MHz
    init_milis();
    init_uart1();

    GPIO_Init(SB_LED8_PORT, SB_LED8_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
}


int main(void)
{

    uint32_t time = 0;

    init();

    while (1) {
        if (((milis() - time > ledtime)) && stop == 1) {
            time = milis();
            REVERSE(SB_LED8);
        }
        if (show == 1) {
            if (stop == 0) {
                printf("Regime: 0 | LED stoped \n");
            } else {
                uint16_t period = ledtime * 2;
                uint16_t freq_raw = 10000 / period;

                printf("Regime: %c | Period: %u ms | Frequency: %u.%u Hz\n", regime, period, freq_raw / 10, freq_raw % 10);
            }
            show = 0;
        }
    }
}
/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
// pyserial-miniterm - 115200
// vyberu port
// klikám tlačitka
// ctrl + altgr + ] (pro exit)