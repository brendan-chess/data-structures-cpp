#ifndef MAP_Z_OUTPUT_H
#define MAP_Z_OUTPUT_H
/*
***** ALL RESULTS ARE VERIFIED ******
//---------------------------------------------------------------------
// BTree remove:
//---------------------------------------------------------------------
[]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:q
Count: 20
           [975]
       [974]
           [973]
   [887]
           [784, 790]
       [709]
           [611, 675]
[579]
           [556]
       [461]
           [423]
   [394]
               [319]
       [139, 318]
               [299]
               [13, 119]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 579
           [975]
       [974]
           [973]
   [887]
           [784, 790]
       [709]
           [611, 675]
[556]
           [423, 461]
       [394]
           [319]
   [318]
           [299]
       [139]
           [13, 119]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 139
           [975]
       [974]
           [973]
   [887]
           [784, 790]
       [709]
           [611, 675]
[556]
           [423, 461]
       [394]
           [319]
   [318]
           [299]
       [119]
           [13]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 887
           [975]
       [974]
           [973]
   [790]
           [784]
       [709]
           [611, 675]
[556]
           [423, 461]
       [394]
           [319]
   [318]
           [299]
       [119]
           [13]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 394
           [975]
       [974]
           [973]
   [790]
           [784]
       [709]
           [611, 675]
[556]
           [461]
       [423]
           [319]
   [318]
           [299]
       [119]
           [13]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 556
           [975]
       [974]
           [973]
[461, 790]
           [784]
       [709]
           [611, 675]
               [319, 423]
       [119, 318]
               [299]
               [13]



//---------------------------------------------------------------------
// Map demo:
//---------------------------------------------------------------------
[]

Inserting...
       [(5,e)]
[(2,b), (4,d)]
       [(3,c)]
       [(1,a)]

Size: 5
Empty: 0
Overwriting: m[1] = 'r'
       [(5,e)]
[(2,b), (4,d)]
       [(3,c)]
       [(1,r)]

Erasing some...
[(1,r), (4,d)]

m[1] = r
m[3] =  
   [(4,d)]
[(3, )]
   [(1,r)]

m.get(2) =  
   [(4,d)]
[(3, )]
   [(1,r), (2, )]

m.at(4) = d
m.at(5) =  
   [(4,d), (5, )]
[(3, )]
   [(1,r), (2, )]

m.contains(2) = 1
m.contains(7) = 0

Clearing...
[]

Size: 0
Empty: 1




*/
#endif //MAP_Z_OUTPUT_H
