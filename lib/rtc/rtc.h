/*
 * Interfacing with the real-time clock
 */

#ifndef _RTC_H_
#define _RTC_H_

class DateTime {
  public:
    int milliseconds;
    int seconds;
    int minutes;
    int hours;
    int day;
    int month;
    int year;
    int dow; // 0 = sunday, to match ctime
};

class RTC {
  public:
    RTC();
    DateTime getTime();
};


#endif
