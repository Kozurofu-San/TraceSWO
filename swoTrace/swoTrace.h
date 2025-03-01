#pragma once

#include <stm32f103xb.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>

#define SWO_STLINK_V2_MAX_SPEED 2250000u

void swoInit(uint32_t portMask, uint32_t cpuCoreFreqHz, uint32_t baudrate);
uint32_t ITM_SendCharToChannel(uint32_t channel, uint32_t symbol);
void printString(uint32_t channel, char *symbol);


void LOGI(const char *msg, ...);  // Info
void LOGW(const char *msg, ...);  // Warning
void LOGE(const char *msg, ...);  // Error
void LOGV(uint32_t channel, int32_t value);   // Value for plotter