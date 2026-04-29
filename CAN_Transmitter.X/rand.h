#ifndef RAND_H
#define	RAND_H

#include "mcc_generated_files/mcc.h"

/*
 * @brief Initialise la generation aleatoire avec la seed
 * @param uint16_t seed : seed pour generer la suite aleatoire
 * @return void
 */
void srand16(uint16_t seed);

/*
 * @brief Genere un nombre 16 bit non signe dans l'intervale [min; max[
 * @param uint16_t min : valeur minimum inclue
 * @param uint16_t max : valeur maximum exclue
 * @return uint16_t : valeur aleatoire entre min et max
 */
uint16_t rand16(uint16_t min, uint16_t max);

#endif

