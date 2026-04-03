#ifndef FLIGHTS_H
#define FLIGHTS_H

enum flights {
  FLIGHT_1,
  FLIGHT_2,
  FLIGHT_3,
  FLIGHT_4,
  FLIGHT_5,
  FLIGHT_6,
  FLIGHT_7,
  FLIGHT_8,
  FLIGHT_MAX
};
typedef struct {
  int dep, arr;
} Flight;

#endif
