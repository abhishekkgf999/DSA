/*
                                #LAMBDA FUNCTION

=>  C++ 11 introduced lambda expressions to allow inline functions which can be used for short snippets of 
    code that are not going to be reused and therefore do not require a name. In their simplest form a lambda 
    expression can be defined as follows:

//syntax 

[ capture_list ] (parameters) -> return-type  
    {   
        definition of method   
    } 

=>  Generally, the return-type in lambda expressions is evaluated by the compiler itself and we don’t need to specify 
    it explicitly. Also the -> return-type part can be ignored.  However, in some complex cases e.g. conditional statements, 
    the compiler can’t determine the return type and explicit specification is required.

=>  Capture List: Specifies which variables from the surrounding scope are accessible inside the lambda.

        [ ] : No variables are captured.
        [x, y] : Captures x and y by value.
        [&x, &y] : Captures x and y by reference.
        [=] : Captures all variables by value.
        [&] : Captures all variables by reference.
        [=, &x] : Captures all variables by value except x, which is captured by reference.
        [&, x] : Captures all variables by reference except x, which is captured by value.

=>  Parameter List: Specifies the parameters passed to the lambda function (optional). It follows the same syntax as regular 
    function parameters.

=>  Return Type: (Optional) Specifies the return type of the lambda. If omitted, the compiler infers it.

=>  Function Body: Contains the code to be executed when the lambda is called.



****When to Specify the Return Type:
Ambiguity:

=>  If the lambda has multiple return statements with different types, the compiler might fail to deduce the type or raise an error.

auto ambiguous = [](bool flag) {
    if (flag) return 1; // int
    else return 1.0;    // double (Error: inconsistent return types)
};

To fix this, specify the return type explicitly:

auto ambiguous = [](bool flag) -> double {
    if (flag) return 1; 
    else return 1.0; // Both are now treated as double
};

Readability:

=>  Explicit return types can make code easier to understand, especially in complex lambdas.

Special Cases:

For certain return types (like iterators or custom types), specifying the type explicitly can prevent unexpected behavior.

*/
#include<bits/stdc++.h>
using namespace std;

string longestPalindrome_ExpandAroundCenter(string s) {
        if(s.size() <= 1) return s;

        //Lambda function (Helper function)
        auto expand_from_center = [&](int left, int right){
            while(left >= 0 && right <s.length() && s[left] == s[right]){
                left--;
                right++;
            }
            return s.substr(left+1, right-left-1);
        };

        string max_str = s.substr(0,1);

        for(int i = 0; i<s.length(); i++){
            string odd = expand_from_center(i, i);
            string even = expand_from_center(i, i+1);

            if(odd.length() > max_str.length()){
                max_str = odd;
            }
            if(even.length() > max_str.length()){
                max_str = even;
            }
        }

        return max_str;
    }