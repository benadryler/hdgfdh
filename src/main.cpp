#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE
#include "esp_log.h"

#include <Arduino.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "bluetooth_service.h"

#include "muse.h"
#include "lovense.h"

static const char* TAG = "main";

void setup() {
  Serial.begin(115200);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }

  Serial.println("program started");
  Serial.println();
  Serial.println();
  Serial.println(F("RS485 RTU SDM120***"));

  bluetooth_service_init();

  lovense_init();
  muse_init();
  muse_start();

  bluetooth_service_start();

  ESP_LOGI(TAG, "SETUP DONE.");
}

void loop() {
  // In this example, the main loop is not used since the lovense sensor task runs independently.
  // You can add other tasks or functionality here if needed.
}
