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

static Stats stats = {{0},
                      {0}};

static void update_best(const int mark)
{
    if (mark > stats.mark.best) {
        stats.mark.best = mark;
    }
}

static void update_worst(const int mark)
{
    int worst = stats.mark.worst;
    if (worst == 0 || mark < worst) {
        stats.mark.worst = mark;
    }
}

static void update_range(const int mark)
{
    update_best(mark);
    update_worst(mark);
    stats.mark.all += mark;
}

static void update_gte_four(const int mark)
{
    if (mark >= 4) {
        ++stats.count.gte_four;
    }
}

static void update_mark_count(const int mark)
{
    ++stats.count.total;
    ++stats.count.mark[mark - 1];
};

// public API

void reset_stats()
{
    stats.mark = (Mark) {0};
    stats.count = (Count) {0};
}

void update_stats(const int mark)
{
    update_mark_count(mark);
    update_gte_four(mark);
    update_range(mark);
}

int total()
{
    return stats.count.total;
}

int low()
{
    return stats.mark.worst;
}

int high()
{
    return stats.mark.best;
}

double avg()
{
    return (double) stats.mark.all / stats.count.total;
}

int qs()
{
    return stats.count.gte_four;
}

double qs_percent()
{
    return (double) qs() / stats.count.total * 100.0;
};

int count(const int mark)
{
    return stats.count.mark[mark - 1];
}