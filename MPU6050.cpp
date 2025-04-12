#include "MPU6050.h"

MPU6050::MPU6050(uint8_t address) {
  _address = address;
}

bool MPU6050::begin() {
  Wire.begin();
  writeRegister(0x6B, 0x00); // Wake up sensor
  return readRegister(0x75) == 0x68; // WHO_AM_I register check
}

void MPU6050::readRawAccel(int16_t &x, int16_t &y, int16_t &z) {
  Wire.beginTransmission(_address);
  Wire.write(0x3B); // ACCEL_XOUT_H
  Wire.endTransmission(false);
  Wire.requestFrom(_address, (uint8_t)6);
  x = (Wire.read() << 8) | Wire.read();
  y = (Wire.read() << 8) | Wire.read();
  z = (Wire.read() << 8) | Wire.read();
}

void MPU6050::readRawGyro(int16_t &x, int16_t &y, int16_t &z) {
  Wire.beginTransmission(_address);
  Wire.write(0x43); // GYRO_XOUT_H
  Wire.endTransmission(false);
  Wire.requestFrom(_address, (uint8_t)6);
  x = (Wire.read() << 8) | Wire.read();
  y = (Wire.read() << 8) | Wire.read();
  z = (Wire.read() << 8) | Wire.read();
}

uint8_t MPU6050::readRegister(uint8_t reg) {
  Wire.beginTransmission(_address);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom(_address, (uint8_t)1);
  return Wire.read();
}

void MPU6050::writeRegister(uint8_t reg, uint8_t data) {
  Wire.beginTransmission(_address);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission();
}
