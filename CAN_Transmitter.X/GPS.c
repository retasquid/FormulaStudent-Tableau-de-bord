#include "GPS.h"

void GPSRxISR(void){
    char UART_tmp = U1RXB;
    static uint8_t UART_strt_receiving = 0;

    // Debut de trame NMEA
    if(UART_tmp == '$'){
        GPSRxBuffer[0] = '\0';
        GPSRxCnt = 0;
        UART_strt_receiving = 1;
    }
    
    // Reception en cours
    if(UART_strt_receiving == 1){
        GPSRxBuffer[GPSRxCnt] = UART_tmp;
        GPSRxCnt++;

        // Fin de trame NMEA
        if(UART_tmp == '*'){
            GPSRxReady = 1;
            UART_strt_receiving = 0;
            GPSRxBuffer[GPSRxCnt] = '\0';

            // Copie de la trame complete dans le buffer principal
            strncpy((char*)GPSMessage, (const char*)GPSRxBuffer, GPSRxCnt + 1);

        // Protection contre depassement du buffer
        } else if(GPSRxCnt == 127){
            UART_strt_receiving = 0;
            GPSRxBuffer[0] = '\0';
            GPSMessage[0] = '\0';
        }
    }
}

void GPGLL_Parser(char* GpsMsgToParse, GPS_Message_t* GpsMsg){

    // Debug : afficher la trame recue
    printf("\n\r message recu : %s\n\r", GpsMsgToParse);

    int ret = sscanf(GpsMsgToParse,
       "$GPGLL,%15[^,],%c,%15[^,],%c,%15[^,],%c,%*[^*]*",
       GpsMsg->latitude,
       &GpsMsg->latDir,
       GpsMsg->longitude,
       &GpsMsg->lonDir,
       GpsMsg->UTC,
       &GpsMsg->NMEA_PSMI);

    // Debug : resultat du parsing
    printf("sscanf retourne : %d\n\r", ret);

    // Debug : afficher les donnees extraites
    printf("donnees recu : %s; %s\n\r", 
           GpsMsg->latitude, 
           GpsMsg->longitude);
}

void GPS_init(){
    // Desactiver GGA
    puts("$PSRF103,00,00,00,01*25");
    __delay_ms(50);
    // Desactiver GSA
    puts("$PSRF103,02,00,00,01*27");
    __delay_ms(50);
    // Desactiver GSV
    puts("$PSRF103,03,00,00,01*26");
    __delay_ms(50);
    // Desactiver RMC
    puts("$PSRF103,04,00,00,01*21");
    __delay_ms(50);
    // Desactiver VTG
    puts("$PSRF103,05,00,00,01*21");
    __delay_ms(50);
    // Activer GLL
    puts("$PSRF103,01,00,01,01*24");
    __delay_ms(50);
}

char* GetLongitude(GPS_Message_t* GpsMsg) {
    return GpsMsg->longitude;
}

char* GetLatitude(GPS_Message_t* GpsMsg) {
    return GpsMsg->latitude;
}