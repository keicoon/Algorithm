
/* function SubString(str, pattern) => interger array
 *
 * If can't find substring, it will return '-1'.
 * Normally, It will return first index of substring.
 */

const Native_string_search = require('./native');
const RabinKarp_string_search = require('./rabin-karp');
const KMP_string_search = require('./knuth-morris-pratt');

function test() {
    // let test_item = ["ABCDABCDABEE", "AB"];
    let test_item = ["ABC ABCDAB ABCDABCDABDE", "ABCDABD"];

    console.log(Native_string_search(test_item[0], test_item[1]))
    console.log(RabinKarp_string_search(test_item[0], test_item[1]))
    console.log(KMP_string_search(test_item[0], test_item[1]))
}

test();