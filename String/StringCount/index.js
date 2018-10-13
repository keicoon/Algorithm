function length(str, buffer = 1024) {
    var literal = undefined // '\0'
    var len = -1;
    while (len < buffer && str[++len] != literal);
    return len;
}

function test() {
    console.log(length("abc"));
    console.log(length(""));
    console.log(length("abcd efg"));
}
// test()