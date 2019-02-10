1. https://leetcode.com/problems/zigzag-conversion/
2. c#
3. 풀이
```
주어진 문자열을, 주어진 값을 열의 개수로 가지는 문자 배열을 만든 후, 행 단위로 새로운 문자열을 출력하는 문제임
나는 지그재그의 규칙을 찾아서 맨 윗, 아랫 줄을 제외하고는 (row - 1) * 2 크기의 step을 움직이며 문자열 배열을 탐색하였다
이 방법 이외에는 지그재그의 index가 2차원 배열에서 아래로 향하다가 마지막을 찍고 다시 위로 방향이 바뀌는 특징을 사용하여,
upOrDown flag를 두어 문자열을 합치는 솔루션이 있다.
```
4. 코드
```
public class Solution {
    public string Convert(string s, int numRows) {
        int stepSize = (numRows > 1) ? (numRows - 1) * 2 : 1;
        int length = s.Length;
        
        var sb = new System.Text.StringBuilder();
        
        for(int i=0; i<numRows; i++) {
            int step = i;
            if(i == 0 || (i + 1) == numRows) {
                while(step < length) {
                    sb.Append(s[step]);
                    step += stepSize;
                }
            } else {
                while(true) {
                    if(step < length) {
                        sb.Append(s[step]);
                    } else break;
                    
                    step += (stepSize - i*2);
                    if(step < length) {
                        sb.Append(s[step]);
                    } else break;
                    
                    step += i*2;
                }
            }
        }
        
        return sb.ToString();
    }
}
```
