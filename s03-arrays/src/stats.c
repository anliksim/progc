#include "stats.h"

typedef struct mark_stats {
    int best;
    int worst;
    int all;
} Mark;

typedef struct count_stats {
    int total;
    int gte_four;
    int mark[6];

} Count;

typedef struct statistics {
    Mark mark;
    Count count;
} Stats;

Stats stats;

void update_best(int mark) {
    if (mark > stats.mark.best) {
        stats.mark.best = mark;
    }
}

void update_worst(int mark) {
    int worst = stats.mark.worst;
    if (worst == 0 || mark < worst) {
        stats.mark.worst = mark;
    }
}

void update_range(int mark) {
    update_best(mark);
    update_worst(mark);
    stats.mark.all += mark;
}

void update_gte_four(int mark) {
    if (mark >= 4) {
        ++stats.count.gte_four;
    }
}

void update_mark_count(int mark) {
    ++stats.count.total;
    ++stats.count.mark[mark - 1];
};

// public API

void reset_stats() {
    Mark new_mark = {0};
    stats.mark = new_mark;
    Count new_count = {0};
    stats.count = new_count;
}

void update_stats(int mark) {
    update_mark_count(mark);
    update_gte_four(mark);
    update_range(mark);
}

int total() {
    return stats.count.total;
}

int low() {
    return stats.mark.worst;
}

int high() {
    return stats.mark.best;
}

double avg() {
    return (double) stats.mark.all / stats.count.total;
}

int qs() {
    return stats.count.gte_four;
}

double qs_percent() {
    return (double) qs() / stats.count.total * 100.0;
};

int count(int mark) {
    return stats.count.mark[mark - 1];
}