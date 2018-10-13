module.exports = (str, pattern) => {
    let n = str.length;
    let m = pattern.length;
    for (let i = 0; i < n - m + 1; i++) {
        let j = 0;
        for (; j < m; j++) {
            if (s[i + j - 1] != pattern[j]) {
                break;
            }
        }
        if (j < m) {
            return i;
        }
    }
    return -1;
}