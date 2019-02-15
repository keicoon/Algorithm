1. https://leetcode.com/problems/design-hashmap/submissions/
2. c#
3. idead
```
array 초기값을 -1로 설정하고 싶었지만 O(n)의 시간 비용이 든다.
그래서 보간 값을 두어 초기값과 set된 value값을 비교하도록 계산.
```
4. code
```
public class MyHashMap {
    private const int HASH = 1000001;
    private int[] obj = new int[HASH];
    private readonly int I = -1;
    /** Initialize your data structure here. */
    public MyHashMap() {
    }
    
    /** value will always be non-negative. */
    public void Put(int key, int value) {
        obj[key] = value - I;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int Get(int key) {
        return obj[key] + I;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void Remove(int key) {
        obj[key] = 0;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.Put(key,value);
 * int param_2 = obj.Get(key);
 * obj.Remove(key);
 */
```
