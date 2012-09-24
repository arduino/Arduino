//
// FraunchPad_Accelerometer.cpp
// Class library C++ code
// ----------------------------------
// Developed with embedxcode
// http://embedxcode.weebly.com
//
// Project FRAM_ACC
//
// Created by Rei Vilo, Sept 22, 2012
// Revised by Robert, Sept 23, 2012
//
// Copyright © Rei Vilo, 2012
// Licence CC = BY NC SA
//
// See FraunchPad_Accelerometer.h and ReadMe.txt for references
//


// Library header
#include "FraunchPad_Accelerometer.h"

// Utilities
int32_t asin_degX100(int32_t x) {
  int32_t sign = 1;
  int32_t angle;
  
  if (x<0) sign = -1;
  
  // input 1 g = 100
  x *= sign * 10; // base 1 g = 1000
  // output 1 degree = 100
  
  if      (x<259) angle = map(x,   0,  259,    0, 1500);
  else if (x<500) angle = map(x, 259,  500, 1500, 3000);
  else if (x<707) angle = map(x, 500,  707, 3000, 4500);
  else if (x<866) angle = map(x, 707,  866, 4500, 6000);
  else if (x<966) angle = map(x, 866,  966, 6000, 7500);
  else            angle = map(x, 966, 1000, 7500, 9000);
  
  return sign * angle;
}

///
/// @brief	Square root with integers only
/// @param	x number, unsigned 32-bit integer
/// @return	square root, unsigned 16-bit integer
/// @see	nightcracker answered Mar 14 '11 at 9:17
/// 	 	http://stackoverflow.com/a/5296669/1190049
///
uint32_t int_sqrt64(uint64_t x) {
  uint64_t hi = x;
  uint64_t lo = 0;
  uint64_t mid = ( hi + lo ) / 2;
  uint64_t mid2 = mid * mid;
  
  while ( (lo < hi-1) && (mid2 != x) ) {
    
    if ( mid2 < x )  lo = mid;
    else             hi = mid;
    
    mid = ( hi + lo ) / 2;
    mid2 = mid * mid;
  }
  
  return (uint16_t)mid;
}


// Code
accelerometer_FR::accelerometer_FR() {
  pinMode(ACC_ENABLE, OUTPUT);
  
  pinMode(ACC_X, INPUT);
  pinMode(ACC_Y, INPUT);
  pinMode(ACC_Z, INPUT);
}

void accelerometer_FR::begin() {
  digitalWrite(ACC_ENABLE, HIGH);
  
  _x = 0;
  _y = 0;
  _z = 0;
  
  _vRef = 3000;
  
  _x0 = _vRef / 2;
  _y0 = _vRef / 2;
  _z0 = _vRef / 2;
}

void accelerometer_FR::get() {
  _x = analogRead(ACC_X);
  _y = analogRead(ACC_Y);
  _z = analogRead(ACC_Z);
  
  _x = (_x * _vRef) / 1024;
  _y = (_y * _vRef) / 1024;
  _z = (_z * _vRef) / 1024;
}

void accelerometer_FR::calibrate() {
  _x0 = 0;
  _y0 = 0;
  _z0 = 0;
  
  for (uint8_t i=0; i<8; i++) {
    get();
    _x0 += _x;
    _y0 += _y;
    _z0 += _z;
    delay(250);
  }
  _x0 /= 8;
  _y0 /= 8;
  _z0 /= 8;
  _z0 -= _vRef / 10; // z0 = +1 g
}

String accelerometer_FR::WhoAmI() {
  return "FraunchPad ADXL335 accelerometer";
}

void accelerometer_FR::gravityX100(int32_t &x, int32_t &y, int32_t &z) {
  x = _x - _x0;
  y = _y - _y0;
  z = _z - _z0;
  
  x = (x * 1000) / _vRef; // 1 g = 100
  y = (y * 1000) / _vRef;
  z = (z * 1000) / _vRef;
}

void accelerometer_FR::degreeX100(int32_t &x, int32_t &y, int32_t &z) {
  x = _x - _x0;
  y = _y - _y0;
  z = _z - _z0;
  
  x = (x * 1000) / _vRef; // 1 g = 100
  y = (y * 1000) / _vRef;
  z = (z * 1000) / _vRef;
  
  int64_t k = (int64_t)(x*x + y*y + z*z);
  k = int_sqrt64(k);
  
  x = (x * 100) / k; // normalisation
  y = (y * 100) / k;
  z = (z * 100) / k;
  
  x = asin_degX100(x); // 90 degrees = 9000
  y = asin_degX100(y);
  z = asin_degX100(z);
}



