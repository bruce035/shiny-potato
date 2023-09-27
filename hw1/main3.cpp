#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int x;
    
    cout << "請輸入要輸入的姓名數量 x：" << endl;
    cin >> x;
    
    // 捕獲換行符號
    cin.ignore(100, '\n');
    
    char** dynamicArray = new char*[x];
    
    int maxLength = 0;  // 用於記錄最長姓名的長度
    int MaxfirstNameLength = 0;
    
    for (int i = 0; i < x; i++) {
        cout << "請輸入姓名 #" << i + 1 << "：" << endl;
        
        char input[100];  // 假定最長的姓名不超過 100 個字符
        
        cin.getline(input, sizeof(input));
        
        // 計算姓名的長度
        int length = strlen(input);
        
        // 更新最長姓名的長度
        if (length > maxLength) {
            maxLength = length;
        }
        
        const char* spacePosition = strchr(input, ' ');

        if (spacePosition != nullptr) {
            // 計算firstNameLength
            int firstNameLength = spacePosition - input;
            
            // 更新最長firstNameLength
            if (firstNameLength > MaxfirstNameLength) {
                MaxfirstNameLength = firstNameLength;
            }
        }
        
        // 分配動態記憶體並複製姓名到動態陣列中
        dynamicArray[i] = new char[length + 1];
        strcpy(dynamicArray[i], input);
    }
    
    cout << "姓名列表：" << endl;
    
    for (int i = 0; i < x; i++) {
        const char* spacePosition = strchr(dynamicArray[i], ' ');
        
        if (spacePosition != nullptr) {
            int firstNameLength = spacePosition - dynamicArray[i];
            int spaceCount = MaxfirstNameLength - firstNameLength;
            
            // 印出對齊的姓名
            for (int j = 0; j < spaceCount; j++) {
                cout << ' ';
            }
        }
        
        cout << dynamicArray[i] << endl;
    }
    
    // 釋放動態記憶體
    for (int i = 0; i < x; i++) {
        delete[] dynamicArray[i];
    }
    
    delete[] dynamicArray;
    
    return 0;
}
