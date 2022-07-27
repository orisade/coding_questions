#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
#define DEBUG 0


int solution(string input);

int main(int argc, char* argv[]){

    //simulation
    pair<string,int> simulation[] = {pair<string,int>("babaa",2),
                                     pair<string,int>("ababa",4),
                                     pair<string,int>("aba",0),
                                     pair<string,int>("bbbbb",6)};


    for (pair<string,int>& item : simulation){
        
        int res = solution(item.first);
        string passed = (res == item.second) ? "PASSED" : "FAILED";

        string log_str = "%s! input: %-10s , output = %-5d, expected = %-5d\n";
        printf(log_str.c_str(), passed.c_str(), item.first.c_str(), res, item.second);        
        
    }

    return 0;
}

int recursive_solution(string input, int count_per_part, int part);
int calc_solution(string input, int count_per_part);

int solution(string input){
    //"babaa" -> 2
    //"bbbbb" -> 6
    
    //need to count number of "a"
    //each part will have to be with count/3 -> this will set our limits
    //only problem in case we have cout = 0, which is special case

    int a_count = std::count(input.begin(), input.end(), 'a');

    if (a_count% 3 != 0)
        return 0;

    if (a_count == 0)
        return recursive_solution(input, 0, 1);

    return calc_solution(input, a_count/3);
}


int calc_solution(string input, int count_per_part){
    int coeff[3] = {0,0,0};

    int count = 0, index=0;
    for(char &c : input){
        if (c == 'a'){
            count++;
            if(count > count_per_part){
                index++;
                count=1;
            }
        }
        
        if(count == count_per_part ){
            coeff[index]++;
        }
        
    }

    int cacluation = coeff[0] * coeff[1] * coeff[2];

    return cacluation;
}

int recursive_solution(string input, int count_per_part, int part){
    static string parts[3];
    if(part > 3)    //no more parts
        return 0;

    //"babaa" -> 2
    //"ababa" -> 4
    //"bbbbb" -> 6
    int count = 0;
    int res = 0;
    for(int i=0; i< input.length(); ++i){
        parts[part-1] = input.substr(0,i+1);
        if (input[i] == 'a')
            count++;

        if (count == count_per_part && i+1 < input.length()){
            if(DEBUG) cout << "send : " << input.substr(0,i+1) << ", part: " << part << " -> " << res << endl;
            res += recursive_solution(input.substr(i+1), count_per_part, part+1); 
        }

        else if (count == count_per_part && (i ==  (input.length()-1)) && (part==3))
            res++;

        if (count > count_per_part)
            break;
    }

    if(DEBUG) cout << "return : " << input << ", part: "<< part <<" -> " << res << ",";
    if(DEBUG) cout << "conmibnation = " << parts[0] << "|" << parts[1] << "|" << parts[2] << endl;
    return res;
}





