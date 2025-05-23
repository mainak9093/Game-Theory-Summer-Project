#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vll vector<long long>
#define vc vector<char>
#define pb push_back
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define vb vector<bool> 

// NEELATMAJAM DWIVEDI 240687
signed main() {
	fast
	int t; // no. of test cases
	cin >> t; 
	while(t--){
	    int n; // length of array
	    cin >>n;
	    vll v1; // vector to store array
	    for(int i=0;i<n;i++){
	        int a;
	        cin >> a;
	        v1.pb(a);
	    }
	    
	    int p=0;// no. of places which are in favour of Aria
	    int q=0;// no. of places which are in favour of Darrus
	    for(int i=0;i<n;i++){
	        if(i - v1[i] + 1==0){
	            p++;
	        }
	        else if(n-i-v1[i]==0){
	            q++;
	        }
	    }
	    
	    // LOGIC:
	    /*
	   Optimal Strategy would be firstly marking blue the places which are of your opponents favour , If there are none such places then mark the places which are not in your favour.
	    
	   for even n:
	   Winning Strategy since Aria has first turn so if p>=n/2 Aria will have to mark only n/2 or less ,lets see with an example
	   lets suppose  1 2 3 6 5 4 is the array or 1 2 3 are in favour of Aria and no number are in favour of Darrus 
	   first turn - Aria will mark blue any one number from 6 5 4 , lets say 4 
	   second turn - Darrus will mark blue any one number from 1 2 3 , lets say 1
	   third turn - Aria will mark 5
	   fourth turn - D marks 2
	   fifth turn -  A marks 6
	   no matter what does darrus do in his turn Aria will win in the next turn
	   
	   Same goes For darrus but in his case q > n/2 because Aria has the first turn benefit 
	   
	   if both of above cases do not satisfy the match will always TIE because both of them will not choose to fill the last element.
	   
	   for odd n:
	   both p and q will need to be larger than n/2 to win , If less than this there will remain a last element to convert which both of them will not as they are playing strategically ..
	   lets understand with an example: lets take array 1 2 5 4 3 
	   p =2 and q=0 so,first turn- A will  choose 3 
	   second turn- D will choose 1 
	   3rd turn - A will choose 4 
	   4th turn - D will choose 2
	   now 1 element remaining (5) and both of them will pass because if one of them chooses 5 other will rearrange the array and make it sorted.
	    
	    
	    
	    */
    	    if(n%2==0){
	       if(p>=n/2){
	        cout << "First" << endl;
	       }
	       else if(q>n/2){
	           cout << "Second" << endl;
	       } 
	        else {
	            cout << "Tie" << endl;
	        }
	    }
	    else{
	        if(p>=(n/2)+1){
	            cout << "First" << endl;
	        }
	        else if(q >=(n/2)+1){
	            cout << "Second" << endl;
	        }
	        else{
	            cout << "Tie" << endl;
	        }
	    }
	}

}
//Passed all test cases
//Code well commented
//Well done :D
