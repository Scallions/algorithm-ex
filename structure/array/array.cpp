/*
 * @Author       : Scallions
 * @Date         : 2022-01-21 13:11:00
 * @LastEditors  : Scallions
 * @LastEditTime : 2022-01-21 14:19:58
 * @FilePath     : /algorithm-ex/structure/array/array.cpp
 * @Description  : c++的数组相关
 * 资料：
 * https://www.runoob.com/cplusplus/cpp-arrays.html
 * https://www.runoob.com/cplusplus/cpp-stl-tutorial.html
 * https://www.cnblogs.com/h46incon/archive/2013/03/17/2965020.html
 */
#include<vector>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // #1 c风格
    int arr1[] = {1,2,3};
    int arr2[3];
    // 增删改查，长度固定不能增删
    arr1[0] = 0;
    cout << arr1[0] << endl;
    // 遍历
    // 1. for each
    for(auto i: arr1){
        cout << i << endl;
    }
    // 2. for idx
    int l = sizeof arr1 / sizeof arr1[0];
    for(int i=0; i<l; ++i){
        cout << arr1[i] << endl;
    }

    // #2 vector
    vector<int> arr3(3);
    vector<int> arr4(3, 1);
    vector<int> arr5{1,2,3};
    // 增删改查
    arr5.push_back(4); // 添加到末尾
    arr5.insert(arr5.begin()+0, 0);
    arr5.erase(arr5.begin()+0); // 删除指定位置
    arr5.pop_back(); // 删除末尾
    arr5[0] = 10;
    cout << arr5[0] << endl;
    cout << arr5.at(0) << endl;
    // 遍历
    // 1. for idx 同上
    // 2. for each
    for(auto i: arr5){
        cout << i << endl;
    }
    // 3. iterator
    for(auto ite=arr5.begin(); ite!=arr5.end(); ++ite){
        cout << *ite << endl;
    }

    return 0;
}
