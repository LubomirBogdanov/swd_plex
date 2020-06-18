/*
    Copyright (C) 2020 Lubomir Bogdanov
    Contributor Lubomir Bogdanov <lbogdanov@tu-sofia.bg>
    This file is part of swd_plex.
    swd_plex is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    swd_plex is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.
    You should have received a copy of the GNU Lesser General Public License
    along with swd_plex.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __MAIN_H__
#define __MAIN_H__

#include <msp430.h>
#include <stdint.h>

#define ICs_EN_PORT			P1DIR
#define ICs_EN_OUTREG			P1OUT
#define IC1_EN				BIT0
#define IC2_EN				BIT1
#define IC3_EN				BIT2

#define CHAN_SEL_PORT			P1DIR
#define CHAN_SEL_OUTREG			P1OUT
#define CHAN_SEL_0			BIT3
#define CHAN_SEL_1			BIT4

#define SOFT_UART_PORT			P1DIR
#define SOFT_UART_IEREG			P1IE
#define SOFT_UART_IESREG		P1IES
#define SOFT_UART_INREG			P1IN
#define SOFT_UART_OUTREG		P1OUT
#define SOFT_UART_MCU_TX_PIN		BIT7
#define SOFT_UART_MCU_RX_PIN		BIT6
#define SOFT_UART_MCU_RX_BIT_POSITION	6

#define LED_PORT			P1DIR
#define LED_OUTREG			P1OUT
#define LED_PIN				BIT5

void init_gpio(void);
void init_enable_pins(void);
void init_channel_select_pins(void);
void init_clocks(void);
void init_timer(void);
void timer_delay(uint16_t delay_val);
void init_soft_uart(void);
void init(void);
void enable_chip(uint8_t chip_num);
void set_channel(uint8_t chan_num);
uint8_t soft_uart_read_rx(uint8_t bit_position);
void soft_uart_write_tx(uint8_t byte);
void display_msg(void);

#endif
