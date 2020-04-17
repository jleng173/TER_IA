#ifndef __ACTIONS
#define __ACTIONS

/* ascii codes for various special keys */

#include "touches.h"
#include "switch_blend.h"
#include "switch_light.h"
#include <stdlib.h>

void touche_pressee(unsigned char key, int x, int y);
void mouseClicks(int button, int state, int x, int y);
void mouseMove(int x, int y);

#endif
