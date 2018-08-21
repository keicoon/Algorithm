-- MS algorithm for rand()
local bit = require("bit")
seed = 0 -- allocate random seed
print(seed)
function MS()
    seed = 214013 * seed + 253011
    return bit.band(bit.rshift(seed, 16), 32767) -- return bits 16-30
end
return MS 