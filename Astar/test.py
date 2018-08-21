# @using numpy library
# 16 x 16 Image

# @ Wall, R channel
# Start = G channel
# Dest = B channel
MAP = '''
################
###########D####
################
################
################
################
################
################
################
##@@@@@#########
######@#########
######@#########
##S###@#########
######@#########
################
################
'''
MAP = MAP.replace('\n', '')
REGULARS = {'Source':'S', 'Destination':'D', 'Map': [' ', '#'], 'Wall':['@']}

import numpy as np
def ReadData(w, h, regulars, MAP):
    IMAGE = np.zeros((3, h, w))
    for y in range(h):
        for x in range(w):
            _block = MAP[y*h+x]
            if _block == regulars['Source']:
                IMAGE[1][y][x] = '1'
            elif _block == regulars['Destination']:
                IMAGE[2][y][x] = '1'
            else:
                for block in regulars['Wall']:
                        if _block == block:
                            IMAGE[0][y][x] = 1
                # for block in MAP
                #     if _block == block
                #         IMAGE[0][y][x] = 0
    return IMAGE
    
IMAGE = ReadData(16, 16, REGULARS, MAP)

import astar
path = astar.GetPath(16, 16, IMAGE)
print path
