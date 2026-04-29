#include "displayFunctions.h"

#define DEG2RAD 0.0174532925f  // Conversion degres -> radians

// Dessin d'une ligne horizontale avec epaisseur
void ScreenDrawLineH(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, uint8_t thickness) {
    // Si x0 > x1, inversion des points pour simplifier le dessin
    if (x0 > x1) {
        x0 = x0 ^ x1;
        x1 = x0 ^ x1;
        x0 = x0 ^ x1;
        y0 = y0 ^ y1;
        y1 = y0 ^ y1;
        y0 = y0 ^ y1;
    }

    int16_t dx = (int16_t)(x1 - x0);
    int16_t dy = (int16_t)(y1 - y0);
    int16_t dir = (dy < 0) ? -1 : 1;

    if (dy < 0) dy = -dy;

    if (dx != 0) {
        int16_t y = (int16_t)y0;
        int16_t p = (int16_t)((dy << 1) - dx);
        for (uint16_t i = 0; i <= dx; i++) {
            ptrScreenDrawPixelThick(x0 + i, y, color, thickness);

            if (p >= 0) {
                y += dir;
                p = p - (dx << 1);
            }
            p = p + (dy << 1);
        }
    }
}

// Dessin d'une ligne verticale avec epaisseur
void ScreenDrawLineV(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, uint8_t thickness) {
    // Si y0 > y1, inversion des points pour simplifier le dessin
    if (y0 > y1) {
        x0 = x0 ^ x1;
        x1 = x0 ^ x1;
        x0 = x0 ^ x1;
        y0 = y0 ^ y1;
        y1 = y0 ^ y1;
        y0 = y0 ^ y1;
    }

    int16_t dx = x1 - x0;
    int16_t dy = y1 - y0;
    int16_t dir = (dx < 0) ? -1 : 1;

    if (dx < 0) dx = -dx;

    if (dy != 0) {
        int16_t p = (dy << 1) - dx;
        int16_t x = x0;
        for (uint16_t i = 0; i <= dy; i++) {
            ptrScreenDrawPixelThick(x, y0 + i, color, thickness);

            if (p >= 0) {
                x += dir;
                p = p - (dy << 1);
            }
            p = p + (dx << 1);
        }
    }
}

// Dessin d'une ligne quelconque en appelant ligne horizontale ou verticale
void ScreenDrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, uint8_t thickness) {
    int16_t dx = x0 - x1; dx = dx > 0 ? dx : -dx;
    int16_t dy = y0 - y1; dy = dy > 0 ? dy : -dy;

    if (dx > dy) {
        ScreenDrawLineH(x0, y0, x1, y1, color, thickness);
    } else {
        ScreenDrawLineV(x0, y0, x1, y1, color, thickness);
    }
}

// Dessin d'un caractere vertical a l'ecran
void ScreenDrawCharV(uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bg) {
    if (c < 32 || c > 126) return; // caracteres non imprimables ignores

    const uint16_t* bitmap = &Font10x21[c - 32];

    for (uint8_t col = 0; col < 10; col++) {
        uint16_t line = bitmap[col];
        for (uint8_t row = 0; row < 14; row++) {
            if (line & (1 << row))
                ptrScreenDrawPixel(x + col, y + row, color);
            else if (bg != color)
                ptrScreenDrawPixel(x + col, y + row, bg);
        }
    }

    // Effacement de la colonne de separation
    for (uint8_t r = 0; r < 14; r++)
        ptrScreenDrawPixel(x + 10, y + r, bg);
}

// Dessin d'un caractere horizontal a l'ecran (rotation 90 degres)
void ScreenDrawCharH(uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bg) {
    if (c < 32 || c > 126) return;

    const uint16_t* bitmap = Font10x21[c - 32];

    for (uint16_t row = 0; row < HEIGHT; row++) {
        uint16_t line = bitmap[row];
        for (uint16_t col = 0; col < LENGHT; col++) {
            if (line & (1 << (LENGHT - 1 - col)))
                ptrScreenDrawPixel(239 - y - row, x + col, color);
            else if (bg != color)
                ptrScreenDrawPixel(239 - y - row, x + col, bg);
        }
    }

    for (uint16_t r = 0; r < HEIGHT; r++) {
        ptrScreenDrawPixel(239 - y - r, x + 10, bg);
    }
}

// Affichage d'une chaine de caracteres verticalement
void ScreenDrawTextV(uint16_t x, uint16_t y, const char* text, uint16_t color, uint16_t bg) {
    while (*text) {
        ScreenDrawCharV(x, y, *text, color, bg);
        x += 12; // decalage horizontal pour le caractere suivant
        text++;
    }
}

// Affichage d'une chaine de caracteres horizontalement
void ScreenDrawTextH(uint16_t x, uint16_t y, const char* text, uint16_t color, uint16_t bg) {
    while (*text) {
        ScreenDrawCharH(x, y, *text, color, bg);
        x += 11; // decalage horizontal pour le caractere suivant
        text++;
    }
}

// Dessin d'un arc circulaire avec graduation tous les 20 degres
void ScreenDrawArc(uint16_t xc, uint16_t yc, uint16_t r, int16_t angle_start, int16_t angle_end, uint16_t color) {
    int16_t angle;
    float rad;
    int16_t x, y;

    // inversion si angle_end < angle_start
    if (angle_end < angle_start) {
        int16_t tmp = angle_start;
        angle_start = angle_end;
        angle_end = tmp;
    }

    for (angle = angle_start; angle <= angle_end; angle++) {
        rad = angle * DEG2RAD;
        x = xc + (int16_t)(r * cos(rad));
        y = yc + (int16_t)(r * sin(rad));

        ptrScreenDrawPixelThick(x, y, color, 2);

        // Dessin des graduations tous les 20 degres
        if ((angle - angle_start) % 20 == 0) {
            int16_t x1 = xc + (int16_t)((r - 6) * cos(rad));
            int16_t y1 = yc + (int16_t)((r - 6) * sin(rad));
            int16_t x2 = xc + (int16_t)(r * cos(rad));
            int16_t y2 = yc + (int16_t)(r * sin(rad));
            ScreenDrawLine(x1, y1, x2, y2, color, 2);
        }
    }
}

// Dessin d'une ligne verticale droite
void ScreenDrawStraightLineV(uint16_t x, uint16_t y0, uint16_t y1, uint16_t color, uint8_t thickness) {
    int16_t dy = y0 - y1; dy = dy > 0 ? dy : -dy;
    while (dy) {
        ptrScreenDrawPixelThick(y0 + dy, x, color, thickness);
        dy--;
    }
}

// Dessin d'une ligne horizontale droite
void ScreenDrawStraightLineH(uint16_t x0, uint16_t x1, uint16_t y, uint16_t color, uint8_t thickness) {
    int16_t dx = x0 - x1; dx = dx > 0 ? dx : -dx;
    while (dx) {
        ptrScreenDrawPixelThick(y, x0 + dx, color, thickness);
        dx--;
    }
}

