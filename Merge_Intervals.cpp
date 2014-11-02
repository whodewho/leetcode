/*
  O(N*log(N))
 */

struct StartIncreasing {
    bool operator()(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }
} start_increasing;


vector<Interval> merge(vector<Interval> &intervals) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function

    //sort(intervals.begin(), intervals.end(), compare);
    //this does not work, but in eclipse, it's ok
    sort(intervals.begin(), intervals.end(), start_increasing);

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

