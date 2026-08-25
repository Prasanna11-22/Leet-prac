class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totcost=0,currcost=0,start=0;
  for(int i=0;i<gas.size();i++)
  {
    int t=gas[i]-cost[i];

    totcost+=t;
    currcost+=t;

    if(currcost<0)
    {
        currcost=0;
        start=i+1;
    }
  }


  return (totcost>=0)?start:-1;
    }
};