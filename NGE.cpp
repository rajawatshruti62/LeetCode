// Print the Next Greater Element(NGE) for every element.
// The Next Greater Element for an element 'x' is the first element on the right side of 'x' in the array, which is greater than 'x'.
// If no greater elements exist to the right of 'x', consider the next greater element as -1.
#include<stack>
vector<int> nextGreaterElement(vector<int>& nums, int n)
{
  //using iterative approach
	// vector<int>ans(n,-1);
	// for(int i=0;i<n;i++){
	// 	for(int j=i+1;j<n;j++){
	// 		if(nums[j]>nums[i]){
	// 		ans[i]=nums[j];break;}
	// 	}
	// }
	// return ans;

	//using stack
	vector<int>ans(n,-1);
	stack<int>s;
	for(int i=n-1;i>=0;i--){
		while(!s.empty() && s.top()<=nums[i]){
			s.pop();
		}
		if(!s.empty()){
			ans[i]=s.top();
		}
		s.push(nums[i]);
	}
	return ans;
}
