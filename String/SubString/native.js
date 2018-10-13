module.exports = (str, pattern) => {
    var matched_idx = new Array();
    var n = str.length;
    var m = pattern.length;
    for (var i = 0; i < n - m + 1; i++) {
        var j = 0;
        for (; j < m; j++) {
            if (str[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            matched_idx.push(i);
        }
    }
    return (matched_idx.length > 0) ? matched_idx : -1;
}