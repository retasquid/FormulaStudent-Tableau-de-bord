#ifndef LCD_H
#define LCD_H
 
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "mcc_generated_files/mcc.h"

#define LCD_DATA_LAT    LATC        
#define LCD_DATA_TRIS   TRISC

#define LCD_RST_LAT     LATAbits.LATA0
#define LCD_CS_LAT      LATAbits.LATA1
#define LCD_RS_LAT      LATAbits.LATA2   
#define LCD_WR_LAT      LATAbits.LATA3
#define LCD_RD_LAT      LATAbits.LATA4


/*
 * @brief Permet de reinitialiser l'ecran LCD
 * @param void
 * @return void
 */
static void LCD_Reset(void);

/*
 * @brief Permet d'ecrire un octet sur le bus 8 bits
 * @param uint8_t data : octet a envoyer sur le bus de donnees
 * @return void
 */
inline static void LCD_WriteBus(uint8_t data);

/*
 * @brief Permet d'envoyer une commande (RS=0)
 * @param uint8_t cmd : commande a envoyer à l'écran LCD
 * @return void
 */
static void LCD_WriteCommand(uint8_t cmd);

/*
 * @brief Permet d'envoyer une donnee (RS=1)
 * @param uint8_t data : donnee a envoyer a l'écran LCD
 * @return void
 */
static void LCD_WriteData(uint8_t data);


/*
 * @brief Permet d'initialiser l'ecran LCD
 * @param void
 * @return void
 */
void LCD_Init(void);

/*
 * @brief Fonction qui permet d'afficher un pixel (x,y) couleur 16 bits RGB
 * @param uint16_t x : coordonnee horizontale du pixel
 * @param uint16_t y : coordonnee verticale du pixel
 * @param uint16_t color : couleur du pixel en format RGB 16 bits
 * @return void
 */
void LCD_DrawPixel(uint16_t x, uint16_t y, uint16_t color);

/*
 * @brief Fonction qui permet de dessiner un pixel epaissi en affichant un carre de pixels
 * @param uint16_t x : coordonnee horizontale
 * @param uint16_t y : coordonnee verticale
 * @param uint16_t color : couleur du pixel
 * @param uint8_t thickness : taille du carre de pixels
 * @return void
 */
void LCD_DrawPixelThick(uint16_t x, uint16_t y, uint16_t color, uint8_t thickness);

/**
 * @brief Fonction qui permet de remplir tout l'ecran avec une couleur
 * @param uint16_t color : couleur de remplissage de l'ecran
 * @return void
 */
void LCD_FillScreen(uint16_t color);

#endif