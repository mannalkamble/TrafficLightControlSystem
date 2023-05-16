#include <stdio.h>
#include <header1.h>
int main()
{
    int stateA = 1; //Both Red
    int stateB = 0; //NS Green, EW Red
    int stateC = 0; //NS Yellow
    int stateD = 0; //EW Green, NS Red
    int stateE = 0; // EW Yellow
    int stateF = 0; // Both Red, Pedestrian Green
    int error = 0;
    setupGPIO();
    setLED(PIN_9,ON);
    setLED(PIN_6, OFF);
    setLED(PIN_17, ON);
    setLED(PIN_18, OFF);
    setLED(PIN_19, OFF);
    setLED(PIN_2, ON);
    setLED(PIN_7, OFF);
    setLED(PIN_8, OFF);
    while(1)
    {
        while(stateA)
        {
            delay(5000); 
            setLED(PIN_17, ON);
            setLED(PIN_18, OFF);
            setLED(PIN_19, OFF);
            setLED(PIN_2, ON);
            setLED(PIN_7, OFF);
            setLED(PIN_8, OFF);

            if(delay(10000))
            {
                int c = 0;
                while(c<20){
                    delay(10);
                    c++;
                }
                stateF = 1;
                break;

            }
            stateA = 0;
            stateB = 1;
        }
        while(stateB)
        {
            setLED(PIN_17, OFF);
            setLED(PIN_18, OFF);
            setLED(PIN_19, ON);
            setLED(PIN_2, ON);
            setLED(PIN_7, OFF);
            setLED(PIN_8, OFF);
            if(delay(20000))
            {
                stateF = 2;
                break;
            }
            stateC = 1;
            stateB = 0;

        }
        while(stateC)
        {       
            setLED(PIN_17, OFF);
            setLED(PIN_18, ON);
            setLED(PIN_19, OFF);
            setLED(PIN_2, ON);
            setLED(PIN_7, OFF);
            setLED(PIN_8, OFF);

            if(delay(3000))
            {
                stateF = 1;
                break;
            }
            stateD = 1;
            stateC = 0;

        }
        while(stateD)
        {

            setLED(PIN_17, ON);
            setLED(PIN_18, OFF);
            setLED(PIN_19, OFF);
            delay(5000);
            setLED(PIN_2, OFF);
            setLED(PIN_7, OFF);
            setLED(PIN_8, ON);

            if(delay(20000))
            {
                stateF = 3;
                break;
            }
            stateD = 0;
            stateE = 1;

        }
        while(stateE)
        {
            setLED(PIN_17, ON);
            setLED(PIN_18, OFF);
            setLED(PIN_19, OFF);
            setLED(PIN_2, OFF);
            setLED(PIN_7, ON);
            setLED(PIN_8, OFF);


            if(delay(3000))
            {
                stateF = 1;
                break;
            }    
            stateA = 1;
            stateE = 0;   
            setLED(PIN_2, ON);
            setLED(PIN_7, OFF);
            setLED(PIN_8, OFF);
    

        }

        while(stateF)
        {   
            if(stateF == 2){
                setLED(PIN_19,OFF);
                int c = 0;
                while(c<100)
                {
                    setLED(PIN_18, ON);
                    delay(100);
                    error = setLED(PIN_18, OFF);
                    delay(100);
                    c = c+1; 
                }
                setLED(PIN_18,OFF);
                setLED(PIN_17,ON);
            }
            if(stateF == 3){
                setLED(PIN_8,OFF);
                int c = 0;
                while(c<100)
                {
                    setLED(PIN_7, ON);
                    delay(100);
                    error = setLED(PIN_7, OFF);
                    delay(100);
                    c = c+1; 
                }
                setLED(PIN_7,OFF);
                setLED(PIN_2,ON);
            }
            setLED(PIN_17, ON);
            setLED(PIN_18, OFF);
            setLED(PIN_19, OFF);
            setLED(PIN_2, ON);
            setLED(PIN_7, OFF);
            setLED(PIN_8, OFF);
            setLED(PIN_6, ON);
            setLED(PIN_9, OFF);
            delay(15000);
            setLED(PIN_6, OFF);
            setLED(PIN_9, ON);
            stateF = 0;            

        }
    }
 return 0;
}