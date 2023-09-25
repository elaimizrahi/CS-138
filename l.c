 #include <string.h>
 #include <assert.h>
 #include <stdbool.h>
 #include <stdio.h>

bool isPalindrome(int a, int b, char *s, int len){
    int count = 0;
    for(int k = 0; k < len-a; k++){
        if(k+a < len || b-k > 0){
            if(s[k+a] == s[b-k]){
            count++;
            printf("%d", count);

        }
        }

    }
                printf("%d", count);

    if(count == b-a+1){
        return true;
    }
    return false;
 }

 bool is_semidrome(char *s){
    int len = strlen(s);
    int firstcount = 0;
    if(isPalindrome(3,5,s,len)){
    }



    int i = 0;
    if(len < 2){
        return false;
    }
    if(len == 2){
        if(s[0] == s[1]){
            return true;
        }
        return false;
    }

    for(int i = 0; i < len; i++){
        for(int j = len-1; j >= 0; j--){
        //if(isPalindrome(i,j,s) == true){
            while(s[i] == s[j]){
                if(isPalindrome(i,j,s,len)){
                    if(j == i){
                    return false;
                }              
                if(j == len-1){
                    return true;
                }
                i = j+1;
                j = len;
                }
            else{return false;}
            }    
        }
    }
    return false;
 }

 int main(void)
 {
assert(is_semidrome("popeye"));
assert(is_semidrome("racecar"));
 assert(is_semidrome("bab"));
 assert(!is_semidrome(""));
 assert(!is_semidrome("a"));
 assert(!is_semidrome("popeyeb"));
 assert(is_semidrome("pp"));
 assert(is_semidrome("bababaca"));
 assert(!is_semidrome("babbb"));
 assert(is_semidrome("popeye"));
    assert(!is_semidrome("popbeye"));
    assert(is_semidrome("popbbeye"));
    assert(!is_semidrome("popeyeb"));
    assert(is_semidrome("racecar"));
    assert(!is_semidrome("aab"));
    assert(is_semidrome("aba"));
    assert(is_semidrome("abba"));
    assert(!is_semidrome(""));
    assert(!is_semidrome("a"));
    assert(is_semidrome("aa"));
    assert(!is_semidrome("ab"));
    assert(is_semidrome("bababaca"));
 return 0;
 }
