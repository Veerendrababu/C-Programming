#include<stdio.h>
#include"uart.h"

void user_uart_tx_complete(void){
    printf("UART TX Completed\n");
}

struct UART{
    void (*uart_tx_complete)(void);
};
void main(){
    struct UART uart1;
    
    uart1.uart_tx_complete = user_uart_tx_complete;
    uart_send("Hello 👋 ",uart1.uart_tx_complete);
    
}
