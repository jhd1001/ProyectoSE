/** ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : CPU_Config.h
**     Project     : Proyecto
**     Processor   : MK64FN1M0VLQ12
**     Version     : Component 01.046, Driver 01.00, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-03-15, 17:36, # CodeGen: 1
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file CPU_Config.h                                                  
** @version 01.00
*/         
/*!
**  @addtogroup CPU_Config_module CPU_Config module documentation
**  @{
*/         

#ifndef __CPU_Config_H
#define __CPU_Config_H

/* MODULE CPU_Config.h */

/* Include C integer types declaration header */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* EntryPoint function definition */
#define PEX_ENTRYPOINT_FUNCTION                            __init_hardware
#define PEX_ENTRYPOINT_FUNCTION_TYPE                       void
#define PEX_ENTRYPOINT_FUNCTION_RETURN            

/* 
   Component method constants. Internal methods are not included. 

   When method is enabled in the processor (CPU) component associated constant
   has value 1 otherwise 0.
*/

#define CPU_SET_CLOCK_CONFIGURATION                        0x00U      
#define CPU_GET_CLOCK_CONFIGURATION                        0x00U      
#define CPU_SET_OPERATION_MODE                             0x00U      
#define CPU_ENABLE_INT                                     0x00U      
#define CPU_DISABLE_INT                                    0x00U      
#define CPU_MCG_AUTO_TRIM                                  0x00U      
#define CPU_VLP_MODE_ENABLE                                0x00U      
#define CPU_VLP_MODE_DISABLE                               0x00U      
#define CPU_SYSTEM_RESET                                   0x00U      

/* Events constants. */

/* Processor (CPU) component's events are called from ISRs implemented in the Cpu.c as 
   code of the CPU ISRs depends on the RTOS Adaptor and may vary. Only exception is OnReset event
   which is called directly as this event doesn't have any ISR. */


/* 
    Processor type constants 

    Constants specifying processor family, type or variant.    
*/

#define CPU_FAMILY_Kinetis             /* Specification of the core type of the selected processor */
#define CPU_DERIVATIVE_MK64FN1M0LQ12   /* Name of the selected processor derivative */
#define CPU_PARTNUM_MK64FN1M0VLQ12     /* Part number of the selected processor */
#define CPU_LITTLE_ENDIAN              /* The selected processor uses little endian */

/* 
    Processor clock source constants
    
    Constants containing frequencies of processor reference clock sources.
*/

#define CPU_BUS_CLK_HZ                  20971520U /* Initial value of the bus clock frequency in Hz */
#define CPU_CORE_CLK_HZ                 20971520U /* Initial value of the core/system clock frequency in Hz.  */
#define CPU_INT_SLOW_CLK_HZ             32768U /* Value of the slow internal oscillator clock frequency in Hz  */
#define CPU_INT_FAST_CLK_HZ             4000000U /* Value of the fast internal oscillator clock frequency in Hz  */
/* 
    Clock configuration frequency constants

    Following constants contain variety of frequency values generated by the processor
    in the specific Clock configuration.
    Clock configurations are used to control general processor timing 
    (for example core and bus clock or FLL and PLL submodules) and to predefine
    up to 8 different processor timing schemes.
    After reset, processor is set to the Clock configuration 0. During the 
    application run-time SetClockConfiguration() method can be used to switch 
    between predefined Clock configurations.
    Clock configurations are set in the processor (CPU) component: 
    Clock settings\Clock configurations group of properties.
*/

#define CPU_CLOCK_CONFIG_NUMBER         0x01U /* Specifies number of defined clock configurations. */

#define CPU_BUS_CLK_HZ_CLOCK_CONFIG0    20971520U /* Value of the bus clock frequency in the clock configuration 0 in Hz. */
#define CPU_CORE_CLK_HZ_CLOCK_CONFIG0   20971520U /* Value of the core/system clock frequency in the clock configuration 0 in Hz. */

/* CPU frequencies in clock configuration 0 */
#define CPU_CLOCK_CONFIG_0              0x00U /* Clock configuration 0 identifier */
#define CPU_CORE_CLK_HZ_CONFIG_0        20971520UL /* Core clock frequency in clock configuration 0 */
#define CPU_BUS_CLK_HZ_CONFIG_0         20971520UL /* Bus clock frequency in clock configuration 0 */
#define CPU_FLEXBUS_CLK_HZ_CONFIG_0     10485760UL /* Flexbus clock frequency in clock configuration 0 */
#define CPU_FLASH_CLK_HZ_CONFIG_0       10485760UL /* FLASH clock frequency in clock configuration 0 */
#define CPU_USB_CLK_HZ_CONFIG_0         0UL /* USB clock frequency in clock configuration 0 */
#define CPU_PLL_FLL_CLK_HZ_CONFIG_0     20971520UL /* PLL/FLL clock frequency in clock configuration 0 */
#define CPU_MCGIR_CLK_HZ_CONFIG_0       32768UL /* MCG internal reference clock frequency in clock configuration 0 */
#define CPU_OSCER_CLK_HZ_CONFIG_0       0UL /* System OSC external reference clock frequency in clock configuration 0 */
#define CPU_ERCLK32K_CLK_HZ_CONFIG_0    1000UL /* External reference clock 32k frequency in clock configuration 0 */
#define CPU_MCGFF_CLK_HZ_CONFIG_0       32768UL /* MCG fixed frequency clock */


/* Clock configuration structure declaration. Structure is initialized in PE_LDD.c */
typedef struct  {
  uint32_t cpu_core_clk_hz;            /* Core clock frequency in clock configuration */
  uint32_t cpu_bus_clk_hz;             /* Bus clock frequency in clock configuration */
  uint32_t cpu_flexbus_clk_hz;         /* Flexbus clock frequency in clock configuration */
  uint32_t cpu_flash_clk_hz;           /* FLASH clock frequency in clock configuration */
  uint32_t cpu_usb_clk_hz;             /* USB clock frequency in clock configuration */
  uint32_t cpu_pll_fll_clk_hz;         /* PLL/FLL clock frequency in clock configuration */
  uint32_t cpu_mcgir_clk_hz;           /* MCG internal reference clock frequency in clock configuration */
  uint32_t cpu_oscer_clk_hz;           /* System OSC external reference clock frequency in clock configuration */
  uint32_t cpu_erclk32k_clk_hz;        /* External reference clock 32k frequency in clock configuration */
  uint32_t cpu_mcgff_clk_hz;           /* MCG fixed frequency clock */
} TCpuClockConfiguration;

/* The array of clock frequencies in configured clock configurations */
extern const TCpuClockConfiguration PE_CpuClockConfigurations[CPU_CLOCK_CONFIG_NUMBER];

/* 
    Clock generator (MCG) mode constants
    
    Constants and types used to specify MCG mode and clock sources used 
    by the clock generator. Each mode constant consists of unique mode ID 
    number and mode features encoded using bit-mask. Clock sources are encoded
    using just bit-mask describing source features.
*/

/* MCG mode and clock source features - used to fill CPU_TClockGenMode and CPU_TClockSource */
#define CPU_CLOCK_SLOW_MASK                                0x10U     /* Mode uses slow internal reference clock */ 
#define CPU_CLOCK_FAST_MASK                                0x20U     /* Mode uses fast internal reference clock */ 
#define CPU_CLOCK_EXTERNAL_CLOCK_MASK                      0x40U     /* Mode uses external reference clock from external clock input */ 
#define CPU_CLOCK_EXTERNAL_CRYSTAL_MASK                    0x80U     /* Mode uses external reference clock from crystal/resonator reference connection */ 
#define CPU_CLOCK_RTC_OSC_MASK                             0x0100U   /* Mode uses RTC oscillator clock */ 
#define CPU_CLOCK_PLL_MASK                                 0x0200U   /* PLL module is enabled in other than PEE and PBE mode */ 
#define CPU_CLOCK_IRC48M_MASK                              0x0400U   /* Mode uses internal reference clock 48MHz */ 


/* MCG mode IDs - used to fill CPU_TClockGenMode */
#define CPU_MCG_MODE_FEI                                   0x00U     /* FEI mode ID */ 
#define CPU_MCG_MODE_FBI                                   0x01U     /* FBI mode ID */ 
#define CPU_MCG_MODE_BLPI                                  0x02U     /* BLPI mode ID */ 
#define CPU_MCG_MODE_FEE                                   0x03U     /* FEE mode ID */ 
#define CPU_MCG_MODE_FBE                                   0x04U     /* FBE mode ID */ 
#define CPU_MCG_MODE_BLPE                                  0x05U     /* BLPE mode ID */ 
#define CPU_MCG_MODE_PBE                                   0x06U     /* PBE mode ID */ 
#define CPU_MCG_MODE_PEE                                   0x07U     /* PEE mode ID */ 
#define CPU_MCG_MODES                                      0x08U     /* Number of available MCG modes */ 
#define CPU_MCG_MODE_INDEX_MASK                            0x0FU     /* Mask of bits where MCG mode ID is encoded */ 

/* MCG mode type - used to specify MCG mode of each Clock configuration */
typedef uint16_t CPU_TClockGenMode;

/* 
    Very low power mode constants
    
    Constants used to specify very low power mode settings in each
    clock configuration.
*/

/* Low power mode settings mask constants - used to fill CPU_TClockVeryPowerMode */
#define CPU_CLOCK_VLP_ENABLE_MASK                          0x01U     /* Very low power mode enabled */ 
#define CPU_CLOCK_VLP_AUTO_ENABLE_MASK                     0x02U     /* Very low power mode entered automatically from SetClockConfiguration method */ 
#define CPU_CLOCK_VLP_WAKEUP_MASK                          0x04U     /* Very low power mode exited after any interrupt */ 

/* Low power mode settings type - used to enable/set-up Very low power mode of each Clock configuration */
typedef uint8_t CPU_TClockPowerMode;

/* 
    Clock configuration descriptor
    
    Following types are used to define and store settings related to
    clock generator modules (i.e. MCG and OSC modules), system or common clock 
    dividers and selectors (SIM module) for each predefined Clock configuration. 
    When Clock configuration is switched the processor registers are updated 
    from the following descriptors.
*/

/* MCG and OSC module structure type
   Structure with MCG and OSC configuration. To lower memory footprint the structure 
   doesn't contain full list of MCG and OSC registers but only those with settings 
   necessary to set Clock configuration. */
typedef struct {
  uint8_t MCG_C1_value;
  uint8_t MCG_C2_value;
  uint8_t MCG_C4_value;
  uint8_t MCG_C5_value;
  uint8_t MCG_C6_value;
  uint8_t MCG_C7_value;
  uint8_t MCG_SC_value;
  uint8_t OSC_CR_value;
} CPU_TClockGenRegs;

/* Clock system settings structure type
   Structure contains system integration level clock settings - clock source 
   selectors and dividers which control clocks produced by MCG and OSC modules and 
   peripheral clock source selections common for multiple peripheral instances. */
typedef struct {
  uint32_t SIM_SOPT1_value;
  uint32_t SIM_SOPT2_value;
  uint32_t SIM_CLKDIV1_value;
} CPU_TClockSysRegs;

/* Clock configuration descriptor structure type 
   Gathers all Clock configuration settings. Content of this structure is used 
   during Clock configuration set up. */
typedef struct {
  CPU_TClockGenMode Mode;
  CPU_TClockPowerMode PowerMode;
  CPU_TClockGenRegs GenRegs;
  CPU_TClockSysRegs SysRegs;
  uint32_t BusClock;
} CPU_TClockConfigDescriptor;

/* Clock configuration structure content
   
   Following constants are use to initialize CPU_TClockConfigDescriptor structure
   in the static CPU_Init.c module. Constants for each Clock configuration
   enabled in the processor (CPU) component are generated.

   Properties: Clock settings\Clock configurations,
               Clock settings\Clock source settings,
               Clock settings\Clock sources.
*/

/* Clock configuration 0 */
#define CPU_MCG_MODE_CONFIG_0                              (CPU_MCG_MODE_FEI | CPU_CLOCK_SLOW_MASK) /* Clock generator mode */
#define CPU_CLOCK_PMODE_CONFIG_0                           0U /* RUN power mode */

#define CPU_MCG_C1_CONFIG_0                                0x06U /* MCG_C1 */
#define CPU_MCG_C2_CONFIG_0                                0x00U /* MCG_C2 */
#define CPU_MCG_C4_CONFIG_0                                0x00U /* MCG_C4 */
#define CPU_MCG_C5_CONFIG_0                                0x00U /* MCG_C5 */
#define CPU_MCG_C6_CONFIG_0                                0x00U /* MCG_C6 */
#define CPU_MCG_C7_CONFIG_0                                0x00U /* MCG_C7 */
#define CPU_MCG_SC_CONFIG_0                                0x00U /* MCG_SC */
#define CPU_OSC_CR_CONFIG_0                                0x80U /* OSC_CR */
#define CPU_SIM_SOPT1_CONFIG_0                             0x000C0000UL /* SIM_SOPT1 */
#define CPU_SIM_SOPT2_CONFIG_0                             0x00UL /* SIM_SOPT2 */
#define CPU_SIM_CLKDIV1_CONFIG_0                           0x00110000UL /* SIM_CLKDIV1 */

/* 
   Clock generator structure default content
   
   When Clock configurations set in the processor (CPU) component use different MCG 
   modes and transition between them requires passing through some intermediate MCG 
   mode then following constants are used to set up clock generator modules to these 
   intermediate MCG modes. Following constants represent CPU_TClockGenRegs structure 
   content loaded to the clock generator registers to configure the intermediate 
   mode of the generator modules.
   
   If setting is controlled by any property then the associated property is specified. 
   Rest of settings are not controlled by any property and their value is static.
*/


/* Clock generator default state in FEI mode 
   Clock source:                        Slow internal reference, disabled in the STOP mode
   Clock source frequency:              32.768 kHz (Property: Clock settings\Clock sources\Internal oscillator\Slow internal reference clock)
   FLL:                                 Enabled, engaged
   FLL factor:                          640
   Internal reference clock (MCGIRCLK): Disabled
   External reference clock (OSCERCLK): Disabled
   External clock monitor:              Disabled
   Loss of clock reset:                 Enabled
*/
/* MCG_C1: CLKS=0,IREFS=1,IRCLKEN=0,IREFSTEN=0 */
#define CPU_DEFAULT_FEI_MCG_C1                             0x04U     /* MCG_C1 value in FEI default state */ 
/* MCG_C2: LOCRE0=1 */
#define CPU_DEFAULT_FEI_MCG_C2                             0x80U     /* MCG_C2 value in FEI default state */ 
/* MCG_C4: DMX32=0,DRST_DRS=0 */
#define CPU_DEFAULT_FEI_MCG_C4                             0x00U     /* MCG_C4 value in FEI default state */ 
/* MCG_C5: PLLCLKEN0=0,PLLSTEN0=0,PRDIV0=0 */
#define CPU_DEFAULT_FEI_MCG_C5                             0x00U     /* MCG_C5 value in FEI default state */ 
/* MCG_C6: LOLIE0=0,CME0=0,VDIV0=0 */
#define CPU_DEFAULT_FEI_MCG_C6                             0x00U     /* MCG_C6 value in FEI default state */ 
/* MCG_C7: OSCSEL=0 */
#define CPU_DEFAULT_FEI_MCG_C7                             0x00U     /* MCG_C7 value in FEI default state */ 
/* MCG_SC: FCRDIV|=1 */
#define CPU_DEFAULT_FEI_MCG_SC                             0x02U     /* MCG_SC value in FEI default state */ 
/* OSC_CR: ERCLKEN=0,EREFSTEN=0 */
#define CPU_DEFAULT_FEI_OSC_CR                             0x00U     /* OSC_CR value in FEI default state */ 

/* Clock generator default state in FBI mode
   Clock source:                        Slow internal reference, disabled in the STOP mode
   Clock source frequency:              32.768 kHz (Property: Clock settings\Clock sources\Internal oscillator\Slow internal reference clock)
   FLL:                                 Enabled, bypassed
   FLL factor:                          640
   Internal reference clock (MCGIRCLK): Disabled
   External reference clock (OSCERCLK): Disabled
   External clock monitor:              Disabled
   Loss of clock reset:                 Enabled
*/
/* MCG_C1: CLKS|=1,IREFS=1,IRCLKEN=0,IREFSTEN=0 */
#define CPU_DEFAULT_FBI_MCG_C1                             0x44U     /* MCG_C1 value in FBI default state */ 
/* MCG_C2: LOCRE0=1 */
#define CPU_DEFAULT_FBI_MCG_C2                             0x80U     /* MCG_C2 value in FBI default state */ 
/* MCG_C4: DMX32=0,DRST_DRS=0 */
#define CPU_DEFAULT_FBI_MCG_C4                             0x00U     /* MCG_C4 value in FBI default state */ 
/* MCG_C5: PLLCLKEN0=0,PLLSTEN0=0,PRDIV0=0 */
#define CPU_DEFAULT_FBI_MCG_C5                             0x00U     /* MCG_C5 value in FBI default state */ 
/* MCG_C6: LOLIE0=0,CME0=0,VDIV0=0 */
#define CPU_DEFAULT_FBI_MCG_C6                             0x00U     /* MCG_C6 value in FBI default state */ 
/* MCG_C7: OSCSEL=0 */
#define CPU_DEFAULT_FBI_MCG_C7                             0x00U     /* MCG_C7 value in FBI default state */ 
/* MCG_SC: FCRDIV|=1 */
#define CPU_DEFAULT_FBI_MCG_SC                             0x02U     /* MCG_SC value in FBI default state */ 
/* OSC_CR: ERCLKEN=0,EREFSTEN=0 */
#define CPU_DEFAULT_FBI_OSC_CR                             0x00U     /* OSC_CR value in FBI default state */ 

/* Clock generator default state in BLPI mode
   Clock source:                        Slow internal reference, disabled in the STOP mode
   Clock source frequency:              32.768 kHz (Property: Clock settings\Clock sources\Internal oscillator\Slow internal reference clock)
   FLL:                                 Disabled
   Internal reference clock (MCGIRCLK): Disabled
   External reference clock (OSCERCLK): Disabled
   External clock monitor:              Disabled
   Loss of clock reset:                 Enabled
*/
/* MCG_C1: CLKS|=1,IREFS=1,IRCLKEN=0,IREFSTEN=0 */
#define CPU_DEFAULT_BLPI_MCG_C1                            0x44U     /* MCG_C1 value in BLPI default state */ 
/* MCG_C2: LOCRE0=1,LP=1 */
#define CPU_DEFAULT_BLPI_MCG_C2                            0x82U     /* MCG_C2 value in BLPI default state */ 
/* MCG_C4:  */
#define CPU_DEFAULT_BLPI_MCG_C4                            0x00U     /* MCG_C4 value in BLPI default state */ 
/* MCG_C5: PLLCLKEN0=0,PLLSTEN0=0,PRDIV0=0 */
#define CPU_DEFAULT_BLPI_MCG_C5                            0x00U     /* MCG_C5 value in BLPI default state */ 
/* MCG_C6: LOLIE0=0,CME0=0,VDIV0=0 */
#define CPU_DEFAULT_BLPI_MCG_C6                            0x00U     /* MCG_C6 value in BLPI default state */ 
/* MCG_C7: OSCSEL=0 */
#define CPU_DEFAULT_BLPI_MCG_C7                            0x00U     /* MCG_C7 value in BLPI default state */ 
/* MCG_SC: FCRDIV|=1 */
#define CPU_DEFAULT_BLPI_MCG_SC                            0x02U     /* MCG_SC value in BLPI default state */ 
/* OSC_CR: ERCLKEN=0,EREFSTEN=0 */
#define CPU_DEFAULT_BLPI_OSC_CR                            0x00U     /* OSC_CR value in BLPI default state */ 

/* Clock generator default state in FEE mode
   Clock source:                        External crystal (oscillator)
   External frequency range:            Low
   FLL external reference divider:      1
   FLL:                                 Enabled, engaged
   FLL factor:                          640
   Internal reference clock (MCGIRCLK): Disabled
   External reference clock (OSCERCLK): Disabled
   External clock monitor:              Disabled
   Loss of clock reset:                 Enabled
*/
/* MCG_C1: CLKS=0,FRDIV|=6,IREFS=0,IRCLKEN=0,IREFSTEN=0 */
#define CPU_DEFAULT_FEE_MCG_C1                             0x30U     /* MCG_C1 value in FEE default state */ 
/* MCG_C2: LOCRE0=1,RANGE|=2,EREFS=1 */
#define CPU_DEFAULT_FEE_MCG_C2                             0xA4U     /* MCG_C2 value in FEE default state */ 
/* MCG_C4: DMX32=0,DRST_DRS=0 */
#define CPU_DEFAULT_FEE_MCG_C4                             0x00U     /* MCG_C4 value in FEE default state */ 
/* MCG_C5: PLLCLKEN0=0,PLLSTEN0=0,PRDIV0=0 */
#define CPU_DEFAULT_FEE_MCG_C5                             0x00U     /* MCG_C5 value in FEE default state */ 
/* MCG_C6: LOLIE0=0,CME0=0,VDIV0=0 */
#define CPU_DEFAULT_FEE_MCG_C6                             0x00U     /* MCG_C6 value in FEE default state */ 
/* MCG_C7: OSCSEL=2 */
#define CPU_DEFAULT_FEE_MCG_C7                             0x02U     /* MCG_C7 value in FEE default state */ 
/* MCG_SC: FCRDIV|=1 */
#define CPU_DEFAULT_FEE_MCG_SC                             0x02U     /* MCG_SC value in FEE default state */ 
/* OSC_CR: ERCLKEN=0,EREFSTEN=0 */
#define CPU_DEFAULT_FEE_OSC_CR                             0x00U     /* OSC_CR value in FEE default state */ 

/* Clock generator default state in FBE mode
   Clock source:                        External crystal (oscillator)
   External frequency range:            Low
   FLL external reference divider:      1
   FLL:                                 Enabled, bypassed
   FLL factor:                          640
   Internal reference clock (MCGIRCLK): Disabled
   External reference clock (OSCERCLK): Disabled
   External clock monitor:              Disabled
   Loss of clock reset:                 Enabled
*/
/* MCG_C1: CLKS|=2,FRDIV|=6,IREFS=0,IRCLKEN=0,IREFSTEN=0 */
#define CPU_DEFAULT_FBE_MCG_C1                             0xB0U     /* MCG_C1 value in FBE default state */ 
/* MCG_C2: LOCRE0=1,RANGE|=2,EREFS=1 */
#define CPU_DEFAULT_FBE_MCG_C2                             0xA4U     /* MCG_C2 value in FBE default state */ 
/* MCG_C4: DMX32=0,DRST_DRS=0 */
#define CPU_DEFAULT_FBE_MCG_C4                             0x00U     /* MCG_C4 value in FBE default state */ 
/* MCG_C5: PLLCLKEN0=0,PLLSTEN0=0,PRDIV0=0 */
#define CPU_DEFAULT_FBE_MCG_C5                             0x00U     /* MCG_C5 value in FBE default state */ 
/* MCG_C6: LOLIE0=0,CME0=0,VDIV0=0 */
#define CPU_DEFAULT_FBE_MCG_C6                             0x00U     /* MCG_C6 value in FBE default state */ 
/* MCG_C7: OSCSEL=2 */
#define CPU_DEFAULT_FBE_MCG_C7                             0x02U     /* MCG_C7 value in FBE default state */ 
/* MCG_SC: FCRDIV|=1 */
#define CPU_DEFAULT_FBE_MCG_SC                             0x02U     /* MCG_SC value in FBE default state */ 
/* OSC_CR: ERCLKEN=0,EREFSTEN=0 */
#define CPU_DEFAULT_FBE_OSC_CR                             0x00U     /* OSC_CR value in FBE default state */ 

/* Clock generator default state in BLPE mode
   Clock source:                        External crystal (oscillator)
   External frequency range:            Low
   FLL external reference divider:      1
   FLL:                                 Disabled
   Internal reference clock (MCGIRCLK): Disabled
   External reference clock (OSCERCLK): Disabled
   External clock monitor:              Disabled
   Loss of clock reset:                 Enabled
*/
/* MCG_C1: CLKS|=1,FRDIV|=6,IREFS=0,IRCLKEN=0,IREFSTEN=0 */
#define CPU_DEFAULT_BLPE_MCG_C1                            0x70U     /* MCG_C1 value in BLPE default state */ 
/* MCG_C2: LOCRE0=1,RANGE|=2,EREFS=1,LP=1 */
#define CPU_DEFAULT_BLPE_MCG_C2                            0xA6U     /* MCG_C2 value in BLPE default state */ 
/* MCG_C4:  */
#define CPU_DEFAULT_BLPE_MCG_C4                            0x00U     /* MCG_C4 value in BLPE default state */ 
/* MCG_C5: PLLCLKEN0=0,PLLSTEN0=0,PRDIV0=0 */
#define CPU_DEFAULT_BLPE_MCG_C5                            0x00U     /* MCG_C5 value in BLPE default state */ 
/* MCG_C6: LOLIE0=0,CME0=0,VDIV0=0 */
#define CPU_DEFAULT_BLPE_MCG_C6                            0x00U     /* MCG_C6 value in BLPE default state */ 
/* MCG_C7: OSCSEL=2 */
#define CPU_DEFAULT_BLPE_MCG_C7                            0x02U     /* MCG_C7 value in BLPE default state */ 
/* MCG_SC: FCRDIV|=1 */
#define CPU_DEFAULT_BLPE_MCG_SC                            0x02U     /* MCG_SC value in BLPE default state */ 
/* OSC_CR: ERCLKEN=0,EREFSTEN=0 */
#define CPU_DEFAULT_BLPE_OSC_CR                            0x00U     /* OSC_CR value in BLPE default state */ 
/* Clock generator default state in PEE mode
   Clock source:                        External crystal (oscillator)
   FLL external reference divider:      1
   PLL:                                 Enabled, engaged
   Internal reference clock (MCGIRCLK): Disabled
   External reference clock (OSCERCLK): Disabled
   External clock monitor:              Disabled
   Loss of clock reset:                 Enabled
*/
/* MCG_C1: CLKS=0,FRDIV|=6,IREFS=0,IRCLKEN=0,IREFSTEN=0 */
#define CPU_DEFAULT_PEE_MCG_C1                             0x30U     /* MCG_C1 value in PEE default state */ 
/* MCG_C2: LOCRE0=1,RANGE|=2,EREFS=1 */
#define CPU_DEFAULT_PEE_MCG_C2                             0xA4U     /* MCG_C2 value in PEE default state */ 
/* MCG_C4: DMX32=0,DRST_DRS=0 */
#define CPU_DEFAULT_PEE_MCG_C4                             0x00U     /* MCG_C4 value in PEE default state */ 
/* MCG_C5: PLLCLKEN0=0,PLLSTEN0=0,PRDIV0|=0x0B */
#define CPU_DEFAULT_PEE_MCG_C5                             0x0BU     /* MCG_C5 value in PEE default state */ 
/* MCG_C6: PLLS=1,CME0=0,VDIV0|=0x18 */
#define CPU_DEFAULT_PEE_MCG_C6                             0x58U     /* MCG_C6 value in PEE default state */ 
/* MCG_C7: OSCSEL=2 */
#define CPU_DEFAULT_PEE_MCG_C7                             0x02U     /* MCG_C7 value in PEE default state */ 
/* MCG_SC: FCRDIV|=1 */
#define CPU_DEFAULT_PEE_MCG_SC                             0x02U     /* MCG_SC value in PEE default state */ 
/* OSC_CR: ERCLKEN=0,EREFSTEN=0 */
#define CPU_DEFAULT_PEE_OSC_CR                             0x00U     /* OSC_CR value in PEE default state */ 
/* Clock generator default state in PBE mode
   Clock source:                        External crystal (oscillator)
   FLL external reference divider:      1
   PLL:                                 Enabled, bypassed
   Internal reference clock (MCGIRCLK): Disabled
   External reference clock (OSCERCLK): Disabled
   External clock monitor:              Disabled
   Loss of clock reset:                 Enabled
*/
/* MCG_C1: CLKS|=2,IREFS=0,IRCLKEN=0,IREFSTEN=0 */
#define CPU_DEFAULT_PBE_MCG_C1                             0x80U     /* MCG_C1 value in PBE default state */ 
/* MCG_C2: LOCRE0=1,RANGE|=2,EREFS=1 */
#define CPU_DEFAULT_PBE_MCG_C2                             0xA4U     /* MCG_C2 value in PBE default state */ 
/* MCG_C4: DMX32=0,DRST_DRS=0 */
#define CPU_DEFAULT_PBE_MCG_C4                             0x00U     /* MCG_C4 value in PBE default state */ 
/* MCG_C5: PLLCLKEN0=0,PLLSTEN0=0,PRDIV0|=0x0B */
#define CPU_DEFAULT_PBE_MCG_C5                             0x0BU     /* MCG_C5 value in PBE default state */ 
/* MCG_C6: PLLS=1,CME0=0,VDIV0|=0x18 */
#define CPU_DEFAULT_PBE_MCG_C6                             0x58U     /* MCG_C6 value in PBE default state */ 
/* MCG_C7: OSCSEL=2 */
#define CPU_DEFAULT_PBE_MCG_C7                             0x02U     /* MCG_C7 value in PBE default state */ 
/* MCG_SC: FCRDIV|=1 */
#define CPU_DEFAULT_PBE_MCG_SC                             0x02U     /* MCG_SC value in PBE default state */ 
/* OSC_CR: ERCLKEN=0,EREFSTEN=0 */
#define CPU_DEFAULT_PBE_OSC_CR                             0x00U     /* OSC_CR value in PBE default state */ 

/* 
   Low power mode settings
  
   Following constants are used for SetOperationMode() method parameterization.
   This method switches 4 driver operation modes - RUN, WAIT, SLEEP and STOP.
   These driver operation modes represents higher-level abstraction and maps 
   hardware power modes as follows:

   Driver mode      Hardware mode
   RUN   :          RUN / (VLPR)*
   WAIT  :          WAIT / (VLPW)*
   SLEEP :          Normal STOP / (VLPS)*
   STOP  :          VLLS0 / VLLS2 / VLLS1 / VLLS3 / LLS
   
   Very-low-power modes marked with ()* can be entered after additional 
   VLPModeEnable() method call. 
   Specific SLEEP or STOP mode entered after SetOperationMode() call is selected 
   in the processor (CPU) component.

   Properties: Low power mode settings\Operation mode settings\WAIT operation mode
               Low power mode settings\Operation mode settings\SLEEP operation mode
               Low power mode settings\Operation mode settings\STOP operation mode
*/

/* WAIT operation mode settings */
#define CPU_LOW_POWER_WAIT_SLEEP_ON_EXIT                   0x00U     /* ARM sleep-on-exit is disabled in WAIT operation mode (when the lowest priority ISR is exited then processor state unstacking is done before system goes back to low-power mode) */ 

/* SLEEP operation mode settings */
#define CPU_LOW_POWER_SLEEP_SLEEP_ON_EXIT                  0x00U     /* ARM sleep-on-exit is disabled in STOP operation mode (when the lowest priority ISR is exited unstacking is done before system goes back to low-power mode) */ 

/* STOP operation mode settings */
#define CPU_LOW_POWER_STOP_VLLS0                           0x01U     /* Very-Low-Leakage Stop 0 */ 
#define CPU_LOW_POWER_STOP_VLLS1                           0x02U     /* Very-Low-Leakage Stop 1 */ 
#define CPU_LOW_POWER_STOP_VLLS3                           0x03U     /* Very-Low-Leakage Stop 3 */ 
#define CPU_LOW_POWER_STOP_VLLS2                           0x04U     /* Very-Low-Leakage Stop 2 */ 
#define CPU_LOW_POWER_STOP_LLS                             0x05U     /* Low-Leakage Stop */ 

/* After reset values optimization */

/* Property: Common settings\Utilize after reset values */
#define CPU_AFTER_RESET_VALUES                             0x00U     /* After reset values optimization is disabled */ 

/* 
   Startup - parameterization
   
   Following constants contains parameterization of the MCU startup sequence 
   placed in the __init_hardware() method according to Processor Expert 
   CPU component settings but can be used to parameterize any user startup 
   code.   
   Values of the constants are generated from the component properties 
   specified in comments. If not specified differently, value 0 = feature 
   disabled and 1 = feature enabled. If constant has no defined value it 
   means feature is not used.
*/
  
/* Watchdog initialization */

/* Property: Common settings\Watchdog disable */
#define STARTUP_WDOG                                       0x01U     /* Watchdog disabled */ 
#define STARTUP_WDOG_KEY_1                                 0xC520U   /* Watchdog unlock key 1 */ 
#define STARTUP_WDOG_KEY_2                                 0xD928U   /* Watchdog unlock key 2 */ 

/* System clock initialization */
#define STARTUP_RTCOSC                                     0x00U     /* RTC oscillator not initialized */ 
  
/* Internal reference clock trim initialization 
   Properties: Clock settings\Clock sources\Internal oscillator\Initialize slow trim value */
#undef STARTUP_CLOCK_INTERNAL_SLOW_TRIM_ADDRESS                      /* Slow oscillator not trimmed */
#undef STARTUP_CLOCK_INTERNAL_SLOW_FINE_TRIM_ADDRESS                 /* Slow oscillator not trimmed */
/* Properties: Clock settings\Clock sources\Internal oscillator\Initialize fast trim value */
#undef STARTUP_CLOCK_INTERNAL_FAST_TRIM_ADDRESS                      /* Fast oscillator not trimmed */
#undef STARTUP_CLOCK_INTERNAL_FAST_FINE_TRIM_ADDRESS                 /* Fast oscillator not trimmed */

/* 
   Startup - register values
   
   Following constants represents the full set of registers accessed during 
   MCU startup sequence placed in the __init_hardware() method and their values 
   depends on Processor Expert's processor (CPU) component settings. 
   The constants have values of registers after the startup is finished.
   Although the list of registers accessed during the startup sequence may vary 
   across different CPU component settings, following constants represents 
   a superset of all registers which might be accessed. If register or register 
   bitfield is not modified during the particular startup sequence
   then its after reset value is presented.
   If register or register bitfield is accessed multiple times during the startup
   then the last written value is used.
*/

/* WDOG */

#define STARTUP_WDOG_STCTRLH_VALUE                         0x01D2U   /* WDOG_STCTRLH value */ 

/* MCG */

#define STARTUP_MCG_C1_VALUE                               0x06U     /* MCG_C1 value */ 
#define STARTUP_MCG_C2_VALUE                               0x00U     /* MCG_C2 value */ 
#define STARTUP_MCG_C3_VALUE                               0x00U     /* MCG_C3 value */ 
#define STARTUP_MCG_C4_VALUE                               0x00U     /* MCG_C4 value */ 
#define STARTUP_MCG_C6_VALUE                               0x00U     /* MCG_C6 value */ 
#define STARTUP_MCG_SC_VALUE                               0x02U     /* MCG_SC value */ 

/* OSC0 */

#define STARTUP_OSC_CR_VALUE                               0x80U     /* OSC_CR value */ 

/* SIM */

#define STARTUP_SIM_SOPT1_VALUE                            0x000C0000UL /* SIM_SOPT1 value */ 
#define STARTUP_SIM_SOPT2_VALUE                            0x00UL    /* SIM_SOPT2 value */ 
#define STARTUP_SIM_CLKDIV1_VALUE                          0x00110000UL /* SIM_CLKDIV1 value */ 
#define STARTUP_SIM_SCGC5_VALUE                            0x00040182UL /* SIM_SCGC5 value */ 
  
/* 
   PE_low_level_init() parameterization constants 

   Following constants contains parameterization of the PE_low_level_init() 
   method called at the main() method.
   Values of the constants are generated from the component properties 
   specified in comments. If not specified differently, value 0 = feature 
   disabled and 1 = feature enabled. If constant has no defined value it 
   means feature is not used.   
*/

/* Non-maskable interrupt pin initialization 
   Property: Common settings\NMI pin */
#define CPU_NMI_PIN                                        0x01U     /* NMI pin initialized */ 

/* JTAG TDI pin initialization 
   Property: Common settings\Debug interface (JTAG)\TDI pin */
#define CPU_JTAG_TDI_PIN                                   0x01U     /* JTAG TDI pin initialized */ 

/* JTAG TDO pin initialization 
   Property: Common settings\Debug interface (JTAG)\TDO pin */
#define CPU_JTAG_TDO_PIN                                   0x01U     /* JTAG TDO pin initialized */ 

/* JTAG TCK pin initialization 
   Property: Common settings\Debug interface (JTAG)\TCK pin */
#define CPU_JTAG_TCK_PIN                                   0x01U     /* JTAG TCK pin initialized */ 

/* JTAG TMS pin initialization 
   Property: Common settings\Debug interface (JTAG)\TMS pin */
#define CPU_JTAG_TMS_PIN                                   0x01U     /* JTAG TMS pin initialized */ 

/* JTAG TRST pin initialization 
   Property: Common settings\Debug interface (JTAG)\nTRST pin */
#define CPU_JTAG_TRST_PIN                                  0x00U     /* JTAG nTRST pin not initialized */ 

/* Low power modes protection initialization 
   Properties: Low power mode settings\Allowed low power modes */
#define CPU_LOW_POWER_ALLOW_VLP                            0x00U     /* VLPR VLPW and VLPS are not allowed */ 
#define CPU_LOW_POWER_ALLOW_LLS                            0x00U     /* LLS isn't allowed */ 
#define CPU_LOW_POWER_ALLOW_VLLS                           0x00U     /* No VLLSx mode is allowed */ 
     
/* Flash configuration field constants */
#define CPU_FLASH_CONFIG_FIELD \
               /* NV_BACKKEY3: KEY=0xFF */ \
               0xFFU, \
               /* NV_BACKKEY2: KEY=0xFF */ \
               0xFFU, \
               /* NV_BACKKEY1: KEY=0xFF */ \
               0xFFU, \
               /* NV_BACKKEY0: KEY=0xFF */ \
               0xFFU, \
               /* NV_BACKKEY7: KEY=0xFF */ \
               0xFFU, \
               /* NV_BACKKEY6: KEY=0xFF */ \
               0xFFU, \
               /* NV_BACKKEY5: KEY=0xFF */ \
               0xFFU, \
               /* NV_BACKKEY4: KEY=0xFF */ \
               0xFFU, \
               /* NV_FPROT3: PROT=0xFF */ \
               0xFFU, \
               /* NV_FPROT2: PROT=0xFF */ \
               0xFFU, \
               /* NV_FPROT1: PROT=0xFF */ \
               0xFFU, \
               /* NV_FPROT0: PROT=0xFF */ \
               0xFFU, \
               /* NV_FSEC: KEYEN=1,MEEN=3,FSLACC=3,SEC=2 */ \
               0x7EU, \
               /* NV_FOPT: ??=1,??=1,??=1,??=1,??=1,??=1,EZPORT_DIS=1,LPBOOT=1 */ \
               0xFFU, \
               /* NV_FEPROT: EPROT=0xFF */ \
               0xFFU, \
               /* NV_FDPROT: DPROT=0xFF */ \
               0xFFU

/* Common_Init() parameterization settings */
  
#define CPU_COMMON_INIT                                    0x00U     /* Common_Init() method is not called in PE_low_level_init() */ 

/* Peripherals_Init() parameterization settings */
  
#define CPU_PERIPHERALS_INIT                               0x00U     /* Peripherals_Init() method is not called in PE_low_level_init() */ 

/* Components_Init() parameterization settings */

#define CPU_COMPONENTS_INIT                                0x01U     /* Call Components_Init() method in PE_low_level_init() */ 

/* Interrupts priority level settings */
  
/* Property: Common settings\Initialization priority */
#define CPU_INT_PRIORITY                                   0xF0U     /* Priority level constant of enabled interrupts initialized in PE_low_level_init() */ 

#ifdef __cplusplus
}
#endif

#endif
/* __CPU_Config_H */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

