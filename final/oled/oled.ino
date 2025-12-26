#include <Adafruit_I2CDevice.h>
Adafruit_I2CDevice i2c_dev = Adafruit_I2CDevice(0x10);
void setup() {
  while (!Serial) { delay(10); }
  Serial.begin(115200);
  Serial.println("I2C adres taraması > devreyakan.com");
  if (!i2c_dev.begin()) {
    Serial.print("0x Noktasında her hangi bir baglanti mevcut degil");
    Serial.println(i2c_dev.address(), HEX);
    while (1);
  }
  Serial.print("Cihaz bulundu... ");
  Serial.println(i2c_dev.address(), HEX);
}
void loop() {
}
