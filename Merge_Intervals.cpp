/*
   nothing special, you just need a good sort algorithm
   quick sort, n(log(n)) is a must
   wrote two quick sorts, both cool, long time no see
   I don't know why the STL sort does not work on leetcode, is that supposed to be a sort question?
   I checked anson's code, found another way to support STL sort. another bunos...
 */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <climits>
#include <memory.h>
#include <string.h>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() :
        start(0), end(0) {
        }
    Interval(int s, int e) :
        start(s), end(e) {
        }
};

bool compare(Interval first, Interval second) {
    return first.start < second.start;
}

struct StartIncreasing {
    bool operator()(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }
} start_increasing;

void swap(int i, int j, vector<Interval> &intervals) {
    Interval tmp = intervals[i];
    intervals[i] = intervals[j];
    intervals[j] = tmp;
}

void quick_sort(vector<Interval>& intervals, int left, int right) {
    int i = left + 1, j = right;
    Interval key = intervals[left];

    if (left >= right)
        return;

    /* 从i++和j--两个方向搜索不满足条件的值并交换  *
     * 条件为：i++方向小于key，j--方向大于key      */
    while (1) {
        while (intervals[j].start > key.start)
            j--;
        while (intervals[i].start < key.start && i < j)
            i++;
        if (i >= j)
            break;
        swap(i, j, intervals);
        if (intervals[i].start == key.start)
            j--;
        else
            i++;
    }

    /* 关键数据放到‘中间’ */
    swap(left, j, intervals);

    if (left < i - 1)
        quick_sort(intervals, left, i - 1);
    if (j + 1 < right)
        quick_sort(intervals, j + 1, right);

}

void quickSort(int start, int end, vector<Interval> &intervals) {
    if (end <= start) {
        return;
    }

    Interval key = intervals[start];
    int i = start;
    int j = end;
    while (i < j) {
        while (i < j && intervals[j].start > key.start) {
            j--;
        }
        if (i < j) {
            intervals[i] = intervals[j];
            i++;
        }
        if (i == j)
            break;
        while (i < j && intervals[i].start < key.start) {
            i++;
        }
        if (i < j) {
            intervals[j] = intervals[i];
            j--;
        }
    }
    intervals[i] = key;

    quickSort(start, i - 1, intervals);
    quickSort(i + 1, end, intervals);
}

vector<Interval> merge(vector<Interval> &intervals) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function

    //sort(intervals.begin(), intervals.end(), compare);
    //this does not work, but in eclipse, it's ok
    sort(intervals.begin(), intervals.end(), start_increasing);
    quick_sort(intervals, 0, intervals.size() - 1);
    quickSort(0, intervals.size() - 1, intervals);

    vector<Interval> res;
    for (int i = 0; i < intervals.size(); i++) {
        if (res.empty()) {
            res.push_back(intervals[i]);
        } else {
            int j = res.size() - 1;
            if (intervals[i].start > res[j].end) {
                res.push_back(intervals[i]);
                continue;
            } else {
                if (intervals[i].end <= res[j].end) {
                    continue;
                } else {
                    res[j].end = intervals[i].end;
                }
            }
        }
    }
    return res;
}

int main() {
    vector<Interval> intervals;
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(15, 18));
    intervals.push_back(Interval(1, 4));
    intervals.push_back(Interval(5, 6));
    merge(intervals);
    return 0;
}

