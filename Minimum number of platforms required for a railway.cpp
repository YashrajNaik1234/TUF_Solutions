class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        //your code goes here
        sort(Arrival.begin(),Arrival.end());
        sort(Departure.begin(),Departure.end());
        
        int i(0),j(0);
        int cnt(0),count(0);

        while(i < Arrival.size() and j < Arrival.size()){
            if(Arrival[i] <= Departure[j]){
                i++; cnt++;
            }
            else{
                j++; cnt--;
            }

            count = max(count, cnt);
        }

        return count;
    }
};
