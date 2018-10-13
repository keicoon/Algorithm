var reverse = module.exports = (str) => {
    return str ? reverse(str.substr(1)) + str[0] : str;
}