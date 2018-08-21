# @ Wall, R channel
# Start = G channel
# Dest = B channel

# Output 1x1
def node(G, P1, P2):
    return {'G':G, 'self':P1, 'parent':P2}
def FIND(list, node):
    for n in list:
        if n['self'] == node:
            return n
    return None
import math
def MANHATAN(P1, P2):
    return (math.fabs(P1[0]-P2[0])+math.fabs(P1[1]-P2[1]))*10
def FindSimbol(w, h, c):
    for y in range(h):
        for x in range(w):
            if C[y][x] >= 255:
                return [y, x]
def STEP(w, h, C, openlist, closelist, current_P, neighbor_P, G):
    if neighbor_P[0] >= h or neighbor_P[0] < 0 or neighbor_P[1] >= w or neighbor_P[1] < 0:
        return openlist
    if C[neighbor_P[0][neighbor_P[1]] < 255 and (FIND(closelist, neighbor_P) is None):
        oepn_node = FIND(openlist, neighbor_P)
        if (not open_node is None) and open_node['G'] > G:
            open_node['G'] = G
            open_node['parent'] = current_P
        else:
            openlist.append(node(G, neighbor_P, current_P))
    return openlist
import sys
def GetPath(w, h, Image):
    src = FindSimbol(w, h, Image[1])
    des = FindSimbol(w, h, Image[2])
    
    openlist = [node(0, src, src)]
    closelist = []
    while True:
        lowestF = sys.maxint
        for on in openlist:
            H = MANHATAN(des, on['self'])
            F = on['G'] + H
            if lowestF > F:
                lowestF = F
                current_node = on
        openlist.remove(current_node)
        
        tp = current_node['self']
        G = current_node['G']
        if tp == des:
            break
        
        openlist = STEP(w, h, Image[0], openlist, closelist, tp, [tp[0]-1, tp[1]-1], G+14)
        openlist = STEP(w, h, Image[0], openlist, closelist, tp, [tp[0]-1, tp[1]], G+10)
        openlist = STEP(w, h, Image[0], openlist, closelist, tp, [tp[0]-1, tp[1]+1], G+14)
        openlist = STEP(w, h, Image[0], openlist, closelist, tp, [tp[0], tp[1]-1], G+10)
        openlist = STEP(w, h, Image[0], openlist, closelist, tp, [tp[0], tp[1]-1], G+10)
        openlist = STEP(w, h, Image[0], openlist, closelist, tp, [tp[0]+1, tp[1]-1], G+14)
        openlist = STEP(w, h, Image[0], openlist, closelist, tp, [tp[0]+1, tp[1]], G+10)
        openlist = STEP(w, h, Image[0], openlist, closelist, tp, [tp[0]+1, tp[1]-1], G+14)
        
        closelist.append(current_node)
    
    reverse_P = current_node['parrent']
    path = [current_node['self]]
    while reverse_P != src:
        path.insert(0, reverse_P)
        close_node = FIND(closelist, reverse_P)
        reverse_P = close_node['parent']
    return path
