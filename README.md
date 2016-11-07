# C++ template type name pretty printer

Super simple and ugly coded quick and dirty tool that takes the printed name of a templated type (e.g., `vector<vector<int>>`)
and tries to pretty print the type name in order to make it more readable. The end of the input sequence is recognized by the first empty line.

* Compile: `g++ pretty.cpp -o pretty`
* Run: `./pretty`
* Example:
```cpp
[user@local]$ ./pretty
give me some templated type:
vector< vector < some_unreadable_type_name< nested<int>, nested<float>, nested<nested<char>>>>>


#####PRETTY PRINT BEGIN#####
vector <
	 vector  <
		 some_long_type_name <
			 nested <int>,
			 nested <float>,
			 nested <
				nested <char>
			>
		>
	>
>
#####PRETTY PRINT END#####
[user@local]$
```
