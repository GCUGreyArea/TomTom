
# Group integers into pairs of difference

```text
    ar1 = {1,2,3,4};
    ar2 = {1,2,3,4};

    // Arrangement is such that 
    // 1. gap of zero (3,3)
    // 2. gap of 1 (2,1)
    // 3. gap of 4 (4,6)
    ar1 = {1,1,2,2,3,3,4,6,9};
    ar2 = {1,2,1,2,3,4,3,6,9};

    // These will be distributed 
    // 1. (1,2) and (3,4) gap of one
    // 2. (3,6) gap of 3
    // 3. (9,11) gap of 4
    // 4. (9,14) gap of 5 and (14,9)
    ar1 = {1,1,2,2,3,3,4,6,9,9,9,11,14};
    ar2 = {1,2,1,2,3,4,3,6,9,11,9,14,9};

    // These will be distributed 
    // 1. (1,2) (2,3) (3,4)
    // 2. (6,9)
    // 3. (9,11)
    // 4. (9,14) 
    ar1 = {1,2,2,3,3,4,6,9,9,9,11,14};
    ar2 = {1,2,2,3,3,4,6,9,9,11,9,14};
```
