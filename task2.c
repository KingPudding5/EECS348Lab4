#include <stdio.h>
#include <string.h>
#include <ctype.h>


float getTemp()
{
    float Temp;
    int result;
    int ch;

    while (1)
    {
        printf("Enter the temperature value: ");
        result = scanf("%f", &Temp);

        if (result == 1)
        {
            return Temp;
        }

        printf("Invalid input. Enter a number.\n");

        // Clear bad input from input buffer
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
    }
}


char getOriginalScale()
{
    char originalScale[100];
    int ch;

    while (1)
    {
        printf("Enter the original scale (C, F, or K): ");

        if (scanf("%99s", originalScale) == 1)
        {
            // Make first character uppercase
            originalScale[0] = toupper(originalScale[0]);

            // Make sure user only typed one character
            if (strlen(originalScale) == 1 &&
                (originalScale[0] == 'C' ||
                 originalScale[0] == 'F' ||
                 originalScale[0] == 'K'))
            {
                return originalScale[0];
            }
        }

        printf("Invalid input. Enter C, F, or K.\n");

        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
    }
}


char getNewScale()
{
    char newScale[100];
    int ch;

    while (1)
    {
        printf("Enter the scale to convert to (C, F, or K): ");

        if (scanf("%99s", newScale) == 1)
        {
            // Make first character uppercase
            newScale[0] = toupper(newScale[0]);

            if (strlen(newScale) == 1 &&
                (newScale[0] == 'C' ||
                 newScale[0] == 'F' ||
                 newScale[0] == 'K'))
            {
                return newScale[0];
            }
        }

        printf("Invalid input. Enter C, F, or K.\n");

        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
    }
}


// Convert any temperature to Celsius
float convertToCelsius(float Temp, char originalScale)
{
    if (originalScale == 'C')
    {
        return Temp;
    }
    else if (originalScale == 'F')
    {
        return (Temp - 32.0) * 5.0 / 9.0;
    }
    else
    {
        return Temp - 273.15;
    }
}


// Convert Celsius to whatever scale the user wants
float convertFromCelsius(float Celsius, char newScale)
{
    if (newScale == 'C')
    {
        return Celsius;
    }
    else if (newScale == 'F')
    {
        return (Celsius * 9.0 / 5.0) + 32.0;
    }
    else
    {
        return Celsius + 273.15;
    }
}


void printCategory(float Celsius)
{
    if (Celsius < 0)
    {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Bundle up!\n");
    }
    else if (Celsius < 10)
    {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    }
    else if (Celsius < 25)
    {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Enjoy the weather!\n");
    }
    else if (Celsius < 35)
    {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    }
    else
    {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors and drink lots of water!\n");
    }
}


int main()
{
    float Temp;
    float Celsius;
    float convertedTemp;

    char originalScale;
    char newScale;

    // Get user input
    Temp = getTemp();
    originalScale = getOriginalScale();
    newScale = getNewScale();

    // First convert original temperature to Celsius
    Celsius = convertToCelsius(Temp, originalScale);

    // Then convert Celsius to desired scale
    convertedTemp = convertFromCelsius(Celsius, newScale);

    // Print answer
    printf("Converted temperature: %.2f %c\n",
           convertedTemp, newScale);

    // Categorize based on Celsius equivalent
    printCategory(Celsius);

    return 0;
}
