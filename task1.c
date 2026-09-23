


#include <stdio.h>


int scoreInput() 
{
    int Score;
    int result;
    int ch;
    while (1)
    {
        printf("Enter the NFL socre (Enter 1 to stop): ");
        result = scanf("%d", &Score);
        
        if (result == 1 && Score > 0)
        {
            return Score;
        }
        
        printf("Invalid input. Enter a positvie integer.\n");
        
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
    }
}

int main()
{
    int Score;
    
    while (1)
    {
    Score = scoreInput();
    
    if (Score == 1)
    {
        break;
    }
    
    printf("Possible combinations of scoring plays if a teams score is %d\n", Score);
    
        for (int TD2 = 0; TD2 <= Score / 8; TD2++){
            for (int TD1 = 0; TD1 <= Score / 7; TD1++){
                for (int TD = 0; TD <= Score / 6; TD++){
                    for (int FG = 0; FG <= Score/ 3; FG++){
                        for (int S = 0; S<= Score/2; S++){
                            if (8*TD2 + 7*TD1 + 6*TD + 3*FG + 2*S == Score){
                                printf("%d touchdown + 2pt, %d touchdown + 1pt, %d TD, %d FG, %d Safety\n",
                                TD2, TD1, TD, FG, S);
                            }
                        }
                    }
                }
            }
        }
    }
}
