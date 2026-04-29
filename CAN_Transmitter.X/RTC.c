#include "RTC.h"

/*
 * Fonction temporaire car aucun module RTC installe
 */

void initDateTime(DateHeure* dateTime) {
    dateTime->annee.b16 = 2026;
    dateTime->mois = 3;
    dateTime->jour = 24;
    dateTime->heure = 8;
    dateTime->min = 13;
    dateTime->sec = 10;
}

void getDate(DateHeure* dateTime) {
    dateTime->annee.b16 = 2026; 
    dateTime->mois = 3;
    dateTime->jour = 24;
}

void getTime(DateHeure* dateTime, GPS_Message_t* GpsMsg) {
    //Recuperation de l'heure en BCD et convertion en numerique
    dateTime->heure = (GpsMsg->UTC[0]-'0')*10 + (GpsMsg->UTC[1]-'0');
    dateTime->min   = (GpsMsg->UTC[2]-'0')*10 + (GpsMsg->UTC[3]-'0');
    dateTime->sec   = (GpsMsg->UTC[4]-'0')*10 + (GpsMsg->UTC[5]-'0');
}