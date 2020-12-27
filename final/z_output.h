#ifndef DATABASE_Z_OUTPUT_H
#define DATABASE_Z_OUTPUT_H
/*

//=========================================================
// final batch file run + delete demo   https://youtu.be/VN7fi85iJXo
//=========================================================

> batch final.bat
//****************************************************************************
//		CREATE TABLES AND INSERT RECORDS
//****************************************************************************


[0] make table employee fields  last, 		first, 			dep,  		salary, 	year
[1] insert into employee values Blow, 		Joe, 			CS,		 	100000, 	2018
[2] insert into employee values Blow, 		JoAnn,			Physics, 	200000, 	2016
[3] insert into employee values Johnson, 	Jack, 			HR, 		150000, 	2014
[4] insert into employee values Johnson, 	"Jimmy", 		Chemistry,	140000, 	2018
[5] insert into employee values Yao,	 	Jimmy, 			Math,		145000, 	2014
[6] insert into employee values "Yao", 		Flo, 			CS,			147000, 	2012
[7] insert into employee values Yang, 		Bo, 			CS,			160000, 	2013
[8] insert into employee values Jackson,	"Flo", 			Math,		165000, 	2017
[9] insert into employee values Jackson,	Bo,	 			Chemistry,	130000, 	2011
[10] insert into employee values "Jackson",	Billy, 			Math,	 	170000, 	2017
[11] insert into employee values Johnson,	"Mary Ann", 	Math,		165000, 	2014
[12] insert into employee values Johnson,	"Billy Bob", 	Physics,	142000, 	2014
[13] insert into employee values Johnson,	Billy, 			"Phys Ed",	102000, 	2014
[14] insert into employee values "Van Gogh",	Vincent, 		Art,		240000, 	2015
[15] insert into employee values "Van Gogh",	Vincent, 		CS,			245000, 	2015
[16] insert into employee values "Van Gogh",	"Jim Bob", 		"Phys Ed",	230000, 	2010
[17] select * from employee
_temp_employee1
                    last               first                 dep              salary                year

   0                Blow                 Joe                  CS              100000                2018
   1                Blow               JoAnn             Physics              200000                2016
   2             Johnson                Jack                  HR              150000                2014
   3             Johnson             "Jimmy"           Chemistry              140000                2018
   4                 Yao               Jimmy                Math              145000                2014
   5               "Yao"                 Flo                  CS              147000                2012
   6                Yang                  Bo                  CS              160000                2013
   7             Jackson               "Flo"                Math              165000                2017
   8             Jackson                  Bo           Chemistry              130000                2011
   9           "Jackson"               Billy                Math              170000                2017
  10             Johnson          "Mary Ann"                Math              165000                2014
  11             Johnson         "Billy Bob"             Physics              142000                2014
  12             Johnson               Billy           "Phys Ed"              102000                2014
  13          "Van Gogh"             Vincent                 Art              240000                2015
  14          "Van Gogh"             Vincent                  CS              245000                2015
  15          "Van Gogh"           "Jim Bob"           "Phys Ed"              230000                2010
Number of records: 16


[18] make table student fields fname, lname, major, age, company
[19] insert into student values Flo, 			Yao, 		CS, 				20, 	Google
[20] insert into student values Bo, 				Yang, 		CS, 				28,		Microsoft
[21] insert into student values "Sammuel L.", 	Jackson, 	CS, 				40,		Uber
[22] insert into student values "Flo", 			"Jackson", 	Math,	 			21,		Google
[23] insert into student values "Greg", 			"Pearson", 	Physics,			20,		Amazon
[24] insert into student values "Jim Bob", 		Smith, 		Math,	 			23,		Verizon
[25] insert into student values Calvin, 			Woo, 		Physics,			22,		Uber
[26] insert into student values "Anna Grace", 	"Del Rio", 	CS,	 				22,		USAF
[27] insert into student values "Teresa Mae", 	Gowers, 	Chemistry,			22,		Verizon
[28] insert into student values Alex,			Smith,		"Gender Studies", 	53,		Amazon
[29] select * from student
_temp_student2
                   fname               lname               major                 age             company

   0                 Flo                 Yao                  CS                  20              Google
   1                  Bo                Yang                  CS                  28           Microsoft
   2        "Sammuel L."             Jackson                  CS                  40                Uber
   3               "Flo"           "Jackson"                Math                  21              Google
   4              "Greg"           "Pearson"             Physics                  20              Amazon
   5           "Jim Bob"               Smith                Math                  23             Verizon
   6              Calvin                 Woo             Physics                  22                Uber
   7        "Anna Grace"           "Del Rio"                  CS                  22                USAF
   8        "Teresa Mae"              Gowers           Chemistry                  22             Verizon
   9                Alex               Smith    "Gender Studies"                  53              Amazon
Number of records: 10



//****************************************************************************
//		SIMPLE SELECT:
//****************************************************************************

[30] select * from student
_temp_student3
                   fname               lname               major                 age             company

   0                 Flo                 Yao                  CS                  20              Google
   1                  Bo                Yang                  CS                  28           Microsoft
   2        "Sammuel L."             Jackson                  CS                  40                Uber
   3               "Flo"           "Jackson"                Math                  21              Google
   4              "Greg"           "Pearson"             Physics                  20              Amazon
   5           "Jim Bob"               Smith                Math                  23             Verizon
   6              Calvin                 Woo             Physics                  22                Uber
   7        "Anna Grace"           "Del Rio"                  CS                  22                USAF
   8        "Teresa Mae"              Gowers           Chemistry                  22             Verizon
   9                Alex               Smith    "Gender Studies"                  53              Amazon
Number of records: 10


//------- simple strings -------------------
[31] select * from student where lname = Jackson
_temp_student4
                   fname               lname               major                 age             company

   0        "Sammuel L."             Jackson                  CS                  40                Uber
Number of records: 1

[32] select * from student where major = CS
_temp_student5
                   fname               lname               major                 age             company

   0                 Flo                 Yao                  CS                  20              Google
   1                  Bo                Yang                  CS                  28           Microsoft
   2        "Sammuel L."             Jackson                  CS                  40                Uber
   3        "Anna Grace"           "Del Rio"                  CS                  22                USAF
Number of records: 4

[33] select * from student where company = Uber
_temp_student6
                   fname               lname               major                 age             company

   0        "Sammuel L."             Jackson                  CS                  40                Uber
   1              Calvin                 Woo             Physics                  22                Uber
Number of records: 2


//----- quoted strings ---------------------
[34] select * from student where lname = "Del Rio"
_temp_student7
                   fname               lname               major                 age             company

   0        "Anna Grace"           "Del Rio"                  CS                  22                USAF
Number of records: 1

[35] select * from student where fname = "Jim Bob"
_temp_student8
                   fname               lname               major                 age             company

   0           "Jim Bob"               Smith                Math                  23             Verizon
Number of records: 1

[36] select * from student where fname = "Anna Grace"
_temp_student9
                   fname               lname               major                 age             company

   0        "Anna Grace"           "Del Rio"                  CS                  22                USAF
Number of records: 1

[37] select * from student where fname = "Teresa Mae"
_temp_student10
                   fname               lname               major                 age             company

   0        "Teresa Mae"              Gowers           Chemistry                  22             Verizon
Number of records: 1


//-------- non-existing string ------------------
[38] select * from student where lname = "Does Not Exist"
_temp_student11
                   fname               lname               major                 age             company

Number of records: 0


//****************************************************************************
//		RELATIONAL OPERATORS:
//****************************************************************************

//.................
//:Greater Than   :
//.................
[39] select * from student where lname > Yang
_temp_student12
                   fname               lname               major                 age             company

   0                 Flo                 Yao                  CS                  20              Google
Number of records: 1

[40] select * from student where major > Math
_temp_student13
                   fname               lname               major                 age             company

   0              "Greg"           "Pearson"             Physics                  20              Amazon
   1              Calvin                 Woo             Physics                  22                Uber
Number of records: 2

[41] select * from student where fname > "Sammuel L."
_temp_student14
                   fname               lname               major                 age             company

   0        "Teresa Mae"              Gowers           Chemistry                  22             Verizon
   1                Alex               Smith    "Gender Studies"                  53              Amazon
   2                  Bo                Yang                  CS                  28           Microsoft
   3              Calvin                 Woo             Physics                  22                Uber
   4                 Flo                 Yao                  CS                  20              Google
Number of records: 5

[42] select * from employee where salary > 200000
_temp_employee15
                    last               first                 dep              salary                year

   0          "Van Gogh"           "Jim Bob"           "Phys Ed"              230000                2010
   1          "Van Gogh"             Vincent                 Art              240000                2015
   2          "Van Gogh"             Vincent                  CS              245000                2015
Number of records: 3

[43] select * from employee where dep > Chemistry
_temp_employee16
                    last               first                 dep              salary                year

   0             Johnson                Jack                  HR              150000                2014
   1                 Yao               Jimmy                Math              145000                2014
   2             Jackson               "Flo"                Math              165000                2017
   3           "Jackson"               Billy                Math              170000                2017
   4             Johnson          "Mary Ann"                Math              165000                2014
   5                Blow               JoAnn             Physics              200000                2016
   6             Johnson         "Billy Bob"             Physics              142000                2014
Number of records: 7

[44] select * from employee where last > Jackson
_temp_employee17
                    last               first                 dep              salary                year

   0             Johnson                Jack                  HR              150000                2014
   1             Johnson             "Jimmy"           Chemistry              140000                2018
   2             Johnson          "Mary Ann"                Math              165000                2014
   3             Johnson         "Billy Bob"             Physics              142000                2014
   4             Johnson               Billy           "Phys Ed"              102000                2014
   5                Yang                  Bo                  CS              160000                2013
   6                 Yao               Jimmy                Math              145000                2014
Number of records: 7

[45] select * from employee where first > "Billy Bob"
_temp_employee18
                    last               first                 dep              salary                year

   0             Jackson               "Flo"                Math              165000                2017
   1          "Van Gogh"           "Jim Bob"           "Phys Ed"              230000                2010
   2             Johnson             "Jimmy"           Chemistry              140000                2018
   3             Johnson          "Mary Ann"                Math              165000                2014
   4           "Jackson"               Billy                Math              170000                2017
   5             Johnson               Billy           "Phys Ed"              102000                2014
   6                Yang                  Bo                  CS              160000                2013
   7             Jackson                  Bo           Chemistry              130000                2011
   8               "Yao"                 Flo                  CS              147000                2012
   9             Johnson                Jack                  HR              150000                2014
  10                 Yao               Jimmy                Math              145000                2014
  11                Blow               JoAnn             Physics              200000                2016
  12                Blow                 Joe                  CS              100000                2018
  13          "Van Gogh"             Vincent                 Art              240000                2015
  14          "Van Gogh"             Vincent                  CS              245000                2015
Number of records: 15



//. . . . . . . . . . . . . (Greater Than: Non-existing) . . . . . . . . . . . . . . . . . . . . .
[46] select * from student where age > 50
_temp_student19
                   fname               lname               major                 age             company

Number of records: 0

[47] select * from student where age > 35
_temp_student20
                   fname               lname               major                 age             company

Number of records: 0

[48] select * from student where fname > T
_temp_student21
                   fname               lname               major                 age             company

Number of records: 0

[49] select * from employee where salary > 130000
_temp_employee22
                    last               first                 dep              salary                year

   0             Johnson             "Jimmy"           Chemistry              140000                2018
   1             Johnson         "Billy Bob"             Physics              142000                2014
   2                 Yao               Jimmy                Math              145000                2014
   3               "Yao"                 Flo                  CS              147000                2012
   4             Johnson                Jack                  HR              150000                2014
   5                Yang                  Bo                  CS              160000                2013
   6             Jackson               "Flo"                Math              165000                2017
   7             Johnson          "Mary Ann"                Math              165000                2014
   8           "Jackson"               Billy                Math              170000                2017
   9                Blow               JoAnn             Physics              200000                2016
  10          "Van Gogh"           "Jim Bob"           "Phys Ed"              230000                2010
  11          "Van Gogh"             Vincent                 Art              240000                2015
  12          "Van Gogh"             Vincent                  CS              245000                2015
Number of records: 13

[50] select * from employee where  year > 2009
_temp_employee23
                    last               first                 dep              salary                year

Number of records: 0


//. . . . . . . . . . . . . (Greater than: last item) . . . . . . . . . . . . . . . . . .
[51] select * from student where age  > 53
_temp_student24
                   fname               lname               major                 age             company

Number of records: 0

[52] select * from student where lname > Yao
_temp_student25
                   fname               lname               major                 age             company

Number of records: 0

[53] select * from student where fname > "Teresa Mae"
_temp_student26
                   fname               lname               major                 age             company

   0                Alex               Smith    "Gender Studies"                  53              Amazon
   1                  Bo                Yang                  CS                  28           Microsoft
   2              Calvin                 Woo             Physics                  22                Uber
   3                 Flo                 Yao                  CS                  20              Google
Number of records: 4

[54] select * from employee where last > "Van Gogh"
_temp_employee27
                    last               first                 dep              salary                year

   0               "Yao"                 Flo                  CS              147000                2012
   1                Blow                 Joe                  CS              100000                2018
   2                Blow               JoAnn             Physics              200000                2016
   3             Jackson               "Flo"                Math              165000                2017
   4             Jackson                  Bo           Chemistry              130000                2011
   5             Johnson                Jack                  HR              150000                2014
   6             Johnson             "Jimmy"           Chemistry              140000                2018
   7             Johnson          "Mary Ann"                Math              165000                2014
   8             Johnson         "Billy Bob"             Physics              142000                2014
   9             Johnson               Billy           "Phys Ed"              102000                2014
  10                Yang                  Bo                  CS              160000                2013
  11                 Yao               Jimmy                Math              145000                2014
Number of records: 12

[55] select * from employee where first > Vincent
_temp_employee28
                    last               first                 dep              salary                year

Number of records: 0

[56] select * from employee where salary > 260000
_temp_employee29
                    last               first                 dep              salary                year

Number of records: 0


//. . . . . . . . . . . . . (Greater Than: Passed last item) . . . . . . . . . . . . . . . . . . . . .
[57] select * from student where age > 54
_temp_student30
                   fname               lname               major                 age             company

Number of records: 0

[58] select * from student where lname > Zoolander
_temp_student31
                   fname               lname               major                 age             company

Number of records: 0

[59] select * from employee where last > Zoolaner
_temp_employee32
                    last               first                 dep              salary                year

Number of records: 0

[60] select * from employee where first > Xu
_temp_employee33
                    last               first                 dep              salary                year

Number of records: 0


//.................
//:Greater Equal  :
//.................
[61] select * from student where lname >= Yang
_temp_student34
                   fname               lname               major                 age             company

   0                  Bo                Yang                  CS                  28           Microsoft
   1                 Flo                 Yao                  CS                  20              Google
Number of records: 2

[62] select * from student where fname >= "Sammuel L."
_temp_student35
                   fname               lname               major                 age             company

   0        "Sammuel L."             Jackson                  CS                  40                Uber
   1        "Teresa Mae"              Gowers           Chemistry                  22             Verizon
   2                Alex               Smith    "Gender Studies"                  53              Amazon
   3                  Bo                Yang                  CS                  28           Microsoft
   4              Calvin                 Woo             Physics                  22                Uber
   5                 Flo                 Yao                  CS                  20              Google
Number of records: 6

[63] select * from student where age >= 40
_temp_student36
                   fname               lname               major                 age             company

   0        "Sammuel L."             Jackson                  CS                  40                Uber
   1                Alex               Smith    "Gender Studies"                  53              Amazon
Number of records: 2

//. . . . . .  (Greater Equal non-existing: ) . . . . . . . . . . .
[64] select * from employee where last >= Jack
_temp_employee37
                    last               first                 dep              salary                year

Number of records: 0

[65] select * from employee where first >= Bill
_temp_employee38
                    last               first                 dep              salary                year

Number of records: 0

[66] select * from employee where salary >= 235000
_temp_employee39
                    last               first                 dep              salary                year

Number of records: 0



//.................
//:Less Than      :
//.................


//. . . . . . . . . . . . . (Less Than: Non-existing) . . . . . . . . . . . . . . . . . . . . .
[67] select * from student where lname < Jackson
_temp_student40
                   fname               lname               major                 age             company

   0        "Anna Grace"           "Del Rio"                  CS                  22                USAF
   1               "Flo"           "Jackson"                Math                  21              Google
   2              "Greg"           "Pearson"             Physics                  20              Amazon
   3        "Teresa Mae"              Gowers           Chemistry                  22             Verizon
Number of records: 4

[68] select * from student where major < Math
_temp_student41
                   fname               lname               major                 age             company

   0                Alex               Smith    "Gender Studies"                  53              Amazon
   1                 Flo                 Yao                  CS                  20              Google
   2                  Bo                Yang                  CS                  28           Microsoft
   3        "Sammuel L."             Jackson                  CS                  40                Uber
   4        "Anna Grace"           "Del Rio"                  CS                  22                USAF
   5        "Teresa Mae"              Gowers           Chemistry                  22             Verizon
Number of records: 6

[69] select * from student where fname < "Jim Bob"
_temp_student42
                   fname               lname               major                 age             company

   0        "Anna Grace"           "Del Rio"                  CS                  22                USAF
   1               "Flo"           "Jackson"                Math                  21              Google
   2              "Greg"           "Pearson"             Physics                  20              Amazon
Number of records: 3

[70] select * from employee where salary < 200000
_temp_employee43
                    last               first                 dep              salary                year

   0                Blow                 Joe                  CS              100000                2018
   1             Johnson               Billy           "Phys Ed"              102000                2014
   2             Jackson                  Bo           Chemistry              130000                2011
   3             Johnson             "Jimmy"           Chemistry              140000                2018
   4             Johnson         "Billy Bob"             Physics              142000                2014
   5                 Yao               Jimmy                Math              145000                2014
   6               "Yao"                 Flo                  CS              147000                2012
   7             Johnson                Jack                  HR              150000                2014
   8                Yang                  Bo                  CS              160000                2013
   9             Jackson               "Flo"                Math              165000                2017
  10             Johnson          "Mary Ann"                Math              165000                2014
  11           "Jackson"               Billy                Math              170000                2017
Number of records: 12

[71] select * from employee where dep < CS
_temp_employee44
                    last               first                 dep              salary                year

   0             Johnson               Billy           "Phys Ed"              102000                2014
   1          "Van Gogh"           "Jim Bob"           "Phys Ed"              230000                2010
   2          "Van Gogh"             Vincent                 Art              240000                2015
Number of records: 3

[72] select * from employee where last < Jackson
_temp_employee45
                    last               first                 dep              salary                year

   0           "Jackson"               Billy                Math              170000                2017
   1          "Van Gogh"             Vincent                 Art              240000                2015
   2          "Van Gogh"             Vincent                  CS              245000                2015
   3          "Van Gogh"           "Jim Bob"           "Phys Ed"              230000                2010
   4               "Yao"                 Flo                  CS              147000                2012
   5                Blow                 Joe                  CS              100000                2018
   6                Blow               JoAnn             Physics              200000                2016
Number of records: 7

[73] select * from employee where first < "Billy Bob"
_temp_employee46
                    last               first                 dep              salary                year

Number of records: 0


//. . . . . . . . . . . . . (Less than: first item) . . . . . . . . . . . . . . . . . .
[74] select * from student where age  < 20
_temp_student47
                   fname               lname               major                 age             company

Number of records: 0

[75] select * from student where lname < "Del Rio"
_temp_student48
                   fname               lname               major                 age             company

Number of records: 0

[76] select * from student where fname < Alex
_temp_student49
                   fname               lname               major                 age             company

   0        "Anna Grace"           "Del Rio"                  CS                  22                USAF
   1               "Flo"           "Jackson"                Math                  21              Google
   2              "Greg"           "Pearson"             Physics                  20              Amazon
   3           "Jim Bob"               Smith                Math                  23             Verizon
   4        "Sammuel L."             Jackson                  CS                  40                Uber
   5        "Teresa Mae"              Gowers           Chemistry                  22             Verizon
Number of records: 6

[77] select * from employee where last < Blow
_temp_employee50
                    last               first                 dep              salary                year

   0           "Jackson"               Billy                Math              170000                2017
   1          "Van Gogh"             Vincent                 Art              240000                2015
   2          "Van Gogh"             Vincent                  CS              245000                2015
   3          "Van Gogh"           "Jim Bob"           "Phys Ed"              230000                2010
   4               "Yao"                 Flo                  CS              147000                2012
Number of records: 5

[78] select * from employee where first < Billy
_temp_employee51
                    last               first                 dep              salary                year

   0             Johnson         "Billy Bob"             Physics              142000                2014
   1             Jackson               "Flo"                Math              165000                2017
   2          "Van Gogh"           "Jim Bob"           "Phys Ed"              230000                2010
   3             Johnson             "Jimmy"           Chemistry              140000                2018
   4             Johnson          "Mary Ann"                Math              165000                2014
Number of records: 5

[79] select * from employee where salary < 100000
_temp_employee52
                    last               first                 dep              salary                year

Number of records: 0



//. . . . . . . . . . . . . (Less Than: before first item) . . . . . . . . . . . . . . . . . . . . .

[80] select * from student where age  < 19
_temp_student53
                   fname               lname               major                 age             company

Number of records: 0

[81] select * from student where lname < Adams
_temp_student54
                   fname               lname               major                 age             company

Number of records: 0

[82] select * from student where fname < Adam
_temp_student55
                   fname               lname               major                 age             company

Number of records: 0

[83] select * from employee where last < Alex
_temp_employee56
                    last               first                 dep              salary                year

Number of records: 0

[84] select * from employee where first < Avory
_temp_employee57
                    last               first                 dep              salary                year

Number of records: 0

[85] select * from employee where dep < Alchemy
_temp_employee58
                    last               first                 dep              salary                year

Number of records: 0



//.................
//:Less Equal     :
//.................

[86] select * from student where lname <= Smith
_temp_student59
                   fname               lname               major                 age             company

   0           "Jim Bob"               Smith                Math                  23             Verizon
   1                Alex               Smith    "Gender Studies"                  53              Amazon
   2        "Anna Grace"           "Del Rio"                  CS                  22                USAF
   3               "Flo"           "Jackson"                Math                  21              Google
   4              "Greg"           "Pearson"             Physics                  20              Amazon
   5        "Teresa Mae"              Gowers           Chemistry                  22             Verizon
   6        "Sammuel L."             Jackson                  CS                  40                Uber
Number of records: 7

[87] select * from student where fname <= Greg
_temp_student60
                   fname               lname               major                 age             company

Number of records: 0

[88] select * from student where age <= 40
_temp_student61
                   fname               lname               major                 age             company

   0        "Sammuel L."             Jackson                  CS                  40                Uber
   1                 Flo                 Yao                  CS                  20              Google
   2              "Greg"           "Pearson"             Physics                  20              Amazon
   3               "Flo"           "Jackson"                Math                  21              Google
   4              Calvin                 Woo             Physics                  22                Uber
   5        "Anna Grace"           "Del Rio"                  CS                  22                USAF
   6        "Teresa Mae"              Gowers           Chemistry                  22             Verizon
   7           "Jim Bob"               Smith                Math                  23             Verizon
   8                  Bo                Yang                  CS                  28           Microsoft
Number of records: 9


//. . . . . .  (Less Equal non-existing: ) . . . . . . . . . . .
[89] select * from employee where last <= Peach
_temp_employee62
                    last               first                 dep              salary                year

Number of records: 0

[90] select * from employee where first <= Gary
_temp_employee63
                    last               first                 dep              salary                year

Number of records: 0

[91] select * from employee where salary <= 23500
_temp_employee64
                    last               first                 dep              salary                year

Number of records: 0


//****************************************************************************
//		LOGICAL OPERATORS
//****************************************************************************


//.................
//:AND            :
//.................

[92] select * from student where fname = "Flo" and lname = "Yao"
_temp_student65
                   fname               lname               major                 age             company

Number of records: 0

[93] select * from student where major = "CS" and age < 25
_temp_student66
                   fname               lname               major                 age             company

Number of records: 0

[94] select * from student where major < Math and age > 25
_temp_student67
                   fname               lname               major                 age             company

Number of records: 0

[95] select * from employee where dep = CS and salary > 150000
_temp_employee68
                    last               first                 dep              salary                year

   0                Yang                  Bo                  CS              160000                2013
   1          "Van Gogh"             Vincent                  CS              245000                2015
Number of records: 2

[96] select * from employee where last = Jackson and year < 2015
_temp_employee69
                    last               first                 dep              salary                year

   0             Jackson                  Bo           Chemistry              130000                2011
Number of records: 1

[97] select * from employee where last = Johnson and year >=2014
_temp_employee70
                    last               first                 dep              salary                year

   0             Johnson                Jack                  HR              150000                2014
   1             Johnson             "Jimmy"           Chemistry              140000                2018
   2             Johnson          "Mary Ann"                Math              165000                2014
   3             Johnson         "Billy Bob"             Physics              142000                2014
   4             Johnson               Billy           "Phys Ed"              102000                2014
Number of records: 5



//.................
//:OR            :
//.................
[98] select * from student where fname = Flo or lname = Jackson
_temp_student71
                   fname               lname               major                 age             company

   0                 Flo                 Yao                  CS                  20              Google
   1        "Sammuel L."             Jackson                  CS                  40                Uber
Number of records: 2

[99] select * from student where age >=40  or company = Verizon
_temp_student72
                   fname               lname               major                 age             company

   0        "Sammuel L."             Jackson                  CS                  40                Uber
   1           "Jim Bob"               Smith                Math                  23             Verizon
   2        "Teresa Mae"              Gowers           Chemistry                  22             Verizon
   3                Alex               Smith    "Gender Studies"                  53              Amazon
Number of records: 4

[100] select * from employee where first = Bo or last = Johnson
_temp_employee73
                    last               first                 dep              salary                year

   0             Johnson                Jack                  HR              150000                2014
   1             Johnson             "Jimmy"           Chemistry              140000                2018
   2                Yang                  Bo                  CS              160000                2013
   3             Jackson                  Bo           Chemistry              130000                2011
   4             Johnson          "Mary Ann"                Math              165000                2014
   5             Johnson         "Billy Bob"             Physics              142000                2014
   6             Johnson               Billy           "Phys Ed"              102000                2014
Number of records: 7

[101] select * from employee where year >= 2015 or dep = CS
_temp_employee74
                    last               first                 dep              salary                year

   0                Blow                 Joe                  CS              100000                2018
   1                Blow               JoAnn             Physics              200000                2016
   2             Johnson             "Jimmy"           Chemistry              140000                2018
   3               "Yao"                 Flo                  CS              147000                2012
   4                Yang                  Bo                  CS              160000                2013
   5             Jackson               "Flo"                Math              165000                2017
   6           "Jackson"               Billy                Math              170000                2017
   7          "Van Gogh"             Vincent                 Art              240000                2015
   8          "Van Gogh"             Vincent                  CS              245000                2015
Number of records: 9



//.................
//:OR AND         :
//.................
[102] select * from student where fname = Flo or major = CS and age <= 23
_temp_student75
                   fname               lname               major                 age             company

   0                 Flo                 Yao                  CS                  20              Google
   1        "Anna Grace"           "Del Rio"                  CS                  22                USAF
Number of records: 2

[103] select * from student where lname = Jackson or age < 23 and company > Uber
_temp_student76
                   fname               lname               major                 age             company

   0        "Sammuel L."             Jackson                  CS                  40                Uber
   1        "Teresa Mae"              Gowers           Chemistry                  22             Verizon
Number of records: 2

[104] select * from employee where last = "Van Gogh" or last = Jackson and salary >= 165000
_temp_employee77
                    last               first                 dep              salary                year

   0             Jackson               "Flo"                Math              165000                2017
   1          "Van Gogh"             Vincent                 Art              240000                2015
   2          "Van Gogh"             Vincent                  CS              245000                2015
   3          "Van Gogh"           "Jim Bob"           "Phys Ed"              230000                2010
Number of records: 4



//.................
//:AND OR AND     :
//.................

[105] select * from student where age <30 and major=CS or major = Physics and company = Amazon
_temp_student78
                   fname               lname               major                 age             company

   0              "Greg"           "Pearson"             Physics                  20              Amazon
Number of records: 1

[106] select * from student where age <=40 and company=Uber or major = CS and company = Google
_temp_student79
                   fname               lname               major                 age             company

   0                 Flo                 Yao                  CS                  20              Google
   1        "Sammuel L."             Jackson                  CS                  40                Uber
   2              Calvin                 Woo             Physics                  22                Uber
Number of records: 3

[107] select * from employee where dep = CS and salary >= 160000 or year > 2014 and last = "Van Gogh"
_temp_employee80
                    last               first                 dep              salary                year

   0                Yang                  Bo                  CS              160000                2013
   1          "Van Gogh"             Vincent                 Art              240000                2015
   2          "Van Gogh"             Vincent                  CS              245000                2015
Number of records: 3



//.................
//:OR AND OR      :
//.................

[108] select * from student where lname = Yang or major = CS and age < 23 or company = Google
_temp_student81
                   fname               lname               major                 age             company

   0                 Flo                 Yao                  CS                  20              Google
   1                  Bo                Yang                  CS                  28           Microsoft
   2               "Flo"           "Jackson"                Math                  21              Google
   3        "Anna Grace"           "Del Rio"                  CS                  22                USAF
Number of records: 4

[109] select * from student where major = Physics or major = Math and company = Google or lname = Jackson
_temp_student82
                   fname               lname               major                 age             company

   0        "Sammuel L."             Jackson                  CS                  40                Uber
   1               "Flo"           "Jackson"                Math                  21              Google
   2              "Greg"           "Pearson"             Physics                  20              Amazon
   3              Calvin                 Woo             Physics                  22                Uber
Number of records: 4

[110] select * from employee where dep = CS or year >2014 and year < 2018 or salary >= 265000
_temp_employee83
                    last               first                 dep              salary                year

   0                Blow                 Joe                  CS              100000                2018
   1                Blow               JoAnn             Physics              200000                2016
   2               "Yao"                 Flo                  CS              147000                2012
   3                Yang                  Bo                  CS              160000                2013
   4             Jackson               "Flo"                Math              165000                2017
   5           "Jackson"               Billy                Math              170000                2017
   6          "Van Gogh"             Vincent                 Art              240000                2015
   7          "Van Gogh"             Vincent                  CS              245000                2015
Number of records: 8











> delete from employee where last = Johnson or last = Blow
> select * from employee
_temp_employee84
                    last               first                 dep              salary                year

   0                 Yao               Jimmy                Math              145000                2014
   1               "Yao"                 Flo                  CS              147000                2012
   2                Yang                  Bo                  CS              160000                2013
   3             Jackson               "Flo"                Math              165000                2017
   4             Jackson                  Bo           Chemistry              130000                2011
   5           "Jackson"               Billy                Math              170000                2017
   6          "Van Gogh"             Vincent                 Art              240000                2015
   7          "Van Gogh"             Vincent                  CS              245000                2015
   8          "Van Gogh"           "Jim Bob"           "Phys Ed"              230000                2010
Number of records: 9

> delete from employee where salary <= 170000
> select * from employee
_temp_employee85
                    last               first                 dep              salary                year

   0          "Van Gogh"             Vincent                 Art              240000                2015
   1          "Van Gogh"             Vincent                  CS              245000                2015
   2          "Van Gogh"           "Jim Bob"           "Phys Ed"              230000                2010
Number of records: 3

> exit

Process finished with exit code 0



//=========================================================
// B+Tree demonstration
//=========================================================
Inserting numbers 1 through 200:
                                                                                   [199, 200]
                                                                       [198, 199]
                                                                                   [198]
                                                                                   [197]
                                                           [195, 197]
                                                                                   [196]
                                                                       [196]
                                                                                   [195]
                                                                                   [194]
                                                                       [194]
                                                                                   [193]
                                               [189, 193]
                                                                                   [192]
                                                                       [192]
                                                                                   [191]
                                                           [191]
                                                                                   [190]
                                                                       [190]
                                                                                   [189]
                                                                                   [188]
                                                                       [188]
                                                                                   [187]
                                                           [187]
                                                                                   [186]
                                                                       [186]
                                                                                   [185]
                                   [185]
                                                                                   [184]
                                                                       [184]
                                                                                   [183]
                                                           [183]
                                                                                   [182]
                                                                       [182]
                                                                                   [181]
                                               [181]
                                                                                   [180]
                                                                       [180]
                                                                                   [179]
                                                           [179]
                                                                                   [178]
                                                                       [178]
                                                                                   [177]
                       [177]
                                                                                   [176]
                                                                       [176]
                                                                                   [175]
                                                           [175]
                                                                                   [174]
                                                                       [174]
                                                                                   [173]
                                               [173]
                                                                                   [172]
                                                                       [172]
                                                                                   [171]
                                                           [171]
                                                                                   [170]
                                                                       [170]
                                                                                   [169]
                                   [169]
                                                                                   [168]
                                                                       [168]
                                                                                   [167]
                                                           [167]
                                                                                   [166]
                                                                       [166]
                                                                                   [165]
                                               [165]
                                                                                   [164]
                                                                       [164]
                                                                                   [163]
                                                           [163]
                                                                                   [162]
                                                                       [162]
                                                                                   [161]
           [161]
                                                                                   [160]
                                                                       [160]
                                                                                   [159]
                                                           [159]
                                                                                   [158]
                                                                       [158]
                                                                                   [157]
                                               [157]
                                                                                   [156]
                                                                       [156]
                                                                                   [155]
                                                           [155]
                                                                                   [154]
                                                                       [154]
                                                                                   [153]
                                   [153]
                                                                                   [152]
                                                                       [152]
                                                                                   [151]
                                                           [151]
                                                                                   [150]
                                                                       [150]
                                                                                   [149]
                                               [149]
                                                                                   [148]
                                                                       [148]
                                                                                   [147]
                                                           [147]
                                                                                   [146]
                                                                       [146]
                                                                                   [145]
                       [145]
                                                                                   [144]
                                                                       [144]
                                                                                   [143]
                                                           [143]
                                                                                   [142]
                                                                       [142]
                                                                                   [141]
                                               [141]
                                                                                   [140]
                                                                       [140]
                                                                                   [139]
                                                           [139]
                                                                                   [138]
                                                                       [138]
                                                                                   [137]
                                   [137]
                                                                                   [136]
                                                                       [136]
                                                                                   [135]
                                                           [135]
                                                                                   [134]
                                                                       [134]
                                                                                   [133]
                                               [133]
                                                                                   [132]
                                                                       [132]
                                                                                   [131]
                                                           [131]
                                                                                   [130]
                                                                       [130]
                                                                                   [129]
[65, 129]
                                                                                   [128]
                                                                       [128]
                                                                                   [127]
                                                           [127]
                                                                                   [126]
                                                                       [126]
                                                                                   [125]
                                               [125]
                                                                                   [124]
                                                                       [124]
                                                                                   [123]
                                                           [123]
                                                                                   [122]
                                                                       [122]
                                                                                   [121]
                                   [121]
                                                                                   [120]
                                                                       [120]
                                                                                   [119]
                                                           [119]
                                                                                   [118]
                                                                       [118]
                                                                                   [117]
                                               [117]
                                                                                   [116]
                                                                       [116]
                                                                                   [115]
                                                           [115]
                                                                                   [114]
                                                                       [114]
                                                                                   [113]
                       [113]
                                                                                   [112]
                                                                       [112]
                                                                                   [111]
                                                           [111]
                                                                                   [110]
                                                                       [110]
                                                                                   [109]
                                               [109]
                                                                                   [108]
                                                                       [108]
                                                                                   [107]
                                                           [107]
                                                                                   [106]
                                                                       [106]
                                                                                   [105]
                                   [105]
                                                                                   [104]
                                                                       [104]
                                                                                   [103]
                                                           [103]
                                                                                   [102]
                                                                       [102]
                                                                                   [101]
                                               [101]
                                                                                   [100]
                                                                       [100]
                                                                                   [99]
                                                           [99]
                                                                                   [98]
                                                                       [98]
                                                                                   [97]
           [97]
                                                                                   [96]
                                                                       [96]
                                                                                   [95]
                                                           [95]
                                                                                   [94]
                                                                       [94]
                                                                                   [93]
                                               [93]
                                                                                   [92]
                                                                       [92]
                                                                                   [91]
                                                           [91]
                                                                                   [90]
                                                                       [90]
                                                                                   [89]
                                   [89]
                                                                                   [88]
                                                                       [88]
                                                                                   [87]
                                                           [87]
                                                                                   [86]
                                                                       [86]
                                                                                   [85]
                                               [85]
                                                                                   [84]
                                                                       [84]
                                                                                   [83]
                                                           [83]
                                                                                   [82]
                                                                       [82]
                                                                                   [81]
                       [81]
                                                                                   [80]
                                                                       [80]
                                                                                   [79]
                                                           [79]
                                                                                   [78]
                                                                       [78]
                                                                                   [77]
                                               [77]
                                                                                   [76]
                                                                       [76]
                                                                                   [75]
                                                           [75]
                                                                                   [74]
                                                                       [74]
                                                                                   [73]
                                   [73]
                                                                                   [72]
                                                                       [72]
                                                                                   [71]
                                                           [71]
                                                                                   [70]
                                                                       [70]
                                                                                   [69]
                                               [69]
                                                                                   [68]
                                                                       [68]
                                                                                   [67]
                                                           [67]
                                                                                   [66]
                                                                       [66]
                                                                                   [65]
                                                                                   [64]
                                                                       [64]
                                                                                   [63]
                                                           [63]
                                                                                   [62]
                                                                       [62]
                                                                                   [61]
                                               [61]
                                                                                   [60]
                                                                       [60]
                                                                                   [59]
                                                           [59]
                                                                                   [58]
                                                                       [58]
                                                                                   [57]
                                   [57]
                                                                                   [56]
                                                                       [56]
                                                                                   [55]
                                                           [55]
                                                                                   [54]
                                                                       [54]
                                                                                   [53]
                                               [53]
                                                                                   [52]
                                                                       [52]
                                                                                   [51]
                                                           [51]
                                                                                   [50]
                                                                       [50]
                                                                                   [49]
                       [49]
                                                                                   [48]
                                                                       [48]
                                                                                   [47]
                                                           [47]
                                                                                   [46]
                                                                       [46]
                                                                                   [45]
                                               [45]
                                                                                   [44]
                                                                       [44]
                                                                                   [43]
                                                           [43]
                                                                                   [42]
                                                                       [42]
                                                                                   [41]
                                   [41]
                                                                                   [40]
                                                                       [40]
                                                                                   [39]
                                                           [39]
                                                                                   [38]
                                                                       [38]
                                                                                   [37]
                                               [37]
                                                                                   [36]
                                                                       [36]
                                                                                   [35]
                                                           [35]
                                                                                   [34]
                                                                       [34]
                                                                                   [33]
           [33]
                                                                                   [32]
                                                                       [32]
                                                                                   [31]
                                                           [31]
                                                                                   [30]
                                                                       [30]
                                                                                   [29]
                                               [29]
                                                                                   [28]
                                                                       [28]
                                                                                   [27]
                                                           [27]
                                                                                   [26]
                                                                       [26]
                                                                                   [25]
                                   [25]
                                                                                   [24]
                                                                       [24]
                                                                                   [23]
                                                           [23]
                                                                                   [22]
                                                                       [22]
                                                                                   [21]
                                               [21]
                                                                                   [20]
                                                                       [20]
                                                                                   [19]
                                                           [19]
                                                                                   [18]
                                                                       [18]
                                                                                   [17]
                       [17]
                                                                                   [16]
                                                                       [16]
                                                                                   [15]
                                                           [15]
                                                                                   [14]
                                                                       [14]
                                                                                   [13]
                                               [13]
                                                                                   [12]
                                                                       [12]
                                                                                   [11]
                                                           [11]
                                                                                   [10]
                                                                       [10]
                                                                                   [9]
                                   [9]
                                                                                   [8]
                                                                       [8]
                                                                                   [7]
                                                           [7]
                                                                                   [6]
                                                                       [6]
                                                                                   [5]
                                               [5]
                                                                                   [4]
                                                                       [4]
                                                                                   [3]
                                                           [3]
                                                                                   [2]
                                                                       [2]
                                                                                   [1]

========================================================
Tree is valid: 1
========================================================
Printing leaves using Iterator:
[1]
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
[17]
[18]
[19]
[20]
[21]
[22]
[23]
[24]
[25]
[26]
[27]
[28]
[29]
[30]
[31]
[32]
[33]
[34]
[35]
[36]
[37]
[38]
[39]
[40]
[41]
[42]
[43]
[44]
[45]
[46]
[47]
[48]
[49]
[50]
[51]
[52]
[53]
[54]
[55]
[56]
[57]
[58]
[59]
[60]
[61]
[62]
[63]
[64]
[65]
[66]
[67]
[68]
[69]
[70]
[71]
[72]
[73]
[74]
[75]
[76]
[77]
[78]
[79]
[80]
[81]
[82]
[83]
[84]
[85]
[86]
[87]
[88]
[89]
[90]
[91]
[92]
[93]
[94]
[95]
[96]
[97]
[98]
[99]
[100]
[101]
[102]
[103]
[104]
[105]
[106]
[107]
[108]
[109]
[110]
[111]
[112]
[113]
[114]
[115]
[116]
[117]
[118]
[119]
[120]
[121]
[122]
[123]
[124]
[125]
[126]
[127]
[128]
[129]
[130]
[131]
[132]
[133]
[134]
[135]
[136]
[137]
[138]
[139]
[140]
[141]
[142]
[143]
[144]
[145]
[146]
[147]
[148]
[149]
[150]
[151]
[152]
[153]
[154]
[155]
[156]
[157]
[158]
[159]
[160]
[161]
[162]
[163]
[164]
[165]
[166]
[167]
[168]
[169]
[170]
[171]
[172]
[173]
[174]
[175]
[176]
[177]
[178]
[179]
[180]
[181]
[182]
[183]
[184]
[185]
[186]
[187]
[188]
[189]
[190]
[191]
[192]
[193]
[194]
[195]
[196]
[197]
[198]
[199]
[200]
========================================================
Find 10 values that are in the tree:
83 was found
191 was found
38 was found
35 was found
104 was found
16 was found
128 was found
21 was found
100 was found
156 was found
========================================================
Find 10 values that are not in the tree:
599 was not found
576 was not found
535 was not found
614 was not found
661 was not found
617 was not found
680 was not found
637 was not found
565 was not found
642 was not found
========================================================
Removing some values from the tree:
Removing 100
Removing 191
Removing 9
Removing 95
Removing 142
Removing 128
Removing 108
Removing 172
Removing 168
Removing 146
Removing 157
Removing 70
Removing 29
Removing 29
Removing 17
Removing 46
Removing 49
Removing 176
Removing 14
Removing 1
Removing 178
Removing 8
Removing 160
Removing 190
Removing 177
Removing 118
Removing 177
Removing 181
Removing 45
Removing 17
Removing 173
Removing 106
Removing 153
Removing 156
Removing 52
Removing 93
Removing 116
Removing 200
Removing 174
Removing 172
Removing 135
Removing 142
Removing 80
Removing 77
Removing 170
Removing 2
Removing 67
Removing 54
Removing 45
Removing 110
                                                                       [199]
                                                           [198, 199]
                                                                       [198]
                                                                       [197]
                                               [197]
                                                                       [196]
                                                           [196]
                                                                       [195]
                                   [195]
                                                                       [194]
                                                           [194]
                                                                       [193]
                                               [193]
                                                                       [192]
                                                           [192]
                                                                       [189]
                       [189]
                                                                       [188]
                                                           [188]
                                                                       [187]
                                               [187]
                                                                       [186]
                                                           [186]
                                                                       [185]
                                   [185]
                                                                       [184]
                                                           [184]
                                                                       [183]
                                               [183]
                                                                       [182]
                                                           [180, 181]
                                                                       [180]
                                                                       [179]
           [179]
                                                                       [175]
                                                           [174]
                                                                       [171]
                                               [167, 171]
                                                                       [169]
                                                           [169]
                                                                       [167]
                                                                       [166]
                                                           [166]
                                                                       [165]
                                   [161, 165]
                                                                       [164]
                                                           [164]
                                                                       [163]
                                               [163]
                                                                       [162]
                                                           [162]
                                                                       [161]
                                                                       [159]
                                                           [159]
                                                                       [158]
                                               [157]
                                                                       [155]
                                                           [155]
                                                                       [154]
                       [154]
                                                                       [152]
                                                           [152]
                                                                       [151]
                                               [149, 151]
                                                                       [150]
                                                           [150]
                                                                       [149]
                                                                       [148]
                                                           [147, 148]
                                                                       [147]
                                                                       [145]
                                   [137, 145]
                                                                       [144]
                                                           [143, 144]
                                                                       [143]
                                                                       [141]
                                               [139, 141]
                                                                       [140]
                                                           [140]
                                                                       [139]
                                                                       [138]
                                                           [138]
                                                                       [137]
                                                                       [136]
                                                           [134, 135]
                                                                       [134]
                                                                       [133]
                                               [131, 133]
                                                                       [132]
                                                           [132]
                                                                       [131]
                                                                       [130]
                                                           [130]
                                                                       [129]
[65, 129]
                                                                       [127]
                                                           [126, 127]
                                                                       [126]
                                                                       [125]
                                               [125]
                                                                       [124]
                                                           [124]
                                                                       [123]
                                   [123]
                                                                       [122]
                                                           [122]
                                                                       [121]
                                               [117, 121]
                                                                       [120]
                                                           [119, 120]
                                                                       [119]
                                                                       [117]
                                                                       [115]
                                                           [114, 115]
                                                                       [114]
                                                                       [113]
                       [113]
                                                                       [112]
                                                           [111, 112]
                                                                       [111]
                                                                       [109]
                                               [105, 109]
                                                                       [107]
                                                           [107]
                                                                       [105]
                                                                       [104]
                                                           [104]
                                                                       [103]
                                   [103]
                                                                       [102]
                                                           [102]
                                                                       [101]
                                               [101]
                                                                       [99]
                                                           [98, 99]
                                                                       [98]
                                                                       [97]
           [97]
                                                                       [96]
                                                           [95]
                                                                       [94]
                                               [91, 94]
                                                                       [92]
                                                           [92]
                                                                       [91]
                                                                       [90]
                                                           [90]
                                                                       [89]
                                   [85, 89]
                                                                       [88]
                                                           [88]
                                                                       [87]
                                               [87]
                                                                       [86]
                                                           [86]
                                                                       [85]
                                                                       [84]
                                                           [84]
                                                                       [83]
                                               [83]
                                                                       [82]
                                                           [82]
                                                                       [81]
                       [81]
                                                                       [79]
                                                           [79]
                                                                       [78]
                                               [75, 78]
                                                                       [76]
                                                           [76]
                                                                       [75]
                                                                       [74]
                                                           [74]
                                                                       [73]
                                   [73]
                                                                       [72]
                                                           [72]
                                                                       [71]
                                               [68, 71]
                                                                       [69]
                                                           [69]
                                                                       [68]
                                                                       [66]
                                                           [66]
                                                                       [65]
                                                                       [64]
                                                           [64]
                                                                       [63]
                                               [63]
                                                                       [62]
                                                           [62]
                                                                       [61]
                                   [57, 61]
                                                                       [60]
                                                           [60]
                                                                       [59]
                                               [59]
                                                                       [58]
                                                           [58]
                                                                       [57]
                                                                       [56]
                                                           [56]
                                                                       [55]
                                               [55]
                                                                       [53]
                                                           [51, 53]
                                                                       [51]
                                                                       [50]
                       [49]
                                                                       [48]
                                                           [48]
                                                                       [47]
                                               [43, 47]
                                                                       [44]
                                                           [44]
                                                                       [43]
                                                                       [42]
                                                           [42]
                                                                       [41]
                                   [37, 41]
                                                                       [40]
                                                           [40]
                                                                       [39]
                                               [39]
                                                                       [38]
                                                           [38]
                                                                       [37]
                                                                       [36]
                                                           [36]
                                                                       [35]
                                               [35]
                                                                       [34]
                                                           [34]
                                                                       [33]
           [33]
                                                                       [32]
                                                           [31, 32]
                                                                       [31]
                                                                       [30]
                                               [27, 30]
                                                                       [28]
                                                           [28]
                                                                       [27]
                                                                       [26]
                                                           [26]
                                                                       [25]
                                   [25]
                                                                       [24]
                                                           [24]
                                                                       [23]
                                               [21, 23]
                                                                       [22]
                                                           [22]
                                                                       [21]
                                                                       [20]
                                                           [19, 20]
                                                                       [19]
                                                                       [18]
                       [18]
                                                                       [16]
                                                           [16]
                                                                       [15]
                                               [12, 15]
                                                                       [13]
                                                           [13]
                                                                       [12]
                                                                       [11]
                                                           [11]
                                                                       [10]
                                   [9]
                                                                       [7]
                                                           [6, 7]
                                                                       [6]
                                                                       [5]
                                               [5]
                                                                       [4]
                                                           [4]
                                                                       [3]

========================================================
Clearing the tree:
[]

========================================================
End of test
========================================================

Process finished with exit code 0



//=========================================================
// MultiMap demonstration
// I couldn't run the main.cpp on the assignment page, so
// here I am submitting my MMap tests
//=========================================================
Inserting 50 random pairs of <int, <char> >:
                                   [(13,<W,V,V>), (14,<I,X>)]
                       [(13,<W>)]
                                   [(11,<H,S,Y,L,R,P,L,E>), (12,<Q,U,R,W>)]
           [(11,<H,S>)]
                                   [(9,<J,L,K,C,Y,V>), (10,<I,X,T>)]
                       [(7,<R>), (9,<J>)]
                                   [(7,<R>), (8,<T,H,O>)]
                                   [(6,<V,S,N,J,P>)]
[(6,<V>)]
                                   [(4,<C,W,K>), (5,<W,G>)]
                       [(4,<C,W,K>)]
                                   [(3,<W,V,N,A>)]
           [(3,<W,V>)]
                                   [(1,<C,J>), (2,<T,P>)]
                       [(1,<C>)]
                                   [(0,<Z,K>)]


========================================================
mmap is valid: 1
========================================================
Printing leaves using Iterator:
[(0,<Z,K>)]
[(1,<C,J>)]
[(2,<T,P>)]
[(3,<W,V,N,A>)]
[(4,<C,W,K>)]
[(5,<W,G>)]
[(6,<V,S,N,J,P>)]
[(7,<R>)]
[(8,<T,H,O>)]
[(9,<J,L,K,C,Y,V>)]
[(10,<I,X,T>)]
[(11,<H,S,Y,L,R,P,L,E>)]
[(12,<Q,U,R,W>)]
[(13,<W,V,V>)]
[(14,<I,X>)]
========================================================
Find 5 keys that are in the mmap:
12 was found
11 was found
6 was found
3 was found
13 was found
========================================================
Find 5 keys that are not in the mmap:
20 was not found
21 was not found
22 was not found
23 was not found
24 was not found
========================================================
Removing all keys from the mmap:
                                   [(13,<W,V,V>), (14,<I,X>)]
                       [(13,<W>)]
                                   [(11,<H,S,Y,L,R,P,L,E>), (12,<Q,U,R,W>)]
           [(11,<H,S>)]
                                   [(9,<J,L,K,C,Y,V>), (10,<I,X,T>)]
                       [(7,<R>), (9,<J>)]
                                   [(7,<R>), (8,<T,H,O>)]
                                   [(6,<V,S,N,J,P>)]
[(6,<V>)]
                                   [(4,<C,W,K>), (5,<W,G>)]
                       [(4,<C,W,K>)]
                                   [(3,<W,V,N,A>)]
           [(3,<W,V>)]
                                   [(1,<C,J>), (2,<T,P>)]
                       [(1,<C>)]
                                   [(0,<Z,K>)]


Removing 0
Removing 1
Removing 2
Removing 3
Removing 4
Removing 5
Removing 6
Removing 7
Removing 8
Removing 9
Removing 10
Removing 11
Removing 12
Removing 13
Removing 14
[]


========================================================
End of test
========================================================

Process finished with exit code 0

*/

#endif //DATABASE_Z_OUTPUT_H
