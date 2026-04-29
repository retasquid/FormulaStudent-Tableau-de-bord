#ifndef GPS_H
#define	GPS_H

#include "mcc_generated_files/mcc.h"
#include <string.h>
#include <stdint.h>

#define RX_BUFFER_SIZE 128

static volatile uint8_t GPSRxBuffer[RX_BUFFER_SIZE];
volatile char GPSMessage[RX_BUFFER_SIZE];
static volatile uint8_t GPSRxCnt = 0;
volatile uint8_t GPSRxReady = 0;
char GPSMessage_safe[RX_BUFFER_SIZE];

typedef struct{
    char latitude[16];
    char longitude[16];
    char UTC[16];
    char msgType[8];
    char latDir;
    char lonDir;
    char NMEA_PSMI;
}GPS_Message_t; 

/*
 * @brief reception du message GPS par interruption
 * @param void
 * @return void
 */
void GPSRxISR(void);

/*
 * @brief decoupage des donnees GPGLL et organisation dans une struct
 * @param char* GpsMsgToParse : message recu depuis l'interruption
 * @param GPS_Message_t* GpsMsg : struct contenant les donnees
 * @return void
 */
void GPGLL_Parser(char* GpsMsgToParse, GPS_Message_t* GpsMsg);

/*
 * @brief initialisation du GPS pour obtenir seulement des messages GPGLL
 * @param void
 * @return void
 */
void GPS_init(void);

/*
 * @brief recuperation de la longitude
 * @param GPS_Message_t* GpsMsg : message GPS
 * @return char* : string contenant la longitude
 */
char* GetLongitude(GPS_Message_t* GpsMsg);

/*
 * @brief recuperation de la latitude
 * @param GPS_Message_t* GpsMsg : message GPS
 * @return char* : string contenant la latitude
 */
char* GetLatitude(GPS_Message_t* GpsMsg);

#endif

