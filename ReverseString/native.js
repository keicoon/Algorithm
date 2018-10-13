module.exports = (str) => {
    // Assume str that is defined const type.
    var mid = parseInt(str.length / 2);
    var odd = (str.length % 2) == 1;
    var reversed_str = odd ? str[mid] : '';
    for (var i = 0, idx = odd ? 1 : 0; i < mid; i++) {
        reversed_str = str[mid + i + idx] + reversed_str + str[mid - i - 1];
    }
    return reversed_str;
}