#ifndef BPLUSTREE_Z_OUTPUT_H
#define BPLUSTREE_Z_OUTPUT_H
/*
***** ALL RESULTS ARE VERIFIED ******
//---------------------------------------------------------------------
// test bpt:
//---------------------------------------------------------------------
Inserting 50 random integers:
                                               [963, 972]
                                   [963]
                                               [961]
                       [881, 961]
                                               [955]
                                   [955]
                                               [881]
                                               [876, 877]
                                   [858, 876]
                                               [858]
                                               [804]
           [804]
                                               [692, 784]
                                   [692]
                                               [672]
                       [576, 672]
                                               [580, 616]
                                   [580]
                                               [576, 577]
                                               [547, 572]
                                   [547]
                                               [519]
[519]
                                               [485, 510]
                                   [480, 485]
                                               [480]
                                               [448]
                       [414, 448]
                                               [423]
                                   [423]
                                               [414]
                                               [406, 411]
                                   [406]
                                               [386]
           [189, 386]
                                               [371, 378]
                                   [371]
                                               [357]
                       [221, 357]
                                               [242, 337]
                                   [242]
                                               [221]
                                               [204]
                                   [204]
                                               [189, 190]
                                               [149, 181]
                                   [149]
                                               [145]
                       [53, 145]
                                               [79, 97]
                                   [79]
                                               [53, 77]
                                               [45]
                                   [45]
                                               [28]

========================================================
Tree is valid: 1
========================================================
Printing leaves using Iterator:
[28]
[45]
[53]
[77]
[79]
[97]
[145]
[149]
[181]
[189]
[190]
[204]
[221]
[242]
[337]
[357]
[371]
[378]
[386]
[406]
[411]
[414]
[423]
[448]
[480]
[485]
[510]
[519]
[547]
[572]
[576]
[577]
[580]
[616]
[672]
[692]
[784]
[804]
[858]
[876]
[877]
[881]
[955]
[961]
[963]
[972]
========================================================
Find 10 values that are in the tree:
480 was found
190 was found
190 was found
189 was found
189 was found
485 was found
672 was found
877 was found
961 was found
672 was found
========================================================
Find 10 values that are not in the tree:
1220 was not found
1685 was not found
1559 was not found
1249 was not found
1830 was not found
1166 was not found
1532 was not found
1372 was not found
1301 was not found
1481 was not found
========================================================
Removing all values from the tree:
                                               [963, 972]
                                   [963]
                                               [961]
                       [881, 961]
                                               [955]
                                   [955]
                                               [881]
                                               [876, 877]
                                   [858, 876]
                                               [858]
                                               [804]
           [804]
                                               [692, 784]
                                   [692]
                                               [672]
                       [576, 672]
                                               [580, 616]
                                   [580]
                                               [576, 577]
                                               [547, 572]
                                   [547]
                                               [519]
[519]
                                               [485, 510]
                                   [480, 485]
                                               [480]
                                               [448]
                       [414, 448]
                                               [423]
                                   [423]
                                               [414]
                                               [406, 411]
                                   [406]
                                               [386]
           [189, 386]
                                               [371, 378]
                                   [371]
                                               [357]
                       [221, 357]
                                               [242, 337]
                                   [242]
                                               [221]
                                               [204]
                                   [204]
                                               [189, 190]
                                               [149, 181]
                                   [149]
                                               [145]
                       [53, 145]
                                               [79, 97]
                                   [79]
                                               [53, 77]
                                               [45]
                                   [45]
                                               [28]

Removing 804
Removing 45
Removing 881
Removing 386
Removing 79
Removing 784
Removing 955
Removing 145
Removing 858
Removing 357
Removing 580
Removing 97
Removing 961
Removing 204
Removing 414
Removing 519
Removing 28
Removing 371
Removing 577
Removing 858
Removing 877
Removing 406
Removing 672
Removing 692
Removing 480
Removing 411
Removing 221
Removing 149
Removing 242
Removing 77
Removing 963
Removing 204
Removing 190
Removing 423
Removing 189
Removing 972
Removing 181
Removing 576
Removing 616
Removing 876
Removing 371
Removing 53
Removing 448
Removing 378
Removing 448
Removing 485
Removing 572
Removing 510
Removing 337
Removing 547
[]

========================================================
End of test
========================================================



//---------------------------------------------------------------------
// test bpt big 3:
//---------------------------------------------------------------------
Inserting 50 random integers:
                                               [987, 996]
                                   [987]
                                               [976]
                       [892, 976]
                                               [936, 953]
                                   [903, 936]
                                               [903]
                                               [892]
                                               [840, 843]
                                   [840]
                                               [769, 828]
           [769]
                                               [727]
                                   [727]
                                               [667, 680]
                       [629, 667]
                                               [645, 653]
                                   [645]
                                               [629]
                                               [602, 620]
                                   [602]
                                               [572]
[572]
                                               [538, 541]
                                   [498, 538]
                                               [498, 502]
                                               [472, 484]
                       [472]
                                               [458]
                                   [458]
                                               [408, 448]
           [198, 408]
                                               [378, 390]
                                   [338, 378]
                                               [338, 342]
                                               [318]
                       [318]
                                               [247, 295]
                                   [227, 247]
                                               [227]
                                               [198, 225]
                                               [172, 176]
                                   [172]
                                               [153]
                       [105, 153]
                                               [115, 123]
                                   [115]
                                               [105, 112]
                                               [70, 76]
                                   [58, 70]
                                               [58]
                                               [31]

========================================================
Copy constructor:
BPlusTree<int> bpt2(bpt);
bpt2:
                                               [987, 996]
                                   [987]
                                               [976]
                       [892, 976]
                                               [936, 953]
                                   [903, 936]
                                               [903]
                                               [892]
                                               [840, 843]
                                   [840]
                                               [769, 828]
           [769]
                                               [727]
                                   [727]
                                               [667, 680]
                       [629, 667]
                                               [645, 653]
                                   [645]
                                               [629]
                                               [602, 620]
                                   [602]
                                               [572]
[572]
                                               [538, 541]
                                   [498, 538]
                                               [498, 502]
                                               [472, 484]
                       [472]
                                               [458]
                                   [458]
                                               [408, 448]
           [198, 408]
                                               [378, 390]
                                   [338, 378]
                                               [338, 342]
                                               [318]
                       [318]
                                               [247, 295]
                                   [227, 247]
                                               [227]
                                               [198, 225]
                                               [172, 176]
                                   [172]
                                               [153]
                       [105, 153]
                                               [115, 123]
                                   [115]
                                               [105, 112]
                                               [70, 76]
                                   [58, 70]
                                               [58]
                                               [31]

========================================================
Assignment operator:
bpt3 = bpt;
bpt3:
                                               [987, 996]
                                   [987]
                                               [976]
                       [892, 976]
                                               [936, 953]
                                   [903, 936]
                                               [903]
                                               [892]
                                               [840, 843]
                                   [840]
                                               [769, 828]
           [769]
                                               [727]
                                   [727]
                                               [667, 680]
                       [629, 667]
                                               [645, 653]
                                   [645]
                                               [629]
                                               [602, 620]
                                   [602]
                                               [572]
[572]
                                               [538, 541]
                                   [498, 538]
                                               [498, 502]
                                               [472, 484]
                       [472]
                                               [458]
                                   [458]
                                               [408, 448]
           [198, 408]
                                               [378, 390]
                                   [338, 378]
                                               [338, 342]
                                               [318]
                       [318]
                                               [247, 295]
                                   [227, 247]
                                               [227]
                                               [198, 225]
                                               [172, 176]
                                   [172]
                                               [153]
                       [105, 153]
                                               [115, 123]
                                   [115]
                                               [105, 112]
                                               [70, 76]
                                   [58, 70]
                                               [58]
                                               [31]

========================================================
End of test
========================================================



*/
#endif //BPLUSTREE_Z_OUTPUT_H
