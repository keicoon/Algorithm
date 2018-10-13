module.exports = (str, pattern) => {
    function kmp(pattern, m) {
        var i = 1, j = 0;
        var pi = [0];
        while (i < m) {
            if (pattern[i] == pattern[j]) {
                pi[i++] = ++j;
            } else if (j == 0) {
                pi[i++] = j;
            } else {
                j = pi[j - 1];
            }
        }
        return pi;
    }
    var matched_idx = new Array();
    var n = str.length;
    var m = pattern.length;
    var pi = kmp(pattern, m);
    var i = 0, j = 0;
    while (i < n) {
        if (str[i] == pattern[j]) {
            i++;
            j++;
        } else if (str[i] != pattern[j]) {
            if (j == 0) {
                i++;
            } else {
                j = pi[j - 1];
            }
        }
        if (j == m) {
            matched_idx.push(i - m);
            j = pi[j - 1];
        }
    }
    return (matched_idx.length > 0) ? matched_idx : -1;
}