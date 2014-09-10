#include <iostream>

using namespace std;

int main()
{
    int ans3 = 0;
    int ans5 = 0;
    int count3 = 0;
    int count5 = 0;
    for(int i = 1; i <= 1000; i++)
    {
        ans3 = i % 3;
        if(ans3 == 0)
        {
            count3 += 1;
        }

        ans5 = i % 5;
        if(ans5 == 0)
        {
            count5 += 1;
        }
                
    }


    cout << "Count for 3: " << count3 << endl;
    cout << "Count for 5: " << count5 << endl;
    int count = count3 + count5;
    cout << "Count: " << count << endl;
    return 0;


}
