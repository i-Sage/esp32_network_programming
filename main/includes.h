#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "lwip/err.h"
#include "lwip/sys.h"



/// @brief NVS (Non-Volatile Storage). This is a key-value storage system
/// in the ESP32's flash memory, similar to a little persistent file system
/// where we can store things like:
/// - Wi-Fi credentials (SSID/password)
/// - Calibration data (e.g., ADC calibration)
/// - App settings (e.g., device name, configs)
/// - BLE bonding info
/// - Custom App data
/// It's stored in flash, so it presists even after power down.
/// **We need to initialise NVS to use the wifi stack**
void init_nvs()
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
}