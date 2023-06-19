#include "Time_.h"

void Time_::tickTime()
{
    this->seconds += 1;

    if (this->seconds >= 60)
    {
        this->seconds %= 60;
        this->minutes += 1;
    }

    if (this->minutes >= 60)
    {
        this->minutes %= 60;
        this->hour += 1;
    }

    if (this->hour >= 24)
        this->minutes %= 24;
}

bool Time_::valid()
{
    time_t t = time(NULL);
    tm flag;
    localtime_s(&flag, &t);

    if (this->hour == flag.tm_hour && this->minutes == flag.tm_min && this->seconds == flag.tm_sec)
        return true;
    return false;
}

bool Time_::setFormat(const char* format)
{
    if (strcmp("am/pm", format) == 0 || strcmp("utc", format) == 0)
    {
        strcpy_s(this->format, format);
        return true;
    }
    return false;

}

const char* Time_::getFormat()
{
    return this->format;
}

Time_::Time_()
{
    time_t t = time(NULL);
    tm flag;
    localtime_s(&flag, &t);

    this->hour = flag.tm_hour;
    this->minutes = flag.tm_min;
    this->seconds = flag.tm_sec;
    strcpy_s(this->format, "utc");
}

Time_::Time_(int hour, int minutes, int seconds, const char* format)
{
    this->hour = hour;
    this->minutes = minutes;
    this->seconds = seconds;

    strcpy_s(this->format, "utc");
}

Time_::Time_(const Time_& obj)
{
    this->hour = obj.hour;
    this->minutes = obj.minutes;
    this->seconds = obj.seconds;

    strcpy_s(this->format, obj.format);
}

Time_::~Time_() {}

void Time_::showTime()
{
    if (strcmp("am/pm", format) == 0)
    {
        cout << "Текущее время = " << hour % 12 << " : " << minutes << " : " << seconds << " (";
        if (hour > 12) cout << "pm)\n"; else cout << "am)\n";
    }
    else
        cout << hour << " : " << minutes << " : " << seconds << " (" << format << ")\n";

}

string Time_::timetostring() const&
{
    string s;
    s.append(to_string(hour) + ":" + to_string(minutes));
    return s;
}

void Time_::setHour(int hour)
{
    this->hour = hour;
}

int Time_::getHour()
{
    return hour;
}

void Time_::setMinutes(int minutes)
{
    this->minutes = minutes;
}

int Time_::getMinutes()
{
    return minutes;
}

void Time_::setSeconds(int seconds)
{
    this->seconds = seconds;
}

int Time_::getSeconds()
{
    return seconds;
}

int Time_::gettimeseconds() const
{
    return ((this->hour * 60) + this->minutes);
}

bool Time_::operator==(const Time_& obj)
{
    if (this->hour == obj.hour &&
        this->minutes == obj.minutes &&
        this->seconds == obj.seconds)
        return true;
    else return false;
}

bool Time_::operator!=(const Time_& obj)
{
    return !(*this == obj);
}

bool Time_::operator>(const Time_& obj)
{
    if (this->hour > obj.hour)
        return true;
    else if (this->hour == obj.hour && this->minutes > obj.minutes)
        return true;
    else if (this->hour == obj.hour && this->minutes == obj.minutes
        && this->seconds > obj.seconds)
        return true;
    else false;
}

bool Time_::operator<(const Time_& obj)
{
    return !(*this > obj) && (*this != obj);
}

bool Time_::operator>=(const Time_& obj)
{
    return !(*this > obj) || (*this == obj);
}

bool Time_::operator<=(const Time_& obj)
{
    return !(*this < obj) || (*this == obj);
}

void Time_::operator-(int minutes)
{
    int h = minutes / 60;
    int m = minutes % 60;
    if (this->hour <= h) {
        this->hour =- h;
    }
    else {
        this->hour = h - this->hour;
    }
    if (this->minutes <= m) {
        this->minutes =- m;
    }
    else {
        this->minutes = m - this->minutes;
        if (this->hour == 0 || 24) {
            this->hour = 23;
        }
        else this->hour--;
    }
}

void Time_::operator+(int minutes)
{
    int h = minutes / 60;
    int m = minutes % 60;
    this->minutes = m + this->minutes;
    if (this->minutes > 59) {
        this->minutes %= 60;
        if (this->hour == 24) {
            this->hour = 1;
        }
        else this->hour++;
    }
    this->hour = (h + this->hour)%24;
}

Time_& Time_::operator+=(int sec) {
    for (int i = 0; i < sec; i++) {
        this->tickTime();
    }
    return *this;
}

Time_& Time_::operator=(const Time_& obj)
{
    // TODO: вставьте здесь оператор return
    this->hour = obj.hour;
    this->minutes = obj.minutes;
    this->seconds = obj.seconds;
    return *this;
}

istream& operator>>(istream& in, Time_& t)
{
    // TODO: вставьте здесь оператор return
    cout << "Часы:"; in >> t.hour;
    cout << "минуты: "; in >> t.minutes;
    t.seconds = 0;
    return in;
}

ostream& operator<<(ostream& os, const Time_& t)
{
    // TODO: вставьте здесь оператор return
    os << t.hour / 10 << t.hour % 10 << ":"
        << t.minutes / 10 << t.minutes % 10 << ":"
        << t.seconds / 10 << t.seconds % 10 << endl;
    return os;
}