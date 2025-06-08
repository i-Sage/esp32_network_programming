/// To setup a socket for inter-application communications, we first need
/// to connect to a network. So thats the task for today, get the esp32 
/// connected to my Wi-Fi network.


#include "includes.h"
#include "wifi_sta.h"


void app_main(void)
{
    init_nvs();
    wifi_init_sta();
}