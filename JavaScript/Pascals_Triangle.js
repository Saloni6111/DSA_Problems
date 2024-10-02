// Function to calculate nCr (binomial coefficient)
function nCr(n, r) {
    let res = 1;
    // calculating nCr:
    for (let i = 0; i < r; i++) {
      res = res * (n - i); // Multiply by (n-i) (numerator part)
      res = res / (i + 1); // Divide by (i+1) (denominator part)
    }
    return parseInt(res);
}
  
function pascalTriangle(n) {
    const ans = [];
    //Store the entire pascal's triangle:
    for (let row = 1; row <= n; row++) {
      const tempLst = []; 
      for (let col = 1; col <= row; col++) {
        tempLst.push(nCr(row - 1, col - 1)); // Push the binomial coefficient C(row-1, col-1)
      }
      ans.push(tempLst);
    }
    return ans;
}
  
const n = 5;
const ans = pascalTriangle(n);
for (let i = 0; i < ans.length; i++) {
    console.log(ans[i].join(" "));
}
