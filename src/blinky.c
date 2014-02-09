/*
 * blinky.c
 *
 *  Created on: Dec 10, 2013
 *      Author: kjell
 */

#include "ch.h"
#include "hal.h"
#include "blinky.h"

#include "uart.h" // temporarily included to test cyclic UART tx
#include "uart_scp.h"
#include "uart_lld.h"

static WORKING_AREA(waBlinkyBlue, BLINKY_STACK_SIZE);
static msg_t tBlinkyBlue(void *arg) {
  (void)arg;
  chRegSetThreadName("BlinkyBlue");

  while (TRUE) {
    chThdSleepMilliseconds(500);
    // Use this with the strip
    //palTogglePad(GPIOB, GPIOB_LEDR);

    // Use this with the Discovery F3 board
    palTogglePad(GPIOE, GPIOE_LED4_BLUE);
    // palTogglePad(GPIOC, GPIOC_LED4); // F0 board
  }

  return 0;
}

void startBlinkyBlue(void) {
  chThdCreateStatic(waBlinkyBlue, sizeof(waBlinkyBlue),
  NORMALPRIO,
                    tBlinkyBlue, NULL);
}

static WORKING_AREA(waBlinkyGreen, BLINKY_STACK_SIZE);
static msg_t tBlinkyGreen(void *arg) {
  (void)arg;
  uint8_t testbyte;
  chRegSetThreadName("BlinkyGreen");
  //chSysLockFromIsr();

  while (TRUE) {
    chThdSleepMilliseconds(300);
    // Use this with the strip
    //palTogglePad(GPIOB, GPIOB_LEDG);

    // Use this with the Discovery board
    //palTogglePad(GPIOC, GPIOC_LED3);
    palTogglePad(GPIOE, GPIOE_LED7_GREEN);
    testbyte = 77;
    //uartStartSendI(&UARTD1, 1, &testbyte);
    uartStartSend(&UARTD1, 1, &testbyte);

  }
  //chSysUnlockFromIsr();
  return 0;
}

void startBlinkyGreen(void) {
  chThdCreateStatic(waBlinkyGreen, sizeof(waBlinkyGreen),
  NORMALPRIO,
                    tBlinkyGreen, NULL);
}
