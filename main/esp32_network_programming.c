/// To setup a socket for inter-application communications, we first need
/// to connect to a network. So thats the task for today, get the esp32 
/// connected to my Wi-Fi network.


#include "includes.h"
#include "wifi_sta.h"
#include "socket.h"
#include "gpio_control.h"


void app_main(void)
{
    // Initialize NVS (required for WiFi)
    init_nvs();
    
    // GPIO D2 Examples - Choose one or combine as needed:
    
    // Example 1: Basic output control
    ESP_LOGI("MAIN", "=== GPIO D2 Output Example ===");
    gpio_d2_init(GPIO_MODE_OUTPUT_ONLY);
    
    // Set pin HIGH
    gpio_d2_set_level(1);
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // Wait 1 second
    
    // Set pin LOW
    gpio_d2_set_level(0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // Wait 1 second
    
    // Blink the LED/pin 5 times with 500ms intervals
    gpio_d2_blink(5, 500);
    
    // Example 2: Input reading (uncomment to use)
    /*
    ESP_LOGI("MAIN", "=== GPIO D2 Input Example ===");
    gpio_d2_init(GPIO_MODE_INPUT_PULLUP);  // or GPIO_MODE_INPUT_PULLDOWN
    
    for (int i = 0; i < 10; i++) {
        int level = gpio_d2_get_level();
        ESP_LOGI("MAIN", "Reading %d: GPIO D2 = %d", i+1, level);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    */
    
    // Example 3: Toggle functionality
    ESP_LOGI("MAIN", "=== GPIO D2 Toggle Example ===");
    gpio_d2_init(GPIO_MODE_OUTPUT_ONLY);
    
    for (int i = 0; i < 6; i++) {
        gpio_d2_toggle();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
    ESP_LOGI("MAIN", "GPIO D2 examples completed!");
    
    // Your original code (commented out)
    /*
    wifi_init_sta();
    send_msg();
    */
}