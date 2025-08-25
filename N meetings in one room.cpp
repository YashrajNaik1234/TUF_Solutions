class Solution{
    public:
    class Meet{
        public:
            int start;
            int end;
            int index;

            Meet(int st, int end, int i){
                this -> start = st;
                this -> end = end;
                this -> index = i;
            }
    };

    class MyObjectComparator{
    public:
        bool operator()(Meet val1, Meet val2) {
            return val1.end < val2.end;
        }
    };
    int maxMeetings(vector<int>& start, vector<int>& end){
        //your code goes here
        vector<Meet> mp;
        for(int i(0);i < start.size();i++){
            mp.push_back(Meet(start[i], end[i], i));
        }

        MyObjectComparator comp;
        sort(mp.begin(),mp.end(), comp);

        int count(1), x1 = mp[0].end;
        for(int i(1);i < start.size() - 1;i++){
            if(mp[i].start > x1){
                x1 = mp[i].end; count++;
            }
        }

        return count;
    }
};
