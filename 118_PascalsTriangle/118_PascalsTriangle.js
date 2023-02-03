function generate(numRows) {
  const output = [ [ 1 ] ];

  for (let i = 1; i < numRows; i++) {
    const currentRow = [];
    const lastRow = output.slice(-1)[0];
    const temp = [0, ...lastRow, 0];
    for (let j = 0; j <= lastRow.length; j++) {
      currentRow.push(temp[j] + temp[j+1]);
    }
    output.push(currentRow);
  }

  return output;
}

console.log(generate(1)); // [[1]]
console.log(generate(5)); // [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]