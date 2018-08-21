import math
# Global Varialbe
lowPt = []

def findLowestPoint(_set):
    lowIdx = 0
    min = _set[0][1]
    for i in range(1, len(_set)):
        if _set[i][1] < _set[lowIdx][1]:
            lowIdx = i
        elif _set[i][1] == _set[lowIdx][1] and _set[i][0] < _set[lowIdx][0]:
            lowIdx = i
    return lowIdx
    
def Theata(m):
    global lowPt
    return math.fabs(math.atan2(m[1] - lowPt[1], m[0] - lowPt[0])*180.0/math.pi)
    
def thetaCompare(a, b):
    return Theata(a) >= Theata(b) and 1 or -1
    
def ccw(a, b, c):
    return (b[1] - a[1]) * (c[0] - a[0]) - (b[0] - a[0]) * (c[1] - a[1])
    
def ComputeHull(input):
    if len(input) < 0:
        return []
        
    lowIdx = findLowestPoint(input)
    input[0], input[lowIdx] = input[lowIdx], input[0]
    
    global lowPt
    lowPt = input[0]

    _set = input[:1] + sorted(input[1:], cmp=thetaCompare)

    convex_hull = []
    for p in _set:
        while len(convex_hull) > 1 and ccw(convex_hull[-2], convex_hull[-1], p) >= 0:
            convex_hull.pop()
        convex_hull.append(p)
        
    return convex_hull