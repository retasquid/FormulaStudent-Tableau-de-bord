/*
 * Auteur : Noe Dargaud
 * Date de modification : 21 mars 2026
 * Description : ce programme genere des donnees aleatoires
 * et recupere des donnees GPS afin de les transmettre sur le bus CAN
 */

#include "mcc_generated_files/mcc.h"
#include "CAN_format.h"
#include "rand.h"
#include "RTC.h"
#include "GPS.h"

GPS_Message_t GpsMsg;
DateHeure horodatage;

void main(void) {
    SYSTEM_Initialize();
    UART1_SetRxInterruptHandler(GPSRxISR);  // Initialisation de l'interruption GPS
    INTERRUPT_GlobalInterruptEnable();
    STBY_SetLow();                          // Activation du module CAN
    srand16(TMR2);                          // Initialisation de la seed RNG avec un timer
    initDateTime(&horodatage);
    LED_SetLow();
    GPS_init();
    __delay_ms(100);
    
    while (1) {
        LED_SetHigh();

        // Mise a jour de l'heure
        getTime(&horodatage, &GpsMsg);
        
        // Affichage des donnees sur l'ecran principal
        msgScreenSwitch(0);
        
        /* Envoi des informations aleatoires a la carte ecran */
        msgKmh((float)(rand16(0, 2500) / 10.0));
        
        msgTrminVbat(rand16(0, 6000), (float)(rand16(120, 160) / 10.0));
        
        msgDateTime(&horodatage);
        
        LED_SetLow();
        __delay_ms(5000);
        LED_SetHigh();
        
        // Affichage des donnees sur l'ecran secondaire
        msgScreenSwitch(1);
        
        /* Reception et copie securisee du message GPS */
        INTERRUPT_GlobalInterruptDisable();
        if(GPSRxReady){
            GPSRxReady = 0;
            strncpy(GPSMessage_safe, (const char*)GPSMessage, RX_BUFFER_SIZE);
        }
        INTERRUPT_GlobalInterruptEnable();

        // Parsing de la trame GPS
        GPGLL_Parser(GPSMessage_safe, &GpsMsg);

        /* Envoi des informations GPS a la carte ecran */
        msgLatitude(GpsMsg.latitude);
        msgLongitude(GpsMsg.longitude);
        
        __delay_ms(10);
        LED_SetLow();
        __delay_ms(5000);
    }
}