function areDisjoint(A, B) {
    for (let i = 0; i < A.length; i++) {
      for (let j = 0; j < B.length; j++) {
          if (A[i] === B[j]) {
            console.log(`${A[i]} == ${B[j]}`);
          return false;
        }
      }
    }
    return true;
  }
  
  // Contoh penggunaan
  const A1 = [1, 3, 5, 7, 9];
  const B1 = [2, 4, 6, 8, 10];
  
  if (areDisjoint(A1, B1)) {
    console.log("List A1 dan B1 adalah disjoint set.");
  } else {
    console.log("List A1 dan B1 bukan disjoint set.");
  }
  
  const A2 = [1, 15, 6, 8, 13];
  const B2 = [2, 4, 6, 8, 10];
  
  if (areDisjoint(A2, B2)) {
    console.log("List A2 dan B2 adalah disjoint set.");
  } else {
    console.log("List A2 dan B2 bukan disjoint set.");
  }
  