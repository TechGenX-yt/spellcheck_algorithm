// javascript version for website integration

function getDistance(search_input, word) {
    const a = search_input.length;
    const b = word.length;
    const addn_wt = 1, del_wt = 1, subs_wt = 1;

    // if search input is incomplete, i.e. a substring of word
    if (word.includes(search_input)) {
        return (b - a) * addn_wt * 0.25;
    }

    // initialization of matrix
    let distanceMatrix = Array.from(Array(a + 1), () => new Array(b + 1).fill(0));

    // storing non-recursive values
    for (let i = 0; i <= a; i++) {
        distanceMatrix[i][0] = i;
    }
    for (let j = 0; j <= b; j++) {
        distanceMatrix[0][j] = j;
    }

    // recursive steps
    for (let i = 1; i <= a; i++) {
        for (let j = 1; j <= b; j++) {
            if (search_input[i - 1] === word[j - 1]) {  // if end characters match up
                distanceMatrix[i][j] = distanceMatrix[i - 1][j - 1];
            } else {
                distanceMatrix[i][j] = Math.min(
                    distanceMatrix[i][j - 1] + addn_wt,
                    distanceMatrix[i - 1][j] + del_wt,
                    distanceMatrix[i - 1][j - 1] + subs_wt
                );
            }
        }
    }

    return distanceMatrix;
}
