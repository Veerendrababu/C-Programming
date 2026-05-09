#include <stdio.h>
#include <string.h>
#inlcude "temp_uart.h"
/* UART Transmit Function */
void uart_send(char *data, void (*callback)(void))
{
    printf("Sending Data: %s\n", data);

    /* Assume transmission completed here */

    /*
        callback contains address of:
        tx_complete_callback()

        callback() means:
        call the function whose address is stored in callback
    */

    callback();
}
