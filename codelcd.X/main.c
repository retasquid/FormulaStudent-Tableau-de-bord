#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compteur_vitesse.h"
#include <math.h>
#include "CAN_format.h"
#include "displayFunctions.h"

int main(void) {
    // Declaration d'une structure pour recevoir les messages CAN
    CAN_MSG_OBJ rxMessage;

    // Variable pour stocker la vitesse sous forme flottante
    FloatToBytes vitesse;
    vitesse.f32 = 0.0f;

    // Initialisation du systeme et des peripherals MCC
    SYSTEM_Initialize();

    // Initialisation de l'ecran
    ptrScreenInit();

    // Dessin des arcs de base pour le speedometre et le compte-tours
    ScreenDrawArc(120, 240, 60, -130, 130, 0xFFFF); // Speedometre
    ScreenDrawArc(120, 80, 60, -130, 130, 0xFFFF);  // Compte-tours

    // Initialisation des LED et STBY a l'etat bas
    LED_SetLow();
    STBY_SetLow();

    // Variable pour suivre l'ecran courant
    static uint8_t screen;

    // Boucle principale infinie
    while (1) {
        // Verification de la reception d'un message CAN
        if (CAN1_Receive(&rxMessage)) {

            // Traitement en fonction de l'ecran courant
            if (screen == 0) { // Ecran principal : vitesse, tr/min, date/heure
                switch (rxMessage.msgId) {
                    case 51: // Message de vitesse km/h
                        LED_SetHigh();          // Allumer LED indicatrice
                        GetMsgKmh(rxMessage.data);
                        LED_SetLow();           // Eteindre LED
                        break;

                    case 26: // Message de compte-tours et tension batterie
                        LED_SetHigh();
                        GetMsgTrminVbat(rxMessage.data);
                        LED_SetLow();
                        break;

                    case 34: // Message date et heure
                        LED_SetHigh();
                        GetMsgDateTime(rxMessage.data);
                        LED_SetLow();
                        break;

                    case 69: // Message de changement d'ecran
                        LED_SetHigh();
                        screen = GetScreenSwitch(rxMessage.data);
                        LED_SetLow();
                        break;

                    default: // Message inconnu : clignotement LED pour debug
                        LED_SetLow();
                        __delay_ms(1000);
                        LED_SetHigh();
                        __delay_ms(1000);
                }
            } 
            else if (screen == 1) { // Ecran secondaire : GPS (latitude / longitude)
                switch (rxMessage.msgId) {
                    case 36: // Message latitude
                        LED_SetHigh();
                        GetMsgLatitude(rxMessage.data);
                        LED_SetLow();
                        break;

                    case 37: // Message longitude
                        LED_SetHigh();
                        GetMsgLongitude(rxMessage.data);
                        LED_SetLow();
                        break;

                    case 69: // Message changement d'ecran
                        LED_SetHigh();
                        screen = GetScreenSwitch(rxMessage.data);
                        LED_SetLow();
                        break;

                    default: // Message inconnu : clignotement LED pour debug
                        LED_SetLow();
                        __delay_ms(1000);
                        LED_SetHigh();
                        __delay_ms(1000);
                }
            }
        }
    }

    return 0;
}