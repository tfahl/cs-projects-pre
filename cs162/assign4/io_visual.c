#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file;
    FILE *file2;
    float k, p, c, init_temp, low, high, length, dtime;
    int time = 1, sec = 1, init_sec = 0, t, section;
    char word[10];
    file = fopen(argv[1], "r");
    file2 = fopen(argv[2], "wb");

    if(file == NULL)
    {
        printf("This file does not exsist \n");
    }
    else
    {
        //printf("this file exsists! \n");
        fscanf(file, "%s", word);
        k = atof(word);
        fscanf(file, "%s", word);
        p = atof(word);
        fscanf(file, "%s", word);
        c = atof(word);
        fscanf(file, "%s", word);
        init_temp = atof(word);
        fscanf(file, "%s", word);
        low = atof(word);
        fscanf(file, "%s", word);
        high = atof(word);
        fscanf(file, "%s", word);
        length = atof(word);
        fscanf(file, "%s", word);
        section = atoi(word);
        fscanf(file, "%s", word);
        t = atoi(word);
        fscanf(file, "%s", word);
        dtime = atof(word);
    }

    float value[t][section];
    float dsec = (length / section);
    float cont_var = ((k * dtime) / ((dsec * dsec) * (c * p)));
    int x = 0, y = 0;
    float write[1];
    for(x; x < section; x++)
    {
        value[0][x] = low;
    }
    for(y; y < t; y++)
    {
        value[y][section - 1] = high;
    }

    for(time; time < t - 1; time++)
    {
        write[0] = time;
        fwrite(write, sizeof(float), 1, file2);
        printf("Time: %i ", time);
            for(sec; sec < section - 1; sec++)
            { 
                value[time][0] = low;
                value[time + 1][0] = low;
                value[time + 1][sec] = ((cont_var * (value[time][sec + 1] - (2 * (value[time][sec])) + value[time][sec - 1])) + value[time][sec]);
                write[0] = value[time+1][sec];
                fwrite(write, sizeof(float), 1, file2);
                printf("%.2f ", value[time + 1][sec]);
            }
            write[0] = high;
            fwrite(write, sizeof(float), 1, file2);
            sec = 1;
            printf("\n");

    }

    fclose(file);
    fclose(file2);
    return 0;
}
