#ifndef MPU6050_H
#define MPU6050_H

#include <Wire.h>

class MPU6050 {
  public:
    MPU6050(uint8_t address = 0x68);
    bool begin();
    void readRawAccel(int16_t &x, int16_t &y, int16_t &z);
    void readRawGyro(int16_t &x, int16_t &y, int16_t &z);

  private:
    uint8_t _address;
    uint8_t readRegister(uint8_t reg);
    void writeRegister(uint8_t reg, uint8_t data);
};

#endif
