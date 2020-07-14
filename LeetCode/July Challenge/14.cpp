class Solution {
public:
    double angleClock(int hour, int minutes) {
        int hr = hour*60 + minutes;
        hr %= 720;
        double hrAngle = (double)(hr)/2;
        double minAngle = (double)minutes*6;
        double angA = hrAngle - minAngle;
        if(angA < 0){
            angA *= -1;
        }
        double angB = (double)360.00 - angA;
        if(angB < angA){
        	swap(angA, angB);
        }
        cout<<angA<<" "<<angB;
        return angA; 
    }
};