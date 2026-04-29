#include "lcd.h"

// Fonction interne pour reinitialiser l'ecran LCD
static void LCD_Reset(void) {
    LCD_RST_LAT = 0;      // Mettre la broche RESET a 0
    __delay_ms(50);       // Attendre 50 ms
    LCD_RST_LAT = 1;      // Relacher le RESET
    __delay_ms(120);      // Attendre que l'ecran soit pret
}

// Fonction interne pour ecrire un octet sur le bus de donnees
inline static void LCD_WriteBus(uint8_t data) {
    LCD_DATA_LAT = data;  // Placer la valeur sur le bus
    LCD_CS_LAT = 0;       // Activer la puce LCD
    LCD_WR_LAT = 0;       // Activer l'ecriture
    LCD_WR_LAT = 1;       // Fin de l'ecriture
    LCD_CS_LAT = 1;       // Desactiver la puce LCD
}

// Fonction interne pour envoyer une commande LCD
static void LCD_WriteCommand(uint8_t cmd) {
    LCD_RS_LAT = 0;       // RS = 0 pour indiquer une commande
    LCD_WriteBus(cmd);
}

// Fonction interne pour envoyer des donnees LCD
static void LCD_WriteData(uint8_t data) {
    LCD_RS_LAT = 1;       // RS = 1 pour indiquer des donnees
    LCD_WriteBus(data);
}

// Initialisation de l'ecran LCD
void LCD_Init(void) {
    // Configuration des GPIO comme sorties
    LCD_DATA_TRIS = 0x00;
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA2 = 0;
    TRISAbits.TRISA3 = 0;
    TRISAbits.TRISA4 = 0;

    // Initialisation des lignes de controle
    LCD_RS_LAT = 1;
    LCD_WR_LAT = 1;
    LCD_RD_LAT = 1;
    LCD_CS_LAT = 1;
    LCD_RST_LAT = 1;

    LCD_Reset(); // Reset physique de l'ecran

    // Envoi des commandes d'initialisation spécifiques au LCD
    LCD_WriteCommand(0xCF);
    LCD_WriteData(0x00);
    LCD_WriteData(0xAA);
    LCD_WriteData(0xE0);

    LCD_WriteCommand(0xED);
    LCD_WriteData(0x67);
    LCD_WriteData(0x03);
    LCD_WriteData(0x12);
    LCD_WriteData(0x81);

    LCD_WriteCommand(0xE8);
    LCD_WriteData(0x8A);
    LCD_WriteData(0x01);
    LCD_WriteData(0x78);

    LCD_WriteCommand(0xCB);
    LCD_WriteData(0x39);
    LCD_WriteData(0x2C);
    LCD_WriteData(0x00);
    LCD_WriteData(0x34);
    LCD_WriteData(0x02);

    LCD_WriteCommand(0xF7);
    LCD_WriteData(0x20);

    LCD_WriteCommand(0xEA);
    LCD_WriteData(0x00);
    LCD_WriteData(0x00);

    LCD_WriteCommand(0xC0);
    LCD_WriteData(0x23);

    LCD_WriteCommand(0xC1);
    LCD_WriteData(0x11);

    LCD_WriteCommand(0xC5);
    LCD_WriteData(0x43);
    LCD_WriteData(0x4C);

    LCD_WriteCommand(0xC7);
    LCD_WriteData(0xA0);

    LCD_WriteCommand(0x36);
    LCD_WriteData(0x48);

    LCD_WriteCommand(0x3A);
    LCD_WriteData(0x55);

    LCD_WriteCommand(0x11); // Sortie du mode veille
    __delay_ms(120);

    LCD_WriteCommand(0x29); // Activation de l'affichage
    LCD_FillScreen(0x0000); // Remplir l'ecran de noir
}

// Dessin d'un pixel simple sur le LCD
void LCD_DrawPixel(uint16_t x, uint16_t y, uint16_t color) {
    uint8_t xh = x >> 8;
    LCD_WriteCommand(0x2A); // Set column address
    LCD_WriteData(xh);
    LCD_WriteData((uint8_t)x);
    LCD_WriteData(xh);
    LCD_WriteData((uint8_t)x);

    uint8_t yh = y >> 8;
    LCD_WriteCommand(0x2B); // Set page address
    LCD_WriteData(yh);
    LCD_WriteData((uint8_t)y);
    LCD_WriteData(yh);
    LCD_WriteData((uint8_t)y);

    LCD_WriteCommand(0x2C); // Write memory
    LCD_WriteData(color >> 8);
    LCD_WriteData((uint8_t)color);
}

// Dessin d'un pixel avec epaisseur (pour les lignes plus larges)
void LCD_DrawPixelThick(uint16_t x, uint16_t y, uint16_t color, uint8_t thickness) {
    for (uint8_t dx = 0; dx < thickness; dx++)
        for (uint8_t dy = 0; dy < thickness; dy++)
            LCD_DrawPixel(x + dx, y + dy, color);
}

// Remplissage complet de l'ecran avec une couleur
void LCD_FillScreen(uint16_t color) {
    uint16_t x, y;

    // Configuration de la zone ecran (full screen)
    LCD_WriteCommand(0x2A); // Set column address
    LCD_WriteData(0);
    LCD_WriteData(0);
    LCD_WriteData(0);
    LCD_WriteData(239);

    LCD_WriteCommand(0x2B); // Set page address
    LCD_WriteData(0);
    LCD_WriteData(0);
    LCD_WriteData(1);
    LCD_WriteData(63);

    LCD_WriteCommand(0x2C); // Write memory
    uint8_t ColorH = color >> 8;
    uint8_t ColorL = color & 0xFF;

    for (y = 0; y < 320; y++) {
        for (x = 0; x < 240; x++) {
            LCD_WriteData(ColorH);
            LCD_WriteData(ColorL);
        }
    }
}

