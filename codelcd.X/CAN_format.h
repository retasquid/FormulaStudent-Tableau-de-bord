#ifndef CAN_FORMAT_H
#define	CAN_FORMAT_H
#include "mcc_generated_files/mcc.h"
#include "lcd_font.h"
#include "lcd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compteur_vitesse.h"

//Decoupage float 32 bit en 4 octetcs transmissible

typedef union {
    float f32;
    uint8_t u8[4];
} FloatToBytes;

//Decoupage uint 16 bit en 2 octets transmissible

typedef union {
    uint8_t u8[2];
    uint16_t u16;
} BytesToHalf;

//Decoupage double 64 bit en 8 octets transmissible
typedef union {
    double f64;
    uint8_t u8[8];
} DoubleToBytes;
/*
 * @brief Fonction permet de traiter un message CAN contenant la vitesse, la limite a une valeur maximale et l'afficher sous le compteur et l'ecran LCD en km/h.
 * @param uint8_t *rxData : pointeur vers les données reçues du bus CAN contenant la vitesse
 * @return void
 */
void GetMsgKmh(uint8_t *rxData);

/*
 * @brief Fonction permet de traiter un message CAN contenant le regime moteur et la tension batterie, et de les afficher sur les jauges et l'ecran LCD.
 * @param uint8_t *rxData : pointeur vers les donnees reçues du bus CAN contenant le régime moteur et la tension batterie
 * @return void
 */
void GetMsgTrminVbat(uint8_t *rxData);

/*
 * @brief Fonction permet de traiter un message CAN contenant la date et l'heure et de les afficher sur l'ecran LCD.
 * @param uint8_t *rxData : pointeur vers les donnees reçues du bus CAN contenant la date et l'heure
 * @return void
 */
void GetMsgDateTime(uint8_t *rxData);

/*
 * @brief Fonction permet de traiter un message CAN contenant la latitude et de l'afficher sur l'ecran LCD.
 * @param uint8_t *rxData : pointeur vers les données reçues du bus CAN contenant la latitude
 * @return void
 */
void GetMsgLatitude(uint8_t *rxData);

/*
 * @brief Fonction permet de traiter un message CAN contenant la longitude et de l'afficher sur l'ecran LCD.
 * @param uint8_t *rxData : pointeur vers les donnees reçues du bus CAN contenant la longitude
 * @return void
 */
void GetMsgLongitude(uint8_t *rxData);

/*
 * @brief Fonction permet de traiter le changement d'écran et met a jour l'affichage de l'ecran LCD 
 * @param uint8_t *rxData : pointeur vers les donnees reçues du bus CAN representant l'etat de l'ecran
 * @return uint8_t : valeur de l'etat de l'ecran reçue (0, 1 ou valeur par defaut)
 */
uint8_t GetScreenSwitch(uint8_t *rxData);

#endif

