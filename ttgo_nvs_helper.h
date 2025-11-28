#pragma once
#include "nvs_flash.h"
#include "nvs.h"

float get_nvs_usage() {
    nvs_stats_t nvs_stats;
    esp_err_t err = nvs_get_stats(NULL, &nvs_stats);
    if (err != ESP_OK) {
        return 0.0;
    }
    
    size_t used = nvs_stats.used_entries;
    size_t total = nvs_stats.total_entries;
    
    if (total == 0) {
        return 0.0;
    }
    
    return (float)used / (float)total * 100.0;
}

void do_nvs_erase() {
    esp_err_t err = nvs_flash_erase();
    if (err == ESP_OK) {
        ESP_LOGI("nvs", "NVS sters");
        nvs_flash_init();
    } else {
        ESP_LOGE("nvs", "Eroare NVS: %d", err);
    }
}
