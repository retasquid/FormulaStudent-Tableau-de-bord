#include "CAN_format.h"
#include "GPS.h"

CAN_TX_MSG_REQUEST_STATUS msgKmh(float kmh) {
    static CAN_MSG_OBJ txMessage;
    static uint8_t TAB[4];                 // declaration de la donnee en static obligatoire
    FloatToBytes vitesse;

    vitesse.f32 = kmh;
    memcpy(TAB, vitesse.u8, 4);
    
    txMessage.msgId = 51;                  // Identifiant CAN du message vitesse
    txMessage.field.idType = CAN_ID_TYPE;
    txMessage.field.dlc = 4;               // Taille du payload : 4 octets
    txMessage.field.brs = CAN_BRS_MODE;
    txMessage.field.formatType = CAN_FORMAT_TYPE;
    txMessage.data = TAB;

    CAN_TX_MSG_REQUEST_STATUS status = CAN1_Transmit(CAN1_TX_FIFO1, &txMessage);
    return status;
}

CAN_TX_MSG_REQUEST_STATUS msgTrminVbat(uint16_t trmin, float Vbat) {
    static CAN_MSG_OBJ txMessage;
    static uint8_t TAB[6];                 // declaration de la donnee en static obligatoire
    FloatToBytes Voltbat;
    BytesToHalf TrMin;

    Voltbat.f32 = Vbat;
    TrMin.u16 = trmin;

    memcpy(TAB, TrMin.u8, 2);      // Copie tr/min
    memcpy(TAB + 2, Voltbat.u8, 4); // Copie tension batterie
    
    txMessage.msgId = 26;                  // Identifiant CAN tr/min + Vbat
    txMessage.field.idType = CAN_ID_TYPE;
    txMessage.field.dlc = 6;               // Taille du payload : 6 octets
    txMessage.field.brs = CAN_BRS_MODE;
    txMessage.field.formatType = CAN_FORMAT_TYPE;
    txMessage.data = TAB;

    CAN_TX_MSG_REQUEST_STATUS status = CAN1_Transmit(CAN1_TX_FIFO1, &txMessage);
    return status;
}

CAN_TX_MSG_REQUEST_STATUS msgDateTime(DateHeure *horodatage) {
    static CAN_MSG_OBJ txMessage;
    static uint8_t TAB[7];                 // declaration de la donnee en static obligatoire

    TAB[0] = horodatage->annee.b8[0];
    TAB[1] = horodatage->annee.b8[1];
    TAB[2] = horodatage->mois;
    TAB[3] = horodatage->jour;
    TAB[4] = horodatage->heure;
    TAB[5] = horodatage->min;
    TAB[6] = horodatage->sec;

    txMessage.msgId = 34;                  // Identifiant CAN date/heure
    txMessage.field.idType = CAN_ID_TYPE;
    txMessage.field.dlc = 7;               // Taille du payload : 7 octets
    txMessage.field.brs = CAN_BRS_MODE;
    txMessage.field.formatType = CAN_FORMAT_TYPE;
    txMessage.data = TAB;

    CAN_TX_MSG_REQUEST_STATUS status = CAN1_Transmit(CAN1_TX_FIFO1, &txMessage);
    return status;
}

CAN_TX_MSG_REQUEST_STATUS msgLatitude(char* latitude) {
    static CAN_MSG_OBJ txMessage;
    static uint8_t TAB[8];                 // declaration de la donnee en static obligatoire
    DoubleToBytes Latitude;

    Latitude.f64 = (double)atof(latitude);
    memcpy(TAB, Latitude.u8, 8);
    
    txMessage.msgId = 36;                  // Identifiant CAN latitude
    txMessage.field.idType = CAN_ID_TYPE;
    txMessage.field.dlc = 8;               // Taille du payload : 8 octets
    txMessage.field.brs = CAN_BRS_MODE;
    txMessage.field.formatType = CAN_FORMAT_TYPE;
    txMessage.data = TAB;

    CAN_TX_MSG_REQUEST_STATUS status = CAN1_Transmit(CAN1_TX_FIFO1, &txMessage);
    return status;
}

CAN_TX_MSG_REQUEST_STATUS msgLongitude(char* longitude) {
    static CAN_MSG_OBJ txMessage;
    static uint8_t TAB[8];                 // declaration de la donnee en static obligatoire
    DoubleToBytes Longitude;

    Longitude.f64 = (double)atof(longitude);
    memcpy(TAB, Longitude.u8, 8);
    
    txMessage.msgId = 37;                  // Identifiant CAN longitude
    txMessage.field.idType = CAN_ID_TYPE;
    txMessage.field.dlc = 8;               // Taille du payload : 8 octets
    txMessage.field.brs = CAN_BRS_MODE;
    txMessage.field.formatType = CAN_FORMAT_TYPE;
    txMessage.data = TAB;

    CAN_TX_MSG_REQUEST_STATUS status = CAN1_Transmit(CAN1_TX_FIFO1, &txMessage);
    return status;
}


CAN_TX_MSG_REQUEST_STATUS msgScreenSwitch(uint8_t screen) {
    static CAN_MSG_OBJ txMessage;
    static uint8_t Screen;                 // declaration de la donnee en static obligatoire

    Screen = screen;
    
    txMessage.msgId = 69;                  // Identifiant CAN changement écran
    txMessage.field.idType = CAN_ID_TYPE;
    txMessage.field.dlc = 1;               // Taille du payload : 1 octet
    txMessage.field.brs = CAN_BRS_MODE;
    txMessage.field.formatType = CAN_FORMAT_TYPE;
    txMessage.data = &Screen;

    CAN_TX_MSG_REQUEST_STATUS status = CAN1_Transmit(CAN1_TX_FIFO1, &txMessage);
    return status;
}