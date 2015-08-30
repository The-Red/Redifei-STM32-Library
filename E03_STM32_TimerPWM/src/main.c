/*
 * Redifei: E03 TimerPWM Library Example
 * The code is released under the 'GNU GENERAL PUBLIC LICENSE Version 2'
 */
#include "stm32f10x_conf.h"
#include "printf.h"

#include "i2c.h"
#include "pwm.h"
#include "serial.h"
#include "vcom.h"

serialUartPort_t*   serialPort;
vComPort_t*         vcomPort;
i2cPort_t*          i2cPort;
timPwmPort_t*       pwmInPort;
timPwmPort_t*       pwmOutPort;


void _delay(uint32_t ms) {
  ms *= 8000;
  while(--ms);
}

int main(void) {
  serialPort = openSerial3(SERIAL_INTERRPUT_MODE);
  serialPort->printf("Hello World!\r\n");

  pwmInPort = openTimerPwm101(TIM_PWM_INPUT_MODE);
  pwmOutPort = openTimerPwm301(TIM_PWM_OUTPUT_MODE);
  pwmOutPort = openTimerPwm302(TIM_PWM_OUTPUT_MODE);

  pwmOutPort->chan1Write(500);
  pwmOutPort->chan2Write(1500);

  while(1) {
    serialPort->printf("%d\r\n",pwmInPort->chan1Read());
    _delay(100);
  }
}
