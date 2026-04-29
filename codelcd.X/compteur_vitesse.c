#include "compteur_vitesse.h"

// Definition des angles de debut et de fin pour les aiguilles du compteur
#define angle_debut_deg  -130.0f
#define angle_fin_deg    130.0f

// Variables globales pour stocker les angles actuels des aiguilles
float angle_aiguille_deg = 0.0f;
float angle_aiguille_deg2 = 0.0f;

// Calcul de l'increment d'angle par unite pour km/h et tr/min
float angle_delta_deg_kmh = (angle_fin_deg - angle_debut_deg) / VITESSE_MAX_KMH;
float angle_delta_deg_trmin = (angle_fin_deg - angle_debut_deg) / VITESSE_MAX_TRMIN;

// Mise a jour et affichage de l'aiguille du compteur de vitesse (km/h)
void SpeedometerKmh(uint16_t X, uint16_t Y, float vitesse) {
    static uint16_t px2, py2;   // Coordonnees de l'extremite precedente de l'aiguille
    static float angle_rad;

    // Effacement de l'aiguille precedente
    ScreenDrawLine(X, Y, px2, py2, BLACK, 2);

    // Calcul de l'angle de l'aiguille en fonction de la vitesse
    angle_aiguille_deg = angle_debut_deg + (angle_delta_deg_kmh * vitesse);
    angle_rad = angle_aiguille_deg * (M_PI / 180.0f);

    // Calcul des coordonnees de l'extremite de l'aiguille
    px2 = (uint16_t)(X + LONGUEUR_AIGUILLE * cosf(angle_rad));
    py2 = Y + LONGUEUR_AIGUILLE * sinf(angle_rad);

    // Dessin de la nouvelle aiguille
    ScreenDrawLine(X, Y, px2, py2, RED, 2);
}

// Mise a jour et affichage de l'aiguille du compte-tour (tr/min)
void SpeedometerTrmin(uint16_t X, uint16_t Y, float vitesse) {
    static uint16_t px22, py22;  // Coordonnees de l'extremite precedente de l'aiguille
    static float angle_rad2;

    // Effacement de l'aiguille precedente
    ScreenDrawLine(X, Y, px22, py22, BLACK, 2);

    // Calcul de l'angle de l'aiguille en fonction des tr/min
    angle_aiguille_deg2 = angle_debut_deg + (angle_delta_deg_trmin * vitesse);
    angle_rad2 = angle_aiguille_deg2 * (M_PI / 180.0f);

    // Calcul des coordonnees de l'extremite de l'aiguille
    px22 = X + LONGUEUR_AIGUILLE * cosf(angle_rad2);
    py22 = Y + LONGUEUR_AIGUILLE * sinf(angle_rad2);

    // Dessin de la nouvelle aiguille
    ScreenDrawLine(X, Y, px22, py22, RED, 2);
}

// Affichage du voltmetre avec codes couleurs en fonction de la tension
void Voltmeter(uint16_t X, uint16_t Y, float voltage) {
    int16_t thickness = 20;  // Epaisseur des barres du voltmetre

    // Dessin des lignes de fond
    ScreenDrawStraightLineV(X + 31, Y + 5, Y + thickness - 5, WHITE, 4);
    ScreenDrawStraightLineV(X + 27, Y, Y + thickness, WHITE, 4);

    // Dessin des barres de tension selon les niveaux de voltage
    if (voltage >= VBAT_MAX) {
        ScreenDrawStraightLineV(X + 22, Y, Y + thickness, GREEN, 4);
    } else {
        ScreenDrawStraightLineV(X + 22, Y, Y + thickness, BLACK, 4);
    }

    if (voltage >= VBAT_HIGH) {
        ScreenDrawStraightLineV(X + 17, Y, Y + thickness, LGREEN, 4);
    } else {
        ScreenDrawStraightLineV(X + 17, Y, Y + thickness, BLACK, 4);
    }

    if (voltage >= VBAT_MID) {
        ScreenDrawStraightLineV(X + 12, Y, Y + thickness, ORANGE, 4);
    } else {
        ScreenDrawStraightLineV(X + 12, Y, Y + thickness, BLACK, 4);
    }

    if (voltage >= VBAT_LOW) {
        ScreenDrawStraightLineV(X + 7, Y, Y + thickness, RED, 4);
    } else {
        ScreenDrawStraightLineV(X + 7, Y, Y + thickness, BLACK, 4);
    }

    // Dessin de la barre principale du voltmetre
    ScreenDrawStraightLineV(X, Y, Y + thickness - 2, WHITE, 6);
}