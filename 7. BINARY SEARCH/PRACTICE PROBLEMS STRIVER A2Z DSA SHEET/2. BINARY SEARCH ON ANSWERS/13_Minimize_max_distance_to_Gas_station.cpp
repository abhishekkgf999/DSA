/*

#MINIMIZE MAX DISTANCE TO GAS STATION (Mark for revision)

LINK:- https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1
*/

#include<bits/stdc++.h>
using namespace std;

//BRUTE FORCE SOLUTION (TC:- O(k*n) + O(n) & SC:- O(n-1))
double findSmallestMaxDist_LinearSearch(vector<int> &stations, int k) {
        int n = stations.size();
        vector<int> gasStations(n-1,0);
        for(int i = 1; i<=k; i++){
            long double maxVal = -1; 
            int maxInd = -1;
            for(int j = 0; j<n-1; j++){
                long double diff = stations[j+1]-stations[j];
                long double section_len = diff/(long double)(gasStations[j] +1);
                if(maxVal < section_len){
                    maxVal = section_len;
                    maxInd = j;
                }
            }
            gasStations[maxInd]++;
        }
        
        long double maxAns = -1;
        for(int i = 0; i<n-1; i++){
            long double diff = stations[i+1]-stations[i];
            long double section_len = diff/(long double)(gasStations[i] + 1);
            maxAns = max(maxAns, section_len);
        }
        return maxAns;
    }


//BETTER SOLUTION (TC:- O(nlogn + klogn) & SC:- O(n-1) + O(n-1))
double findSmallestMaxDist_UsingMaxHeap(vector<int> &stations, int k) {
        int n = stations.size();
        vector<int>  howMany(n-1, 0);
        priority_queue<pair<long double, int>> pq;
        for(int i =0; i<n-1; i++){
            pq.push({stations[i+1]-stations[i] ,i});
        }

        for(int i = 1; i<=k; i++){
            auto tp = pq.top(); 
            pq.pop();
            int secInd = tp.second;
            howMany[secInd]++;
            long double iniDiff = stations[secInd+1]-stations[secInd];
            long double newSecLen = iniDiff/(long double)(howMany[secInd]+1);
            pq.push({newSecLen, secInd});
        }

        return pq.top().first;
    }

//OPTIMAL SOLUTION-1 (TC:-  O(n*log(Len)) + O(n) & SC:- O(1))

int numberOfGasStationRequired(long double dist, vector<int> &arr){
    int cnt = 0;
    for(int i = 1; i<arr.size(); i++){
        int numberInBetween = ((arr[i] - arr[i-1]) / dist);
        if((arr[i]- arr[i-1]) == (numberInBetween*dist)){
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}
double findSmallestMaxDist_BinarySearch(vector<int> &stations, int k) {
    int n = stations.size();
    long double low = 0;
    long double high = 0;
    for(int i = 0; i<n-1; i++){
        high = max(high, (long double)(stations[i+1] - stations[i]));
    }

    long double diff = 0.001;
    while(high-low > diff){
        long double mid = low + (high-low)/2;
        int cnt = numberOfGasStationRequired(mid, stations);
        if(cnt > k) low = mid;
        else high = mid;
    }
    return round(high * 100.0) / 100.0;
}

//OPTIMAL SOLUTION-2 (MORE EASY SOLUTION  TC:- nlog(x))
bool check(vector<int> &stations,  int k, double mid){
    int count = 0;

    for(int i = 1; i<stations.size(); i++){
        int diff = stations[i]-stations[i-1];

        if(diff>mid){
            count += diff/mid;
        }
    }

    if(count > k) return false;

    return true;
}

double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        double low = 0;
        double high = stations[n-1]-stations[0];

        double ans = 0;
        while(low <= high){
            double mid = low + (high-low)/2;

            if(check(stations, k, mid)){
                ans = mid;
                high = mid-0.000001;
            }
            else low = mid+0.000001;
        }

        return ans;
    }

int main(){
    vector<int> stations = {3,6,12,19,33,44,67,72,89};
    int k = 2;
    // double ans = findSmallestMaxDist_LinearSearch(stations, k);
    // double ans = findSmallestMaxDist_UsingMaxHeap(stations, k);
    double ans = findSmallestMaxDist_BinarySearch(stations, k);
    cout<<ans;
    return 0;
}