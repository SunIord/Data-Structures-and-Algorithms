#include <stdio.h>
#include <stdlib.h>

int main() {
    int totalVotes;
    scanf("%d", &totalVotes);
    
    int *votesCount = (int*)calloc(5, sizeof(int));
    
    for (int i = 0; i < totalVotes; i++) {
        int vote;
        scanf("%d", &vote);
        
        if (vote >= 1 && vote <= 5) {
            votesCount[vote - 1]++;
        }
    }
    
    for (int i = 0; i < 5; i++) {
        printf("%d\n", votesCount[i]);
    }
    
    free(votesCount);
    
    return 0;
}