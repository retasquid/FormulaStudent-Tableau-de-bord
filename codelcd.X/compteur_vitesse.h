#include "displayFunctions.h"  
#include <math.h>  

#ifndef COMPTEUR_VITESSE_H
#define COMPTEUR_VITESSE_H

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define LGREEN  0xEFE2
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define ORANGE  0xFD20
#define WHITE   0xFFFF

#define VITESSE_MAX_TRMIN     6000
#define VITESSE_MAX_KMH       250
#define LONGUEUR_AIGUILLE     50

#define VBAT_MAX     14.7f
#define VBAT_HIGH    13.7f
#define VBAT_MID     12.7f
#define VBAT_LOW     12.4f

/*
 * @brief Fonction qui permet de calculer la position de l'aiguille en fonction de la vitesse en km/h et de l'afficher sur le compteur.
 * @param uint16_t X : coordonnee x du centre du compteur
 * @param uint16_t Y : coordonnee y du centre du compteur
 * @param float vitesse : vitesse du vehicule en km/h
 * @return void
 */
void SpeedometerKmh(uint16_t X, uint16_t Y, float vitesse);

/*
 * @brief Fonction qui permet de calculer la position de l'aiguille en fonction du regime moteur (tr/min) et de l'afficher sur le compteur.
 * @param uint16_t X : coordonnee x du centre du compteur
 * @param uint16_t Y : coordonnee y du centre du compteur
 * @param float vitesse : regime moteur en tours par minute (tr/min)
 * @return void
 */
void SpeedometerTrmin(uint16_t X, uint16_t Y, float vitesse);

/*
 * @brief Fonction qui permet d'afficher le niveau de tension batterie sous forme de jauge selon la valeur mesuree.
 * @param uint16_t X : coordonnee x de la jauge de tension
 * @param uint16_t Y : coordonnee y de la jauge de tension
 * @param float voltage : tension batterie mesuree en volts
 * @return void
 */
void Voltmeter(uint16_t X, uint16_t Y, float voltage);

#endif
