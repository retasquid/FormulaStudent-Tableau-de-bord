#ifndef CAN_FORMAT_H
#define	CAN_FORMAT_H

#include "mcc_generated_files/mcc.h"
#include "RTC.h"
#include "string.h"

// Norme CAN utilisee
#define CAN_ID_TYPE CAN_FRAME_STD
#define CAN_BRS_MODE CAN_NON_BRS_MODE
#define CAN_FORMAT_TYPE CAN_2_0_FORMAT


//Decoupage float 32bit en 4 octets transmissible
typedef union {
    float f32;
    uint8_t u8[4];
} FloatToBytes;

//Decoupage double 64bit en 8 octets transmissible
typedef union {
    double f64;
    uint8_t u8[8];
} DoubleToBytes;

//Decoupage uint 16 bit en 2 octets transmissible
typedef union {
    uint8_t u8[2];
    uint16_t u16;
} BytesToHalf;

/*
 * @brief Envoie la vitesse du vehicule en Km/h
 * @param float kmh : vitesse a envoyer
 * @return CAN_TX_MSG_REQUEST_STATUS : status de l'envoie
 */
CAN_TX_MSG_REQUEST_STATUS msgKmh(float kmh);

/*
 * @brief Envoie la vitesse du moteur en Tr/min et la tension de la batterie
 * @param uint16_t trmin : vitesse moteur a envoyer
 * @param float Vbat : voltage batte a envoyer
 * @return CAN_TX_MSG_REQUEST_STATUS : status de l'envoie
 */
CAN_TX_MSG_REQUEST_STATUS msgTrminVbat(uint16_t trmin, float Vbat);

/*
 * @brief Envoie la date et l'heure
 * @param DateHeure *horodatage : envoie de l'heure
 * @return CAN_TX_MSG_REQUEST_STATUS : status de l'envoie
 */
CAN_TX_MSG_REQUEST_STATUS msgDateTime(DateHeure *horodatage);

/*
 * @brief Envoie la latitude
 * @param char* latitude : envoie de la latitude
 * @return CAN_TX_MSG_REQUEST_STATUS : status de l'envoie
 */
CAN_TX_MSG_REQUEST_STATUS msgLatitude(char* latitude);

/*
 * @brief Envoie la longitude
 * @param char* longitude : envoie de la longitude
 * @return CAN_TX_MSG_REQUEST_STATUS : status de l'envoie
 */
CAN_TX_MSG_REQUEST_STATUS msgLongitude(char* longitude);

/*
 * @brief Change la page de l'interface graphique de l'ecran
 * @param uint8_t screen : ecran vers lequel changer
 * @return CAN_TX_MSG_REQUEST_STATUS : status de l'envoie
 */
CAN_TX_MSG_REQUEST_STATUS msgScreenSwitch(uint8_t screen);

#endif

