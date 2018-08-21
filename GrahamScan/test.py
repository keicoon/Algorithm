import grahamscan as gs

# input = [[1,1],[2,2],[3,3],[1,3]]
# input = [[0,0],[10,0],[0,10]]
# input = [[41, -6], [-24, -74], [-51, -6], [73, 17], [-30, -34]]
input = [[732, 590], [415, 360], [276, 276], [229, 544], [299, 95]]
output = gs.ComputeHull(input)

print(input)
print(output)