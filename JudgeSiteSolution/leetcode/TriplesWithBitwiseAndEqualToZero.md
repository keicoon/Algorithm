1. https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/
2. c#
3. review
```
O(n^3) time-complexity 에 combination 을 고려해야 함
3개의 수의 조합이므로 표현할 수 있는 조합의 set은
- [ x x x ] : 1개
- [ x y y ] : 3개
- [ x x y ] : 3개
- [ x y z ] : 6개
이 있음
```
4. code
```
public class Solution {
    public int CountTriplets(int[] A) {
        int len = A.Length, count = 0;
        
        for (int i = 0; i < len; i++) {
            if (A[i] == 0){
                count += 1;
            }
            for (int j = i + 1; j < len; j++) {
                if ((A[i] & A[i] & A[j]) == 0) {
                    count += 3;
                }
                if ((A[j] & A[j] & A[i]) == 0) {
                    count += 3;
                }
                for (int k = j + 1; k < len; k++) {
                    if ((A[i] & A[j] & A[k]) == 0) {
                        count += 6;
                    }
                }
            }
        }
        
        return count;
    }
}
```
