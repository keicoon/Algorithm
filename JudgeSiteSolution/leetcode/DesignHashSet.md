1. https://leetcode.com/problems/design-hashset/submissions/
2. c#
3. idea
```
bool 타입 array를 생성하여 method를 
```
4.
```
public class MyHashSet {
    private const int SIZE = 1000001;
    private Boolean[] obj = new Boolean[SIZE];
    /** Initialize your data structure here. */
    public MyHashSet() {
        
    }
    
    public void Add(int key) {
        obj[key] = true;
    }
    
    public void Remove(int key) {
        obj[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    public bool Contains(int key) {
        return obj[key];
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.Add(key);
 * obj.Remove(key);
 * bool param_3 = obj.Contains(key);
 */
```
