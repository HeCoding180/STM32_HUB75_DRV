/* * * * * * * * * * * * * * * * * * * * * * *
 *         Library Configuration File        *
 * * * * * * * * * * * * * * * * * * * * * * *
 * 
 *  @author HeCoding180
 *  @date   24.07.2024
 *  @file   LibConfig.h
 * 
 */

// Color depth per color (must be either 8, 16, 32 or 64)
#define COLOR_DEPTH 8

// Define to use efficient data transmission.
//
// When USE_FAST_DRIVER is defined the driver writes the R, G and B bits all at once.
// If not defined the R, G and B bits must be written individually, which takes quite some time
//
// USE_FAST_DRIVER can be used if all color lines of the individual pairs are arranged in series
// and are part of the same port with Rx being bit 0, Gx being bit 1 and Bx being bit 2.
//
// Example output configurations (-- = don't care):
// Port    ||                                       X                                       ||                                       Y                                       ||
// Pin     || 00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 | 08 | 09 | 10 | 11 | 12 | 13 | 14 | 15 || 00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 | 08 | 09 | 10 | 11 | 12 | 13 | 14 | 15 ||
// Valid   || -- | -- | -- | R0 | G0 | B0 | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- || -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | R1 | G1 | B1 | -- | -- ||
// Valid   || -- | -- | -- | -- | -- | -- | -- | R1 | G1 | B1 | R0 | G0 | B0 | -- | -- | -- || -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- ||
// Invalid || B0 | -- | R0 | G0 | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | R1 | G1 || B1 | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- ||
#define USE_FAST_DRIVER
