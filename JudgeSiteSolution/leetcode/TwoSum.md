1. https://leetcode.com/problems/two-sum/
2. c#
3. 풀이  
```
배열안에 있는 정수 2개를 찾아 더하여 정답을 찾아라  
첫번째는 시간복잡도 o(n^2)로 list를 두 번 검색하며 첫번째 찾은 수와 찾은 수를 제외한 나머지 수를 더해가며 정답이 되는 수의 index를 검색하는 방법과  
두번째는 시간복잡도 o(n)으로 hashMap을 만들고 list를 돌면서 현재 값을 table에 넣어가며 정답이 되는 나머지 값이 table에 있는지 찾아가는 방법이 있다.  
hashMap을 쓰면 시간복잡도 1차원정도는 쉽게 줄일 수 있다.. hash를 쓰는 단점도 있지만 장점도 분명함.. 앞으로 자주 생각해봐야할 조건임  
```
4. 코드
```
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> map = new Dictionary<int, int>();
        for(int i = 0; i < nums.Length; i++) {
            int complement = target - nums[i];
            if(map.ContainsKey(complement)) {
                return new int[]{ map[complement], i};
            } else {
                if(map.ContainsKey(nums[i]) == false) {
                    map.Add(nums[i], i);
                }
            }
        }
        throw new System.Exception();
    } 
}
```
