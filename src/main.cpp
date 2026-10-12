#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEAdvertising.h>

// UUID de prueba para SecureEvent
#define SERVICE_UUID "4fa8c85a-1141-45e0-9037-56747515d18e"

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("--- Pulsera SecureEvent (XIAO ESP32-S3) Iniciada ---");

  // Inicializar dispositivo BLE con el nombre de la pulsera
  BLEDevice::init("SE-Pulsera-Karla");

  // Configurar publicidad BLE
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  
  BLEAdvertisementData oAdvertisementData = BLEAdvertisementData();
  oAdvertisementData.setFlags(0x04); // Solo BLE (BR_EDR_NOT_SUPPORTED)
  oAdvertisementData.setCompleteServices(BLEUUID(SERVICE_UUID));
  
  pAdvertising->setAdvertisementData(oAdvertisementData);
  pAdvertising->start();

  Serial.println("Transmitiendo ráfagas BLE activamente...");
}

void loop() {
  // En los siguientes pasos agregaremos el manejo de bajo consumo (Duty Cycling)
  delay(2000);
  Serial.println("Beacon activo...");
}