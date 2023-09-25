 #include <stdio.h>
 #include <assert.h>
 #include <stdlib.h>
 #include <string.h>

int strappend(char *final, char *s, int a, int b, int count){
    for(int i = a; i < b; i++){
        final[count] = s[i];
        count++;
    }
    return count;
}




char* merge (char* s1, char* s2){
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    int totalcount = 0;
        
    char *final = (char*)calloc((length1+length2+1),sizeof(char));
    for(int i = 0; i < length1 + length2; i++){
        final[i] = 0;
    }    
    int length3 = (int)strlen(final);
    int count = 0;
    int wordcount = 0;

    for(int i = 0; i < length1; i++){
        if(s1[i] == 32){
            wordcount++;
        }
    }
        printf("wordcount:%d\n", s1[3]);

        
    for(int i = 0; i < length1; i++){
        if(s2[i] == 32){
            wordcount++;
        }
    }
        printf("wordcount:%d\n", wordcount);

    wordcount += 2;
    int index1 = 0;
    int index2 = 0;
    printf("wordcount:%d\n", wordcount);

    for(int i = 0; i < wordcount; i++){
        count++;
                        //printf("3:%d\n", count);

        if(count%2 == 1){
            int index3 = index1 + 1;
            if(index1 == 0){
                index3 = 0;
            }

            printf("ii31:%d\n", index3);
            printf("ii11:%d\n", index1);
            while(s1[index3] != 32 && index3 < length1 && s1[index3] != 0){
                printf("3:%d\n", index3);                index3++;

            }//
            if(s1[index3] == 0){
                totalcount = strappend(final, s1, index1, index3, totalcount);
                    for(int i = 0; i < length1+length2+1;i++){
        printf("t3: %d\n", final[i]);
    }
                //final[totalcount] = 32;
                printf("index1: %d\n", totalcount);
                totalcount++;
                //strappend(final, s1, index1, length1, totalcount+1);
                int count5 = 1;
                while(s2[index2-1] != 0){
                    final[totalcount] = s2[index2];
                    index2++;
                    totalcount++;
                    count5++;
                }
                final[totalcount-count5] = 32;
                    printf("%s\n", final);

                final[totalcount] = 0;
                    for(int k = 0; k < length1+length2+3;k++){
        printf("%d\n", final[k]);
    }
    printf("%s\n", final);
                return final;
            }     //      
            index3++;
            printf("total:%d\n", totalcount);

            totalcount = strappend(final, s1, index1, index3, totalcount);
            index1 = index3;
            printf("ii32:%d\n", index3);
            printf("ii12:%d\n", index1);


        }
        if(count%2 == 0){
            int index4 = index2 + 1;
            if(index2 == 0){
                index4 = 0;
            }
            printf("i4: %d\n", index4);

            while(s2[index4] != 32 && index4 < length2 && s2[index4] != 0){
                printf("4: %d\n", index4);
                //printf("s4: %d\n", s1[index4]);
                index4++;
            }
            printf("s4: %d\n", s2[index4]);
            printf("total:%d\n", totalcount);
            if(s2[index4] == 0){
                totalcount = strappend(final, s2, index2, index4, totalcount);
                    for(int i = 0; i < length1+length2+1;i++){
        printf("t4: %d\n", final[i]);
    }
                //final[totalcount] = 32;
                printf("index1: %d\n", totalcount);
                totalcount++;
                //strappend(final, s1, index1, length1, totalcount+1);
                int count5 = 1;
                while(s1[index1-1] != 0){
                    final[totalcount] = s1[index1];
                    index1++;
                    totalcount++;
                    count5++;
                }
                final[totalcount-count5] = 32;
                    printf("%s\n", final);

                final[totalcount] = 0;
                    for(int k = 0; k < length1+length2+3;k++){
        printf("%d\n", final[k]);
    }
    printf("%s\n", final);
                return final;
            }
            index4++;
            totalcount = strappend(final, s2, index2, index4, totalcount);

            index2 = index4;

        }

    }
    for(int i = 0; i < length1+length2;i++){
        printf("t: %d\n", final[i]);
    }
    return final;
}

 int main(void)
 {
 char s1[] = "The brown jumps the dog";
 char s2[] = "quick fox over lazy";

 char *s = merge(s1, s2);
 assert(!strcmp(s, "The quick brown fox jumps over the lazy dog"));
 free(s);

 char s3[] = "the brown";
 char s4[] = "quick fox is sleeping today";
 s = merge(s3,s4);
 assert(!strcmp(s, "the quick brown fox is sleeping today"));
 free(s);

 char* s5 = "happy to you";
 char* s6 = "birthday";
 s = merge(s5,s6);
 assert(!strcmp(s, "happy birthday to you"));
 free(s);

 return 0;
 }
