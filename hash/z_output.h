#ifndef HASH_Z_OUTPUT_H
#define HASH_Z_OUTPUT_H
/*
***** ALL RESULTS ARE VERIFIED ******
//---------------------------------------------------------------------
// open hash random test:
//---------------------------------------------------------------------
Using open_hash<record>
# of Records: 500
Searching for 250 existing keys...
Found: 250
Not Found: 0
Searching for 250 non-existing keys...
Found: 0
Not Found: 250
- - - End of random test - - -



//---------------------------------------------------------------------
// chained hash random test:
//---------------------------------------------------------------------
Using chained_hash<record>
# of Records: 2500
Searching for 1250 existing keys...
Found: 1250
Not Found: 0
Searching for 1250 non-existing keys...
Found: 0
Not Found: 1250
- - - End of random test - - -



//---------------------------------------------------------------------
// open hash interactive test:
//---------------------------------------------------------------------
Using open_hash<record>
[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:3860|Value:4860]
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2]
[3]
[4]
[5]
[6]
[7]
[8]
[9]
[10]
[11]
[12]
[13]
[14]
[15]
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:8447|Value:3263]
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2]
[3]
[4]
[5]
[6]
[7]
[8]
[9]
[10]
[11]
[12]
[13]
[14]
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:7437|Value:4003]
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2]
[3]
[4]
[5]
[6]
[7]
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14]
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:7534|Value:6485]
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2]
[3] [Key:7534|Value:6485] Hash: 3
[4]
[5]
[6]
[7]
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14]
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:9182|Value:5210]
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2] [Key:9182|Value:5210] Hash: 2
[3] [Key:7534|Value:6485] Hash: 3
[4]
[5]
[6]
[7]
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14]
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:171|Value:9956]
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2] [Key:9182|Value:5210] Hash: 2
[3] [Key:7534|Value:6485] Hash: 3
[4] [Key:171|Value:9956] Hash: 1 *
[5]
[6]
[7]
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14]
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:70|Value:203]
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2] [Key:9182|Value:5210] Hash: 2
[3] [Key:7534|Value:6485] Hash: 3
[4] [Key:171|Value:9956] Hash: 1 *
[5] [Key:70|Value:203] Hash: 2 *
[6]
[7]
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14]
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:4149|Value:3841]
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2] [Key:9182|Value:5210] Hash: 2
[3] [Key:7534|Value:6485] Hash: 3
[4] [Key:171|Value:9956] Hash: 1 *
[5] [Key:70|Value:203] Hash: 2 *
[6] [Key:4149|Value:3841] Hash: 1 *
[7]
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14]
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : i
Key: 4529
Value: 9482
Inserted [Key:4529|Value:9482]
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2] [Key:9182|Value:5210] Hash: 2
[3] [Key:7534|Value:6485] Hash: 3
[4] [Key:171|Value:9956] Hash: 1 *
[5] [Key:70|Value:203] Hash: 2 *
[6] [Key:4149|Value:3841] Hash: 1 *
[7] [Key:4529|Value:9482] Hash: 7
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14]
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : i
Key: 6729
Value: 1839
Inserted [Key:6729|Value:1839]
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2] [Key:9182|Value:5210] Hash: 2
[3] [Key:7534|Value:6485] Hash: 3
[4] [Key:171|Value:9956] Hash: 1 *
[5] [Key:70|Value:203] Hash: 2 *
[6] [Key:4149|Value:3841] Hash: 1 *
[7] [Key:4529|Value:9482] Hash: 7
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14] [Key:6729|Value:1839] Hash: 14
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : s
Table Size: 10 records
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2] [Key:9182|Value:5210] Hash: 2
[3] [Key:7534|Value:6485] Hash: 3
[4] [Key:171|Value:9956] Hash: 1 *
[5] [Key:70|Value:203] Hash: 2 *
[6] [Key:4149|Value:3841] Hash: 1 *
[7] [Key:4529|Value:9482] Hash: 7
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14] [Key:6729|Value:1839] Hash: 14
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : d
Key: 4149
Deleted Key 4149
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2] [Key:9182|Value:5210] Hash: 2
[3] [Key:7534|Value:6485] Hash: 3
[4] [Key:171|Value:9956] Hash: 1 *
[5] [Key:70|Value:203] Hash: 2 *
[6] - - - - - - -
[7] [Key:4529|Value:9482] Hash: 7
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14] [Key:6729|Value:1839] Hash: 14
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : d
Key: 9182
Deleted Key 9182
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2] - - - - - - -
[3] [Key:7534|Value:6485] Hash: 3
[4] [Key:171|Value:9956] Hash: 1 *
[5] [Key:70|Value:203] Hash: 2 *
[6] - - - - - - -
[7] [Key:4529|Value:9482] Hash: 7
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14] [Key:6729|Value:1839] Hash: 14
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : d
Key: 5755
Key 5755 not found
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2] - - - - - - -
[3] [Key:7534|Value:6485] Hash: 3
[4] [Key:171|Value:9956] Hash: 1 *
[5] [Key:70|Value:203] Hash: 2 *
[6] - - - - - - -
[7] [Key:4529|Value:9482] Hash: 7
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14] [Key:6729|Value:1839] Hash: 14
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : s
Table Size: 8 records
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2] - - - - - - -
[3] [Key:7534|Value:6485] Hash: 3
[4] [Key:171|Value:9956] Hash: 1 *
[5] [Key:70|Value:203] Hash: 2 *
[6] - - - - - - -
[7] [Key:4529|Value:9482] Hash: 7
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14] [Key:6729|Value:1839] Hash: 14
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : f
Key: 70
Found record: [Key:70|Value:203]
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2] - - - - - - -
[3] [Key:7534|Value:6485] Hash: 3
[4] [Key:171|Value:9956] Hash: 1 *
[5] [Key:70|Value:203] Hash: 2 *
[6] - - - - - - -
[7] [Key:4529|Value:9482] Hash: 7
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14] [Key:6729|Value:1839] Hash: 14
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : f
Key: 1222
Record not found
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2] - - - - - - -
[3] [Key:7534|Value:6485] Hash: 3
[4] [Key:171|Value:9956] Hash: 1 *
[5] [Key:70|Value:203] Hash: 2 *
[6] - - - - - - -
[7] [Key:4529|Value:9482] Hash: 7
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14] [Key:6729|Value:1839] Hash: 14
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : ?
Key: 7534
Key 7534 exists
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2] - - - - - - -
[3] [Key:7534|Value:6485] Hash: 3
[4] [Key:171|Value:9956] Hash: 1 *
[5] [Key:70|Value:203] Hash: 2 *
[6] - - - - - - -
[7] [Key:4529|Value:9482] Hash: 7
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14] [Key:6729|Value:1839] Hash: 14
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : ?
Key: 367
Key 367 does not exist
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2] - - - - - - -
[3] [Key:7534|Value:6485] Hash: 3
[4] [Key:171|Value:9956] Hash: 1 *
[5] [Key:70|Value:203] Hash: 2 *
[6] - - - - - - -
[7] [Key:4529|Value:9482] Hash: 7
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14] [Key:6729|Value:1839] Hash: 14
[15] [Key:8447|Value:3263] Hash: 15
[16]

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : x
Final Table:
[0]
[1] [Key:3860|Value:4860] Hash: 1
[2] - - - - - - -
[3] [Key:7534|Value:6485] Hash: 3
[4] [Key:171|Value:9956] Hash: 1 *
[5] [Key:70|Value:203] Hash: 2 *
[6] - - - - - - -
[7] [Key:4529|Value:9482] Hash: 7
[8] [Key:7437|Value:4003] Hash: 8
[9]
[10]
[11]
[12]
[13]
[14] [Key:6729|Value:1839] Hash: 14
[15] [Key:8447|Value:3263] Hash: 15
[16]



//---------------------------------------------------------------------
// chained hash interactive test:
//---------------------------------------------------------------------
Using chained_hash<record>
[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:4157|Value:2312]
[0] |||
[1] |||
[2] |||
[3] |||
[4] |||
[5] |||
[6] |||
[7] |||
[8] |||
[9] [[Key:4157|Value:2312]]->|||
[10] |||
[11] |||
[12] |||
[13] |||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:2560|Value:304]
[0] |||
[1] |||
[2] |||
[3] |||
[4] |||
[5] |||
[6] |||
[7] |||
[8] |||
[9] [[Key:4157|Value:2312]]->|||
[10] [[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] |||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:2677|Value:2917]
[0] |||
[1] |||
[2] |||
[3] |||
[4] |||
[5] |||
[6] |||
[7] |||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:4157|Value:2312]]->|||
[10] [[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] |||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:1161|Value:5454]
[0] |||
[1] |||
[2] |||
[3] |||
[4] |||
[5] [[Key:1161|Value:5454]]->|||
[6] |||
[7] |||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:4157|Value:2312]]->|||
[10] [[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] |||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:9699|Value:902]
[0] |||
[1] |||
[2] |||
[3] |||
[4] |||
[5] [[Key:1161|Value:5454]]->|||
[6] |||
[7] |||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:9699|Value:902]]->[[Key:4157|Value:2312]]->|||
[10] [[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] |||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:6494|Value:3292]
[0] [[Key:6494|Value:3292]]->|||
[1] |||
[2] |||
[3] |||
[4] |||
[5] [[Key:1161|Value:5454]]->|||
[6] |||
[7] |||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:9699|Value:902]]->[[Key:4157|Value:2312]]->|||
[10] [[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] |||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:5172|Value:3246]
[0] [[Key:6494|Value:3292]]->|||
[1] |||
[2] |||
[3] |||
[4] [[Key:5172|Value:3246]]->|||
[5] [[Key:1161|Value:5454]]->|||
[6] |||
[7] |||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:9699|Value:902]]->[[Key:4157|Value:2312]]->|||
[10] [[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] |||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:347|Value:3058]
[0] [[Key:6494|Value:3292]]->|||
[1] |||
[2] |||
[3] |||
[4] [[Key:5172|Value:3246]]->|||
[5] [[Key:1161|Value:5454]]->|||
[6] |||
[7] [[Key:347|Value:3058]]->|||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:9699|Value:902]]->[[Key:4157|Value:2312]]->|||
[10] [[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] |||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:7860|Value:8132]
[0] [[Key:6494|Value:3292]]->|||
[1] |||
[2] |||
[3] |||
[4] [[Key:5172|Value:3246]]->|||
[5] [[Key:1161|Value:5454]]->|||
[6] [[Key:7860|Value:8132]]->|||
[7] [[Key:347|Value:3058]]->|||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:9699|Value:902]]->[[Key:4157|Value:2312]]->|||
[10] [[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] |||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : r
Inserted [Key:2733|Value:330]
[0] [[Key:6494|Value:3292]]->|||
[1] |||
[2] |||
[3] |||
[4] [[Key:5172|Value:3246]]->|||
[5] [[Key:1161|Value:5454]]->|||
[6] [[Key:7860|Value:8132]]->|||
[7] [[Key:347|Value:3058]]->|||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:9699|Value:902]]->[[Key:4157|Value:2312]]->|||
[10] [[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] [[Key:2733|Value:330]]->|||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : i
Key: 5729
Value: 8342
Inserted [Key:5729|Value:8342]
[0] [[Key:5729|Value:8342]]->[[Key:6494|Value:3292]]->|||
[1] |||
[2] |||
[3] |||
[4] [[Key:5172|Value:3246]]->|||
[5] [[Key:1161|Value:5454]]->|||
[6] [[Key:7860|Value:8132]]->|||
[7] [[Key:347|Value:3058]]->|||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:9699|Value:902]]->[[Key:4157|Value:2312]]->|||
[10] [[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] [[Key:2733|Value:330]]->|||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : i
Key: 9445
Value: 3251
Inserted [Key:9445|Value:3251]
[0] [[Key:5729|Value:8342]]->[[Key:6494|Value:3292]]->|||
[1] |||
[2] |||
[3] |||
[4] [[Key:5172|Value:3246]]->|||
[5] [[Key:1161|Value:5454]]->|||
[6] [[Key:7860|Value:8132]]->|||
[7] [[Key:347|Value:3058]]->|||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:9699|Value:902]]->[[Key:4157|Value:2312]]->|||
[10] [[Key:9445|Value:3251]]->[[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] [[Key:2733|Value:330]]->|||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : s
Table Size: 12 records
[0] [[Key:5729|Value:8342]]->[[Key:6494|Value:3292]]->|||
[1] |||
[2] |||
[3] |||
[4] [[Key:5172|Value:3246]]->|||
[5] [[Key:1161|Value:5454]]->|||
[6] [[Key:7860|Value:8132]]->|||
[7] [[Key:347|Value:3058]]->|||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:9699|Value:902]]->[[Key:4157|Value:2312]]->|||
[10] [[Key:9445|Value:3251]]->[[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] [[Key:2733|Value:330]]->|||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : d
Key: 9699
Deleted Key 9699
[0] [[Key:5729|Value:8342]]->[[Key:6494|Value:3292]]->|||
[1] |||
[2] |||
[3] |||
[4] [[Key:5172|Value:3246]]->|||
[5] [[Key:1161|Value:5454]]->|||
[6] [[Key:7860|Value:8132]]->|||
[7] [[Key:347|Value:3058]]->|||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:4157|Value:2312]]->|||
[10] [[Key:9445|Value:3251]]->[[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] [[Key:2733|Value:330]]->|||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : d
Key: 7860
Deleted Key 7860
[0] [[Key:5729|Value:8342]]->[[Key:6494|Value:3292]]->|||
[1] |||
[2] |||
[3] |||
[4] [[Key:5172|Value:3246]]->|||
[5] [[Key:1161|Value:5454]]->|||
[6] |||
[7] [[Key:347|Value:3058]]->|||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:4157|Value:2312]]->|||
[10] [[Key:9445|Value:3251]]->[[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] [[Key:2733|Value:330]]->|||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : d
Key: 1250
Key 1250 not found
[0] [[Key:5729|Value:8342]]->[[Key:6494|Value:3292]]->|||
[1] |||
[2] |||
[3] |||
[4] [[Key:5172|Value:3246]]->|||
[5] [[Key:1161|Value:5454]]->|||
[6] |||
[7] [[Key:347|Value:3058]]->|||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:4157|Value:2312]]->|||
[10] [[Key:9445|Value:3251]]->[[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] [[Key:2733|Value:330]]->|||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : s
Table Size: 10 records
[0] [[Key:5729|Value:8342]]->[[Key:6494|Value:3292]]->|||
[1] |||
[2] |||
[3] |||
[4] [[Key:5172|Value:3246]]->|||
[5] [[Key:1161|Value:5454]]->|||
[6] |||
[7] [[Key:347|Value:3058]]->|||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:4157|Value:2312]]->|||
[10] [[Key:9445|Value:3251]]->[[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] [[Key:2733|Value:330]]->|||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : f
Key: 6494
Found record: [Key:6494|Value:3292]
[0] [[Key:5729|Value:8342]]->[[Key:6494|Value:3292]]->|||
[1] |||
[2] |||
[3] |||
[4] [[Key:5172|Value:3246]]->|||
[5] [[Key:1161|Value:5454]]->|||
[6] |||
[7] [[Key:347|Value:3058]]->|||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:4157|Value:2312]]->|||
[10] [[Key:9445|Value:3251]]->[[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] [[Key:2733|Value:330]]->|||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : f
Key: 3200
Record not found
[0] [[Key:5729|Value:8342]]->[[Key:6494|Value:3292]]->|||
[1] |||
[2] |||
[3] |||
[4] [[Key:5172|Value:3246]]->|||
[5] [[Key:1161|Value:5454]]->|||
[6] |||
[7] [[Key:347|Value:3058]]->|||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:4157|Value:2312]]->|||
[10] [[Key:9445|Value:3251]]->[[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] [[Key:2733|Value:330]]->|||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : ?
Key: 4157
Key 4157 exists
[0] [[Key:5729|Value:8342]]->[[Key:6494|Value:3292]]->|||
[1] |||
[2] |||
[3] |||
[4] [[Key:5172|Value:3246]]->|||
[5] [[Key:1161|Value:5454]]->|||
[6] |||
[7] [[Key:347|Value:3058]]->|||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:4157|Value:2312]]->|||
[10] [[Key:9445|Value:3251]]->[[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] [[Key:2733|Value:330]]->|||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : ?
Key: 7865
Key 7865 does not exist
[0] [[Key:5729|Value:8342]]->[[Key:6494|Value:3292]]->|||
[1] |||
[2] |||
[3] |||
[4] [[Key:5172|Value:3246]]->|||
[5] [[Key:1161|Value:5454]]->|||
[6] |||
[7] [[Key:347|Value:3058]]->|||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:4157|Value:2312]]->|||
[10] [[Key:9445|Value:3251]]->[[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] [[Key:2733|Value:330]]->|||
[14] |||
[15] |||
[16] |||

[S]ize [I]nsert [R]andom [D]elete [F]ind value [?]Exists?  e[X]it : x
Final Table:
[0] [[Key:5729|Value:8342]]->[[Key:6494|Value:3292]]->|||
[1] |||
[2] |||
[3] |||
[4] [[Key:5172|Value:3246]]->|||
[5] [[Key:1161|Value:5454]]->|||
[6] |||
[7] [[Key:347|Value:3058]]->|||
[8] [[Key:2677|Value:2917]]->|||
[9] [[Key:4157|Value:2312]]->|||
[10] [[Key:9445|Value:3251]]->[[Key:2560|Value:304]]->|||
[11] |||
[12] |||
[13] [[Key:2733|Value:330]]->|||
[14] |||
[15] |||
[16] |||



*/

#endif //HASH_Z_OUTPUT_H
