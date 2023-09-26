#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int x, y;
    
    cout << "請輸入兩個數字 x 和 y：" << endl;
    cin >> x >> y;
    
    char** dynamicArrayNew = new char*[x];

    cout << "請依序輸入 " << x << " 個字串：" << endl;
    
    for (int i = 0; i < x; i++) {
        dynamicArrayNew[i] = new char[y + 1];

        cin >> dynamicArrayNew[i];
        
        if (strlen(dynamicArrayNew[i]) > y) {
            cout << "字串長度超過 " << y << "，請重新輸入：" << endl;
            i--;
        }
    }
    
    // 使用 Bubble Sort 根據字元的 ASCII code 由大到小排序
    for (int i = 0; i < x - 1; i++) {
        for (int j = 0; j < x - i - 1; j++) {
            if (strcmp(dynamicArrayNew[j], dynamicArrayNew[j + 1]) < 0) {
                char* temp = dynamicArrayNew[j];
                dynamicArrayNew[j] = dynamicArrayNew[j + 1];
                dynamicArrayNew[j + 1] = temp;
            }
        }
    }
    
    cout << "排序後的字串：" << endl;
    
    for (int i = 0; i < x; i++) {
        cout << dynamicArrayNew[i] << endl;
    }
    
    // 釋放動態記憶體
    for (int i = 0; i < x; i++) {
        delete[] dynamicArrayNew[i];
    }
    
    delete[] dynamicArrayNew;

    return 0;
}
