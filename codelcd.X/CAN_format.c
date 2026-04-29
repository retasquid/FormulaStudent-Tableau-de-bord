#include "CAN_format.h"

// Traitement des donnees de vitesse en km/h recues via CAN
void GetMsgKmh(uint8_t *rxData) {
    FloatToBytes vitesse;
    char car_trmin[6];

    // Copie des 4 octets de la trame CAN dans la variable flottante
    memcpy(vitesse.u8, rxData, 4);

    // Limitation de la vitesse a la valeur maximale definie
    if (vitesse.f32 > VITESSE_MAX_KMH) vitesse.f32 = VITESSE_MAX_KMH;

    // Mise a jour du compteur de vitesse graphique
    SpeedometerKmh(120, 240, vitesse.f32);

    // Conversion de la vitesse en chaine de caracteres
    snprintf(car_trmin, 6, "%3.1f", vitesse.f32);

    // Effacement de l'ancien affichage et affichage de la nouvelle valeur
    ScreenDrawTextH(220, 145, "     ", 0xFFFF, 0x0000);
    ScreenDrawTextH(220, 145, car_trmin, 0xFFFF, 0x0000);
    ScreenDrawTextH(230, 170, "Km/h", 0xFFFF, 0x0000);
}

// Traitement des donnees moteur (tr/min) et de la tension batterie
void GetMsgTrminVbat(uint8_t *rxData) {
    BytesToHalf vitesse;
    FloatToBytes Voltage;
    char engine_trmin[8];
    char Vbat[8];

    // Extraction des tr/min et de la tension depuis la trame CAN
    memcpy(vitesse.u8, rxData, 2);
    memcpy(Voltage.u8, rxData + 2, 4);

    // Limitation des tr/min a la valeur maximale definie
    if (vitesse.u16 > VITESSE_MAX_TRMIN) vitesse.u16 = VITESSE_MAX_TRMIN;

    // Mise a jour du compteur de tr/min graphique
    SpeedometerTrmin(120, 80, (float)vitesse.u16);

    // Conversion des tr/min en chaine de caracteres
    snprintf(engine_trmin, 6, "%hd", vitesse.u16);

    // Effacement et affichage des nouvelles valeurs tr/min
    ScreenDrawTextH(60, 145, "     ", 0xFFFF, 0x0000);
    ScreenDrawTextH(60, 145, engine_trmin, 0xFFFF, 0x0000);
    ScreenDrawTextH(60, 170, "Tr/min", 0xFFFF, 0x0000);

    // Affichage de la tension batterie sur le voltmetre graphique
    Voltmeter(10, 10, Voltage.f32);
    snprintf(Vbat, 6, "%2.1fV", Voltage.f32);

    // Effacement et affichage de la tension batterie
    ScreenDrawTextH(50, 205, "     ", 0xFFFF, 0x0000);
    ScreenDrawTextH(50, 205, Vbat, 0xFFFF, 0x0000);
}

// Traitement et affichage de la date et de l'heure
void GetMsgDateTime(uint8_t *rxData) {
    BytesToHalf year;
    char Date[16];
    char Heure[16];
    uint8_t month, day, hour, min, sec;

    // Extraction des composantes de la date/heure depuis la trame CAN
    memcpy(year.u8, rxData, 2);
    month = rxData[2];
    day = rxData[3];
    hour = rxData[4];
    min = rxData[5];
    sec = rxData[6];

    // Formatage de la date et mise a jour de l'affichage
    snprintf(Date, 11, "%02hhd/%02hhd/%04hd", day, month, year.u16);
    ScreenDrawTextH(200, 205, "           ", 0xFFFF, 0x0000);
    ScreenDrawTextH(200, 205, Date, 0xFFFF, 0x0000);

    // Formatage de l'heure et mise a jour de l'affichage
    snprintf(Heure, 9, "%02hhd:%02hhd:%02hhd", hour, min, sec);
    ScreenDrawTextH(110, 20, "          ", 0xFFFF, 0x0000);
    ScreenDrawTextH(120, 20, Heure, 0xFFFF, 0x0000);
}

// Affichage de la latitude
void GetMsgLatitude(uint8_t *rxData) {
    DoubleToBytes latitude;
    char string_latitude[25];

    // Copie de la valeur latitude (double) depuis la trame CAN
    memcpy(latitude.u8, rxData, 8);

    // Affichage du label et de la valeur formattee
    ScreenDrawTextH(10, 10, "          ", 0xFFFF, 0x0000);
    ScreenDrawTextH(10, 10, "Latitude :", 0xFFFF, 0x0000);
    snprintf(string_latitude, 26, "%5.5f deg", latitude.f64);
    ScreenDrawTextH(10, 40, "                      ", 0xFFFF, 0x0000);
    ScreenDrawTextH(10, 40, string_latitude, 0xFFFF, 0x0000);
}

// Affichage de la longitude
void GetMsgLongitude(uint8_t *rxData) {
    DoubleToBytes longitude;
    char string_longitude[26];

    // Copie de la valeur longitude (double) depuis la trame CAN
    memcpy(longitude.u8, rxData, 8);

    // Affichage du label et de la valeur formattee
    ScreenDrawTextH(10, 70, "            ", 0xFFFF, 0x0000);
    ScreenDrawTextH(10, 70, "Longitude : ", 0xFFFF, 0x0000);
    snprintf(string_longitude, 26, "%5.5f deg", longitude.f64);
    ScreenDrawTextH(10, 100, "                       ", 0xFFFF, 0x0000);
    ScreenDrawTextH(10, 100, string_longitude, 0xFFFF, 0x0000);
}

// Gestion du changement d'ecran
uint8_t GetScreenSwitch(uint8_t *rxData) {
    uint8_t screen = *rxData;

    // Effacement complet de l'ecran avant changement
    ptrScreenFillScreen(0x0000);

    // Configuration des elements graphiques selon l'ecran selectionne
    switch(screen) {
        case 0:
            ScreenDrawArc(120, 240, 60, -130, 130, 0xFFFF);
            ScreenDrawArc(120, 80, 60, -130, 130, 0xFFFF);
            break;
        case 1:
            // Ecran vide ou non defini pour le moment
            break;
        default:
            // Cas non gere
            break;
    }
    return screen;  
}