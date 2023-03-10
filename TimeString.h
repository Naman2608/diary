// Created by Ashu Sharma on 03-02-2023.
// This file is dedicated to providing dates & time Strings and dealing with time

#ifndef DEAREST_DIARY_TIMESTRING_H
#define DEAREST_DIARY_TIMESTRING_H

#endif // DEAREST_DIARY_TIMESTRING_H

int DD, MM, YY, TH, TM, TS;
char DD_Str[12];
char TT_Str[12];

// Get Time String
void getTheTime()
{
    // struct tm tm;
    // time_t t;
    // time_t utc = timegm(&t);

    // localtime_r(&utc, &t);
    // setenv("TZ", "GMTGMT-1,M3.4.0/01,M10.4.0/02", 1);
    // tzset();
    // t = time(NULL);
    time_t rawtime;
    struct tm *tm;
    time(&rawtime);
    tm = localtime(&rawtime);
    setenv("TZ", "IST-05:30:00", 1);
    tzset();
    printf("Current local time and date: %s", asctime(tm));
    // storing the date/month/and year to a structure
    DD = tm->tm_mday,            // The Current Date
        MM = tm->tm_mon + 1,     // Here 0 = January and 11 = December, so an increment is made to get the dateString
        YY = tm->tm_year + 1900; // This returns the total number of years since 1900, so adding 1900 will get the current dateString
    TH = tm->tm_hour;
    TM = tm->tm_min;
    TS = tm->tm_sec;
    char cDD[4], cMM[4];
    sprintf(cDD, "%d%d", 0, DD);
    sprintf(cMM, "%d%d", 0, MM);
    if (DD < 10 && MM < 10)
    {

        sprintf(DD_Str, "%s-%s-%d", cDD, cMM, YY);
    }

    else if (DD < 10 || MM < 10)
    {
        if (DD < 10)
        {

            sprintf(DD_Str, "%s-%d-%d", cDD, MM, YY);
        }
        if (MM < 10)
        {

            sprintf(DD_Str, "%d-%s-%d", DD, cMM, YY);
        }
    }
    else
    {
        sprintf(DD_Str, "%d-%d-%d", DD, MM, YY);
    }

    sprintf(TT_Str, "%d:%d:%d", TH, TM, TS);
}
