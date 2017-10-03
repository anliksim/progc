#ifndef S03_ARRAYS_STATS_H
#define S03_ARRAYS_STATS_H

void reset_stats();

void update_stats(int mark);

int total();

int low();

int high();

double avg();

int qs();

double qs_percent();

int count(int mark);

#endif //S03_ARRAYS_STATS_H
