
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

#define SAFE_RESET(p, size)     do { if (p != NULL) { memset(p, 0, size); } } while (0)
#define SAFE_FREE(p)            do { if (p != NULL) { free(p), p = NULL; } } while (0)
#define UNUSED(arg)             ((void)(arg))


#endif
