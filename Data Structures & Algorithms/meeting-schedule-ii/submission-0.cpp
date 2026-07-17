/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
            vector<pair<int,int>> timeline;
        for( auto &interval:intervals){
            timeline.push_back({interval.start,1});
            timeline.push_back({interval.end,-1});
        }
        int count= 0;
        int maxCount=0;
        sort( timeline.begin(), timeline.end());
        for( auto & p:timeline){
            count+= p.second;
            maxCount=  max(maxCount, count);
        }
        return maxCount;
    }
};
