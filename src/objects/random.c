#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <psptypes.h>
#include <psprtc.h>
#include "common.h"

int randomT(int min, int max) {
	u64 tick;
	sceRtcGetCurrentTick(&tick);

	return min + ((1103515245 * tick + 12345) % (max - min));
}

void random_str(char *str, int minlen, int maxlen) {
	int len = randomT(minlen, maxlen);

	while(len-- > 0) {
		*str++ = (char)randomT(0x61, 0x7A);
	}

	*str = 0;
}