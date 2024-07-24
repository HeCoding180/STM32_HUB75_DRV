/*
 * HUB75_Driver.c
 *
 *  Created on: Jun 7, 2024
 *      Author: timow
 */

#include "../../STM32_HUB75_DRV/Inc/HUB75_Driver.h"

SyncRate_t DisplaySync = Sync_1_16;
uint8_t nSeriesDrivers = 16;
uint8_t nDriverChannels = 16;

// Utility functions
inline void generateClockPulse()
{
	// Set clock pin to high
	CTRL_CLK_GPIO_Port->BSRR = CTRL_CLK_Pin;
	// Set clock pin to low
	CTRL_CLK_GPIO_Port->BSRR = (uint32_t)(CTRL_CLK_Pin) << 16;
}
void generateNClockPulses(uint16_t N)
{
	for (uint16_t i = 0; i < N; i++)
	{
		generateClockPulse();
	}
}

void initDisplay(SyncRate_t DisplaySyncRate, uint8_t SeriesDrivers, uint8_t DriverChannels)
{
	nSeriesDrivers = SeriesDrivers;
	nDriverChannels = DriverChannels;

#ifdef USE_PWM_DRIVER

#endif
}

void executeVerticalStep()
{

}

#ifdef USE_PWM_DRIVER
void sendDriverCommand(const DrvCmd_t cmd)
{
	CTRL_LAT_GPIO_Port->BSRR = CTRL_LAT_Pin;
	generateNClockPulses((uint8_t)cmd);
	CTRL_LAT_GPIO_Port->BSRR = (uint32_t)(CTRL_LAT_Pin) << 16;
}

void setIndividualDriverRegisters(const DrvReg_t reg, const RW_t dir, const uint8_t R0data, const uint8_t G0data, const uint8_t B0data, const uint8_t R1data, const uint8_t G1data, const uint8_t B1data)
{
	if (!((reg == DebugReg) && (dir != Read)))
	{
		uint8_t nCmd = (8 * nSeriesDrivers) - ((uint8_t)reg + dir);
		for (uint16_t bit = 0; bit < (8 * nSeriesDrivers); bit++)
		{

		}
	}
}

void setAllDriverRegisters(const DrvReg_t reg, const RW_t dir, const uint16_t data)
{
	// Check for illegal combination
	if (!((reg == DebugReg) && (dir != Read)))
	{
		// Generate command
		uint8_t nCmd = (8 * nSeriesDrivers) - (DrvCmd_t)(reg + dir);
		for (uint16_t bit = 0; bit < (8 * nSeriesDrivers); bit++)
		{
			DATA_GPIO_PORT->BSRR = ((data >> (bit % 8)) & 0x01) ? DATA_BSRR_SET_MASK : DATA_BSRR_RESET_MASK;
			generateClockPulse();
		}
	}
}
#endif
