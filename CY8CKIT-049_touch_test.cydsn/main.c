#include <project.h>
#include <stdlib.h>

#define STR_LENGTH 256
#define TOUCH_NUM CapSenseP4_TOTAL_CSD_SENSORS

void InitUART(void);
void InitCapSense(void);
void UpdateCapSense(void);
void DetectHandPosition(void);

char message[STR_LENGTH];

int main() {
    
    CyGlobalIntEnable;      /* Enable global interrupts */
    
    InitUART();
    InitCapSense();
    while(1) {
        UpdateCapSense();
        DetectHandPosition();
        UART_UartPutString("\r\n");
    }
}

void InitUART(void) {
    UART_Start();
    UART_Enable();
}

void InitCapSense(void) {
    CapSenseP4_Start();
    CapSenseP4_InitializeAllBaselines();
}

void UpdateCapSense(void) {
    while(CapSenseP4_IsBusy() != 0);
    //CapSenseP4_UpdateAllBaselines();
    CapSenseP4_ProcessAllWidgets();
    CapSenseP4_ScanAllWidgets();
}

void DetectHandPosition(void) {
    int touch_bool[TOUCH_NUM];
    int i;
    for(i = 0; i < TOUCH_NUM; i++) {
        touch_bool[i] = (CapSenseP4_IsSensorActive(0, i) >> i);
        itoa(touch_bool[i], message, 10);
        UART_UartPutString(message);
    }
}