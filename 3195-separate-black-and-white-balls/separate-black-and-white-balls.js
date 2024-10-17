/**
 * @param {string} s
 * @return {number}
 */
var minimumSteps = function(s) {
    
    let ans=0;
    let black=0;

    for (let i = 0; i < s.length; i++) {
        if (s[i] === '0') ans += black;
        else black++;
    }

    return ans;
};