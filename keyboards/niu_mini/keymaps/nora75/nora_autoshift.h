/*
NORA75:
This file declare custom function.
*/

#ifndef _NORA_AUTOSHIFT_H_
#define _NORA_AUTOSHIFT_H_

#ifndef AUTO_SHIFT_TIMEOUT
    #define AUTO_SHIFT_TIMEOUT = 200
#endif

void my_autoshift_on(void);
void my_autoshift_flush(void);

#endif
