let rec latticePaths n m = if n == 1 || m == 1 then 1 else (latticePaths (n-1) m) + (latticePaths n (m-1));;
