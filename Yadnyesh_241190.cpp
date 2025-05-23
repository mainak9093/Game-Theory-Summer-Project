#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int answer(vector<int>& nums) {
        int n = nums.size();
        // Count the number of elements that are not in their correct position
        // J is the count when element is not as per Jedi wants
        // D is the count when element is not as per Dark wants
        // B is the count when element is not as per both Jedi and Dark
        // While drawing out, their best strategy is to first make all those cards blue that are misplaced according to only them
        // Then, they can make the remaining cards blue that are misplaced according to both of them
        // when someones own misplaced cards that are red go to 0, then they win only if the other person has more than or equal to the number of red cards misplacecd by  both of them and they are the one to take turn in mmidite next step
        // in all other cases, there is a draw

        int J=0,D=0,B=0,ans=0;
        for(int i=0;i<n;i++){
            if(nums[i] != i+1 && nums[i] != n-i){
                B++;
            }
            else if (nums[i] != i+1){
                J++;
            }
            else if (nums[i] != n-i){
                D++;
            }
        }
    
//  if both of them have no common misplaced red element, win dependes purely on who has more misplaced red elements, while Jedi has advantage as he is the one to start
        if(B==0){
            if(D>=J){
                ans= 1;
            }
            else{
                ans= 2;
            }
        }
        else{
            if(J==D){
                ans=3;
            }
            else{
                if(J<D){
                    D-=J;J=0;
                    if(D>=B){
                        ans=1;
                    }
                    else{
                        ans=3;
                    }
                }
                else{
                   ans=3; //this also includes places like J,D,B=3,2,2
                }

            }
        }
        return ans;

    }

};

int main(){
    int testcases;
    cin>>testcases;
    while(testcases--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }

        Solution sol;

        if(sol.answer(nums)==1){
            cout<<"Win"<<endl;}
        else if(sol.answer(nums)==2){
            cout<<"Lose"<<endl;
        }
        else if(sol.answer(nums)==3){
            cout<<"Tie"<<endl;
        }
    }

}