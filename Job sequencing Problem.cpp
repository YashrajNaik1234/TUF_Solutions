class Solution{  
  public:  
    class Job{
    public:
        int id;
        int deadline;
        int profit;

        Job(int x, int y, int z){
            this->id = x;
            this->deadline = y;
            this->profit = z;
        }
    };

    class MyObjectComparator{
    public:
        bool operator()(Job val1, Job val2) {
            return val1.profit > val2.profit;
        }
    };

    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        //your code goes here
      vector<Job> st;
      for(auto i:Jobs){
        st.push_back(Job(i[0], i[1], i[2]));
      }

      MyObjectComparator comp;
      sort(st.begin(), st.end(), comp);
      int sum(0),cnt(0),maxDeadline(-1);

      for(int i(0);i < Jobs.size() - 1;i++){
        maxDeadline = max(maxDeadline, st[i].deadline);
      }

      vi hash(maxDeadline + 1, -1);
      for(int i(0);i < Jobs.size();i++){
        for(int j(st[i].deadline); j > 0;j--){
          if(hash[j] == -1){
            cnt++; hash[j] = st[i].id; sum += st[i].profit; break;
          }
        }
      }
      
      for(int i(0);i < maxDeadline;i++) cout << hash[i] << " ";
      return {cnt, sum};
    } 
};
