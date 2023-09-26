#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    int x, y;
    
    cout << "請輸入兩個數字 x 和 y：" << endl;
    cin >> x >> y;
    
    char** dynamicArrayMalloc = (char**)malloc(x * sizeof(char*));

    cout << "請依序輸入 " << x << " 個字串：" << endl;
    
    for (int i = 0; i < x; i++) {
        dynamicArrayMalloc[i] = (char*)malloc((y + 1) * sizeof(char));

        cin >> dynamicArrayMalloc[i];
        
        if (strlen(dynamicArrayMalloc[i]) > y) {
            cout << "字串長度超過 " << y << "，請重新輸入：" << endl;
            i--;
        }
    }
    
    // 使用 Bubble Sort 根據字元的 ASCII code 由大到小排序
    for (int i = 0; i < x - 1; i++) {
        for (int j = 0; j < x - i - 1; j++) {
            if (strcmp(dynamicArrayMalloc[j], dynamicArrayMalloc[j + 1]) < 0) {
                char* temp = dynamicArrayMalloc[j];
                dynamicArrayMalloc[j] = dynamicArrayMalloc[j + 1];
                dynamicArrayMalloc[j + 1] = temp;
            }
        }
    }
    
    cout << "排序後的字串：" << endl;
    
    for (int i = 0; i < x; i++) {
        cout << dynamicArrayMalloc[i] << endl;
    }
    
    // 釋放動態記憶體
    for (int i = 0; i < x; i++) {
        free(dynamicArrayMalloc[i]);
    }
    
    free(dynamicArrayMalloc);

    return 0;
}
