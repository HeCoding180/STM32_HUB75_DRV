/*
 * HUB75_Driver.h
 *
 *  Created on: Jun 7, 2024
 *      Author: timow
 */

#ifndef INC_HUB75_DRIVER_H_
#define INC_HUB75_DRIVER_H_

// Includes

#include "GPIO_Defines.h"

// Defines

#ifdef USE_ICND2153_DRIVER
#define USE_PWM_DRIVER
#define PWM_BITS 16
#else
#define PWM_BITS 1
#endif

#if PWM_BITS > 8
#define BUFFER_SIZE uint16_t
#else
#define BUFFER_SIZE uint8_t
#endif

// Typedefs
typedef enum SyncRate
{
	Sync_1_4 = 4,
	Sync_1_8 = 8,
	Sync_1_16 = 16,
	Sync_1_32 = 32
} SyncRate_t;

#ifdef USE_PWM_DRIVER
typedef enum DriverCommand
{
	DATA_LATCH = 1,		// Data latch
	WR_DBG = 2,			// Write debug register
	VSYNC = 3,			// Vertical sync
	WR_CFG1 = 4,		// Write configuration register 1
	RD_CFG1 = 5,		// Read configuration register 1
	WR_CFG2 = 6,		// Write configuration register 2
	RD_CFG1 = 7,		// Read configuration register 2
	WR_CFG3 = 8,		// Write configuration register 3
	RD_CFG3 = 9,		// Read configuration register 3
	WR_CFG4 = 10,		// Write configuration register 4
	WR_CFG3 = 11,		// Read configuration register 3
	EN_OP = 12,			// Enable output
	DIS_OP = 13,		// Disable output
	PREACTIVE = 14		// Pre-active
} DrvCmd_t;

typedef enum DriverRegister
{
	DebugReg = 2,
	ConfigReg1 = 4,
	ConfigReg2 = 6,
	ConfigReg3 = 8,
	ConfigReg4 = 10
} DrvReg_t;

typedef enum ReadWrite
{
	Write = 0,
	Read = 1
} RW_t;
#endif

// Function prototypes

inline void generateClockPulse();
void generateNClockPulses(uint16_t);

void initDisplay(SyncRate_t, uint8_t, uint8_t);
void executeVerticalStep();

void sendData();

#ifdef USE_PWM_DRIVER
void sendDriverCommand(const DrvCmd_t);
void setIndividualDriverRegisters(const DrvReg_t, const RW_t, const uint8_t, const uint8_t, const uint8_t, const uint8_t, const uint8_t, const uint8_t);
void setAllDriverRegisters(const DrvReg_t, const RW_t, const uint8_t);
#endif

// Extern variable definitions
extern SyncRate_t DisplaySync;
extern uint8_t nSeriesDrivers;
extern uint8_t nDriverChannels;

#endif /* INC_HUB75_DRIVER_H_ */
