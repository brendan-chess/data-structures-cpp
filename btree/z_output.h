#ifndef BTREE_Z_OUTPUT_H
#define BTREE_Z_OUTPUT_H
/*
***** ALL RESULTS ARE VERIFIED ******
//---------------------------------------------------------------------
// inserting 20 random numbers:
//---------------------------------------------------------------------
Inserting 905
[905]

Inserting 307
[307, 905]

Inserting 115
   [905]
[307]
   [115]

Inserting 641
   [641, 905]
[307]
   [115]

Inserting 54
   [641, 905]
[307]
   [54, 115]

Inserting 105
       [641, 905]
[105, 307]
       [115]
       [54]

Inserting 448
       [905]
   [641]
       [448]
[307]
       [115]
   [105]
       [54]

Inserting 282
       [905]
   [641]
       [448]
[307]
       [115, 282]
   [105]
       [54]

Inserting 395
       [905]
   [641]
       [395, 448]
[307]
       [115, 282]
   [105]
       [54]

Inserting 222
       [905]
   [641]
       [395, 448]
[307]
           [282]
   [105, 222]
           [115]
           [54]

Inserting 871
       [871, 905]
   [641]
       [395, 448]
[307]
           [282]
   [105, 222]
           [115]
           [54]

Inserting 946
           [946]
   [641, 905]
           [871]
           [395, 448]
[307]
           [282]
   [105, 222]
           [115]
           [54]

Inserting 925
           [925, 946]
   [641, 905]
           [871]
           [395, 448]
[307]
           [282]
   [105, 222]
           [115]
           [54]

Inserting 750
           [925, 946]
   [641, 905]
           [750, 871]
           [395, 448]
[307]
           [282]
   [105, 222]
           [115]
           [54]

Inserting 2
           [925, 946]
   [641, 905]
           [750, 871]
           [395, 448]
[307]
           [282]
   [105, 222]
           [115]
           [2, 54]

Inserting 247
           [925, 946]
   [641, 905]
           [750, 871]
           [395, 448]
[307]
           [247, 282]
   [105, 222]
           [115]
           [2, 54]

Inserting 431
           [925, 946]
       [905]
           [750, 871]
[307, 641]
           [448]
       [431]
           [395]
               [247, 282]
       [105, 222]
               [115]
               [2, 54]

Inserting 955
               [955]
       [905, 946]
               [925]
               [750, 871]
[307, 641]
           [448]
       [431]
           [395]
               [247, 282]
       [105, 222]
               [115]
               [2, 54]

Inserting 818
           [955]
       [946]
           [925]
   [905]
           [871]
       [818]
           [750]
[641]
           [448]
       [431]
           [395]
   [307]
               [247, 282]
       [105, 222]
               [115]
               [2, 54]

Inserting 416
           [955]
       [946]
           [925]
   [905]
           [871]
       [818]
           [750]
[641]
           [448]
       [431]
           [395, 416]
   [307]
               [247, 282]
       [105, 222]
               [115]
               [2, 54]



//---------------------------------------------------------------------
// find:
//---------------------------------------------------------------------
[5]

find(3)
0x0 expected null address
find(5)
0x7ffee60aba10 expected real address



//---------------------------------------------------------------------
// copy_tree:
//---------------------------------------------------------------------
BTree bt1:
           [948]
       [927]
           [903]
   [823]
               [538]
       [475, 524]
               [517]
               [370, 459]
[361]
           [360]
       [288]
           [263]
   [250]
               [200]
       [87, 193]
               [157]
               [53]

BTree bt2:
[]

bt2.copy_tree(bt1);
BTree bt2:
           [948]
       [927]
           [903]
   [823]
               [538]
       [475, 524]
               [517]
               [370, 459]
[361]
           [360]
       [288]
           [263]
   [250]
               [200]
       [87, 193]
               [157]
               [53]



//---------------------------------------------------------------------
// clear:
//---------------------------------------------------------------------
BTree bt1:
           [915]
       [906]
           [831]
   [756]
           [727]
       [712]
           [622, 659]
[593]
           [557]
       [548]
           [416]
   [410]
               [398, 400]
       [155, 330]
               [288]
               [48, 72]

bt1.clear_tree();
BTree bt1:
[]


//---------------------------------------------------------------------
// copy constructor:
//---------------------------------------------------------------------
BTree bt1:
               [965]
       [873, 936]
               [881]
               [865]
   [764]
               [752]
       [568, 655]
               [645]
               [415, 417]
[320]
           [300]
       [280]
           [218]
   [58]
           [39]
       [15]
           [12]

BTree<int> bt2(bt1);
BTree bt2:
               [965]
       [873, 936]
               [881]
               [865]
   [764]
               [752]
       [568, 655]
               [645]
               [415, 417]
[320]
           [300]
       [280]
           [218]
   [58]
           [39]
       [15]
           [12]


//---------------------------------------------------------------------
// assignment operator:
//---------------------------------------------------------------------
BTree bt1:
           [891]
       [851]
           [831]
   [789]
           [732]
       [652]
           [642]
[617]
               [586]
       [425, 540]
               [471]
               [417]
   [412]
           [113, 161]
       [69]
           [12, 54]

BTree bt2:
[]

bt2 = bt1;
BTree bt2:
           [891]
       [851]
           [831]
   [789]
           [732]
       [652]
           [642]
[617]
               [586]
       [425, 540]
               [471]
               [417]
   [412]
           [113, 161]
       [69]
           [12, 54]




//---------------------------------------------------------------------
// get:
//---------------------------------------------------------------------
               [180, 190]
           [170]
               [160]
   [110, 150]
               [140]
           [130]
               [120]
               [100]
           [90]
               [80]
[70]
           [60]
       [50]
           [40]
   [30]
           [20]
       [10]
           [0]

bt.get(100) = 100 expected 100
bt.get(102) = 102 expected 102
               [180, 190]
           [170]
               [160]
   [110, 150]
               [140]
           [130]
               [120]
               [100, 102]
           [90]
               [80]
[70]
           [60]
       [50]
           [40]
   [30]
           [20]
       [10]
           [0]



//---------------------------------------------------------------------
// contains:
//---------------------------------------------------------------------
               [180, 190]
           [170]
               [160]
   [110, 150]
               [140]
           [130]
               [120]
               [100]
           [90]
               [80]
[70]
           [60]
       [50]
           [40]
   [30]
           [20]
       [10]
           [0]

bt.contains(100) = 1 expected 1
bt.contains(102) = 0 expected 0
               [180, 190]
           [170]
               [160]
   [110, 150]
               [140]
           [130]
               [120]
               [100]
           [90]
               [80]
[70]
           [60]
       [50]
           [40]
   [30]
           [20]
       [10]
           [0]





//---------------------------------------------------------------------
// remove:
//---------------------------------------------------------------------
[]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:q
Count: 20
               [893]
       [861, 883]
               [882]
               [834]
   [824]
           [688]
       [633]
           [598]
[577]
               [540]
       [396, 417]
               [408]
               [322]
   [299]
           [261]
       [166]
           [64]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 577
               [893]
       [861, 883]
               [882]
               [834]
   [824]
           [688]
       [633]
           [598]
[540]
           [408, 417]
       [396]
           [322]
   [299]
           [261]
       [166]
           [64]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 824
           [893]
       [883]
           [882]
   [861]
           [834]
       [688]
           [598, 633]
[540]
           [408, 417]
       [396]
           [322]
   [299]
           [261]
       [166]
           [64]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 408
           [893]
       [883]
           [882]
   [861]
           [834]
       [688]
           [598, 633]
[540]
           [417]
       [396]
           [322]
   [299]
           [261]
       [166]
           [64]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 396
           [893]
       [883]
           [882]
[540, 861]
           [834]
       [688]
           [598, 633]
               [322, 417]
       [166, 299]
               [261]
               [64]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 893
           [882, 883]
   [688, 861]
           [834]
           [598, 633]
[540]
           [322, 417]
   [166, 299]
           [261]
           [64]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 299
           [882, 883]
   [688, 861]
           [834]
           [598, 633]
[540]
           [417]
   [166, 322]
           [261]
           [64]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 417
           [882, 883]
   [688, 861]
           [834]
           [598, 633]
[540]
       [261, 322]
   [166]
       [64]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 540
           [882, 883]
   [688, 861]
           [834]
           [598, 633]
[322]
       [261]
   [166]
       [64]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 834
           [883]
   [688, 882]
           [861]
           [598, 633]
[322]
       [261]
   [166]
       [64]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 633
           [883]
   [688, 882]
           [861]
           [598]
[322]
       [261]
   [166]
       [64]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 166
       [883]
   [882]
       [861]
[688]
       [598]
   [322]
       [64, 261]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 688
       [883]
   [882]
       [861]
[598]
       [322]
   [261]
       [64]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 861
       [882, 883]
[261, 598]
       [322]
       [64]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 882
       [883]
[261, 598]
       [322]
       [64]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 883
   [322, 598]
[261]
   [64]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 64
   [598]
[322]
   [261]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 322
[261, 598]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 261
[598]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:d
Delete: 598
[]

[R]andom   [I]nsert   [Q]uickfill   [D]elete   [S]ize   [C]ontains   [E]xit:e
[]


*/
#endif //BTREE_Z_OUTPUT_H