#include <iostream>
#include <chrono>
#include <time.h>
#include <vector>
#include <windows.h>
#include <thread>
using namespace std;

int main()
{

    freopen("level.txt","r",stdin);

    INPUT inputs[2] = {};
    ZeroMemory(inputs, sizeof(inputs));
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = 'P';

    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = 'P';
    inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

    double bpm = 150;
    double res = 60000.00/((double)(bpm));
    double time_between_beats = res;
    int straight_delay = time_between_beats;
    int square_delay = res/2.0;
    int delay270 = res*3.0/2.0;
    /*
    time_between beats -> n normal 180degrees
    q quarter 90degrees
    t 270
    */
    /*Sleep(2000);
    //0.9 in 30 bpm
    //0.75 in 60 bpm
    //0.5 in 120 bpm
    //`
    auto startTime2 = std::chrono::system_clock::now();

    for(int i=0;i<1000;i++)
    {
        UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
    }
    auto end_time2 = std::chrono::system_clock::now();
    int time_taken2 = std::chrono::duration_cast<std::chrono::milliseconds>(end_time2 - startTime2).count();
    cout<<time_taken2<<"ms"<<endl;*/
    string level;
    getline(cin,level);
    cout<<level<<endl;
    std::chrono::milliseconds v[1000];
    //Sleep(2000);
    //while(true)
    //if(GetKeyState('R') & 0x8000)
    //{
     //   break;
    //}


    int it=0;
    for(int i=0;i<level.size();i++)
    {
        int time_to_take = 0;
        if(level[i] == 'n')time_to_take = straight_delay;
        if(level[i] == 'q')time_to_take = square_delay;
        if(level[i] == 't')time_to_take = delay270;
        if(level[i] == 's')
        {
            time_between_beats = res;
            time_between_beats*=4;
            straight_delay = time_between_beats;
            square_delay = time_between_beats/2;
            delay270 = time_between_beats*3/2;
            continue;
        }
        if(level[i] == 'f')
        {
            time_between_beats = res/2.0;
            straight_delay = time_between_beats;
            square_delay = time_between_beats/2;
            delay270 = time_between_beats*3/2.0;
            continue;
        }

        v[it++] = (std::chrono::milliseconds(time_to_take ));
    }
    res = 60000.00/(double)(bpm);
    time_between_beats = res;
    straight_delay = time_between_beats;
    cout<<straight_delay<<endl;
    this_thread::sleep_for(std::chrono::milliseconds(5000));
    SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
    this_thread::sleep_for(std::chrono::milliseconds(370 + 4*straight_delay));
    auto start_time = std::chrono::system_clock::now();
    auto startTime = start_time;
    for(int i=0;i<level.size();i++)
    {

        start_time += v[i];
       // start_time += (i&1);
        //level size is kinda small...
        std::this_thread::sleep_until(start_time);
        SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));



    }
    auto end_time = std::chrono::system_clock::now();
    int time_taken = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - startTime).count();
    cout<<time_taken<<"ms";

    /*char x;
    int offset = 0;


    std::this_thread::sleep_for(std::chrono::milliseconds(straight_delay*3));
    int sum_time_needed=0;
    int sum_time_taken=0;
    while(cin>>x)
    {
        if(GetKeyState('B') & 0x8000)
        {
            break;
        }
       // cout<<x<<endl;
        auto start_time = std::chrono::system_clock::now();
        int time_taken = 0;
        if(x == 'n')
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(straight_delay+offset));
        }
        if(x == 'q')
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(square_delay));
        }



        auto end_time = std::chrono::system_clock::now();
        time_taken = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        sum_time_taken+=time_taken;
        sum_time_needed+=straight_delay;
        offset = sum_time_needed - sum_time_taken-rand()%3;

        cout<<time_taken<<"ms"<<endl;

    }
*/
    return 0;
}
