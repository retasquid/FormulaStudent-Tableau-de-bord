/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F27Q84
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LCD_RST aliases
#define LCD_RST_TRIS                 TRISAbits.TRISA0
#define LCD_RST_LAT                  LATAbits.LATA0
#define LCD_RST_PORT                 PORTAbits.RA0
#define LCD_RST_WPU                  WPUAbits.WPUA0
#define LCD_RST_OD                   ODCONAbits.ODCA0
#define LCD_RST_ANS                  ANSELAbits.ANSELA0
#define LCD_RST_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LCD_RST_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LCD_RST_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LCD_RST_GetValue()           PORTAbits.RA0
#define LCD_RST_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LCD_RST_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LCD_RST_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define LCD_RST_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define LCD_RST_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define LCD_RST_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define LCD_RST_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define LCD_RST_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set LCD_CS aliases
#define LCD_CS_TRIS                 TRISAbits.TRISA1
#define LCD_CS_LAT                  LATAbits.LATA1
#define LCD_CS_PORT                 PORTAbits.RA1
#define LCD_CS_WPU                  WPUAbits.WPUA1
#define LCD_CS_OD                   ODCONAbits.ODCA1
#define LCD_CS_ANS                  ANSELAbits.ANSELA1
#define LCD_CS_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LCD_CS_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LCD_CS_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LCD_CS_GetValue()           PORTAbits.RA1
#define LCD_CS_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LCD_CS_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LCD_CS_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define LCD_CS_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define LCD_CS_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define LCD_CS_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define LCD_CS_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define LCD_CS_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set LCD_RS aliases
#define LCD_RS_TRIS                 TRISAbits.TRISA2
#define LCD_RS_LAT                  LATAbits.LATA2
#define LCD_RS_PORT                 PORTAbits.RA2
#define LCD_RS_WPU                  WPUAbits.WPUA2
#define LCD_RS_OD                   ODCONAbits.ODCA2
#define LCD_RS_ANS                  ANSELAbits.ANSELA2
#define LCD_RS_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LCD_RS_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LCD_RS_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LCD_RS_GetValue()           PORTAbits.RA2
#define LCD_RS_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LCD_RS_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LCD_RS_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LCD_RS_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LCD_RS_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LCD_RS_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LCD_RS_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define LCD_RS_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set LCD_WR aliases
#define LCD_WR_TRIS                 TRISAbits.TRISA3
#define LCD_WR_LAT                  LATAbits.LATA3
#define LCD_WR_PORT                 PORTAbits.RA3
#define LCD_WR_WPU                  WPUAbits.WPUA3
#define LCD_WR_OD                   ODCONAbits.ODCA3
#define LCD_WR_ANS                  ANSELAbits.ANSELA3
#define LCD_WR_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LCD_WR_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LCD_WR_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LCD_WR_GetValue()           PORTAbits.RA3
#define LCD_WR_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LCD_WR_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LCD_WR_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define LCD_WR_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define LCD_WR_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define LCD_WR_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define LCD_WR_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define LCD_WR_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set LCD_RD aliases
#define LCD_RD_TRIS                 TRISAbits.TRISA4
#define LCD_RD_LAT                  LATAbits.LATA4
#define LCD_RD_PORT                 PORTAbits.RA4
#define LCD_RD_WPU                  WPUAbits.WPUA4
#define LCD_RD_OD                   ODCONAbits.ODCA4
#define LCD_RD_ANS                  ANSELAbits.ANSELA4
#define LCD_RD_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LCD_RD_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LCD_RD_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LCD_RD_GetValue()           PORTAbits.RA4
#define LCD_RD_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LCD_RD_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LCD_RD_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define LCD_RD_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define LCD_RD_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define LCD_RD_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define LCD_RD_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define LCD_RD_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA5
#define LED_LAT                  LATAbits.LATA5
#define LED_PORT                 PORTAbits.RA5
#define LED_WPU                  WPUAbits.WPUA5
#define LED_OD                   ODCONAbits.ODCA5
#define LED_ANS                  ANSELAbits.ANSELA5
#define LED_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED_GetValue()           PORTAbits.RA5
#define LED_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set STBY aliases
#define STBY_TRIS                 TRISBbits.TRISB0
#define STBY_LAT                  LATBbits.LATB0
#define STBY_PORT                 PORTBbits.RB0
#define STBY_WPU                  WPUBbits.WPUB0
#define STBY_OD                   ODCONBbits.ODCB0
#define STBY_ANS                  ANSELBbits.ANSELB0
#define STBY_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define STBY_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define STBY_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define STBY_GetValue()           PORTBbits.RB0
#define STBY_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define STBY_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define STBY_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define STBY_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define STBY_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define STBY_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define STBY_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define STBY_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSELB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set LCD_D0 aliases
#define LCD_D0_TRIS                 TRISCbits.TRISC0
#define LCD_D0_LAT                  LATCbits.LATC0
#define LCD_D0_PORT                 PORTCbits.RC0
#define LCD_D0_WPU                  WPUCbits.WPUC0
#define LCD_D0_OD                   ODCONCbits.ODCC0
#define LCD_D0_ANS                  ANSELCbits.ANSELC0
#define LCD_D0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LCD_D0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LCD_D0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define LCD_D0_GetValue()           PORTCbits.RC0
#define LCD_D0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define LCD_D0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define LCD_D0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define LCD_D0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define LCD_D0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define LCD_D0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define LCD_D0_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define LCD_D0_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set LCD_D1 aliases
#define LCD_D1_TRIS                 TRISCbits.TRISC1
#define LCD_D1_LAT                  LATCbits.LATC1
#define LCD_D1_PORT                 PORTCbits.RC1
#define LCD_D1_WPU                  WPUCbits.WPUC1
#define LCD_D1_OD                   ODCONCbits.ODCC1
#define LCD_D1_ANS                  ANSELCbits.ANSELC1
#define LCD_D1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LCD_D1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LCD_D1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LCD_D1_GetValue()           PORTCbits.RC1
#define LCD_D1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LCD_D1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define LCD_D1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define LCD_D1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define LCD_D1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define LCD_D1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define LCD_D1_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define LCD_D1_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set LCD_D2 aliases
#define LCD_D2_TRIS                 TRISCbits.TRISC2
#define LCD_D2_LAT                  LATCbits.LATC2
#define LCD_D2_PORT                 PORTCbits.RC2
#define LCD_D2_WPU                  WPUCbits.WPUC2
#define LCD_D2_OD                   ODCONCbits.ODCC2
#define LCD_D2_ANS                  ANSELCbits.ANSELC2
#define LCD_D2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LCD_D2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LCD_D2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LCD_D2_GetValue()           PORTCbits.RC2
#define LCD_D2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LCD_D2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LCD_D2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LCD_D2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LCD_D2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define LCD_D2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define LCD_D2_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define LCD_D2_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set LCD_D3 aliases
#define LCD_D3_TRIS                 TRISCbits.TRISC3
#define LCD_D3_LAT                  LATCbits.LATC3
#define LCD_D3_PORT                 PORTCbits.RC3
#define LCD_D3_WPU                  WPUCbits.WPUC3
#define LCD_D3_OD                   ODCONCbits.ODCC3
#define LCD_D3_ANS                  ANSELCbits.ANSELC3
#define LCD_D3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LCD_D3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LCD_D3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LCD_D3_GetValue()           PORTCbits.RC3
#define LCD_D3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LCD_D3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define LCD_D3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define LCD_D3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define LCD_D3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define LCD_D3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define LCD_D3_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define LCD_D3_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set LCD_D4 aliases
#define LCD_D4_TRIS                 TRISCbits.TRISC4
#define LCD_D4_LAT                  LATCbits.LATC4
#define LCD_D4_PORT                 PORTCbits.RC4
#define LCD_D4_WPU                  WPUCbits.WPUC4
#define LCD_D4_OD                   ODCONCbits.ODCC4
#define LCD_D4_ANS                  ANSELCbits.ANSELC4
#define LCD_D4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LCD_D4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define LCD_D4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define LCD_D4_GetValue()           PORTCbits.RC4
#define LCD_D4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define LCD_D4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define LCD_D4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define LCD_D4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define LCD_D4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define LCD_D4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define LCD_D4_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define LCD_D4_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set LCD_D5 aliases
#define LCD_D5_TRIS                 TRISCbits.TRISC5
#define LCD_D5_LAT                  LATCbits.LATC5
#define LCD_D5_PORT                 PORTCbits.RC5
#define LCD_D5_WPU                  WPUCbits.WPUC5
#define LCD_D5_OD                   ODCONCbits.ODCC5
#define LCD_D5_ANS                  ANSELCbits.ANSELC5
#define LCD_D5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LCD_D5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LCD_D5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LCD_D5_GetValue()           PORTCbits.RC5
#define LCD_D5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LCD_D5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LCD_D5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LCD_D5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LCD_D5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define LCD_D5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define LCD_D5_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define LCD_D5_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set LCD_D6 aliases
#define LCD_D6_TRIS                 TRISCbits.TRISC6
#define LCD_D6_LAT                  LATCbits.LATC6
#define LCD_D6_PORT                 PORTCbits.RC6
#define LCD_D6_WPU                  WPUCbits.WPUC6
#define LCD_D6_OD                   ODCONCbits.ODCC6
#define LCD_D6_ANS                  ANSELCbits.ANSELC6
#define LCD_D6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define LCD_D6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define LCD_D6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define LCD_D6_GetValue()           PORTCbits.RC6
#define LCD_D6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define LCD_D6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define LCD_D6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define LCD_D6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define LCD_D6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define LCD_D6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define LCD_D6_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define LCD_D6_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set LCD_D7 aliases
#define LCD_D7_TRIS                 TRISCbits.TRISC7
#define LCD_D7_LAT                  LATCbits.LATC7
#define LCD_D7_PORT                 PORTCbits.RC7
#define LCD_D7_WPU                  WPUCbits.WPUC7
#define LCD_D7_OD                   ODCONCbits.ODCC7
#define LCD_D7_ANS                  ANSELCbits.ANSELC7
#define LCD_D7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define LCD_D7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define LCD_D7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define LCD_D7_GetValue()           PORTCbits.RC7
#define LCD_D7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define LCD_D7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define LCD_D7_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define LCD_D7_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define LCD_D7_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define LCD_D7_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define LCD_D7_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define LCD_D7_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/