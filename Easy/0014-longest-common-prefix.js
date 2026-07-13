/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let firstWord = strs[0];

    for (let i = 0; i < firstWord.length; i++) {
        for (let j = 1; j < strs.length; j++) {
            if (firstWord[i] !== strs[j][i]) {
                return firstWord.slice(0, i);
            }
        }
    }
    return firstWord;
    
};