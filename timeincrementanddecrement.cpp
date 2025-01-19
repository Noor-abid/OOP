#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void displayTime() {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    void operator++() {
        seconds++;
        if (seconds > 59) {
            seconds = 0;
            minutes++;
            if (minutes > 59) {
                minutes = 0;
                hours++;
                if (hours > 23) {
                    hours = 0;
                }
            }
        }
    }
    void operator--() {
        seconds--;
        if (seconds < 0) {
            seconds = 59;
            minutes--;
            if (minutes < 0) {
                minutes = 59;
                hours--;
                if (hours < 0) {
                    hours = 23;
                }
            }
        }
    }
};

int main() {
    Time t(23, 59, 0);
    cout << "Initial Time: ";
    t.displayTime();

    ++t;
    cout << "Time after increment: ";
    t.displayTime();
    --t;
    cout << "Time after decrement: ";
    t.displayTime();

    return 0;
}