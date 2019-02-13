1. https://leetcode.com/problems/fibonacci-number/
2. c#
3.
```
D에 fibo 값을 caching하고 재사용하여 O(n)으로 수행함
```
4.
```
public class Solution {
    
    private int[] D = new int[31];
    
    public int Fib(int N) {
        if(N == 0) return D[N] = 0;
        else if(N == 1) return D[N] = 1;
        else return D[N] != 0 ? D[N] : (D[N] = Fib(N - 1) + Fib(N - 2));
    }
}
```
