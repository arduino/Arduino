// Adapted from a post on the Arduino Forums by Gabb:
// http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1289151491

#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdlib.h>

// Minimal class to replace std::vector
template<typename Data>
class Vector {
  size_t d_size; // Stores no. of actually stored objects
  size_t d_capacity; // Stores allocated capacity
  Data *d_data; // Stores data
public:
  // Default constructor
  Vector() : d_size(0), d_capacity(0), d_data(0) {};
  // Copy constuctor
  Vector(Vector const &other) : d_size(other.d_size), d_capacity(other.d_capacity), d_data(0) {
    d_data = (Data *) malloc(d_capacity * sizeof(Data));
    memcpy(d_data, other.d_data, d_size * sizeof(Data));
  };

  // Destructor
  ~Vector() {
    free(d_data);
  };

  // Needed for memory management
  Vector &operator=(Vector const &other) {
    free(d_data);
    d_size = other.d_size;
    d_capacity = other.d_capacity;
    d_data = (Data *) malloc(d_capacity * sizeof(Data));
    memcpy(d_data, other.d_data, d_size * sizeof(Data));
    return *this;
  };

  // Const getter
  Data const &operator[](size_t idx) const {
    return d_data[idx];
  };
  // Changeable getter
  Data &operator[](size_t idx) {
    return d_data[idx];
  };

  // Adds new value. If needed, allocates more space
  void push_back(Data const &x) {
    if (d_capacity == d_size) {
      resize();
    }
    d_data[d_size++] = x;
  };

  // Size getter
  size_t size() const {
    return d_size;
  };

private:
  // Allocates double the old space
  void resize() {
    d_capacity = d_capacity ? d_capacity * 2 : 1;
    Data *newdata = (Data *) malloc(d_capacity * sizeof(Data));
    memcpy(newdata, d_data, d_size * sizeof(Data));
    free(d_data);
    d_data = newdata;
  };
};

#endif
