/*
   carm down, i can even modify the args without return.
   checked anson's, one loop...good job!  second is anson's
   if i know there is a return value, i might use anson's solution
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    public:

        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<Interval> res;
            int i = 0;
            while (i < intervals.size() && newInterval.start > intervals[i].end) {

                res.push_back(intervals[i]);
                i++;
            }
            int j = i;
            while (j < intervals.size() && newInterval.end >= intervals[j].start)
                j++;
            j--;
            if (j == i - 1)
                res.push_back(newInterval);
            else {
                Interval tmp;
                tmp.start = min(intervals[i].start, newInterval.start);
                tmp.end = max(intervals[j].end, newInterval.end);
                res.push_back(tmp);
            }
            for (int k = j + 1; k < intervals.size(); k++)
                res.push_back(intervals[k]);

            return res;
        }

        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
            vector<Interval> result;
            bool merge_finished = false;
            for (vector<Interval>::iterator it = intervals.begin(); it != intervals.end(); it++) {
                if ((*it).start <= newInterval.end && newInterval.start <= (*it).end) {
                    newInterval.start = (newInterval.start > (*it).start) ? (*it).start : newInterval.start;
                    newInterval.end = ((newInterval.end < (*it).end) ? (*it).end : newInterval.end);
                    continue;
                }
                if (!merge_finished && (*it).start > newInterval.end) {
                    result.push_back(newInterval);
                    merge_finished = true;
                }
                result.push_back(*it);
            }
            if (!merge_finished) result.push_back(newInterval);
            return result;
        }
};
