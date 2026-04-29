#ifndef RTC_H
#define	RTC_H

#include <stdint.h>
#include "GPS.h"

//Regroupement des variables de date et heure
typedef struct{
    union{
        uint16_t b16;
        uint8_t b8[2];
    }annee;
    uint8_t mois;
    uint8_t jour;
    uint8_t heure;
    uint8_t min;
    uint8_t sec;
}DateHeure;

/*
 * @brief initialise la date et l'heure
 * @param DateHeure* dateTime : passage de la structure comprenant la date et l'heure
 * @return void
 */
void initDateTime(DateHeure* dateTime);

/*
 * @brief met a jour la date
 * @param DateHeure* dateTime : passage de la structure comprenant la date et l'heure
 * @return void
 */
void getDate(DateHeure* dateTime);

/*
 * @brief met a jour l'heure
 * @param DateHeure* dateTime : passage de la structure comprenant la date et l'heure
 * @return void
 */
void getTime(DateHeure* dateTime, GPS_Message_t* GpsMsg);

#endif