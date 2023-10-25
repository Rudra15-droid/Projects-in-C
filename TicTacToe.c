#include<stdio.h>
char table[3][3]={{'a','b','c'},{'d','e','f'},{'g','h','i'}};
void main(){
    int play=1;
    char player='O';
    while(play==1){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf(" | %c | ",table[i][j]);
        }      
        printf("\n");    
        printf("---------------");
        printf("\n");   
    }
    if(player=='X'){
        char choice;
        printf("X, Enter your choice: ");
        scanf("%c",&choice);
        getchar();
        switch (choice)
        {
        case 'a':
            table[0][0]=player;
            break;
        case 'b':
            table[0][1]=player;
            break;
        case 'c': 
            table[0][2]=player;
            break;
        case 'd':
            table[1][0]=player;
            break;
        case 'e':
            table[1][1]=player;
            break;
        case 'f':
            table[1][2]=player;
            break;
        case 'g':
            table[2][0]=player;
            break;
        case 'h':
            table[2][1]=player;
            break;
        case 'i':
            table[2][2]=player;
            break;
        default:
            printf("Error of player O");
        }
        player='O';
    }else if(player=='O'){
        char choice;
        printf("O, Enter your choice: ");
        scanf("%c", &choice);
        getchar(); // Consume newline
        switch (choice)
        {
        case 'a':
            table[0][0]=player;
            break;
        case 'b':
            table[0][1]=player;
            break;
        case 'c': 
            table[0][2]=player;
            break;
        case 'd':
            table[1][0]=player;
            break;
        case 'e':
            table[1][1]=player;
            break;
        case 'f':
            table[1][2]=player;
            break;
        case 'g':
            table[2][0]=player;
            break;
        case 'h':
            table[2][1]=player;
            break;
        case 'i':
            table[2][2]=player;
            break;
        default:
            printf("Error of player O");
        }
        player='X';
    }

    for(int i=0;i<3;i++){
        
            if(table[i][1]==table[i][2]&&table[i][1]==table[i][0]){
                for(int i=0;i<3;i++){
                     for(int j=0;j<3;j++){
                             printf("| %c |",table[i][j]);
                                        }      
                    printf("\n");    
                    printf("---------------");
                    printf("\n");   
    }
                printf("%c is the winner!",table[i][0]);
                play=0;
            }
            }

            for(int i=0;i<3;i++){
        
            if(table[1][i]==table[2][i]&&table[1][i]==table[0][i]){
                for(int i=0;i<3;i++){
                     for(int j=0;j<3;j++){
                             printf("| %c |",table[i][j]);
                                        }      
                    printf("\n");    
                    printf("---------------");
                    printf("\n");   
    }
                printf("%c is the winner!",table[1][i]);
                play=0;
            }
            }
        
        
            if(table[0][0]==table[1][1]&&table[1][1]==table[2][2]){
                for(int i=0;i<3;i++){
                     for(int j=0;j<3;j++){
                             printf("| %c |",table[i][j]);
                                        }      
                    printf("\n");    
                    printf("---------------");
                    printf("\n");   
    }
                printf("%c is the winner!",table[1][1]);
                play=0;
            }

            if(table[0][2]==table[1][1]&&table[2][0]==table[1][1]){
            
                for(int i=0;i<3;i++){
                     for(int j=0;j<3;j++){
                             printf("| %c |",table[i][j]);
                                        }      
                    printf("\n");    
                    printf("---------------");
                    printf("\n");   
                    }
                printf("%c is the winner!",table[1][1]);
                play=0;
            }
            
    }
}
