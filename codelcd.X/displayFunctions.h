#ifndef DISPLAYFUNCTIONS_H
#define DISPLAYFUNCTIONS_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "lcd_font.h"
#include "lcd.h"
#include <xc.h>  
#include <math.h>
#include "mcc_generated_files/mcc.h"

void (*ptrScreenInit)(void) = &LCD_Init;
void (*ptrScreenDrawPixel)(uint16_t x, uint16_t y, uint16_t color) = &LCD_DrawPixel;
void (*ptrScreenDrawPixelThick)(uint16_t x, uint16_t y, uint16_t color, uint8_t thickness) = &LCD_DrawPixelThick;
void (*ptrScreenFillScreen)(uint16_t color) = &LCD_FillScreen;

/*
 * @brief Fonction qui permet de tracer une ligne epaisse horizontale entre deux points sur l'ecran LCD
 * @param uint16_t x0 : coordonnee x du premier point
 * @param uint16_t y0 : coordonnee y du premier point
 * @param uint16_t x1 : coordonnee x du second point
 * @param uint16_t y1 : coordonnee y du second point
 * @param uint16_t color : couleur de la ligne
 * @param uint8_t thickness : epaisseur de la ligne
 * @return void
 */
void ScreenDrawLineH(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, uint8_t thickness);

/*
 * @brief Trace une ligne verticale epaisse entre deux points sur l'ecran LCD
 * @param uint16_t x0 : coordonnee x du premier point
 * @param uint16_t y0 : coordonnee y du premier point
 * @param uint16_t x1 : coordonnee x du second point
 * @param uint16_t y1 : coordonnee y du second point
 * @param uint16_t color : couleur de la ligne
 * @param uint8_t thickness : epaisseur de la ligne
 * @return void
 */
void ScreenDrawLineV(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, uint8_t thickness);

/*
 * @brief Fonction qui permet de tracer une ligne epaisse entre deux points
 * @param uint16_t x0 : coordonnee x du premier point
 * @param uint16_t y0 : coordonnee y du premier point
 * @param uint16_t x1 : coordonnee x du second point
 * @param uint16_t y1 : coordonnee y du second point
 * @param uint16_t color : couleur de la ligne
 * @param uint8_t thickness : epaisseur de la ligne
 * @return void
 */
void ScreenDrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, uint8_t thickness);

/*
 * @brief Fonction qui permet d'afficher un caractère vertical
 * @param uint16_t x : position horizontale
 * @param uint16_t y : position verticale
 * @param char c : caractere à afficher
 * @param uint16_t color : couleur du texte
 * @param uint16_t bg : couleur du fond
 * @return void
 */
void ScreenDrawCharV(uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bg);

/*
 * @brief Fonction qui permet d'afficher un caractere horizontal
 * @param uint16_t x : position horizontale
 * @param uint16_t y : position verticale
 * @param char c : caractere à afficher
 * @param uint16_t color : couleur du texte
 * @param uint16_t bg : couleur du fond
 * @return void
 */
void ScreenDrawCharH(uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bg);

/*
 * @brief Fonction qui permet d'afficher du texte vertical
 * @param uint16_t x : position horizontale de départ
 * @param uint16_t y : position verticale
 * @param const char* text : chaine de caracteres à afficher
 * @param uint16_t color : couleur du texte
 * @param uint16_t bg : couleur du fond
 * @return void
 */
void ScreenDrawTextV(uint16_t x, uint16_t y, const char* text, uint16_t color, uint16_t bg);


/*
 * @brief Fonction qui permet d'afficher du texte horizontal
 * @param uint16_t x : position horizontale de départ
 * @param uint16_t y : position verticale
 * @param const char* text : chaine de caractères à afficher
 * @param uint16_t color : couleur du texte
 * @param uint16_t bg : couleur du fond
 * @return void
 */
void ScreenDrawTextH(uint16_t x, uint16_t y, const char* text, uint16_t color, uint16_t bg);


/*
 * @brief Fonction qui permet de dessiner un arc de cercle avec des graduations
 * @param uint16_t xc : centre du cercle (x)
 * @param uint16_t yc : centre du cercle (y)
 * @param uint16_t r : rayon du cercle
 * @param int16_t angle_start : angle de départ en degrés
 * @param int16_t angle_end : angle de fin en degrés
 * @param uint16_t color : couleur de l'arc
 * @return void
 */
void ScreenDrawArc(uint16_t xc, uint16_t yc, uint16_t r, int16_t angle_start, int16_t angle_end, uint16_t color);

/*
 * @brief Fonction qui permet de tracer une ligne droite verticale epaisse
 * @param uint16_t x : coordonnee x
 * @param uint16_t y0 : coordonnee y de départ
 * @param uint16_t y1 : coordonnee y de fin
 * @param uint16_t color : couleur de la ligne
 * @param uint8_t thickness : epaisseur de la ligne
 * @return void
 */
void ScreenDrawStraightLineV(uint16_t x, uint16_t y0, uint16_t y1, uint16_t color, uint8_t thickness);

/*
 * @brief Fonction qui permet de tracer une ligne droite horizontale epaisse
 * @param uint16_t x0 : coordonnee x de départ
 * @param uint16_t x1 : coordonnee x de fin
 * @param uint16_t y : coordonnee y
 * @param uint16_t color : couleur de la ligne
 * @param uint8_t thickness : epaisseur de la ligne
 * @return void
 */
void ScreenDrawStraightLineH(uint16_t x0, uint16_t x1, uint16_t y, uint16_t color, uint8_t thickness);

#endif
