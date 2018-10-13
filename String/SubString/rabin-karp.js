module.exports = (str, pattern) => {
    var mod = 1000000009;
    function hash(str) {
        var hash_p = 0;
        for (var i = 0; i < str.length; i++) {
            hash_p = ((hash_p * 26) + str.charCodeAt(i)) % mod;
        }
        return hash_p;
    }
    var matched_idx = new Array();
    var n = str.length;
    var m = pattern.length;
    var hpattern = hash(pattern);
    var hstr = 0, last = 1;
    for (var i = 0; i < n; i++) {
        if (i >= m) {
            if (hstr == hpattern) {
                matched_idx.push(i - m);
            }
            hstr -= last * str.charCodeAt(i - m);
        } else if (i < (m - 1)) {
            last = (last * 26) % mod;
        }
        hstr = ((hstr * 26) + str.charCodeAt(i)) % mod;
        hstr = (hstr < 0) ? (hstr + mod) : hstr;
    }
    return (matched_idx.length > 0) ? matched_idx : -1;
}