
/**
 * Fichier : common.h
 * Description : Header commun
 * Auteur : Léo Gouttefarde
 * Date : 23/04/2015
 */

#ifndef COMMON
#define COMMON

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <time.h>

#define SAFE_FREE(p)    do { if (p != NULL) { free(p), p = NULL; } } while (0)
#define SIZE(n)         (sizeof(n) / sizeof(n[0]))


#endif
