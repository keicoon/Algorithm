1. https://leetcode.com/problems/3sum/
2. c#
3.
```
3개의 수를 더해서 0이 되는 조합을 모두 찾는 문제,
o(n^3)으로 찾아야되고 중복되는 경우가 없도록 풀어야 한다. 여기서 중요한 부분은
입력받는 배열을 정렬함으로써 o(n^2) 시간에 해결할 수 있다.
```
4. code
```
public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        Array.Sort(nums);
        IList<IList<int>> lists = new List<IList<int>>();
        int size = nums.Length;
        
        for (int i = 0; i < size - 2; i++) {
            if(i > 0 && nums[i - 1] == nums[i]) continue;
                
            int wish = -(nums[i]);
            int left = i + 1;
            int right = size - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if(sum == wish) {
                    lists.Add(new List<int>() { nums[i], nums[left], nums[right] });
                    
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if(sum < wish ) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return lists;
    }
}
```
