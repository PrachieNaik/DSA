/*

Implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.

Assuption: String will never be null, Do not contain white spaces in start or end, integer will never overflow.

Edge cases: Negative numbers, Non-numeric characters in string. 

*/


int atoi(string str)
{
    int answer = 0;
    int i = 0;
    bool neg = false;
    if(str[i] == '-') {
        neg = true;
        i++;
    }
    for(; i < str.length(); i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            answer *= 10;
            answer += str[i] - '0';
        } else {
            return -1;
        }
    }
    if(neg) {
        answer *= -1;
    }
    return answer;
}
