#ifdef NATIVE

#include <rtc.h>
#include <ctime>

RTC::RTC() {
  // no init required for native
}

DateTime RTC::getTime() {
  time_t t;
  tm tt;
  time(&t);
  tt = *localtime(&t);
  DateTime dt;
  dt.seconds = tt.tm_sec;
  dt.minutes = tt.tm_min;
  dt.hours = tt.tm_hour;
  dt.day = tt.tm_mday;
  dt.month = tt.tm_mon;
  dt.year = tt.tm_year;
  dt.dow = tt.tm_wday;

  return dt;
}

#endif
