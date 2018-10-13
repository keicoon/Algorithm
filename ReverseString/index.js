
/* function ReverseString(str) => reversed string
 */

const native_reverse_string = require('./native');
const node_style_reverse_string = require('./node-style');

function test() {
    var test = 'abcdef'
    console.log(test)
    console.log(native_reverse_string(test))
    console.log(node_style_reverse_string(test))
}

test();