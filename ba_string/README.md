# coding_questions
coding questions
You are given a string S consisting of letters 'a' and 'b'.
You want to split it into three seperate non empty parts.
The length of each part can differ from one another.

In how many ways you can split S into three parts, 
such that each part contains the same number of letters 'a' ? 

//function defenition in C
int solution(char* S);

//examples
1. Given S = "babaa", the function should return 2. 
the possible splits are: 
	-	ba | ba | a
	-	bab | a | a

2. Given S = "ababa", the function should return 4.
the possible splits are: 
	-	a | ba | ba
	-	a | bab | a
	-	ab | a | ba
	-	ab | ba | a

3. Given S = "aba", the function should return 0.
it is not possible to split S are required.

4. Given S = "bbbbb", the function should return 6.
the possible splits are:
	-	b | b | bbb
	-	b | bb | bb
	-	b | bbb | b
	-	bb | b | bb
	-	bb | bb | b
	-	bbb | b | b
*Each part contains the same number of letters 'a', i.e 0.

